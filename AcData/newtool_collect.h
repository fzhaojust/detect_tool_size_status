/**********************************************************************
* Copyright (c) 2021,VISLAB
* All rights reserved.
* �ļ�����newtool_collect.h
* �������µ�������ȡ�߳�
* �������ڣ�20220501
* �����ߣ��Է�
* ��ʼʱ�䣺20220401
* ���ʱ�䣺20220501
* �޸�����       �汾��        �޸���                   �޸�����
* ----------------------------------------------------------------------
* 20220501    V1.0.1        *****                      ������**����
*************************************************************************/
#pragma once
#include<qthread.h>



#include"vary.h"

class newtool_collect:public QThread
{
	Q_OBJECT
public:
	newtool_collect();
	~newtool_collect();
	
	///�����������µ������ɼ��߳�
	///param [I]	��
	///����ֵ��  ��
	///��ע����
	void run();
signals:
	//void detect_signals(QString str);

};

