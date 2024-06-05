/**********************************************************************
* Copyright (c) 2021,VISLAB
* All rights reserved.
* 文件名：detect_status.h
* 描述：崩刃监测线程
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

class detect_status:public QThread
{
	Q_OBJECT
public:
	detect_status();

	~detect_status();
	
	///功能描述：在机状态监测线程
	///param [I]	无
	///返回值：  无
	///备注：无
	void run();



signals:
	//刀具状态异常提示
	void detect_signals(QString str);
	
	//状态线程信息提示
	void detect_info(QString str);


};

