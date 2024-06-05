#ifndef _PCIE9758C_DEVICE_
#define _PCIE9758C_DEVICE_

#define PCIE9758C_AD_MAX_CHANNELS		4	// �������֧��4·ģ��������ͨ��
//#################### ADӲ������PCIE9758C_PARA_AD���� #####################
// ����AD������ʵ��Ӳ������
typedef struct _PCIE9758C_PARA_AD     
{
	LONG bChannelArray[4];	// ����ͨ��ѡ�����У��ֱ����4��ͨ����=1��ʾ��ͨ��������=0������
	LONG InputRange[4];		// ģ������������ѡ�����У��ֱ����4��ͨ��
	LONG RefGround[4];		// �زο���ʽ
	LONG Frequency;         // �ɼ�Ƶ��, ��λΪHz, ��߲�����5MHz
	LONG TriggerMode;		// ����ģʽѡ��
	LONG TriggerType;		// ��������ѡ��
	LONG TriggerDir;		// ��������ѡ��(����/���򴥷�)
	LONG TriggerSource;		// ����Դѡ��
	LONG TrigLevelVolt;		// ������ƽ(����-10V~10V)
	LONG TrigWindow;		// ����������, ��λ25����
	LONG RefClkSrc;			// �ο�ʱ��Դѡ��
	LONG CnvClkSrc;			// ת��ʱ��Դѡ��
	LONG bClockOutput;		// ����ת��ʱ�����CLKOUT, =TRUE:�������, =FALSE:��ֹ���
	LONG SyncTrigSrc;		// ͬ������Դѡ��
	LONG bMasterEn;			// ���豸ʹ��  
							// =0�����豸��ͨ��Trigger�źŽ������豸���͵�ͬ�������ź�
							// =1�����豸��ͨ��Trigger�ź�Ϊ���豸��������Ĵ����ź�
							// ע���ڶ�ģ��ͬ��ϵͳ�У�ֻ���趨����һ���豸Ϊ���豸���������趨Ϊ���豸�����ϵͳ��ֻ��һ���豸�����ж���豸���ǲ�Ҫ��ͬ�����轫�����豸�趨Ϊ���豸
} PCIE9758C_PARA_AD, *PPCIE9758C_PARA_AD;

//***********************************************************
// AD����PCIE9758C_PARA_AD�е�InputRange[X]ʹ�õ�Ӳ������ѡ��
const long PCIE9758C_INPUT_N10000_P10000mV			= 0x00; // ��10000mV
const long PCIE9758C_INPUT_N5000_P5000mV			= 0x01; // ��5000mV
const long PCIE9758C_INPUT_N2500_P2500mV			= 0x02; // ��2500mV
const long PCIE9758C_INPUT_N1250_P1250mV			= 0x03; // ��1250mV

//***********************************************************
// ADӲ������PCIE9758C_PARA_AD�е�RefGround����ģʽ��ʹ�õ�ѡ��
const long PCIE9758C_REFGND_RSE						= 0x00; // ����
const long PCIE9758C_REFGND_DIFF					= 0x01; // ���

//***********************************************************
// ADӲ������PCIE9758C_PARA_AD�е�TriggerMode����ģʽ��ʹ�õ�ѡ��
const long PCIE9758C_TRIGMODE_SOFT					= 0x00; // �������
const long PCIE9758C_TRIGMODE_POST					= 0x01; // Ӳ������

// ADӲ������PCIE9758C_PARA_AD�е�TriggerType����������ʹ�õ�ѡ��
const long PCIE9758C_TRIGTYPE_EDGE					= 0x00; // ���ش���
const long PCIE9758C_TRIGTYPE_PULSE					= 0x01; // ���崥��(��ƽ)

//***********************************************************
// ADӲ������PCIE9758C_PARA_AD�е�TriggerDir����������ʹ�õ�ѡ��
const long PCIE9758C_TRIGDIR_NEGATIVE				= 0x00; // ���򴥷�(������/�½��ش���)
const long PCIE9758C_TRIGDIR_POSITIVE				= 0x01; // ���򴥷�(������/�����ش���)
const long PCIE9758C_TRIGDIR_POSIT_NEGAT			= 0x02; // �����򴥷�(��/�����������/�½��ش���)

