/**********************************************************************
* Copyright (c) 2021,VISLAB
* All rights reserved.
* �ļ�����detect_status.h
* ���������м���߳�
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

class detect_status:public QThread
{
	Q_OBJECT
public:
	detect_status();

	~detect_status();
	
	///�����������ڻ�״̬����߳�
	///param [I]	��
	///����ֵ��  ��
	///��ע����
	void run();



signals:
	//����״̬�쳣��ʾ
	void detect_signals(QString str);
	
	//״̬�߳���Ϣ��ʾ
	void detect_info(QString str);


};

