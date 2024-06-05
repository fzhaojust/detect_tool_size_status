#include "mythread3.h"

mythread3::mythread3() {


}

mythread3::~mythread3() {

}
void mythread3::run() {
	while (!is_stop) {
		unique_lock<mutex>readguard(mu1);
		
			my_con.wait(readguard);
		
			//cout << "W1>";
		//printf("波形显示线程\n");
		
		list = Qline->pointsVector();//获取现在图中列表
		float max_y = 0;
		for (int i = AD_DATA_LEN; i < list.size(); i++)
		{
			if (list.at(i).y() > max_y)max_y = list.at(i).y();
			newlist.append(QPointF(i - AD_DATA_LEN, list.at(i).y()));
			
		}
		LONG ADData;
		float Volt = 0;
		for (int Index = 0; Index < AD_DATA_LEN; Index++) // 总共显示点的AD单位 volt
		{
		
			   //if (Volt > 0.15)
			//if (Volt > max_y)max_y = Volt;
			//ADData = (WORD)ADBuffer[g_ulSegmentID][Index] & 0x3FFF;
			//fVolt = (float)((10000.0 / 16384) * ADData - 5000.0);
			ADData = (USHORT)((ADBuffer[currentindex][Index]^0x8000) & 0xFFFF);
			Volt= (float)((20.0 / 65536) * ADData-10.0);
			if (Volt > max_y)max_y = Volt;
			//Volt = (float)((20.0 / 65536) * ((USHORT)((ADBuffer[currentindex][Index] ^ 0x8000) & 0xFFFF)) - 10000.0);;  // 将AD数据转换为电压值
			newlist.append(QPointF(newlist.size(), Volt));
		}
		//axisYY->setRange(-1, max_y);
		
	/*	for_each(newlist.begin(), newlist.end(), [&max_y](QPointF v) {
			if (v.y() > max_y)max_y = v.y();
		});*/

		//max_y = (int)max_y + 0.5;
		//emit m3_signal(max_y+1);
		//保留小数点后一位
		max_y = (int)(10.0 * max_y + 0.5) / 10.0+0.3;
		emit m3_signal(max_y);

		Qline->replace(newlist);//替换更新
		list.clear();
		newlist.clear();
		//清空内存
		list.swap(QVector<QPointF>());
		newlist.swap(QVector<QPointF>());
		
		//cout << "W2>";


	}
		
		
	
	
}