#pragma once

#include<QtCharts>
QT_CHARTS_USE_NAMESPACE
using namespace QtCharts;
#pragma execution_character_set("utf-8")

//QT���ͷ�ļ�
#include<qchartview.h>//������ʾQcharts
#include<qchart.h>//ͼ�����,��������ͼ������,��ɫ,��С��
#include<qlineseries.h>//��������
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
//c++���ͷ�ļ�
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

//ע���ͷ�ļ��Ƿ��ɾ��
#include<Windows.h>
//
#include"RT_TCM_AE.h"



//���ɿ������ļ�
#pragma comment(lib,"PCIE9758C_64")
#pragma comment(lib,"PCIE9758C_32")
#include"resource.h"
#include"stdafx.h"
#include"PCIE9758C.h"


////SVM����ͷ�ļ�
//#include<opencv2/opencv.hpp>
//#include<opencv2/ml.hpp>
//using namespace cv;
//using namespace cv::ml;


using namespace std;


#define MAX_SEGMENT 32//����AD ���ݵĻ���������

#define AD_DATA_LEN 32768 // Ҫ��ȡ�ʹ����AD���ݳ��ȣ�����֣�32768


extern mutex mu1;
extern condition_variable my_con;//������������

extern mutex mu2;
extern condition_variable my_con2;//������������
extern WORD ADBuffer[MAX_SEGMENT][AD_DATA_LEN]; // ���仺����(�洢ԭʼ����)

extern bool falgs;

//�߳����
extern ULONG ReadIndex;
extern ULONG currentindex;
extern bool is_stop;
extern QSplineSeries* Qline;//������������߶�
	 
extern int maxsize;
extern int flag;



extern QLineSeries* train_line;//�����ɼ�����������߶�


//extern double min_threshold;


