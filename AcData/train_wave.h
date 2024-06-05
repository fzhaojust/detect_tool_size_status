/**********************************************************************
* Copyright (c) 2021,VISLAB
* All rights reserved.
* �ļ�����train_wave.h
* ������QT�ӽ��沨�ζ�̬��ʾ�߳�
* �������ڣ�20220501
* �����ߣ��Է�
* ��ʼʱ�䣺20220401
* ���ʱ�䣺20220501
* �޸�����       �汾��        �޸���                   �޸�����
* ----------------------------------------------------------------------
* 20220501    V1.0.1        *****                      ������**����
*************************************************************************/
#pragma once
#include <qthread.h>
#include"vary.h"

class train_wave :
	public QThread
{

	Q_OBJECT
public:
	train_wave();
	~train_wave();
	
	QVector<QPointF> list;//���沨�����ݴ洢������
	QVector<QPointF> newlist;//���沨�����ݸ�������
	void run();
protected:
	
signals:
	///�������������ӽ��洫�䵱ǰ�ɼ����ݵ����ֵ
	///param [I]	AE�����е����ֵ
	///����ֵ�� ��
	///��ע����
	void train_signal(double pra);

private:


};

