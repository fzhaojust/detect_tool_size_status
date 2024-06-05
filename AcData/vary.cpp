#include "vary.h"


ULONG ReadIndex = 0;
ULONG currentindex = 0;



WORD ADBuffer[MAX_SEGMENT][AD_DATA_LEN];

bool falgs = false;
bool is_stop = false;
mutex mu1;
condition_variable my_con;//生成条件对象

 mutex mu2;
 condition_variable my_con2;//生成条件对象
QSplineSeries* Qline=new QSplineSeries();

int maxsize= AD_DATA_LEN * 10;//设置波形长度

QLineSeries* train_line = new QLineSeries();
int flag = 1;
//double min_threshold = -20;
