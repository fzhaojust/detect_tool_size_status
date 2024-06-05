#pragma once

#include<QtCharts>
QT_CHARTS_USE_NAMESPACE
using namespace QtCharts;
#pragma execution_character_set("utf-8")

//QT相关头文件
#include<qchartview.h>//负责显示Qcharts
#include<qchart.h>//图表界面,用来管理图表内容,颜色,大小等
#include<qlineseries.h>//折线数据
#include<qsplineseries.h>
#include<qvalueaxis.h>
#include<qtimer.h>
#include<qmath.h>
#include<qgraphicsview.h>
#include<qmessagebox.h>

#include<qpoint.h>
#include<qlist.h>
#include<qtimer.h>

#include<qtextbrowser.h>
#include<qstring.h>
#include<qmessagebox.h>
//c++相关头文件
//#include<Windows.h>
#include<iostream>
#include<string>
#include<fstream>
#include<thread>
#include<mutex>
#include<QDebug>
#include<qfile.h>
#include<qfiledialog.h>
#include<qstring.h>
#include<sstream>
#include<chrono>
#include<time.h>
#include<functional>
#include<algorithm>
#include<vector>

//注意此头文件是否可删除
#include<Windows.h>
//
#include"RT_TCM_AE.h"



//数采卡依赖文件
#pragma comment(lib,"PCIE9758C_64")
#pragma comment(lib,"PCIE9758C_32")
#include"resource.h"
#include"stdafx.h"
#include"PCIE9758C.h"


////SVM所需头文件
//#include<opencv2/opencv.hpp>
//#include<opencv2/ml.hpp>
//using namespace cv;
//using namespace cv::ml;


using namespace std;


#define MAX_SEGMENT 32//接收AD 数据的缓冲区个数

#define AD_DATA_LEN 32768 // 要读取和处理的AD数据长度（点或字）32768


extern mutex mu1;
extern condition_variable my_con;//生成条件对象

extern mutex mu2;
extern condition_variable my_con2;//生成条件对象
extern WORD ADBuffer[MAX_SEGMENT][AD_DATA_LEN]; // 分配缓冲区(存储原始数据)

extern bool falgs;

//线程相关
extern ULONG ReadIndex;
extern ULONG currentindex;
extern bool is_stop;
extern QSplineSeries* Qline;//主界面的数据线段
	 
extern int maxsize;
extern int flag;



extern QLineSeries* train_line;//样本采集界面的数据线段


//extern double min_threshold;


