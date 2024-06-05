#include "mythread2.h"

mythread2::mythread2() {

}

mythread2::~mythread2() {

}

void mythread2::run() {
	HANDLE hDevice;
	int DeviceID;
	PCIE9758C_PARA_AD ADPara; // 硬件参数
	ULONG nReadSizeWords;   // 每次读取AD数据的长度(字)
	ULONG nRetSizeWords;
	ULONG nAvailSampsPoints;

	int nCurrentChannel = 0, nChannel = 0, Index = 0;
	

	float fVolt;

	DeviceID = 0;
	hDevice = PCIE9758C_CreateDevice(DeviceID); // 创建设备对象
	if (hDevice == INVALID_HANDLE_VALUE) {
		emit m2_signal("Device don't collecting\n");
		return; // 如果创建设备对象失败，则返回

	}
	/*
	"0. -10V    ～ +10V\n"
	"1. -5V     ～ +5V\n"
	"2. -2.5V   ～ +2.5V\n"
	"3. -1.25V  ～ +1.25V\n"
	*/
	int InputRange =0; // 要求用户从键盘上选择输入量程

	memset(&ADPara, 0x00, sizeof(ADPara)); // 初始化成已知量(强烈建议)

	// 预置硬件参数
	ADPara.bChannelArray[0] = TRUE; // 允许通道0采样
	ADPara.bChannelArray[1] = FALSE; // 允许通道1采样
	ADPara.bChannelArray[2] = FALSE; // 允许通道2采样
	ADPara.bChannelArray[3] = FALSE; // 允许通道3采样	
	ADPara.InputRange[0] = InputRange;  // 模拟通道0输入量程
	ADPara.InputRange[1] = InputRange;  // 模拟通道1输入量程
	ADPara.InputRange[2] = InputRange;  // 模拟通道2输入量程
	ADPara.InputRange[3] = InputRange;  // 模拟通道3输入量程
	//PCIE9758C_REFGND_DIFF
	ADPara.RefGround[0] = PCIE9758C_REFGND_DIFF;
	ADPara.RefGround[1] = PCIE9758C_REFGND_RSE;
	ADPara.RefGround[2] = PCIE9758C_REFGND_RSE;
	ADPara.RefGround[3] = PCIE9758C_REFGND_RSE;
	ADPara.Frequency = 1000; // 采样频率(Hz)
	ADPara.TriggerMode = PCIE9758C_TRIGMODE_SOFT;
	ADPara.TriggerSource = PCIE9758C_TRIGSRC_ATR; // 触发源
	ADPara.TriggerType = PCIE9758C_TRIGTYPE_EDGE; // 触发类型为边沿触发	
	ADPara.TriggerDir = PCIE9758C_TRIGDIR_NEGATIVE; // 触发方向为负
	ADPara.TrigLevelVolt = 0;
	ADPara.TrigWindow = 40;    // 触发灵敏度	
	ADPara.RefClkSrc = 0;
	ADPara.CnvClkSrc = 0;
	ADPara.bMasterEn = 0;


	ADPara.SyncTrigSrc = PCIE9758C_SYNCTRIGSRC_TRIGGER0;

	if (!PCIE9758C_InitDeviceAD(hDevice, &ADPara)) // 初始化硬件
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

	nReadSizeWords = AD_DATA_LEN - AD_DATA_LEN % ChannelCount; // 将数据长度字转换为双字	

	if (!PCIE9758C_StartDeviceAD(hDevice)) // 启动设备
	{
		printf("StartDeviceAD Error...\n");
		return;
	}






	//printf("数据正在采集，请等待，您可以按任意键退出，但请不要直接关闭窗口强制退出...\n");
	//printf("Data is being collected, please wait\n");
	emit m2_signal("Data is being collected, please wait\n");

	while (!is_stop) // kbhit()探测用户是否有按键动作,若有按键则退出
	{
		PCIE9758C_ReadDeviceAD(hDevice, ADBuffer[ReadIndex], nReadSizeWords, &nRetSizeWords, &nAvailSampsPoints, 1.0);
		currentindex = ReadIndex;
		my_con.notify_all();
		ReadIndex = (ReadIndex + 1) % MAX_SEGMENT;
		//cout << "A" << " ";

	}

	PCIE9758C_StopDeviceAD(hDevice);
	PCIE9758C_ReleaseDeviceAD(hDevice); // 释放AD
	PCIE9758C_ReleaseDevice(hDevice); // 释放设备对象



ExitRead0:

	//PCIE9554_ReleaseDeviceDmaAD(hDevice); // 释放AD
	//PCIE9554_ReleaseSystemEvent(hDmaEvent); // 释放DMA事件句柄
ExitRead1:
	//PCIE9554_ReleaseDevice(hDevice); // 释放设备对象


	return;


}

