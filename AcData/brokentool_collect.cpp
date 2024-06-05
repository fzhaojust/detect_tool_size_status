#include "brokentool_collect.h"
brokentool_collect::brokentool_collect() {

}
brokentool_collect::~brokentool_collect() {

}

void brokentool_collect::run() {
	fstream f;
	f.open(".\\dataset\\dataset_AE_breakage.txt", ios::app);//dataset_AE_breakage     dataset_AE_fresh
	if (!f.is_open()) {
		cout << "dataset_AE_breakage file open!" << endl;
		return;
	}

	float Volt = 0;
	LONG ADData;

	//�źŽ�ȡ��ر���
	//������
	float Samplefrequency = 1000000;
	int CollectionPoints = 1048576;
	//��������
	float signal_threhold = 0.3;
	float decision_threshold = 0.15;
	float FD = -1.0;
	int record = 0;
	vector<float>cpeak;
	vector<float>time_value;
	vector<float>WPT_res;
	float fft_energy = 0;
	int det_time = 0;
	float Judgement = 0.0;
	//����״̬�ж�����
	vector<float>Data_Tool;
	//�ж��Ƿ��ȡ
	bool intercept = false;
	bool begin_detect = false;
	int store_size = 0;
	cout << "���������ɼ��߳̿���" << endl;
	while (!is_stop) {
		unique_lock<mutex>readguard(mu1);

		my_con.wait(readguard);
		for (int Index = 0; Index < AD_DATA_LEN; Index++) // �ܹ���ʾ���AD��λ volt
		{
			ADData = (USHORT)((ADBuffer[currentindex][Index] ^ 0x8000) & 0xFFFF);
			Volt = (float)((20.0 / 65536) * ADData - 10.0);
			//�����ж��Ƿ���Ҫ��ȡ
			if (intercept == false && Volt > 0.6) {
				intercept = true;
				det_time = 0;
			}
			//��ȡ����
			if (intercept&&store_size <= 1000000) {
				Data_Tool.push_back(Volt);
				++store_size;
			}
			else if (store_size > 1000000) {//������Χ������ѭ���������ж�����
				begin_detect = true;
				intercept = false;
				store_size = 0;
				break;
			}
		}
		//�����ж����̣�����Ƿ�Ϊ�����׶Ρ�
		if (begin_detect) {
			RT_TCM_AE mv(Data_Tool, 121, 1000000, 0.15);
			if (det_time >1) {
				//�洢�µ���������
				//����˳��:��ֵ������������ֵ���ӣ���ֵ�����������׾�ֵ��С����3��5��6	
				f << time_value[0] << " " << time_value[1] << " " << time_value[2] << " " << FD << " "
					<< fft_energy << " " << WPT_res[0] << " " << WPT_res[1] << " " << WPT_res[2] << endl;
			}
			//�������
			time_value.clear();
			WPT_res.clear();
		
			//���ݾ�ֵ�ж��Ƿ�Ϊ�ӹ�����
			if (mv.stage_cutting() == true) {
				//��ȡʱ����������ֵ������������ֵ����
				mv.cal_Time();
				time_value = mv.getTime();
				//�����ֵ
				mv.cal_Peak();
				// ��ȡ��ֵ
				FD = mv.get_FD();
				//���㹦����������ֵ
				mv.cal_FFT();
				fft_energy = mv.get_FFT();
				//uacout << "������������ֵΪ" << fft_energy << endl;
				mv.cal_WPT();
				WPT_res = mv.get_WPT();
				//�����ȡ����
				++det_time;
				//�洢˳��    ��ֵ��rms����ֵ���ӣ���ֵ������С����������
			}

			//�ж���ɣ���ԭ����
			begin_detect = false;
		}
	}
	f.close();
	return;
}