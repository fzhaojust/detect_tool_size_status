#include "mythread2.h"

mythread2::mythread2() {

}

mythread2::~mythread2() {

}

void mythread2::run() {
	HANDLE hDevice;
	int DeviceID;
	PCIE9758C_PARA_AD ADPara; // Ӳ������
	ULONG nReadSizeWords;   // ÿ�ζ�ȡAD���ݵĳ���(��)
	ULONG nRetSizeWords;
	ULONG nAvailSampsPoints;

	int nCurrentChannel = 0, nChannel = 0, Index = 0;
	

	float fVolt;

	DeviceID = 0;
	hDevice = PCIE9758C_CreateDevice(DeviceID); // �����豸����
	if (hDevice == INVALID_HANDLE_VALUE) {
		emit m2_signal("Device don't collecting\n");
		return; // ��������豸����ʧ�ܣ��򷵻�

	}
	/*
	"0. -10V    �� +10V\n"
	"1. -5V     �� +5V\n"
	"2. -2.5V   �� +2.5V\n"
	"3. -1.25V  �� +1.25V\n"
	*/
	int InputRange =0; // Ҫ���û��Ӽ�����ѡ����������

	memset(&ADPara, 0x00, sizeof(ADPara)); // ��ʼ������֪��(ǿ�ҽ���)

	// Ԥ��Ӳ������
	ADPara.bChannelArray[0] = TRUE; // ����ͨ��0����
	ADPara.bChannelArray[1] = FALSE; // ����ͨ��1����
	ADPara.bChannelArray[2] = FALSE; // ����ͨ��2����
	ADPara.bChannelArray[3] = FALSE; // ����ͨ��3����	
	ADPara.InputRange[0] = InputRange;  // ģ��ͨ��0��������
	ADPara.InputRange[1] = InputRange;  // ģ��ͨ��1��������
	ADPara.InputRange[2] = InputRange;  // ģ��ͨ��2��������
	ADPara.InputRange[3] = InputRange;  // ģ��ͨ��3��������
	//PCIE9758C_REFGND_DIFF
	ADPara.RefGround[0] = PCIE9758C_REFGND_DIFF;
	ADPara.RefGround[1] = PCIE9758C_REFGND_RSE;
	ADPara.RefGround[2] = PCIE9758C_REFGND_RSE;
	ADPara.RefGround[3] = PCIE9758C_REFGND_RSE;
	ADPara.Frequency = 1000; // ����Ƶ��(Hz)
	ADPara.TriggerMode = PCIE9758C_TRIGMODE_SOFT;
	ADPara.TriggerSource = PCIE9758C_TRIGSRC_ATR; // ����Դ
	ADPara.TriggerType = PCIE9758C_TRIGTYPE_EDGE; // ��������Ϊ���ش���	
	ADPara.TriggerDir = PCIE9758C_TRIGDIR_NEGATIVE; // ��������Ϊ��
	ADPara.TrigLevelVolt = 0;
	ADPara.TrigWindow = 40;    // ����������	
	ADPara.RefClkSrc = 0;
	ADPara.CnvClkSrc = 0;
	ADPara.bMasterEn = 0;


	ADPara.SyncTrigSrc = PCIE9758C_SYNCTRIGSRC_TRIGGER0;

	if (!PCIE9758C_InitDeviceAD(hDevice, &ADPara)) // ��ʼ��Ӳ��
	{
		printf("PCIE9758C_InitDeviceProAD...\n");
		
		return ;
	}

	int ChannelCount = 0;
	for (nChannel = 0; nChannel < 4; nChannel++)
	{
		if (ADPara.bChannelArray[nChannel] == TRUE)
		{
			ChannelCount++;
		}
	}
	//cout << "ChannelCount" << ChannelCount << endl;

	nReadSizeWords = AD_DATA_LEN - AD_DATA_LEN % ChannelCount; // �����ݳ�����ת��Ϊ˫��	

	if (!PCIE9758C_StartDeviceAD(hDevice)) // �����豸
	{
		printf("StartDeviceAD Error...\n");
		return;
	}






	//printf("�������ڲɼ�����ȴ��������԰�������˳������벻Ҫֱ�ӹرմ���ǿ���˳�...\n");
	//printf("Data is being collected, please wait\n");
	emit m2_signal("Data is being collected, please wait\n");

	while (!is_stop) // kbhit()̽���û��Ƿ��а�������,���а������˳�
	{
		PCIE9758C_ReadDeviceAD(hDevice, ADBuffer[ReadIndex], nReadSizeWords, &nRetSizeWords, &nAvailSampsPoints, 1.0);
		currentindex = ReadIndex;
		my_con.notify_all();
		ReadIndex = (ReadIndex + 1) % MAX_SEGMENT;
		//cout << "A" << " ";

	}

	PCIE9758C_StopDeviceAD(hDevice);
	PCIE9758C_ReleaseDeviceAD(hDevice); // �ͷ�AD
	PCIE9758C_ReleaseDevice(hDevice); // �ͷ��豸����



ExitRead0:

	//PCIE9554_ReleaseDeviceDmaAD(hDevice); // �ͷ�AD
	//PCIE9554_ReleaseSystemEvent(hDmaEvent); // �ͷ�DMA�¼����
ExitRead1:
	//PCIE9554_ReleaseDevice(hDevice); // �ͷ��豸����


	return;


}

