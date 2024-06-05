#ifndef _PCIE9758C_DEVICE_
#define _PCIE9758C_DEVICE_

#define PCIE9758C_AD_MAX_CHANNELS		4	// 本卡最多支持4路模拟量输入通道
//#################### AD硬件参数PCIE9758C_PARA_AD定义 #####################
// 用于AD采样的实际硬件参数
typedef struct _PCIE9758C_PARA_AD     
{
	LONG bChannelArray[4];	// 采样通道选择阵列，分别控制4个通道，=1表示该通道采样，=0不采样
	LONG InputRange[4];		// 模拟量输入量程选择阵列，分别控制4个通道
	LONG RefGround[4];		// 地参考方式
	LONG Frequency;         // 采集频率, 单位为Hz, 最高采样率5MHz
	LONG TriggerMode;		// 触发模式选择
	LONG TriggerType;		// 触发类型选择
	LONG TriggerDir;		// 触发方向选择(正向/负向触发)
	LONG TriggerSource;		// 触发源选择
	LONG TrigLevelVolt;		// 触发电平(量程-10V~10V)
	LONG TrigWindow;		// 触发灵敏窗, 单位25纳秒
	LONG RefClkSrc;			// 参考时钟源选择
	LONG CnvClkSrc;			// 转换时钟源选择
	LONG bClockOutput;		// 允许转换时钟输出CLKOUT, =TRUE:允许输出, =FALSE:禁止输出
	LONG SyncTrigSrc;		// 同步触发源选择
	LONG bMasterEn;			// 主设备使能  
							// =0：从设备，通过Trigger信号接收主设备发送的同步触发信号
							// =1：主设备，通过Trigger信号为从设备发送自身的触发信号
							// 注：在多模块同步系统中，只能设定其中一个设备为主设备，其余需设定为从设备，如果系统中只有一个设备或者有多个设备但是不要求同步，需将所有设备设定为从设备
} PCIE9758C_PARA_AD, *PPCIE9758C_PARA_AD;

//***********************************************************
// AD参数PCIE9758C_PARA_AD中的InputRange[X]使用的硬件增益选项
const long PCIE9758C_INPUT_N10000_P10000mV			= 0x00; // ±10000mV
const long PCIE9758C_INPUT_N5000_P5000mV			= 0x01; // ±5000mV
const long PCIE9758C_INPUT_N2500_P2500mV			= 0x02; // ±2500mV
const long PCIE9758C_INPUT_N1250_P1250mV			= 0x03; // ±1250mV

//***********************************************************
// AD硬件参数PCIE9758C_PARA_AD中的RefGround触发模式所使用的选项
const long PCIE9758C_REFGND_RSE						= 0x00; // 单端
const long PCIE9758C_REFGND_DIFF					= 0x01; // 差分

//***********************************************************
// AD硬件参数PCIE9758C_PARA_AD中的TriggerMode触发模式所使用的选项
const long PCIE9758C_TRIGMODE_SOFT					= 0x00; // 软件触发
const long PCIE9758C_TRIGMODE_POST					= 0x01; // 硬件触发

// AD硬件参数PCIE9758C_PARA_AD中的TriggerType触发类型所使用的选项
const long PCIE9758C_TRIGTYPE_EDGE					= 0x00; // 边沿触发
const long PCIE9758C_TRIGTYPE_PULSE					= 0x01; // 脉冲触发(电平)

//***********************************************************
// AD硬件参数PCIE9758C_PARA_AD中的TriggerDir触发方向所使用的选项
const long PCIE9758C_TRIGDIR_NEGATIVE				= 0x00; // 负向触发(低脉冲/下降沿触发)
const long PCIE9758C_TRIGDIR_POSITIVE				= 0x01; // 正向触发(高脉冲/上升沿触发)
const long PCIE9758C_TRIGDIR_POSIT_NEGAT			= 0x02; // 正负向触发(高/低脉冲或上升/下降沿触发)

