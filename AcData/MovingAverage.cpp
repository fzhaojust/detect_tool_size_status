#include "MovingAverage.h"
//para1：信号     para2：平滑数
MovingAverage::MovingAverage(vector<float>data,int size):PI(3.1416), Frequency_length(65536)
{

	this->len = size;
	filter_res.clear();
	raw_data.clear();
	time_value.clear();
	WPT_res.clear();
	raw_data = data;
	filter_sum = 0;
}



//均值滤波+峰值计算
void MovingAverage::cal_Peak() {
	int length = raw_data.size();
	
	for (int i = 0; i < length; ++i) {
		filter_res.push_back(this->next(raw_data[i]));
	}
	////峰值提取
	vector<float>peak_points = calculate_Peak(filter_res);
//	cout << "峰值点数为：" << peak_points.size() << " ";
	Fluctuation = calcalate_FD(peak_points, 0.7, 1.3);
	
}


//均值滤波步骤
float MovingAverage::next(float val) {
	que.push(val);
	filter_sum += val;
	while(que.size() > len) {
		filter_sum -= que.front();//超出窗口容量，先把队首元素获取，在sum里减去
		que.pop();//再把队首元素弹出
	}
	return filter_sum / que.size();
}


//获取峰值波动特征
float MovingAverage::get_FD() {
	return Fluctuation;
}

vector<float> MovingAverage::calculate_Peak(vector<float> smooth_data) {
	int length = smooth_data.size();
	vector<float>peak_ans;
	float avg = -1;
	float sum = 0;
	for (int i = 0; i < length; ++i) {
		sum += smooth_data[i];
	}
	avg = float(sum / length);
	vector<int> coordinate_x;
	for (int i = 1; i < length - 1; ++i) {
		if (smooth_data[i] > smooth_data[i - 1] && smooth_data[i] > smooth_data[i + 1] && smooth_data[i] >= avg) {//
			if (!coordinate_x.empty()&&(i - coordinate_x.back() < 2000)) {
				if (smooth_data[i] > peak_ans.back()) {
					peak_ans.pop_back(); coordinate_x.pop_back();
					coordinate_x.push_back(i); peak_ans.push_back(smooth_data[i]);
				}
				else {
					continue;
				}
			}
			else {
				coordinate_x.push_back(i); peak_ans.push_back(smooth_data[i]);
			}
		}
	}
	return peak_ans;
}

float MovingAverage::calcalate_FD(vector<float> data, float low_hold, float high_hold) {

	int brow = data.size();
	int vebral = 0;
	float val = 0;
	for (int i = 0; i < brow - 1; ++i) {
		val = data[i] / data[i + 1];
		if (val<=low_hold || val >= high_hold) {
			vebral+=1;
		}
	}

	//cout<<"超出范围为"<< vebral<<" ";

	float ans = float(vebral)/float(brow);

	return ans;

	
}

//判断是否加工区域
bool MovingAverage::stage_cutting() {
	float process_value = 0;
	float decision_threshold = 0.15;//设定加工下限阈值
	int datasize = raw_data.size();
	for (int j = 0; j < datasize; ++j) {	
		process_value += raw_data[j];
	}
	//计算均值
	float average = process_value / (float)datasize;
	return average > decision_threshold;
}
//获取时域特征
vector<float> MovingAverage::getTime() {
	return time_value;
}

//计算时域特征
void MovingAverage::cal_Time() {
	float process_value = 0;
	float Rms_value = 0;
	float max_value = -1;
			
	int datasize = raw_data.size();
	for (int j = 0; j < datasize; ++j) {
		if (raw_data[j] > max_value)max_value = raw_data[j];
		process_value += raw_data[j];
		Rms_value += raw_data[j] * raw_data[j];
	}

	//计算均值
	float average = process_value / (float)datasize;
	//计算均方根
	float rms = Rms_value / (float)datasize;
	//计算峰值因子
	float perk = max_value / rms;
	time_value.push_back(average);
	time_value.push_back(rms);
	time_value.push_back(perk);
}


////频域分析


inline void MovingAverage::swap(float &a, float &b)
{
	float t;
	t = a;
	a = b;
	b = t;
}

void MovingAverage::bitrp(float xreal[], float ximag[], int n)
{
	// 位反转置换 Bit-reversal Permutation
	int i, j, a, b, p;

	for (i = 1, p = 0; i < n; i *= 2)
	{
		p++;
	}
	for (i = 0; i < n; i++)
	{
		a = i;
		b = 0;
		for (j = 0; j < p; j++)
		{
			b = (b << 1) + (a & 1);    // b = b * 2 + a % 2;
			a >>= 1;        // a = a / 2;
		}
		if (b > i)
		{
			swap(xreal[i], xreal[b]);
			swap(ximag[i], ximag[b]);
		}
	}
}

