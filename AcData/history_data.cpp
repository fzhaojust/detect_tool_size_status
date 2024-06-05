#include "history_data.h"

history_data::history_data(QWidget *parent)
	: QWidget(parent)
{

	ui.setupUi(this);

	
	ThRead = new mythread2();
	ThWave = new train_wave();
	Nc = new newtool_collect();
	Bc = new brokentool_collect();
	createChart();//创建图表


	connect(ui.pushButton, &QPushButton::clicked, this, &history_data::prepareData);//生成数据
	connect(ui.pushButton_2, &QPushButton::clicked, this, &history_data::stop_collect);
	connect(ui.pushButton_3, &QPushButton::clicked, this, &history_data::Exit_interface);
	connect(ui.pushButton_4, &QPushButton::clicked, this, &history_data::clean_newdata);
	connect(ui.pushButton_5, &QPushButton::clicked, this, &history_data::clean_brokendata);
	connect(ui.pushButton_6, &QPushButton::clicked, this, &history_data::train_data);
	//connect(ThWave, SIGNAL(train_signal(double)), this, SLOT(paramer_change(double)));
	connect(ThWave, SIGNAL(train_signal(double)), this, SLOT(parameter_change(double)));


}

void history_data::Exit_interface() {
	emit Exit_data();

}


history_data::~history_data()
{
	delete chart;
	delete axisX;
	delete axisY;
	delete ThWave;
	delete ThRead;
	delete Nc;
	Nc = nullptr;
	delete Bc;
	Bc = nullptr;

	/*if (Nc != nullptr) {
		delete Nc;
		Nc = nullptr;
	}
	if (Bc != nullptr) {
		delete Bc;
		Bc = nullptr;
	}*/

}


void history_data::createChart()
{ //创建图表
	this->setWindowTitle("TCM");
	chart = new QChart();
	chart->addSeries(train_line);

	axisX = new QValueAxis(this);
	axisY = new QValueAxis(this);
	//line->setName("RMS value");//设置曲线名称
	train_line->setPen(QColor(255, 0, 0));//设置曲线颜色
	train_line->setUseOpenGL(true);//openGl 加速
	chart->legend()->hide();

	chart->setTitle("AE Data");//设置图标标题
	chart->removeSeries(train_line);
	chart->addSeries(train_line);
	chart->createDefaultAxes();//设置坐标轴

	axisX->setRange(0, maxsize);//范围
	axisX->setTitleText("points");//标题
   // axisX->setTickCount(10);//分隔个数
	axisX->setLineVisible(true);//可视化
	axisX->setLinePenColor(Qt::blue);//颜色

	axisY->setRange(0, 10);
	axisY->setTitleText("value");
	axisY->setTickCount(6);
	axisY->setLineVisible(true);
	axisY->setLinePenColor(Qt::blue);

	chart->setAxisX(axisX, train_line);
	chart->setAxisY(axisY, train_line);
	QVector<QPointF>list;
	ui.chartView->setChart(chart);
	for (int i = 0; i < maxsize; ++i) {
		list.append(QPointF(i, 0));
	}
	train_line->replace(list);
	//初始化文字大小

	QFont ft;
	ft.setPointSize(16);
	ui.pushButton->setFont(ft);
	ui.pushButton_2->setFont(ft);
	ui.pushButton_3->setFont(ft);
	ui.pushButton_4->setFont(ft);
	ui.pushButton_5->setFont(ft);
	ui.pushButton_6->setFont(ft);
	ui.radioButton->setFont(ft);
	ui.radioButton_2->setFont(ft);

}



void history_data::prepareData(){

	is_stop = false;
	//采集线程启动

	ThRead->start();

	if (ThRead->isRunning() == true) {
		cout << "read is running " << endl;
		ThWave->start();
		//Nc->start();

	}
	else {
		ui.textBrowser->insertPlainText("thread don't start\n");
	}
	
	//监测目前的判定模式
	if (ui.radioButton->isChecked()) {
		Nc->start();
		
	}
	else if (ui.radioButton_2->isChecked()) {
		Bc->start();
	}
}

void history_data::stop_collect() {
	if (is_stop == false) {
		is_stop = true;
	}

	if (ThRead->isRunning() == true) {//ThWaveform->isRunning()==true

		ThRead->quit();
		ThRead->wait();
		ThWave->quit();
		ThWave->wait();
		ui.textBrowser->insertPlainText("End of data collection\n");
		ui.textBrowser->moveCursor(QTextCursor::End);
	}

	else {
		ui.textBrowser->insertPlainText("the program do not start\n");
		ui.textBrowser->moveCursor(QTextCursor::End);
	}
	//关闭监测线程
		//监测目前的判定模式
	if (Nc->isRunning() == true) {
		Nc->quit();
		Nc->wait();
	}
	else if (Bc->isRunning() == true) {
		Bc->quit();
		Bc->wait();
	}

}

void history_data::broadcast(QString str) {

	ui.textBrowser->insertPlainText(str);
	ui.textBrowser->moveCursor(QTextCursor::End);

}

void history_data::parameter_change(double pra) {
	axisY->setRange(-0.1, pra);
	ui.chartView->setChart(chart);
}

//清空新刀样本文件
void history_data::clean_newdata() {
	QMessageBox msg(this);//对话框设置父组件
	msg.setWindowTitle("消息提示");//对话框标题
	msg.setText("确认删除新刀样本数据");//对话框提示文本
	msg.setIcon(QMessageBox::Information);//设置图标类型
	//msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel | QMessageBox::YesToAll);//对话框上包含的按钮
	msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	if (msg.exec() == QMessageBox::Ok)//模态调用
	{
		string data = ".\\dataset\\dataset_AE_fresh.txt";
		ifstream iFile;
		iFile.open(data, ios::out | ios::trunc);
		iFile.close();

	}

	
	return;
}
//清空崩刃样本文件
void history_data::clean_brokendata() {
	QMessageBox msg(this);//对话框设置父组件
	msg.setWindowTitle("消息提示");//对话框标题
	msg.setText("确认删除崩刃样本数据");//对话框提示文本
	msg.setIcon(QMessageBox::Information);//设置图标类型
	//msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel | QMessageBox::YesToAll);//对话框上包含的按钮
	msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	if (msg.exec() == QMessageBox::Ok)//模态调用
	{
		string data = ".\\dataset\\dataset_AE_breeakage.txt";
		ifstream iFile;
		iFile.open(data, ios::out | ios::trunc);
		iFile.close();

	}
	
	return;
}


//训练模型并保存
void history_data::train_data() {
	QMessageBox msg(this);//对话框设置父组件
	msg.setWindowTitle("消息提示");//对话框标题
	msg.setText("确认开始训练SVM分类模型");//对话框提示文本
	msg.setIcon(QMessageBox::Information);//设置图标类型
	//msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel | QMessageBox::YesToAll);//对话框上包含的按钮
	msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	
	if (msg.exec() == QMessageBox::Ok){//模态调用
		RT_TCM_AE mv;
		int res=mv.train_model();
		if (res == 1) {
			cout << "特征参数为空" << endl;
		}else if (res == 2) {
			cout << "读取文本失败" << endl;
		}
	}


	return;
}