//***********************************************************
// AD硬件参数PCIE9758C_PARA_AD中的TriggerSource触发源信号所使用的选项
const long PCIE9758C_TRIGSRC_DTR					= 0x00; // 选择DTR作为触发源
const long PCIE9758C_TRIGSRC_ATR					= 0x01; // 选择ATR作为触发源
const long PCIE9758C_TRIGSRC_TRIG					= 0x02; // Trigger信号触发（用于多卡同步）

//***********************************************************
// AD硬件参数PCIE9758C_PARA_AD中的RefClkSrc参考时钟源所使用的选项
const long PCIE9758C_REFCLKSRC_IN					= 0x00; // 使用内部参考时钟
const long PCIE9758C_REFCLKSRC_10M					= 0x01; // 使用主卡10M时钟

//***********************************************************
// AD硬件参数PCIE9758C_PARA_AD中的CnvClkSrc转换时钟源所使用的选项
const long PCIE9758C_CNVCLKSRC_IN					= 0x00; // 使用内部转换时钟
const long PCIE9758C_CNVCLKSRC_EXT					= 0x01; // 使用外部转换时钟,由EXT_CLK管脚输入

//***********************************************************
// AD硬件参数PCIE9758C_PARA_AD中的SyncTrigSrc同步触发源所使用的选项
const long PCIE9758C_SYNCTRIGSRC_TRIGGER0					= 0x00; // 选择同步TRIG0信号触发
const long PCIE9758C_SYNCTRIGSRC_TRIGGER1					= 0x01; // 选择同步TRIG1信号触发
const long PCIE9758C_SYNCTRIGSRC_TRIGGER2					= 0x02; // 选择同步TRIG2信号触发
const long PCIE9758C_SYNCTRIGSRC_TRIGGER3					= 0x03; // 选择同步TRIG3信号触发
const long PCIE9758C_SYNCTRIGSRC_TRIGGER4					= 0x04; // 选择同步TRIG4信号触发
const long PCIE9758C_SYNCTRIGSRC_TRIGGER5					= 0x05; // 选择同步TRIG5信号触发
const long PCIE9758C_SYNCTRIGSRC_TRIGGER6					= 0x06; // 选择同步TRIG6信号触发
const long PCIE9758C_SYNCTRIGSRC_TRIGGER7					= 0x07; // 选择同步TRIG7信号触发


//*************************************************************************************
// 用于AD采样的实际硬件参数
typedef struct _PCIE9758C_STATUS_AD     
{
	LONG bNotEmpty;			// 板载FIFO存储器的非空标志，=TRUE非空， = FALSE 空
	LONG bHalf;				// 板载FIFO存储器的半满标志，=TRUE半满以上， = FALSE 半满以下
	LONG bDynamic_Overflow; // 板载FIFO存储器的动态溢出标志，= TRUE已发生溢出， = FALSE　未发生溢出
	LONG bStatic_Overflow;  // 板载FIFO存储器的静态溢出标志，= TRUE已发生溢出， = FALSE　未发生溢出
} PCIE9758C_STATUS_AD, *PPCIE9758C_STATUS_AD;

//***********************************************************
// 用户函数接口
#ifndef _PCIE9758C_DRIVER_
#define DEVAPI __declspec(dllimport)
#else
#define DEVAPI __declspec(dllexport)
#endif