void MovingAverage::FFT(float xreal[], float ximag[], int n)
{
	const int frequency = 1000000;
	// 快速傅立叶变换，将复数 x 变换后仍保存在 x 中，xreal, ximag 分别是 x 的实部和虚部
	float wreal[frequency / 2], wimag[frequency / 2], treal, timag, ureal, uimag, arg;
	int m, k, j, t, index1, index2;

	bitrp(xreal, ximag, n);

	// 计算 1 的前 n / 2 个 n 次方根的共轭复数 W'j = wreal [j] + i * wimag [j] , j = 0, 1, ... , n / 2 - 1
	arg = -2 * PI / n;
	treal = cos(arg);
	timag = sin(arg);
	wreal[0] = 1.0;
	wimag[0] = 0.0;
	for (j = 1; j < n / 2; j++)
	{
		wreal[j] = wreal[j - 1] * treal - wimag[j - 1] * timag;
		wimag[j] = wreal[j - 1] * timag + wimag[j - 1] * treal;
	}

	for (m = 2; m <= n; m *= 2)
	{
		for (k = 0; k < n; k += m)
		{
			for (j = 0; j < m / 2; j++)
			{
				index1 = k + j;
				index2 = index1 + m / 2;
				t = n * j / m;    // 旋转因子 w 的实部在 wreal [] 中的下标为 t
				treal = wreal[t] * xreal[index2] - wimag[t] * ximag[index2];
				timag = wreal[t] * ximag[index2] + wimag[t] * xreal[index2];
				ureal = xreal[index1];
				uimag = ximag[index1];
				xreal[index1] = ureal + treal;
				ximag[index1] = uimag + timag;
				xreal[index2] = ureal - treal;
				ximag[index2] = uimag - timag;
			}
		}
	}
}


void MovingAverage::cal_FFT()
{
	const int frequency = 1000000;
	float xreal[frequency] = {}, ximag[frequency] = {};
	//float xreal[frequency] = {}, ximag[frequency] = {0};
	int n, i= Frequency_length;

	for (int j = 0; j < i; ++j) {
		xreal[j]=raw_data[j];
		ximag[j]=0;
	}
	
	n = i;    // 要求 n 为 2 的整数幂
	while (i > 1)
	{
		if (i % 2)
		{
			printf( "%d is not a power of 2! ", n);
			exit(1);
		}
		i /= 2;
	}
	
	FFT(xreal, ximag, n);

	//printf( "FFT:    i	    real	imag\n");
	float sum = 0;
	for (i = 0; i < n; i++)
	{
		sum += xreal[i];
		//printf( "%4d    %8.4f    %8.4f\n", i, xreal[i], ximag[i]);
	}
	fft_energy = sum / (float)n;
}

float MovingAverage::get_FFT() {
	return fft_energy;

}


//计算小波包能量比结果
void MovingAverage::cal_WPT() {
	vector<double>signal;
	int data_size = Frequency_length;
	for (int i = 0;i < data_size; ++i) {
		signal.push_back(raw_data[i]);
	}
	std::vector<double> reconstructed_signal;
	reconstructed_signal.resize(signal.size());

	// Load well-known wavelet coefficients.
	Wavelet wavelet;
	Wavelet::GetWaveletCoefficients(&wavelet, Wavelet::WaveletType::Daubechies, 5);

	// Construct wavelet packet tree of height = 3.
	// This tree has 4 wavelet levels, and 4 leaves.
	WaveletPacketTree tree(4, &wavelet);
	tree.SetRootSignal(&signal);
	tree.Decompose();

	// Reconstruct signal one wavelet level at a time.
	//cout << "小波包叶子为：" << tree.GetWaveletLevelCount() << endl;
	vector<double>energy;
	for (size_t i = 0; i < tree.GetWaveletLevelCount(); i++) {
		tree.Reconstruct(i);
		
		auto root_signal = tree.GetRootSignal();

		// Add the coefficients of wavelet level i to the reconstructed signal.
		std::transform(reconstructed_signal.cbegin(), reconstructed_signal.cend(), root_signal->cbegin(), reconstructed_signal.begin(), std::plus<double>());
	
		//root_signal:最后一层小波包重构信号
		double sum = 0;
		for_each(root_signal->cbegin(), root_signal->cend(), [&](double x) {
			sum += x;
		});
		sum = sqrtf(sum);
		energy.push_back(sum);
	}
	//for_each(energy.begin(), energy.end(), [](float x) {
	//	cout << x << " ";
	//});
	double all_sum = 0;
	for_each(energy.begin(), energy.end(), [&](double x) {
		all_sum += x;
	});
	WPT_res.push_back(energy[2]/all_sum*100); 
	WPT_res.push_back(energy[4] / all_sum * 100); 
	WPT_res.push_back(energy[5] / all_sum * 100);
	//for (int i = 0; i < WPT_res.size(); ++i) {
	//		cout << WPT_res[i] << " ";
	//}
		//cout << "总和为" << all_sum << "节点占比为";
	//vector<float>En_ratio;
	//for_each(energy.begin(), energy.end(), [&](double x) {
	//	En_ratio.push_back((x / all_sum)*100);
	//	cout << (x / all_sum)*100 << " ";
	//});
	////WPT_res.push_back({En_ratio[2],En_ratio[4],En_ratio[5] });
	//WPT_res.push_back(En_ratio[2]); WPT_res.push_back(En_ratio[4]); WPT_res.push_back(En_ratio[5]);
}

//获取小波包能量比的3、5、6节点的能量比结果
vector<float> MovingAverage::get_WPT() {
	return WPT_res;
}


