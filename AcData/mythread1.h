/**********************************************************************
* Copyright (c) 2021,VISLAB
* All rights reserved.
* 文件名：mythread1.h
* 描述：AE信号本地TXT数据持久化保存
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


//写线程
class mythread1 :public QThread
{
	Q_OBJECT
public:
	mythread1();

	~mythread1();
	///功能描述：AE数据本地保存线程
	///param [I]	无
	///返回值： 无
	///备注：无
	void run();

public:
	QVector<QPointF> list;//界面波形存储数据
	QVector<QPointF> newlist;//数据更新容器

signals:
	///功能描述：向主界面传输当前线程的运行信息
	///param [I]	字符串提示信息
	///返回值： 无
	///备注：无
	void m1_signal(QString str);
	///功能描述：向主界面传输当前采集数据的最大值
	///param [I]	字符串提示信息
	///返回值： 无
	///备注：无
	void m3_signal(double pra);

private:
	

};

