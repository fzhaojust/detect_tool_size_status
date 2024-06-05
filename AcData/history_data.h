/**********************************************************************
* Copyright (c) 2021,VISLAB
* All rights reserved.
* 文件名：history_data.h
* 描述：QT子界面功能集成
* 创建日期：20220501
* 开发者：赵飞
* 开始时间：20220401
* 完成时间：20220501
* 修改日期       版本号        修改者                   修改内容
* ----------------------------------------------------------------------
* 20220501    V1.0.1        *****                      增加了**功能
*************************************************************************/
#pragma once

#include <QWidget>
#include "ui_history_data.h"
#include    "qwchartview.h"

#include    <QtCharts>  //必须这么设置
QT_CHARTS_USE_NAMESPACE     //必须这么设置
#include    <QLabel>
#include"vary.h"
#include"mythread2.h"
#include"train_wave.h"
#include"newtool_collect.h"
#include"brokentool_collect.h"




class history_data : public QWidget
{
	Q_OBJECT

public:
	history_data(QWidget *parent = Q_NULLPTR);
	~history_data();
signals://信号必须有signals关键字声明

	///功能描述：返回主界面发出的信号
	///param [I]	无
	///返回值： 无
	///备注：无
	void Exit_data();

public slots:
	///功能描述：返回主界面
	///param [I]	无
	///返回值： 无
	///备注：无
	void Exit_interface();
	///功能描述：向子界面发送提示信息
	///param [I]	字符串提示信息
	///返回值： 无
	///备注：无
	void broadcast(QString str);

	///功能描述：启动选中的单选框特征采集线程
	///param [I]	无
	///返回值： 无
	///备注：无
	void    prepareData();  
	//
	///功能描述：停止特征采集
	///param [I]	无
	///返回值： 无
	///备注：无
	void    stop_collect();
	///功能描述：动态改变Y轴坐标长度
	///param [I]	当前数据的最大值
	///返回值： 无
	///备注：无
	void parameter_change(double pra);
	
	///功能描述：清空新刀样本文件
	///param [I]	无
	///返回值： 无
	///备注：无
	void clean_newdata();

	///功能描述：清空崩刃样本文件
	///param [I]	无
	///返回值： 无
	///备注：无
	void clean_brokendata();
	
	///功能描述：训练SVM模型并保存
	///param [I]	无
	///返回值： 无
	///备注：无
	void train_data();

private:
	Ui::history_data ui;
	
	///功能描述：初始化图表界面
	///param [I]	无
	///返回值： 无
	///备注：无
	void createChart(); //创建图表


private:
	//绘图变量和坐标
	QChart* chart;//波形对象
	QValueAxis *axisX;//横坐标对象
	QValueAxis *axisY;//纵坐标对象
	//QValueAxis *axisY;

	mythread2 *ThRead;//读线程对象
	train_wave *ThWave;//显示线程
	//写线程
	newtool_collect *Nc;//新刀数据采集
	brokentool_collect *Bc;//崩刃数据采集

};
