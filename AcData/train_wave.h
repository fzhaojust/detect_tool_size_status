/**********************************************************************
* Copyright (c) 2021,VISLAB
* All rights reserved.
* 文件名：train_wave.h
* 描述：QT子界面波形动态显示线程
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

class train_wave :
	public QThread
{

	Q_OBJECT
public:
	train_wave();
	~train_wave();
	
	QVector<QPointF> list;//界面波形数据存储旧容器
	QVector<QPointF> newlist;//界面波形数据更新容器
	void run();
protected:
	
signals:
	///功能描述：向子界面传输当前采集数据的最大值
	///param [I]	AE数据中的最大值
	///返回值： 无
	///备注：无
	void train_signal(double pra);

private:


};

