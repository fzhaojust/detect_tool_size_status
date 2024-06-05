#include "mythread1.h"

mythread1::mythread1() {

}

mythread1::~mythread1() {

}
void mythread1::run()
{
	//创建日志，保存当前数据
	string str_log;
	SYSTEMTIME sys;

	GetLocalTime(&sys);
	//printf("%4d/%02d/%02d %02d:%02d:%02d.%03d 星期%1d\n", sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute, sys.wSecond, sys.wMilliseconds, sys.wDayOfWeek);
	
	char ch_temp[32];
	sprintf_s(ch_temp, "%4d_%02d_%02d_%02d_%02d_%02d", sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute, sys.wSecond);
	string str_temp = ch_temp;
	QString str = ch_temp;
	emit m1_signal(str+"\n");
	str_log = "rms_" + str_temp + ".txt";


	fstream log;
	log.open(str_log, ios::app);
	//float Volt = 0;
	LONG ADData;
	WORD value;
	float Volt;
	//vector<float>data;
	
	//emit m1_signal("Creat file success\n");
	//cout << "创建文件成功，开始写入" << endl;

	vector<WORD>data;
	//vector<float>data;
	while (!is_stop) {
		unique_lock<mutex>readguard(mu1);
	
			my_con.wait(readguard);

			//cout <<"S1>";
		//log << num << endl;
		
		//cout << "2";


				for (int Index = 0; Index < AD_DATA_LEN; Index++)
				{

					//方式二：存取word类型
					// 将原码高2位屏蔽掉
					
					//value = ADBuffer[currentindex][Index];
					//cout << value << " ";
					//data.push_back(value);
					//log << to_string(value) << " ";



					//方式一  存取float类型
					ADData = (USHORT)((ADBuffer[currentindex][Index] ^ 0x8000) & 0xFFFF);
					Volt = (float)((20.0 / 65536) * ADData - 10.0);
					//data.push_back(Volt);	
					log << to_string(value) << endl;

				}
				
				//cout << "S2>";


	}
	
	//int length = data.size();

	//*cout << "采集点数为" << length << endl;*/
	//auto start = std::chrono::steady_clock::now();
	//

	//for (int i = 0; i < length; ++i) {
	//	//log << to_string(data[i]) << " ";
	//	//log << data[i] << " ";
	//	
	//	log << to_string(data[i])<< " ";
	//}

	//auto end = std::chrono::steady_clock::now();
	//std::chrono::duration<double, std::micro> elapsed = end - start; // std::micro 表示以微秒为时间单位
	//double tt = elapsed.count() / 1000000;
	////std::cout << "time: " << elapsed.count() / 1000000 << "s" << std::endl;
	//
	//QString voice = "time consuming" + QString::number(tt,'f',3)+"S,file save success\n";
	//emit m1_signal(voice);


	log.close();
	return;
}