#include "history_data.h"

history_data::history_data(QWidget *parent)
	: QWidget(parent)
{

	ui.setupUi(this);

	
	ThRead = new mythread2();
	ThWave = new train_wave();
	Nc = new newtool_collect();
	Bc = new brokentool_collect();
	createChart();//����ͼ��


	connect(ui.pushButton, &QPushButton::clicked, this, &history_data::prepareData);//��������
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
{ //����ͼ��
	this->setWindowTitle("TCM");
	chart = new QChart();
	chart->addSeries(train_line);

	axisX = new QValueAxis(this);
	axisY = new QValueAxis(this);
	//line->setName("RMS value");//������������
	train_line->setPen(QColor(255, 0, 0));//����������ɫ
	train_line->setUseOpenGL(true);//openGl ����
	chart->legend()->hide();

	chart->setTitle("AE Data");//����ͼ�����
	chart->removeSeries(train_line);
	chart->addSeries(train_line);
	chart->createDefaultAxes();//����������

	axisX->setRange(0, maxsize);//��Χ
	axisX->setTitleText("points");//����
   // axisX->setTickCount(10);//�ָ�����
	axisX->setLineVisible(true);//���ӻ�
	axisX->setLinePenColor(Qt::blue);//��ɫ

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
	//��ʼ�����ִ�С

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
	//�ɼ��߳�����

	ThRead->start();

	if (ThRead->isRunning() == true) {
		cout << "read is running " << endl;
		ThWave->start();
		//Nc->start();

	}
	else {
		ui.textBrowser->insertPlainText("thread don't start\n");
	}
	
	//���Ŀǰ���ж�ģʽ
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
	//�رռ���߳�
		//���Ŀǰ���ж�ģʽ
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

//����µ������ļ�
void history_data::clean_newdata() {
	QMessageBox msg(this);//�Ի������ø����
	msg.setWindowTitle("��Ϣ��ʾ");//�Ի������
	msg.setText("ȷ��ɾ���µ���������");//�Ի�����ʾ�ı�
	msg.setIcon(QMessageBox::Information);//����ͼ������
	//msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel | QMessageBox::YesToAll);//�Ի����ϰ����İ�ť
	msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	if (msg.exec() == QMessageBox::Ok)//ģ̬����
	{
		string data = ".\\dataset\\dataset_AE_fresh.txt";
		ifstream iFile;
		iFile.open(data, ios::out | ios::trunc);
		iFile.close();

	}

	
	return;
}
//��ձ��������ļ�
void history_data::clean_brokendata() {
	QMessageBox msg(this);//�Ի������ø����
	msg.setWindowTitle("��Ϣ��ʾ");//�Ի������
	msg.setText("ȷ��ɾ��������������");//�Ի�����ʾ�ı�
	msg.setIcon(QMessageBox::Information);//����ͼ������
	//msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel | QMessageBox::YesToAll);//�Ի����ϰ����İ�ť
	msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	if (msg.exec() == QMessageBox::Ok)//ģ̬����
	{
		string data = ".\\dataset\\dataset_AE_breeakage.txt";
		ifstream iFile;
		iFile.open(data, ios::out | ios::trunc);
		iFile.close();

	}
	
	return;
}


//ѵ��ģ�Ͳ�����
void history_data::train_data() {
	QMessageBox msg(this);//�Ի������ø����
	msg.setWindowTitle("��Ϣ��ʾ");//�Ի������
	msg.setText("ȷ�Ͽ�ʼѵ��SVM����ģ��");//�Ի�����ʾ�ı�
	msg.setIcon(QMessageBox::Information);//����ͼ������
	//msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel | QMessageBox::YesToAll);//�Ի����ϰ����İ�ť
	msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	
	if (msg.exec() == QMessageBox::Ok){//ģ̬����
		RT_TCM_AE mv;
		int res=mv.train_model();
		if (res == 1) {
			cout << "��������Ϊ��" << endl;
		}else if (res == 2) {
			cout << "��ȡ�ı�ʧ��" << endl;
		}
	}


	return;
}
