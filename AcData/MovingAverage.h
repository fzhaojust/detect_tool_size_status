/**********************************************************************
* Copyright (c) 2021,VISLAB
* All rights reserved.
* �ļ�����MovingAverage.h
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

#include"vary.h"


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


class MovingAverage
{
private://˽�б���
	//Բ����
	const float PI;
	//Ƶ��������ݴ���--��Ϊ2��
	const int Frequency_length;
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
	///�����������вι��캯��
	///param [I]	Ae_data��AE�ź�����
	///param [I]	size	ƽ���˲�����
	///����ֵ�� ��
	///��ע����
	MovingAverage(vector<float>Ae_data, int size);

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
	//
	///���������������ֵ�����̶�
	///param [I]	data���˲�������
	///param [I]	low_hold����ֵ����
	///param [I]	high_hold����ֵ����
	///����ֵ��  ��ֵ��������ֵ
	///��ע����
	float calcalate_FD(vector<float> data,float low_hold,float high_hold);
	//FFT�任
	///�������������ٸ���Ҷ�仯
	///param [I]	xreal�����ݱ任���ʵ������
	///param [I]	ximag�����ݱ任��ĸ�������
	///param [I]	n�����ɿ�������
	///����ֵ��  ��
	///��ע����
	void FFT(float xreal[], float ximag[], int n);
	//�����׷���������ú���
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

