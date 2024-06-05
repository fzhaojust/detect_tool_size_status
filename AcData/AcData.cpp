

#include "AcData.h"

AcData::AcData(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//��ʼ���̶߳���
	ThWrite = new mythread1();
	ThRead = new mythread2();
	ThWave = new mythread3();
	det_sta = new detect_status();

	
	/*if (ui.lineEdit->text().isEmpty() == false) {
		min_threshold = ui.lineEdit->text().toDouble();
	}*/


	init();
	//��ʼ���
	connect(ui.pushButton, &QPushButton::clicked, this, &AcData::Read_data);
	//ֹͣ���
	connect(ui.pushButton_2, &QPushButton::clicked, this, &AcData::push_stop);
	//�ɼ��߳���Ϣ��ʾ
	connect(ThWrite, SIGNAL(m1_signal(QString)), this, SLOT(broadcast(QString)));
	//д�߳���Ϣ��ʾ
	connect(ThRead, SIGNAL(m2_signal(QString)), this, SLOT(broadcast(QString)));
	//�˳�����
	connect(ui.pushButton_3, &QPushButton::clicked, [this]() {QApplication *app; app->exit(); });
	
	//connect(&ana, &Data_analysis::Exit_signal, this, &AcData::dealdata);
	//�����߳̽����������ֵ
	connect(ThWave, SIGNAL(m3_signal(double)), this, SLOT(paramer_change(double)));
	//����������
	connect(&hisdata, &history_data::Exit_data, this, &AcData::dealdata);
	//���ӽ���
	connect(ui.pushButton_5, &QPushButton::clicked, this, &AcData::Open_Data);
	//connect(ThWave,SIGNAL())
	//����
	connect(det_sta, SIGNAL(detect_signals(QString)), this, SLOT(alarm_breakage(QString)));
	//״̬����߳���Ϣ��ʾ
	connect(det_sta, SIGNAL(detect_info(QString)), this, SLOT(broadcast(QString)));

}

void AcData::init() {
	this->setWindowTitle("TCM");
	chart = new QChart();
	chart->addSeries(Qline);

	axisX = new QValueAxis(this);
	axisYY = new QValueAxis(this);
	//line->setName("RMS value");//������������
	Qline->setPen(QColor(255, 0, 0));//����������ɫ
	Qline->setUseOpenGL(true);//openGl ����
	chart->legend()->hide();

	chart->setTitle("Power Data");//����ͼ�����
	chart->removeSeries(Qline);
	chart->addSeries(Qline);
	chart->createDefaultAxes();//����������

	axisX->setRange(0, maxsize);//��Χ
	axisX->setTitleText("points");//����
   // axisX->setTickCount(10);//�ָ�����
	axisX->setLineVisible(true);//���ӻ�
	axisX->setLinePenColor(Qt::blue);//��ɫ

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
	//��ʼ�����ִ�С
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
	//�ɼ��߳�����

	ThRead->start();
	
	if (ThRead->isRunning() == true) {
		ThWrite->start();
		ThWave->start();
		
	}
	else {
		ui.textBrowser->insertPlainText("thread don't start\n");
	}

	//���Ŀǰ���ж�ģʽ
	 if(ui.radioButton_3->isChecked()) {
		det_sta->start();
		 cout << "���ģʽ����" << endl;
	 }
	 else {
		 cout << "���ģʽδ����" << endl;
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
	//�رռ���߳�
	//���Ŀǰ���ж�ģʽ
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
	//��ʾ��ȡ���ݴ���
	hisdata.show();
	this->hide();
}

void AcData::paramer_change(double pra) {
	axisYY->setRange(-0.1, pra);
	ui.widget->setChart(chart);

}


// �ú�����label�ؼ����һ��Բ��ָʾ�ƣ���Ҫָ����ɫcolor�Լ�ֱ��size
// color 0:grey 1:red 2:green 3:yellow
// size  ��λ������
void AcData::setLED(QLabel* label, int color, int size)
{
	// ��label�е��������
	label->setText("");
	// �����þ��δ�С
	// ���ui�������õ�label��С����С��Ⱥ͸߶�С�����ν�������Ϊ��С��Ⱥ���С�߶ȣ�
	// ���ui�������õ�label��С����С��Ⱥ͸߶ȴ󣬾��ν�������Ϊ����Ⱥ����߶ȣ�
	QString min_width = QString("min-width: %1px;").arg(size);              // ��С��ȣ�size
	QString min_height = QString("min-height: %1px;").arg(size);            // ��С�߶ȣ�size
	QString max_width = QString("max-width: %1px;").arg(size);              // ��С��ȣ�size
	QString max_height = QString("max-height: %1px;").arg(size);            // ��С�߶ȣ�size
	// �����ñ߽���״���߿�
	QString border_radius = QString("border-radius: %1px;").arg(size / 2);    // �߿���Բ�ǣ��뾶Ϊsize/2
	QString border = QString("border:1px solid black;");                    // �߿�Ϊ1px��ɫ
	// ������ñ�����ɫ
	QString background = "background-color:";
	switch (color) {
	case 0:
		// ��ɫ
		background += "rgb(190,190,190)";
		break;
	case 1:
		// ��ɫ
		background += "rgb(255,0,0)";
		break;
	case 2:
		// ��ɫ
		background += "rgb(0,255,0)";
		break;
	case 3:
		// ��ɫ
		background += "rgb(255,255,0)";
		break;
	default:
		break;
	}

	const QString SheetStyle = min_width + min_height + max_width + max_height + border_radius + border + background;
	label->setStyleSheet(SheetStyle);
}
//���б���
void AcData::alarm_breakage(QString str) {

	setLED(ui.label_led1, 1, 60);
	QMessageBox::critical(this, "��Ϣ��ʾ", "����״̬�쳣");
	ui.textBrowser->insertPlainText(str);
	ui.textBrowser->moveCursor(QTextCursor::End);
	//������ͣ
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

	delete ThWrite;//д�̶߳���
	ThWrite = nullptr;
	delete ThRead;//���̶߳���
	ThRead = nullptr;
	delete ThWave;
	ThWave = nullptr;
	if (det_sta != nullptr) {
		delete det_sta;
		det_sta = nullptr;
	}

}

