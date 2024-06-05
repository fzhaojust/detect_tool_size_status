/**********************************************************************
* Copyright (c) 2021,VISLAB
* All rights reserved.
* 文件名：newtool_collect.h
* 描述：新刀特征提取线程
* 创建日期：20220501
* 开发者：赵飞
* 开始时间：20220401
* 完成时间：20220501
* 修改日期       版本号        修改者                   修改内容
* ----------------------------------------------------------------------
* 20220501    V1.0.1        *****                      增加了**功能
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
	
	///功能描述：新刀特征采集线程
	///param [I]	无
	///返回值：  无
	///备注：无
	void run();
signals:
	//void detect_signals(QString str);

};

