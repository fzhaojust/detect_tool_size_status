/**********************************************************************
* Copyright (c) 2021,VISLAB
* All rights reserved.
* 文件名：AcData.h
* 描述：QT主界面功能集成
* 创建日期：20220501
* 开发者：赵飞
                                                                                                                                                                         
* 开始时间：20220401
* 完成时间：20220501
* 修改日期       版本号        修改者                   修改内容
* ----------------------------------------------------------------------
* 20220501    V1.0.1        *****                      增加了**功能
*************************************************************************/
#pragma once

#include"vary.h"
#include"mythread1.h"
#include"mythread2.h"
#include"mythread3.h"
#include"history_data.h"
#include"detect_status.h"
#include"newtool_collect.h"
#include"brokentool_collect.h"

#include <QtWidgets/QMainWindow>
#include "ui_AcData.h"


class AcData : public QMainWindow
{
	
	Q_OBJECT

public:

	AcData(QWidget *parent = Q_NULLPTR);
	//初始化界面
	void init();


	///功能描述：基于界面label控件改变颜色
	///param [I]	label,label控件对象，
	///param [I]	color	所选颜色， 0:grey 1:red 2:green 3:yellow
	///param [I]	size	颜色尺寸直径
	///返回值： 无
	///备注：无
	void setLED(QLabel* label, int color, int size);
	//绘图变量和坐标
	QChart* chart;//界面波形对象
	QValueAxis *axisX;//x轴对象
	QValueAxis *axisYY;//y轴对象
	
	~AcData();

signals:

public slots:
	///功能描述：启动监测
	///param [I]	无
	///返回值： 无
	///备注：无
	void Read_data();
	///功能描述：停止监测
	///param [I]	无
	///返回值： 无
	///备注：无
	void push_stop();

	///功能描述：主界面输出字符串提示信息
	///param [I]	无
	///返回值： 无
	///备注：无
	void broadcast(QString str);
	///功能描述：打开子界面
	///param [I]	无
	///返回值： 无
	///备注：无
	void Open_Data();
	//
	///功能描述：返回主界面
	///param [I]	无
	///返回值： 无
	///备注：无
	void dealdata();
	//
	///功能描述：动态改变Y轴坐标显示长度
	///param [I]	无
	///返回值： 无
	///备注：无
	void paramer_change(double pra);
	///功能描述：崩刃提醒
	///param [I]	无
	///返回值： 无
	///备注：无
	void alarm_breakage(QString str);


private:

	Ui::AcDataClass ui;
	mythread1 *ThWrite;//写线程对象
	mythread2 *ThRead;//读线程对象
	mythread3 *ThWave;//显示线程
	detect_status *det_sta;//在机监测线程
	history_data hisdata;//子界面对象
};