//***********************************************************
// ADӲ������PCIE9758C_PARA_AD�е�TriggerSource����Դ�ź���ʹ�õ�ѡ��
const long PCIE9758C_TRIGSRC_DTR					= 0x00; // ѡ��DTR��Ϊ����Դ
const long PCIE9758C_TRIGSRC_ATR					= 0x01; // ѡ��ATR��Ϊ����Դ
const long PCIE9758C_TRIGSRC_TRIG					= 0x02; // Trigger�źŴ��������ڶ࿨ͬ����

//***********************************************************
// ADӲ������PCIE9758C_PARA_AD�е�RefClkSrc�ο�ʱ��Դ��ʹ�õ�ѡ��
const long PCIE9758C_REFCLKSRC_IN					= 0x00; // ʹ���ڲ��ο�ʱ��
const long PCIE9758C_REFCLKSRC_10M					= 0x01; // ʹ������10Mʱ��

//***********************************************************
// ADӲ������PCIE9758C_PARA_AD�е�CnvClkSrcת��ʱ��Դ��ʹ�õ�ѡ��
const long PCIE9758C_CNVCLKSRC_IN					= 0x00; // ʹ���ڲ�ת��ʱ��
const long PCIE9758C_CNVCLKSRC_EXT					= 0x01; // ʹ���ⲿת��ʱ��,��EXT_CLK�ܽ�����

//***********************************************************
// ADӲ������PCIE9758C_PARA_AD�е�SyncTrigSrcͬ������Դ��ʹ�õ�ѡ��
const long PCIE9758C_SYNCTRIGSRC_TRIGGER0					= 0x00; // ѡ��ͬ��TRIG0�źŴ���
const long PCIE9758C_SYNCTRIGSRC_TRIGGER1					= 0x01; // ѡ��ͬ��TRIG1�źŴ���
const long PCIE9758C_SYNCTRIGSRC_TRIGGER2					= 0x02; // ѡ��ͬ��TRIG2�źŴ���
const long PCIE9758C_SYNCTRIGSRC_TRIGGER3					= 0x03; // ѡ��ͬ��TRIG3�źŴ���
const long PCIE9758C_SYNCTRIGSRC_TRIGGER4					= 0x04; // ѡ��ͬ��TRIG4�źŴ���
const long PCIE9758C_SYNCTRIGSRC_TRIGGER5					= 0x05; // ѡ��ͬ��TRIG5�źŴ���
const long PCIE9758C_SYNCTRIGSRC_TRIGGER6					= 0x06; // ѡ��ͬ��TRIG6�źŴ���
const long PCIE9758C_SYNCTRIGSRC_TRIGGER7					= 0x07; // ѡ��ͬ��TRIG7�źŴ���


//*************************************************************************************
// ����AD������ʵ��Ӳ������
typedef struct _PCIE9758C_STATUS_AD     
{
	LONG bNotEmpty;			// ����FIFO�洢���ķǿձ�־��=TRUE�ǿգ� = FALSE ��
	LONG bHalf;				// ����FIFO�洢���İ�����־��=TRUE�������ϣ� = FALSE ��������
	LONG bDynamic_Overflow; // ����FIFO�洢���Ķ�̬�����־��= TRUE�ѷ�������� = FALSE��δ�������
	LONG bStatic_Overflow;  // ����FIFO�洢���ľ�̬�����־��= TRUE�ѷ�������� = FALSE��δ�������
} PCIE9758C_STATUS_AD, *PPCIE9758C_STATUS_AD;

//***********************************************************
// �û������ӿ�
#ifndef _PCIE9758C_DRIVER_
#define DEVAPI __declspec(dllimport)
#else
#define DEVAPI __declspec(dllexport)
#endif

