#include "detect_status.h"
detect_status::detect_status() {

}
detect_status::~detect_status() {

}
void detect_status::run() {

	cout << "det�߳̿���" << endl;
	//����SVMѵ��ģ��
	cv::Ptr<SVM> svm;
	try
	{
		svm = SVM::load("./SVMModel.xml");
	}
	catch (exception e)
	{
		emit detect_info("δ�ҵ����ģ��");
		return;
	}

	float Volt = 0;
	LONG ADData;
	emit detect_info("���ģ�ͼ������");
	//�źŽ�ȡ��ر���
	//������
	float Samplefrequency = 1000000;
	int CollectionPoints = 1048576;
	//��������
	float signal_threhold = 0.3;

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
	//cout << "�����ļ��ɹ�����ʼд��" << endl;
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
			if (intercept==true&&store_size<=1000000) {
				Data_Tool.push_back(Volt);
				++store_size;
			}else if (store_size > 1000000) {//������Χ������ѭ���������ж�����
				begin_detect = true;
				intercept = false;
				store_size = 0;
				break;
			}
		}
		//�����ж����̣�����Ƿ�Ϊ�����׶Ρ�
		if (begin_detect) {
			RT_TCM_AE mv(Data_Tool, 121, 1000000, 0.15);
			if (det_time > 1) {
				//�ڻ����
				//����˳��:��ֵ������������ֵ���ӣ���ֵ�����������׾�ֵ��С����3��5��6
				vector<float>Feature{ time_value[0], time_value[1], time_value[2], FD, fft_energy, WPT_res[0], WPT_res[1], WPT_res[2] };

				int response = mv.use_model(Feature);
				//Mat sampleMat = (Mat_<float>(1, 8) << time_value[0], time_value[1], time_value[2], FD, fft_energy, WPT_res[0], WPT_res[1], WPT_res[2]);
				//float res = svm->predict(sampleMat);
				if (response == 2) {
					cout << "δ�ҵ����ģ��" << endl;
				}
				else if(response==3){
					cout << "��������ά������" << endl;
				}
				else if (response == 1) {
					//�����㲥
					emit detect_signals("����״̬�쳣��");
				}
			}
			//�������
			time_value.clear();
			WPT_res.clear();
			//�����ֵ
			
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
			//�жϽ�������ԭ����
			begin_detect = false;
		}
		
		

	}
}