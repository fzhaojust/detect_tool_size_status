/**********************************************************************
* Copyright (c) 2021,VISLAB
* All rights reserved.
* �ļ�����RT_TCM_AE.h
* ������������������ȡ��������ȡ����ֵ������������ֵ���ӡ���ֵ������������������ֵ��С����������
* �������ڣ�20220501
* �����ߣ��Է�
* ��ʼʱ�䣺20220401
* ���ʱ�䣺20220501
* �޸�����       �汾��        �޸���                   �޸�����
* ----------------------------------------------------------------------
* 20220501    V1.0.1        *****                      ������**����
*************************************************************************/
#pragma once
#include<iostream>
#include<queue>
#include<deque>
#include<math.h>



//С��������ͷ�ļ�
#include <cassert>
#include <algorithm>
#include <cstring>
#include <sstream>
#include "WaveletMath.h"
#include "WaveletPacketTree.h"
#include "StationaryWaveletPacketTree.h"
#include "WaveletPacketTreeBase.h"
using namespace panwave;

//SVM����ͷ�ļ�
#include <opencv2/ml.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/ml.hpp>
#include<fstream>
using namespace cv;
using namespace cv::ml;


using namespace panwave;
using namespace std;



class RT_TCM_AE
{
private://˽�б���
	//Բ����
	const float PI;
	//Ƶ��������ݴ���--��Ϊ2��
	int Frequency_length;
	//���ɿ�������
	int _Frequency;
	//�ж��Ƿ�ӹ��������ֵ�趨
	int _cut_threshold;
	//��ֵ�˲�����ѡ��
	int len = 0;
	//��ֵ�˲��洢����
	queue<float>que;
	//��ֵ�˲��洢ÿ�δ��ڵ�������
	float filter_sum = 0;
	//�洢ԭʼ����
	vector<float>raw_data;
	//�洢��ֵ�˲����
	vector<float>filter_res;
	//��ֵ����
	vector<float>peak_points;
	//�洢��ֵ�������
	float Fluctuation;
	//�洢ʱ������������ֵ������������ֵ����
	vector<float> time_value;
	//FFT�洢��ֵ����λ��Ϣ
	vector<float>xreal, ximag;
	//�洢������������ֵ
	float fft_energy;
	//�洢С������3 5 6 �ڵ�������Ƚ��
	vector<float> WPT_res;

public://���к���
	///�����������вι��캯��������������ȡ����ʱ��ʼ��
	///param [I]	Ae_data��AE�ź�����
	///param [I]	filter_size	ƽ���˲�����
	///param [I]	Frequency	���ɿ�������
	///param [I]	cut_threshold	�ж��ӹ��������ֵ����
	///����ֵ�� ��
	///��ע����
	RT_TCM_AE(vector<float>Ae_data, int filter_size, int Frequency, int cut_threshold);
	///�����������޲ι��캯����ѵ��SVMģ��ʱ��ʼ��
	///param [I]	��	
	///����ֵ�� ��
	///��ע����
	RT_TCM_AE();

	///������������������
	///param [I]	��
	///����ֵ�� ��
	///��ע����
	~RT_TCM_AE();
	///�����������ж�����������Ƿ�Ϊ�ӹ���������
	///param [I]	��
	///����ֵ�� trueΪ�ǣ�falseΪ��
	///��ע����
	bool stage_cutting();

	///������������ȡʱ���������
	///param [I]	��
	///����ֵ�� vector������vector[0]:��ֵ��vector[1]:��������vector[2]:��ֵ����
	///��ע����
	vector<float> getTime();
	
	///������������ȡ��ֵ�������
	///param [I]	��
	///����ֵ�� ��ֵ��������
	///��ע����
	float get_FD();

	///������������ȡƵ�������
	///param [I]	��
	///����ֵ�� ��ֵ��������
	///��ע����
	float get_FFT();

	///������������ȡС������3��5��6�ڵ�������Ƚ��
	///param [I]	��
	///����ֵ�� ��
	///��ע����
	vector<float> get_WPT();

	///��������������ʱ������������ֵ������������ֵ����
	///param [I]	��
	///����ֵ�� ��
	///��ע����
	void cal_Time();

	///���������������ֵ�������
	///param [I]	��
	///����ֵ�� ��
	///��ע����
	void cal_Peak();

	///�������������㹦����������ֵ
	///param [I]	��
	///����ֵ�� ��
	///��ע����
	void cal_FFT();

	///��������������С���������ȵ�3,5,6�ڵ������ֵ
	///param [I]	��
	///����ֵ�� ��
	///��ע����
	void cal_WPT();

	///����������ѵ��SVMģ��
	///param [I]	��
	///����ֵ�� 0 �ɹ���1 ��������Ϊ�գ�2 ��ȡtxt�ļ�ʧ��
	///��ע����
	int train_model();

	///����������ʹ��SVMģ��
	///param [I]	vector 8ά��������������˳��:��ֵ������������ֵ���ӣ���ֵ�����������׾�ֵ��С����3��5��6�ڵ�����������
	///����ֵ�� 0���µ� 1������ 2������
	///��ע����
	int use_model(vector<float>Feature);
	
private://˽�к���
	
	///������������ֵ�˲�����
	///param [I]	val��ƽ���˲�����
	///����ֵ�� ��
	///��ע����
	float next(float val);

	///������������ȡ�����еķ�ֵ��
	///param [I]	smooth_data���˲�������
	///����ֵ�� vector����ֵ��
	///��ע����
	vector<float> calculate_Peak(vector<float> smooth_data);
	
	///���������������ֵ�����̶�
	///param [I]	data���˲�������
	///param [I]	low_hold����ֵ����
	///param [I]	high_hold����ֵ����
	///����ֵ��  ��ֵ��������ֵ
	///��ע����
	float calcalate_FD(vector<float> data,float low_hold,float high_hold);
	
	///�������������ٸ���Ҷ�仯
	///param [I]	xreal�����ݱ任���ʵ������
	///param [I]	ximag�����ݱ任��ĸ�������
	///param [I]	n�����ɿ�������
	///����ֵ��  ��
	///��ע����
	void FFT(float xreal[], float ximag[], int n);
	
	///��������������λ�ý���
	///param [I]	a��һ������
	///param [I]	b��һ������
	///����ֵ��  ��
	///��ע����
	inline void swap(float &a, float &b);
	
	///����������λ��ת�û�
	///param [I]	xreal�����ݱ任���ʵ������
	///param [I]	ximag�����ݱ任��ĸ�������
	///param [I]	n�����ɿ�������
	///����ֵ��  ��
	///��ע����
	void bitrp(float xreal[], float ximag[], int n);
};