#ifdef __cplusplus
extern "C" {
#endif
	//######################## �豸��������� ##############################
	HANDLE DEVAPI FAR PASCAL PCIE9758C_CreateDevice(int DeviceLgcID = 0);     // ���߼��Ŵ����豸����
	int DEVAPI FAR PASCAL PCIE9758C_GetDeviceCount(HANDLE hDevice); // ȡ���豸��̨��
	BOOL DEVAPI FAR PASCAL PCIE9758C_GetDeviceCurrentID(HANDLE hDevice,		// ȡ�õ�ǰ�豸��Ӧ��ID��
													PLONG DeviceLgcID, 
													PLONG DevicePhysID);
	BOOL DEVAPI FAR PASCAL PCIE9758C_ListDeviceDlg(HANDLE hDevice); // �ԶԻ����巽ʽ�б�ϵͳ���е����еĸ�PCI�豸
    BOOL DEVAPI FAR PASCAL PCIE9758C_ReleaseDevice(HANDLE hDevice); // ���ͷ��豸����

	//####################### AD���ݶ�ȡ���� #################################
	// ���ڴ������ͨ�û�����Щ�ӿ���򵥡����ݡ���ɿ������û�����֪���豸
	// �Ͳ㸴�ӵ�Ӳ������Э��ͷ����������Ʊ�̣���������ĳ�ʼ���豸�Ͷ�ȡ
	// AD�������������������ɸ�Ч��ʵ�ָ��١����������ݲɼ�

	//####################### AD���ݶ�ȡ���� #################################
	// ���ڴ������ͨ�û�����Щ�ӿ���򵥡����ݡ���ɿ������û�����֪���豸
	// �Ͳ㸴�ӵ�Ӳ������Э��ͷ����������Ʊ�̣���������ĳ�ʼ���豸�Ͷ�ȡ
	// AD�������������������ɸ�Ч��ʵ�ָ��١����������ݲɼ�
	BOOL DEVAPI FAR PASCAL PCIE9758C_ADCalibration(			// �豸У׼.		
									HANDLE hDevice);		// �豸����

	BOOL DEVAPI FAR PASCAL PCIE9758C_InitDeviceAD(		// ��ʼ���豸��������TRUE��,�豸��׼������.
									HANDLE hDevice,			// �豸����,����CreateDevice��������
									PPCIE9758C_PARA_AD pADPara); // Ӳ������, �����ڴ˺����о���Ӳ��״̬

    BOOL DEVAPI FAR PASCAL PCIE9758C_StartDeviceAD(		// �ڳ�ʼ��֮�������豸
									HANDLE hDevice);		// �豸������,����CreateDevice��������

	BOOL DEVAPI FAR PASCAL PCIE9758C_ReadDeviceAD(	// �ô˺�����ȡ�豸�ϵ�AD����
									HANDLE hDevice,			// �豸���,����CreateDevice��������
									USHORT ADBuffer[],      // �����ڽ���ԭʼAD���ݵ��û�������								
									ULONG nSizePoints,		// ��ȡ���ݵ���
									PULONG pRetPoints,		// ����ʵ�ʶ�ȡ����, =NULL,��ʾ���뷵��
									PULONG pAvailSampsPoints,	// ʣ�����, =NULL,��ʾ���뷵��
									double fTimeout);			// ��ʱʱ�䵥λ:��(S)
		
    BOOL DEVAPI FAR PASCAL PCIE9758C_StopDeviceAD(		// �������豸֮����ͣ�豸
									HANDLE hDevice);		// �豸������,����CreateDevice��������

	BOOL DEVAPI FAR PASCAL PCIE9758C_ReleaseDeviceAD(		// �ر�AD�豸,��ֹ����,���ͷ���Դ
									HANDLE hDevice);		// �豸���,����CreateDevice��������


	//##################### AD��Ӳ�������������� ###########################
	BOOL DEVAPI FAR PASCAL PCIE9758C_SaveParaAD(HANDLE hDevice, PPCIE9758C_PARA_AD pADPara); // ����ǰ��AD��������������ϵͳ��
    BOOL DEVAPI FAR PASCAL PCIE9758C_LoadParaAD(HANDLE hDevice, PPCIE9758C_PARA_AD pADPara); // ��AD����������ϵͳ�ж���
    BOOL DEVAPI FAR PASCAL PCIE9758C_ResetParaAD(HANDLE hDevice, PPCIE9758C_PARA_AD pADPara); // ��AD���������ָ�������Ĭ��ֵ

	//####################### ����I/O����������� #################################
	// �û�����ʹ��WriteRegisterULong��ReadRegisterULong�Ⱥ���ֱ�ӿ��ƼĴ�������I/O
	// �����������ʹ����������������ʡ�£�������Ҫ�����ļĴ��������λ�����ȣ���ֻ
	// ����VB�����Ե����Բ�����ô�򵥵�ʵ�ָ�������ͨ���Ŀ��ơ�

	// ############################ DIO�������������ʵ�ֺ��� ############################
	BOOL DEVAPI FAR PASCAL PCIE9758C_SetDir(			// �����������˿ڸ�ͨ������
									HANDLE hDevice,		// �豸���,����CreateDevice��������
									ULONG bLineDirArray[16]);	// �߷��򻺳���, �˿��и��ߵķ���bLineDirArray[n]=0:��ʾ����, =1��ʾ���

	BOOL DEVAPI FAR PASCAL PCIE9758C_GetDir(			// �ض��������˿ڸ�ͨ������
									HANDLE hDevice,		// �豸���,����CreateDevice��������
									ULONG bLineDirArray[16]);	// �߷��򻺳���, ���ض˿��и��ߵķ���bLineDirArray[n]=0:��ʾ����, =1��ʾ���

	BOOL DEVAPI FAR PASCAL PCIE9758C_ReadPort(			// ���������˿�ֵ
									HANDLE hDevice,		// �豸���,����CreateDevice��������
									ULONG* pPortData);	// ���صĶ˿�����, ��ЧλBit[15:0], ÿһλ����һ��ֵ������������ֵ�򿪹�������ض�ֵ

	BOOL DEVAPI FAR PASCAL PCIE9758C_WritePort(			// д�������˿�ֵ
									HANDLE hDevice,		// �豸���,����CreateDevice��������
									ULONG nPortData);	// �˿�����, ��ЧλBit[15:0]��ÿһλ����һ��ֵ���߷���Ϊ����ʱд���λ��ֵ��Ч,����Ϊ���ʱ=0:��ʾ��(���)״̬, =1��ʾ��(���)״̬

	BOOL DEVAPI FAR PASCAL PCIE9758C_ReadLines(			// ���������˿ڶ���ֵ(Read Mult Lines Data from the DI Port)
									HANDLE hDevice,		// �豸���,����CreateDevice��������
									ULONG bLineDataArray[16]);// �����ݻ�����, ÿһԪ�ش���һ��ֵ������������ֵ�򿪹�������ض�ֵ��=0:��ʾ��(���)״̬, =1��ʾ��(���)״̬

	BOOL DEVAPI FAR PASCAL PCIE9758C_WriteLines(		// д�������˿�ֵ
									HANDLE hDevice,		// �豸���,����CreateDevice��������
									ULONG bLineDataArray[16]); // �����ݻ�����, ÿһԪ�ش���һ��ֵ,�߷���Ϊ����ʱд���λ��ֵ��Ч,����Ϊ���ʱ=0:��ʾ��(���)״̬, =1��ʾ��(���)״̬

	BOOL DEVAPI FAR PASCAL PCIE9758C_ReadLine(			// ����ֵ
									HANDLE hDevice,		// �豸���,����CreateDevice��������
									ULONG nLine,		// �ߺ�[0, 15]
									ULONG* pLineData);	// ������, ȡֵ0��1 

	BOOL DEVAPI FAR PASCAL PCIE9758C_WriteLine(			// д��ֵ
									HANDLE hDevice,		// �豸���,����CreateDevice��������
									ULONG nLine,		// �ߺ�[0, 15]
									ULONG bLineData);	// ��ֵ,ȡֵ0��1

	//################# �ڴ�ӳ��Ĵ���ֱ�Ӳ�������д���� ########################
	// �������û��Ա��豸��ֱ�ӡ������⡢���Ͳ㡢�����ӵĿ��ơ�������������
	// ���ƶ�����Ҫ����Ŀ������̺Ϳ���Ч��ʱ�����û�����ʹ����Щ�ӿ�����ʵ�֡�
	BOOL DEVAPI FAR PASCAL PCIE9758C_GetDeviceBar(			// ȡ��ָ����ָ���豸�Ĵ�����BAR��ַ
									HANDLE hDevice,			// �豸������,����CreateDevice��������
									__int64 pbPCIBar[6]);	// ����PCI BAR���е�ַ,����PCI BAR���ж��ٿ��õ�ַ�뿴Ӳ��˵����

	BOOL DEVAPI FAR PASCAL PCIE9758C_GetDevVersion(			// ��ȡ�豸�̼�������汾
									HANDLE hDevice,			// �豸������,����CreateDevice��������
									PULONG pulFmwVersion,	// �̼��汾
									PULONG pulDriverVersion);// �����汾

    BOOL DEVAPI FAR PASCAL PCIE9758C_WriteRegisterByte(		// ��ָ���Ĵ����ռ�λ��д�뵥��������
									HANDLE hDevice,			// �豸������,����CreateDevice��������
									__int64 pbLinearAddr,		// ָ���Ĵ��������Ի���ַ,������GetDeviceAddr�е�pbLinearAddr��������ֵ
									ULONG OffsetBytes,		// ��������Ի���ַ����ַ��ƫ��λ��(�ֽ�)
									BYTE Value);			// ��ָ����ַд�뵥�ֽ����ݣ����ַ�����Ի���ַ��ƫ��λ�þ�����

	BOOL DEVAPI FAR PASCAL PCIE9758C_WriteRegisterWord(		// д˫�ֽ����ݣ�����ͬ�ϣ�
									HANDLE hDevice, 
									__int64 pbLinearAddr, 
									ULONG OffsetBytes,  
									WORD Value);

	BOOL DEVAPI FAR PASCAL PCIE9758C_WriteRegisterULong(		// д�Ľ������ݣ�����ͬ�ϣ�
									HANDLE hDevice, 
									__int64 pbLinearAddr, 
									ULONG OffsetBytes,  
									ULONG Value);

	BYTE DEVAPI FAR PASCAL PCIE9758C_ReadRegisterByte(		// ���뵥�ֽ����ݣ�����ͬ�ϣ�
									HANDLE hDevice, 
									__int64 pbLinearAddr, 
									ULONG OffsetBytes);

	WORD DEVAPI FAR PASCAL PCIE9758C_ReadRegisterWord(		// ����˫�ֽ����ݣ�����ͬ�ϣ�
									HANDLE hDevice, 
									__int64 pbLinearAddr, 
									ULONG OffsetBytes);

	ULONG DEVAPI FAR PASCAL PCIE9758C_ReadRegisterULong(		// �������ֽ����ݣ�����ͬ�ϣ�
									HANDLE hDevice, 
									__int64 pbLinearAddr, 
									ULONG OffsetBytes);

	//################# I/O�˿�ֱ�Ӳ�������д���� ########################
	// �������û��Ա��豸��ֱ�ӡ������⡢���Ͳ㡢�����ӵĿ��ơ�������������
	// ���ƶ�����Ҫ����Ŀ������̺Ϳ���Ч��ʱ�����û�����ʹ����Щ�ӿ�����ʵ�֡�
	// ����Щ������Ҫ�����ڴ�ͳ�豸����ISA���ߡ����ڡ����ڵ��豸���������ڱ�PCI�豸
    BOOL DEVAPI FAR PASCAL PCIE9758C_WritePortByte(			// 8λд�˿�
									HANDLE hDevice,			// �豸���(��CreateDevice����)
									__int64 pPort,				// �˿ڵ�ַ
									BYTE Value);			// д����8λ��������

    BOOL DEVAPI FAR PASCAL PCIE9758C_WritePortWord(HANDLE hDevice, __int64 pPort, WORD Value);
    BOOL DEVAPI FAR PASCAL PCIE9758C_WritePortULong(HANDLE hDevice, __int64 pPort, ULONG Value);

    BYTE DEVAPI FAR PASCAL PCIE9758C_ReadPortByte(HANDLE hDevice, __int64 pPort);
    WORD DEVAPI FAR PASCAL PCIE9758C_ReadPortWord(HANDLE hDevice, __int64 pPort);
    ULONG DEVAPI FAR PASCAL PCIE9758C_ReadPortULong(HANDLE hDevice, __int64 pPort);
	// �����Ҫ���û�ģʽ�£�ֱ�ӷ���Ӳ���˿ڣ��밲װ��ʹ��ISA\CommUser�µ�����ReadPortByteEx�Ⱥ���

	//########################### ���Ӳ������� ######################################
	HANDLE DEVAPI FAR PASCAL PCIE9758C_CreateSystemEvent(void); // �����ں��¼����󣬹�InitDeviceDmaAD��VB���̵߳Ⱥ���ʹ��
	BOOL DEVAPI FAR PASCAL PCIE9758C_ReleaseSystemEvent(HANDLE hEvent); // �ͷ��ں��¼�����

#ifdef __cplusplus
}
#endif

//***********************************************************
// ����FIFO�洢���ĳ���(��)
const long FIFO_IDT7202_LENGTH			= 1024;
const long FIFO_IDT7203_LENGTH			= 2048;
const long FIFO_IDT7204_LENGTH			= 4096;
const long FIFO_IDT7205_LENGTH			= 8192;
const long FIFO_IDT7206_LENGTH			= 16384;
const long FIFO_IDT7207_LENGTH			= 32768;

// �Զ������������������
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