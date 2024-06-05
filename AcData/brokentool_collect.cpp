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

	//信号截取相关变量
	//采样率
	float Samplefrequency = 1000000;
	int CollectionPoints = 1048576;
	//参数设置
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
	//刀具状态判断容器
	vector<float>Data_Tool;
	//判断是否截取
	bool intercept = false;
	bool begin_detect = false;
	int store_size = 0;
	cout << "崩刃样本采集线程开启" << endl;
	while (!is_stop) {
		unique_lock<mutex>readguard(mu1);

		my_con.wait(readguard);
		for (int Index = 0; Index < AD_DATA_LEN; Index++) // 总共显示点的AD单位 volt
		{
			ADData = (USHORT)((ADBuffer[currentindex][Index] ^ 0x8000) & 0xFFFF);
			Volt = (float)((20.0 / 65536) * ADData - 10.0);
			//粗略判断是否需要截取
			if (intercept == false && Volt > 0.6) {
				intercept = true;
				det_time = 0;
			}
			//截取数据
			if (intercept&&store_size <= 1000000) {
				Data_Tool.push_back(Volt);
				++store_size;
			}
			else if (store_size > 1000000) {//超出范围，跳出循环，进入判定流程
				begin_detect = true;
				intercept = false;
				store_size = 0;
				break;
			}
		}
		//进入判断流程，监测是否为切削阶段。
		if (begin_detect) {
			RT_TCM_AE mv(Data_Tool, 121, 1000000, 0.15);
			if (det_time >1) {
				//存储新刀样本特征
				//输入顺序:均值，均方根，峰值因子，峰值波动，功率谱均值，小波包3，5，6	
				f << time_value[0] << " " << time_value[1] << " " << time_value[2] << " " << FD << " "
					<< fft_energy << " " << WPT_res[0] << " " << WPT_res[1] << " " << WPT_res[2] << endl;
			}
			//容器清空
			time_value.clear();
			WPT_res.clear();
		
			//根据均值判断是否为加工区域
			if (mv.stage_cutting() == true) {
				//获取时域特征：均值、均方根、峰值因子
				mv.cal_Time();
				time_value = mv.getTime();
				//计算峰值
				mv.cal_Peak();
				// 获取峰值
				FD = mv.get_FD();
				//计算功率谱能量均值
				mv.cal_FFT();
				fft_energy = mv.get_FFT();
				//uacout << "功率谱能量均值为" << fft_energy << endl;
				mv.cal_WPT();
				WPT_res = mv.get_WPT();
				//计算截取次数
				++det_time;
				//存储顺序    均值，rms，峰值因子，峰值波动，小波包能量比
			}

			//判断完成，还原变量
			begin_detect = false;
		}
	}
	f.close();
	return;
}