#ifdef __cplusplus
extern "C" {
#endif
	//######################## 设备对象管理函数 ##############################
	HANDLE DEVAPI FAR PASCAL PCIE9758C_CreateDevice(int DeviceLgcID = 0);     // 用逻辑号创建设备对象
	int DEVAPI FAR PASCAL PCIE9758C_GetDeviceCount(HANDLE hDevice); // 取得设备总台数
	BOOL DEVAPI FAR PASCAL PCIE9758C_GetDeviceCurrentID(HANDLE hDevice,		// 取得当前设备相应的ID号
													PLONG DeviceLgcID, 
													PLONG DevicePhysID);
	BOOL DEVAPI FAR PASCAL PCIE9758C_ListDeviceDlg(HANDLE hDevice); // 以对话框窗体方式列表系统当中的所有的该PCI设备
    BOOL DEVAPI FAR PASCAL PCIE9758C_ReleaseDevice(HANDLE hDevice); // 仅释放设备对象

	//####################### AD数据读取函数 #################################
	// 适于大多数普通用户，这些接口最简单、最快捷、最可靠，让用户不必知道设备
	// 低层复杂的硬件控制协议和繁多的软件控制编程，仅用下面的初始化设备和读取
	// AD数据两个函数便能轻松高效地实现高速、连续的数据采集

	//####################### AD数据读取函数 #################################
	// 适于大多数普通用户，这些接口最简单、最快捷、最可靠，让用户不必知道设备
	// 低层复杂的硬件控制协议和繁多的软件控制编程，仅用下面的初始化设备和读取
	// AD数据两个函数便能轻松高效地实现高速、连续的数据采集
	BOOL DEVAPI FAR PASCAL PCIE9758C_ADCalibration(			// 设备校准.		
									HANDLE hDevice);		// 设备对象

	BOOL DEVAPI FAR PASCAL PCIE9758C_InitDeviceAD(		// 初始化设备，当返回TRUE后,设备即准备就绪.
									HANDLE hDevice,			// 设备对象,它由CreateDevice函数创建
									PPCIE9758C_PARA_AD pADPara); // 硬件参数, 它仅在此函数中决定硬件状态

    BOOL DEVAPI FAR PASCAL PCIE9758C_StartDeviceAD(		// 在初始化之后，启动设备
									HANDLE hDevice);		// 设备对象句柄,它由CreateDevice函数创建

	BOOL DEVAPI FAR PASCAL PCIE9758C_ReadDeviceAD(	// 用此函数读取设备上的AD数据
									HANDLE hDevice,			// 设备句柄,它由CreateDevice函数创建
									USHORT ADBuffer[],      // 将用于接受原始AD数据的用户缓冲区								
									ULONG nSizePoints,		// 读取数据点数
									PULONG pRetPoints,		// 返回实际读取点数, =NULL,表示无须返回
									PULONG pAvailSampsPoints,	// 剩余点数, =NULL,表示无须返回
									double fTimeout);			// 超时时间单位:秒(S)
		
    BOOL DEVAPI FAR PASCAL PCIE9758C_StopDeviceAD(		// 在启动设备之后，暂停设备
									HANDLE hDevice);		// 设备对象句柄,它由CreateDevice函数创建

	BOOL DEVAPI FAR PASCAL PCIE9758C_ReleaseDeviceAD(		// 关闭AD设备,禁止传输,且释放资源
									HANDLE hDevice);		// 设备句柄,它由CreateDevice函数创建


	//##################### AD的硬件参数操作函数 ###########################
	BOOL DEVAPI FAR PASCAL PCIE9758C_SaveParaAD(HANDLE hDevice, PPCIE9758C_PARA_AD pADPara); // 将当前的AD采样参数保存至系统中
    BOOL DEVAPI FAR PASCAL PCIE9758C_LoadParaAD(HANDLE hDevice, PPCIE9758C_PARA_AD pADPara); // 将AD采样参数从系统中读出
    BOOL DEVAPI FAR PASCAL PCIE9758C_ResetParaAD(HANDLE hDevice, PPCIE9758C_PARA_AD pADPara); // 将AD采样参数恢复至出厂默认值

	//####################### 数字I/O输入输出函数 #################################
	// 用户可以使用WriteRegisterULong和ReadRegisterULong等函数直接控制寄存器进行I/O
	// 输入输出，但使用下面两个函数更省事，它不需要您关心寄存器分配和位操作等，而只
	// 需象VB等语言的属性操作那么简单地实现各开关量通道的控制。

	// ############################ DIO数字量输入输出实现函数 ############################
	BOOL DEVAPI FAR PASCAL PCIE9758C_SetDir(			// 设置数字量端口各通道方向
									HANDLE hDevice,		// 设备句柄,它由CreateDevice函数创建
									ULONG bLineDirArray[16]);	// 线方向缓冲区, 端口中各线的方向bLineDirArray[n]=0:表示输入, =1表示输出

	BOOL DEVAPI FAR PASCAL PCIE9758C_GetDir(			// 回读数字量端口各通道方向
									HANDLE hDevice,		// 设备句柄,它由CreateDevice函数创建
									ULONG bLineDirArray[16]);	// 线方向缓冲区, 返回端口中各线的方向bLineDirArray[n]=0:表示输入, =1表示输出

	BOOL DEVAPI FAR PASCAL PCIE9758C_ReadPort(			// 读数字量端口值
									HANDLE hDevice,		// 设备句柄,它由CreateDevice函数创建
									ULONG* pPortData);	// 返回的端口数据, 有效位Bit[15:0], 每一位带表一线值，开关量输入值或开关量输出回读值

	BOOL DEVAPI FAR PASCAL PCIE9758C_WritePort(			// 写数字量端口值
									HANDLE hDevice,		// 设备句柄,它由CreateDevice函数创建
									ULONG nPortData);	// 端口数据, 有效位Bit[15:0]，每一位带表一线值，线方向为输入时写入该位的值无效,方向为输出时=0:表示关(或低)状态, =1表示开(或高)状态

	BOOL DEVAPI FAR PASCAL PCIE9758C_ReadLines(			// 读数字量端口多线值(Read Mult Lines Data from the DI Port)
									HANDLE hDevice,		// 设备句柄,它由CreateDevice函数创建
									ULONG bLineDataArray[16]);// 线数据缓冲区, 每一元素带表一线值，开关量输入值或开关量输出回读值，=0:表示关(或低)状态, =1表示开(或高)状态

	BOOL DEVAPI FAR PASCAL PCIE9758C_WriteLines(		// 写数字量端口值
									HANDLE hDevice,		// 设备句柄,它由CreateDevice函数创建
									ULONG bLineDataArray[16]); // 线数据缓冲区, 每一元素带表一线值,线方向为输入时写入该位的值无效,方向为输出时=0:表示关(或低)状态, =1表示开(或高)状态

	BOOL DEVAPI FAR PASCAL PCIE9758C_ReadLine(			// 读线值
									HANDLE hDevice,		// 设备句柄,它由CreateDevice函数创建
									ULONG nLine,		// 线号[0, 15]
									ULONG* pLineData);	// 线数据, 取值0或1 

	BOOL DEVAPI FAR PASCAL PCIE9758C_WriteLine(			// 写线值
									HANDLE hDevice,		// 设备句柄,它由CreateDevice函数创建
									ULONG nLine,		// 线号[0, 15]
									ULONG bLineData);	// 线值,取值0或1

	//################# 内存映射寄存器直接操作及读写函数 ########################
	// 适用于用户对本设备更直接、更特殊、更低层、更复杂的控制。比如根据特殊的
	// 控制对象需要特殊的控制流程和控制效率时，则用户可以使用这些接口予以实现。
	BOOL DEVAPI FAR PASCAL PCIE9758C_GetDeviceBar(			// 取得指定的指定设备寄存器组BAR地址
									HANDLE hDevice,			// 设备对象句柄,它由CreateDevice函数创建
									__int64 pbPCIBar[6]);	// 返回PCI BAR所有地址,具体PCI BAR中有多少可用地址请看硬件说明书

	BOOL DEVAPI FAR PASCAL PCIE9758C_GetDevVersion(			// 获取设备固件及程序版本
									HANDLE hDevice,			// 设备对象句柄,它由CreateDevice函数创建
									PULONG pulFmwVersion,	// 固件版本
									PULONG pulDriverVersion);// 驱动版本

    BOOL DEVAPI FAR PASCAL PCIE9758C_WriteRegisterByte(		// 往指定寄存器空间位置写入单节字数据
									HANDLE hDevice,			// 设备对象句柄,它由CreateDevice函数创建
									__int64 pbLinearAddr,		// 指定寄存器的线性基地址,它等于GetDeviceAddr中的pbLinearAddr参数返回值
									ULONG OffsetBytes,		// 相对于线性基地址基地址的偏移位置(字节)
									BYTE Value);			// 往指定地址写入单字节数据（其地址由线性基地址和偏移位置决定）

	BOOL DEVAPI FAR PASCAL PCIE9758C_WriteRegisterWord(		// 写双字节数据（其余同上）
									HANDLE hDevice, 
									__int64 pbLinearAddr, 
									ULONG OffsetBytes,  
									WORD Value);

	BOOL DEVAPI FAR PASCAL PCIE9758C_WriteRegisterULong(		// 写四节字数据（其余同上）
									HANDLE hDevice, 
									__int64 pbLinearAddr, 
									ULONG OffsetBytes,  
									ULONG Value);

	BYTE DEVAPI FAR PASCAL PCIE9758C_ReadRegisterByte(		// 读入单字节数据（其余同上）
									HANDLE hDevice, 
									__int64 pbLinearAddr, 
									ULONG OffsetBytes);

	WORD DEVAPI FAR PASCAL PCIE9758C_ReadRegisterWord(		// 读入双字节数据（其余同上）
									HANDLE hDevice, 
									__int64 pbLinearAddr, 
									ULONG OffsetBytes);

	ULONG DEVAPI FAR PASCAL PCIE9758C_ReadRegisterULong(		// 读入四字节数据（其余同上）
									HANDLE hDevice, 
									__int64 pbLinearAddr, 
									ULONG OffsetBytes);

	//################# I/O端口直接操作及读写函数 ########################
	// 适用于用户对本设备更直接、更特殊、更低层、更复杂的控制。比如根据特殊的
	// 控制对象需要特殊的控制流程和控制效率时，则用户可以使用这些接口予以实现。
	// 但这些函数主要适用于传统设备，如ISA总线、并口、串口等设备，不能用于本PCI设备
    BOOL DEVAPI FAR PASCAL PCIE9758C_WritePortByte(			// 8位写端口
									HANDLE hDevice,			// 设备句柄(由CreateDevice创建)
									__int64 pPort,				// 端口地址
									BYTE Value);			// 写出的8位整型数据

    BOOL DEVAPI FAR PASCAL PCIE9758C_WritePortWord(HANDLE hDevice, __int64 pPort, WORD Value);
    BOOL DEVAPI FAR PASCAL PCIE9758C_WritePortULong(HANDLE hDevice, __int64 pPort, ULONG Value);

    BYTE DEVAPI FAR PASCAL PCIE9758C_ReadPortByte(HANDLE hDevice, __int64 pPort);
    WORD DEVAPI FAR PASCAL PCIE9758C_ReadPortWord(HANDLE hDevice, __int64 pPort);
    ULONG DEVAPI FAR PASCAL PCIE9758C_ReadPortULong(HANDLE hDevice, __int64 pPort);
	// 如果您要在用户模式下，直接访问硬件端口，请安装并使用ISA\CommUser下的驱动ReadPortByteEx等函数

	//########################### 附加操作函数 ######################################
	HANDLE DEVAPI FAR PASCAL PCIE9758C_CreateSystemEvent(void); // 创建内核事件对象，供InitDeviceDmaAD和VB子线程等函数使用
	BOOL DEVAPI FAR PASCAL PCIE9758C_ReleaseSystemEvent(HANDLE hEvent); // 释放内核事件对象

#ifdef __cplusplus
}
#endif

//***********************************************************
// 各种FIFO存储器的长度(点)
const long FIFO_IDT7202_LENGTH			= 1024;
const long FIFO_IDT7203_LENGTH			= 2048;
const long FIFO_IDT7204_LENGTH			= 4096;
const long FIFO_IDT7205_LENGTH			= 8192;
const long FIFO_IDT7206_LENGTH			= 16384;
const long FIFO_IDT7207_LENGTH			= 32768;

// 自动包含驱动函数导入库
#ifndef _PCIE9758C_DRIVER_
	#ifndef _WIN64
		#pragma comment(lib, "PCIE9758C_32.lib")
		#pragma message("======== Welcome to use our art company's products!")
		#pragma message("======== Automatically linking with PCIE9758C_32.dll...")
		#pragma message("======== Successfully linked with PCIE9758C_32.dll")
	#else
		#pragma comment(lib, "PCIE9758C_64.lib")
		#pragma message("======== Welcome to use our art company's products!")
		#pragma message("======== Automatically linking with PCIE9758C_64.dll...")
		#pragma message("======== Successfully linked with PCIE9758C_64.dll")
	#endif
#endif

#endif // _PCIE9758C_DEVICE_