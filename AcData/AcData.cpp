

#include "AcData.h"

AcData::AcData(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//初始化线程对象
	ThWrite = new mythread1();
	ThRead = new mythread2();
	ThWave = new mythread3();
	det_sta = new detect_status();

	
	/*if (ui.lineEdit->text().isEmpty() == false) {
		min_threshold = ui.lineEdit->text().toDouble();
	}*/


	init();
	//开始监测
	connect(ui.pushButton, &QPushButton::clicked, this, &AcData::Read_data);
	//停止监测
	connect(ui.pushButton_2, &QPushButton::clicked, this, &AcData::push_stop);
	//采集线程信息提示
	connect(ThWrite, SIGNAL(m1_signal(QString)), this, SLOT(broadcast(QString)));
	//写线程信息提示
	connect(ThRead, SIGNAL(m2_signal(QString)), this, SLOT(broadcast(QString)));
	//退出程序
	connect(ui.pushButton_3, &QPushButton::clicked, [this]() {QApplication *app; app->exit(); });
	
	//connect(&ana, &Data_analysis::Exit_signal, this, &AcData::dealdata);
	//波形线程接受数据最大值
	connect(ThWave, SIGNAL(m3_signal(double)), this, SLOT(paramer_change(double)));
	//返回主界面
	connect(&hisdata, &history_data::Exit_data, this, &AcData::dealdata);
	//打开子界面
	connect(ui.pushButton_5, &QPushButton::clicked, this, &AcData::Open_Data);
	//connect(ThWave,SIGNAL())
	//报警
	connect(det_sta, SIGNAL(detect_signals(QString)), this, SLOT(alarm_breakage(QString)));
	//状态监测线程信息提示
	connect(det_sta, SIGNAL(detect_info(QString)), this, SLOT(broadcast(QString)));

}

void AcData::init() {
	this->setWindowTitle("TCM");
	chart = new QChart();
	chart->addSeries(Qline);

	axisX = new QValueAxis(this);
	axisYY = new QValueAxis(this);
	//line->setName("RMS value");//设置曲线名称
	Qline->setPen(QColor(255, 0, 0));//设置曲线颜色
	Qline->setUseOpenGL(true);//openGl 加速
	chart->legend()->hide();

	chart->setTitle("Power Data");//设置图标标题
	chart->removeSeries(Qline);
	chart->addSeries(Qline);
	chart->createDefaultAxes();//设置坐标轴

	axisX->setRange(0, maxsize);//范围
	axisX->setTitleText("points");//标题
   // axisX->setTickCount(10);//分隔个数
	axisX->setLineVisible(true);//可视化
	axisX->setLinePenColor(Qt::blue);//颜色

	axisYY->setRange(-10, 10);
	axisYY->setTitleText("value");
	axisYY->setTickCount(6);
	axisYY->setLineVisible(true);
	axisYY->setLinePenColor(Qt::blue);

	chart->setAxisX(axisX, Qline);
	chart->setAxisY(axisYY, Qline);
	QVector<QPointF>list;
	ui.widget->setChart(chart);
	for (int i = 0; i < maxsize; ++i) {
		list.append(QPointF(i, 0));
	}
	Qline->replace(list);
	//初始化文字大小
	setLED(ui.label_led1, 2, 60);
	QFont ft;
	ft.setPointSize(16);
	ui.pushButton->setFont(ft);
	ui.pushButton_2->setFont(ft);
	ui.pushButton_3->setFont(ft);
	
	ui.pushButton_5->setFont(ft);

	ui.radioButton_3->setFont(ft);
	ui.label->setFont(ft);
	ui.radioButton_3->setChecked(true);

}



void AcData::Read_data() {

	is_stop = false;
	//采集线程启动

	ThRead->start();
	
	if (ThRead->isRunning() == true) {
		ThWrite->start();
		ThWave->start();
		
	}
	else {
		ui.textBrowser->insertPlainText("thread don't start\n");
	}

	//监测目前的判定模式
	 if(ui.radioButton_3->isChecked()) {
		det_sta->start();
		 cout << "监测模式开启" << endl;
	 }
	 else {
		 cout << "监测模式未开启" << endl;
	 }
	 setLED(ui.label_led1, 2, 60);

}

void AcData::push_stop() {
	if (is_stop == false) {
		is_stop = true;
	}
	if ((ThWrite->isRunning() == true) && (ThRead->isRunning() == true)) {//ThWaveform->isRunning()==true
	
	
		ThRead->quit();
		ThRead->wait();
		ThWrite->quit();
		ThWrite->wait();
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
	if (det_sta->isRunning() == true) {
		det_sta->quit();
		det_sta->wait();
	}

}
void AcData::broadcast(QString str) {
	
	ui.textBrowser->insertPlainText(str);
	ui.textBrowser->moveCursor(QTextCursor::End);

}
void AcData::Open_Data() {
	//显示读取数据窗口
	hisdata.show();
	this->hide();
}

void AcData::paramer_change(double pra) {
	axisYY->setRange(-0.1, pra);
	ui.widget->setChart(chart);

}


// 该函数将label控件变成一个圆形指示灯，需要指定颜色color以及直径size
// color 0:grey 1:red 2:green 3:yellow
// size  单位是像素
void AcData::setLED(QLabel* label, int color, int size)
{
	// 将label中的文字清空
	label->setText("");
	// 先设置矩形大小
	// 如果ui界面设置的label大小比最小宽度和高度小，矩形将被设置为最小宽度和最小高度；
	// 如果ui界面设置的label大小比最小宽度和高度大，矩形将被设置为最大宽度和最大高度；
	QString min_width = QString("min-width: %1px;").arg(size);              // 最小宽度：size
	QString min_height = QString("min-height: %1px;").arg(size);            // 最小高度：size
	QString max_width = QString("max-width: %1px;").arg(size);              // 最小宽度：size
	QString max_height = QString("max-height: %1px;").arg(size);            // 最小高度：size
	// 再设置边界形状及边框
	QString border_radius = QString("border-radius: %1px;").arg(size / 2);    // 边框是圆角，半径为size/2
	QString border = QString("border:1px solid black;");                    // 边框为1px黑色
	// 最后设置背景颜色
	QString background = "background-color:";
	switch (color) {
	case 0:
		// 灰色
		background += "rgb(190,190,190)";
		break;
	case 1:
		// 红色
		background += "rgb(255,0,0)";
		break;
	case 2:
		// 绿色
		background += "rgb(0,255,0)";
		break;
	case 3:
		// 黄色
		background += "rgb(255,255,0)";
		break;
	default:
		break;
	}

	const QString SheetStyle = min_width + min_height + max_width + max_height + border_radius + border + background;
	label->setStyleSheet(SheetStyle);
}
//崩刃报警
void AcData::alarm_breakage(QString str) {

	setLED(ui.label_led1, 1, 60);
	QMessageBox::critical(this, "消息提示", "刀具状态异常");
	ui.textBrowser->insertPlainText(str);
	ui.textBrowser->moveCursor(QTextCursor::End);
	//界面暂停
	push_stop();
}


void AcData::dealdata() {
	//ana.hide();
	hisdata.hide();
	this->show();
}


AcData::~AcData() {
	delete chart;
	delete axisX;
	delete axisYY;

	delete ThWrite;//写线程对象
	ThWrite = nullptr;
	delete ThRead;//读线程对象
	ThRead = nullptr;
	delete ThWave;
	ThWave = nullptr;
	if (det_sta != nullptr) {
		delete det_sta;
		det_sta = nullptr;
	}

}

