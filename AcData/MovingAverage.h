/**********************************************************************
* Copyright (c) 2021,VISLAB
* All rights reserved.
* 文件名：MovingAverage.h
* 描述：崩刃特征类提取，特征提取：均值、均方根、峰值因子、峰值波动、功率谱能量均值、小波包能量比
* 创建日期：20220501
* 开发者：赵飞
* 开始时间：20220401
* 完成时间：20220501
* 修改日期       版本号        修改者                   修改内容
* ----------------------------------------------------------------------
* 20220501    V1.0.1        *****                      增加了**功能
*************************************************************************/
#pragma once
#include<iostream>
#include<queue>
#include<deque>

#include"vary.h"


//小波包所需头文件
#include <cassert>
#include <algorithm>
#include <cstring>
#include <sstream>
#include "WaveletMath.h"
#include "WaveletPacketTree.h"
#include "StationaryWaveletPacketTree.h"
#include "WaveletPacketTreeBase.h"



using namespace panwave;


class MovingAverage
{
private://私有变量
	//圆周率
	const float PI;
	//频域处理的数据窗长--需为2的
	const int Frequency_length;
	//均值滤波窗长选择
	int len = 0;
	//均值滤波存储数据
	queue<float>que;
	//均值滤波存储每段窗口的总数据
	float filter_sum = 0;
	//存储原始数据
	vector<float>raw_data;
	//存储均值滤波结果
	vector<float>filter_res;
	//峰值数据
	vector<float>peak_points;
	//存储峰值波动结果
	float Fluctuation;
	//存储时域特征量：均值、均方根、峰值因子
	vector<float> time_value;
	//FFT存储幅值、相位信息
	vector<float>xreal, ximag;
	//存储功率谱能量均值
	float fft_energy;
	//存储小波包的3 5 6 节点的能量比结果
	vector<float> WPT_res;

public://公有函数
	///功能描述：有参构造函数
	///param [I]	Ae_data，AE信号容器
	///param [I]	size	平滑滤波长度
	///返回值： 无
	///备注：无
	MovingAverage(vector<float>Ae_data, int size);

	///功能描述：判断输入的数据是否为加工区域区域
	///param [I]	无
	///返回值： true为是，false为否
	///备注：无
	bool stage_cutting();

	///功能描述：获取时域计算特征
	///param [I]	无
	///返回值： vector容器，vector[0]:均值，vector[1]:均方根，vector[2]:峰值因子
	///备注：无
	vector<float> getTime();
	
	///功能描述：获取峰值波动结果
	///param [I]	无
	///返回值： 峰值波动特征
	///备注：无
	float get_FD();

	///功能描述：获取频域计算结果
	///param [I]	无
	///返回值： 峰值波动特征
	///备注：无
	float get_FFT();

	///功能描述：获取小波包第3、5、6节点的能量比结果
	///param [I]	无
	///返回值： 无
	///备注：无
	vector<float> get_WPT();

	///功能描述：计算时域特征量：均值、均方根、峰值因子
	///param [I]	无
	///返回值： 无
	///备注：无
	void cal_Time();

	///功能描述：计算峰值波动结果
	///param [I]	无
	///返回值： 无
	///备注：无
	void cal_Peak();

	///功能描述：计算功率谱能量均值
	///param [I]	无
	///返回值： 无
	///备注：无
	void cal_FFT();

	///功能描述：计算小波包能量比第3,5,6节点的能量值
	///param [I]	无
	///返回值： 无
	///备注：无
	void cal_WPT();
	
private://私有函数
	
	///功能描述：均值滤波计算
	///param [I]	val，平滑滤波长度
	///返回值： 无
	///备注：无
	float next(float val);

	///功能描述：提取数据中的峰值点
	///param [I]	smooth_data，滤波后数据
	///返回值： vector，峰值点
	///备注：无
	vector<float> calculate_Peak(vector<float> smooth_data);
	//
	///功能描述：计算峰值波动程度
	///param [I]	data，滤波后数据
	///param [I]	low_hold，阈值下限
	///param [I]	high_hold，阈值上限
	///返回值：  峰值波动特征值
	///备注：无
	float calcalate_FD(vector<float> data,float low_hold,float high_hold);
	//FFT变换
	///功能描述：快速傅里叶变化
	///param [I]	xreal，数据变换后的实数集合
	///param [I]	ximag，数据变换后的复数集合
	///param [I]	n，数采卡采样率
	///返回值：  无
	///备注：无
	void FFT(float xreal[], float ximag[], int n);
	//功率谱分析相关内置函数
	///功能描述：两数位置交换
	///param [I]	a，一点数据
	///param [I]	b，一点数据
	///返回值：  无
	///备注：无
	inline void swap(float &a, float &b);
	
	///功能描述：位反转置换
	///param [I]	xreal，数据变换后的实数集合
	///param [I]	ximag，数据变换后的复数集合
	///param [I]	n，数采卡采样率
	///返回值：  无
	///备注：无
	void bitrp(float xreal[], float ximag[], int n);
};

