/**********************************************************************
* Copyright (c) 2021,VISLAB
* All rights reserved.
* 文件名：mythread3.h
* 描述：QT主界面波形动态显示线程
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
//显示线程

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
	///功能描述：波形显示线程
	///param [I]	无
	///返回值：  无
	///备注：无
	void run();
signals:
	///功能描述：向主界面传输当前采集数据的最大值
	///param [I]	AE数据中的最大值
	///返回值： 无
	///备注：无
	void m3_signal(double pra);

private:
	

};

