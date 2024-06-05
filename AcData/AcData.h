/**********************************************************************
* Copyright (c) 2021,VISLAB
* All rights reserved.
* �ļ�����AcData.h
* ������QT�����湦�ܼ���
* �������ڣ�20220501
* �����ߣ��Է�
                                                                                                                                                                         
* ��ʼʱ�䣺20220401
* ���ʱ�䣺20220501
* �޸�����       �汾��        �޸���                   �޸�����
* ----------------------------------------------------------------------
* 20220501    V1.0.1        *****                      ������**����
*************************************************************************/
#pragma once

#include"vary.h"
#include"mythread1.h"
#include"mythread2.h"
#include"mythread3.h"
#include"history_data.h"
#include"detect_status.h"
#include"newtool_collect.h"
#include"brokentool_collect.h"

#include <QtWidgets/QMainWindow>
#include "ui_AcData.h"


class AcData : public QMainWindow
{
	
	Q_OBJECT

public:

	AcData(QWidget *parent = Q_NULLPTR);
	//��ʼ������
	void init();


	///�������������ڽ���label�ؼ��ı���ɫ
	///param [I]	label,label�ؼ�����
	///param [I]	color	��ѡ��ɫ�� 0:grey 1:red 2:green 3:yellow
	///param [I]	size	��ɫ�ߴ�ֱ��
	///����ֵ�� ��
	///��ע����
	void setLED(QLabel* label, int color, int size);
	//��ͼ����������
	QChart* chart;//���沨�ζ���
	QValueAxis *axisX;//x�����
	QValueAxis *axisYY;//y�����
	
	~AcData();

signals:

public slots:
	///�����������������
	///param [I]	��
	///����ֵ�� ��
	///��ע����
	void Read_data();
	///����������ֹͣ���
	///param [I]	��
	///����ֵ�� ��
	///��ע����
	void push_stop();

	///��������������������ַ�����ʾ��Ϣ
	///param [I]	��
	///����ֵ�� ��
	///��ע����
	void broadcast(QString str);
	///�������������ӽ���
	///param [I]	��
	///����ֵ�� ��
	///��ע����
	void Open_Data();
	//
	///��������������������
	///param [I]	��
	///����ֵ�� ��
	///��ע����
	void dealdata();
	//
	///������������̬�ı�Y��������ʾ����
	///param [I]	��
	///����ֵ�� ��
	///��ע����
	void paramer_change(double pra);
	///������������������
	///param [I]	��
	///����ֵ�� ��
	///��ע����
	void alarm_breakage(QString str);


private:

	Ui::AcDataClass ui;
	mythread1 *ThWrite;//д�̶߳���
	mythread2 *ThRead;//���̶߳���
	mythread3 *ThWave;//��ʾ�߳�
	detect_status *det_sta;//�ڻ�����߳�
	history_data hisdata;//�ӽ������
};
