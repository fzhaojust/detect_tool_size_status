/**********************************************************************
* Copyright (c) 2021,VISLAB
* All rights reserved.
* �ļ�����history_data.h
* ������QT�ӽ��湦�ܼ���
* �������ڣ�20220501
* �����ߣ��Է�
* ��ʼʱ�䣺20220401
* ���ʱ�䣺20220501
* �޸�����       �汾��        �޸���                   �޸�����
* ----------------------------------------------------------------------
* 20220501    V1.0.1        *****                      ������**����
*************************************************************************/
#pragma once

#include <QWidget>
#include "ui_history_data.h"
#include    "qwchartview.h"

#include    <QtCharts>  //������ô����
QT_CHARTS_USE_NAMESPACE     //������ô����
#include    <QLabel>
#include"vary.h"
#include"mythread2.h"
#include"train_wave.h"
#include"newtool_collect.h"
#include"brokentool_collect.h"




class history_data : public QWidget
{
	Q_OBJECT

public:
	history_data(QWidget *parent = Q_NULLPTR);
	~history_data();
signals://�źű�����signals�ؼ�������

	///�������������������淢�����ź�
	///param [I]	��
	///����ֵ�� ��
	///��ע����
	void Exit_data();

public slots:
	///��������������������
	///param [I]	��
	///����ֵ�� ��
	///��ע����
	void Exit_interface();
	///�������������ӽ��淢����ʾ��Ϣ
	///param [I]	�ַ�����ʾ��Ϣ
	///����ֵ�� ��
	///��ע����
	void broadcast(QString str);

	///��������������ѡ�еĵ�ѡ�������ɼ��߳�
	///param [I]	��
	///����ֵ�� ��
	///��ע����
	void    prepareData();  
	//
	///����������ֹͣ�����ɼ�
	///param [I]	��
	///����ֵ�� ��
	///��ע����
	void    stop_collect();
	///������������̬�ı�Y�����곤��
	///param [I]	��ǰ���ݵ����ֵ
	///����ֵ�� ��
	///��ע����
	void parameter_change(double pra);
	
	///��������������µ������ļ�
	///param [I]	��
	///����ֵ�� ��
	///��ע����
	void clean_newdata();

	///������������ձ��������ļ�
	///param [I]	��
	///����ֵ�� ��
	///��ע����
	void clean_brokendata();
	
	///����������ѵ��SVMģ�Ͳ�����
	///param [I]	��
	///����ֵ�� ��
	///��ע����
	void train_data();

private:
	Ui::history_data ui;
	
	///������������ʼ��ͼ�����
	///param [I]	��
	///����ֵ�� ��
	///��ע����
	void createChart(); //����ͼ��


private:
	//��ͼ����������
	QChart* chart;//���ζ���
	QValueAxis *axisX;//���������
	QValueAxis *axisY;//���������
	//QValueAxis *axisY;

	mythread2 *ThRead;//���̶߳���
	train_wave *ThWave;//��ʾ�߳�
	//д�߳�
	newtool_collect *Nc;//�µ����ݲɼ�
	brokentool_collect *Bc;//�������ݲɼ�

};
