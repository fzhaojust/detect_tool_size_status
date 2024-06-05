/**********************************************************************
* Copyright (c) 2021,VISLAB
* All rights reserved.
* 文件名：mythread2.h
* 描述：数据采集卡参数预设，AE信号读取
* 创建日期：20220501
* 开发者：赵飞
* 开始时间：20220401
* 完成时间：20220501
* 修改日期       版本号        修改者                   修改内容
* ----------------------------------------------------------------------
* 20220501    V1.0.1        *****                      增加了**功能
*************************************************************************/
#pragma once
#include <qthread.h>
#include"vary.h"
//读线程
class mythread2 :
	public QThread
{
	Q_OBJECT

public:
	mythread2();

	~mythread2();
	///功能描述：数采卡数据读取线程
	///param [I]	无
	///返回值：  无
	///备注：无
	void run();

signals:
	void m2_signal(QString str);
	void m2_sig();

private:
	


};

