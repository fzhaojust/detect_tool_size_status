/**********************************************************************
* Copyright (c) 2021,VISLAB
* All rights reserved.
* �ļ�����mythread3.h
* ������QT�����沨�ζ�̬��ʾ�߳�
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
//��ʾ�߳�

class mythread3 :
	public QThread
{
	Q_OBJECT
public:
	mythread3();

	~mythread3();
	QVector<QPointF> list;
	QVector<QPointF> newlist;
protected:
	///����������������ʾ�߳�
	///param [I]	��
	///����ֵ��  ��
	///��ע����
	void run();
signals:
	///�����������������洫�䵱ǰ�ɼ����ݵ����ֵ
	///param [I]	AE�����е����ֵ
	///����ֵ�� ��
	///��ע����
	void m3_signal(double pra);

private:
	

};

