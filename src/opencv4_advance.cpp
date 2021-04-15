#include "opencv4_advance.h"
#include <vector>

using namespace std;
void opencv4_advance::color_space(cv::Mat &img)
{
	cv::Mat gray, HSV, YUV, Lab, img32;
	img.convertTo(img32, CV_32F, 1.0 / 255); // 将CV_8U类型转换为CV_32F类型
	//img32.convertTo(img, CV_8U, 255);
	cv::cvtColor(img32, HSV, cv::COLOR_BGR2HSV);
	cv::cvtColor(img32, YUV, cv::COLOR_BGR2YUV);
	cv::cvtColor(img32, Lab, cv::COLOR_BGR2Lab);
	cv::cvtColor(img32, gray, cv::COLOR_BGR2GRAY);
	
	cv::imshow("原图", img32);
	cv::imshow("HSV", HSV);
	cv::imshow("YUV", YUV);
	cv::imshow("Lab", Lab);
	cv::imshow("gray", gray);
	cv::waitKey(0);
}

void opencv4_advance::split_merge(cv::Mat &img)
{
	cv::Mat HSV;
	cv::cvtColor(img, HSV, cv::COLOR_BGR2HSV);
	cv::Mat imgs0, imgs1, imgs2;  // 用于存放数组类型的结果
	cv::Mat imgv0, imgv1, imgv2;  // 用于存放vector类型的结果
	cv::Mat result0, result1, result2;  // 多通道合并的结果

	// 输入数组参数的多通道分离与合并
	cv::Mat imgs[3];
	cv::split(img, imgs);
	imgs0 = imgs[0];
	imgs1 = imgs[1];
	imgs2 = imgs[2];
	//cv::imshow("RGB-B通道", imgs0);
	//cv::imshow("RGB-G通道", imgs1);
	//cv::imshow("RGB-R通道", imgs2);
	imgs[2] = img;  // 将数组中的图像通道数变成不一致
	cv::merge(imgs, 3, result0);
	//cv::imshow("result0", result0);  // imshow最多显示4个通道, 可使用Image Watch查看, debug下设置断点，veiw->其他窗口->Image Watch
	cv::Mat zero = cv::Mat::zeros(img.rows, img.cols, CV_8UC1);
	imgs[0] = zero;
	imgs[2] = zero;
	cv::merge(imgs, 3, result1);
	cv::imshow("result1", result1);  // 合并显示结果

	// 输入vector参数的多通道分离与合并
	std::vector<cv::Mat> imgv;
	cv::split(HSV, imgv);
	imgv0 = imgv.at(0);
	imgv1 = imgv.at(1);
	imgv2 = imgv.at(2);
	//cv::imshow("HSV-H通道", imgv0);
	//cv::imshow("HSV-S通道", imgv1);
	//cv::imshow("HSV-V通道", imgv2);
	imgv.push_back(HSV);
	cv::merge(imgv, result2);
	cv::imshow("result2", result2);
	cv::waitKey(0);
}

void opencv4_advance::find_Mat_minmax()
{
	float a[12] = { 1,2,3,4,5,6,7,8,9,10,0 };
	cv::Mat img = cv::Mat(3, 4, CV_32FC1, a);
	cv::Mat imgs = cv::Mat(2, 3, CV_32FC2, a);
	double minVal, maxVal;
	cv::Point minIdx, maxIdx;
	cv::minMaxLoc(img, &minVal, &maxVal, &minIdx, &maxIdx);
	cout << "img中最大值是: " << maxVal << " " << "在矩阵中位置: " << maxIdx << endl;
	cout << "img中最小值是: " << minVal << " " << "在矩阵中位置: " << minIdx << endl;

	// 寻找多通道矩阵中的最值
	cv::Mat imgs_re = imgs.reshape(1, 4);  // 将多通道矩阵变成单通道矩阵
	cv::minMaxLoc(imgs_re, &minVal, &maxVal, &minIdx, &maxIdx);
	cout << "imgs中最大值是: " << maxVal << " " << "在矩阵中位置: " << maxIdx << endl;
	cout << "imgs中最小值是: " << minVal << " " << "在矩阵中位置: " << minIdx << endl;
}

void opencv4_advance::mean_Stddev()
{
	float a[12] = { 1,2,3,4,5,10,6,7,8,9,10,0 };
	cv::Mat img = cv::Mat(3, 4, CV_32FC1, a);
	cv::Mat imgs = cv::Mat(2, 3, CV_32FC2, a);
	cout << "mat" << imgs << endl;
	cout << "用mean求取图像的平均值" << endl;
	cv::Scalar mymean;
	mymean = cv::mean(imgs);   // mean函数没有返回值
	cout << "imgs平均值=" << mymean << endl;
	cout << "imgs第一通道的平均值=" << mymean[0] << " "
		<< "imgs第二通道的平均值=" << mymean[1] << endl << endl;
	cout << "用meanStsDev同时求取图像的平均值和标准差" << endl;
	cv::Mat mymeanMat, myStddevMat;
	cv::meanStdDev(img, mymeanMat, myStddevMat);
	cout << "img平均值=" << mymeanMat << endl;
	cout << "img标准差=" << myStddevMat << endl;
	cv::meanStdDev(imgs, mymeanMat, myStddevMat);
	cout << "imgs平均值=" << mymeanMat << endl;
	cout << "imgs标准差=" << myStddevMat << endl;
}

void opencv4_advance::image_operate(cv::Mat & img0, cv::Mat & img1)
{
	// 对两幅灰度图像进行比较计算
	cv::Mat img0G, img1G, comMinG, comMaxG;
	cv::cvtColor(img0, img0G, cv::COLOR_BGR2GRAY);
	cv::cvtColor(img1, img1G, cv::COLOR_BGR2GRAY);
	cv::max(img0G, img1G, comMaxG);  // 对比图像每一个元素灰度值的大小，保留较大的灰度值
	cv::min(img0G, img1G, comMinG);  // 对比图像每一个元素灰度值的大小，保留较小的灰度值
	cv::imshow("comMinG", comMinG);
	cv::imshow("comMaxG", comMaxG);
	cv::waitKey(0);
	// 两个黑白图像像素逻辑运算
	cv::Mat imgB0 = cv::Mat::zeros(200, 200, CV_8UC1);
	cv::Mat imgB1 = cv::Mat::zeros(200, 200, CV_8UC1);
	cv::Rect rect0(50, 50, 100, 100);
	imgB0(rect0) = cv::Scalar(255);   // imgB0的rect0区域像素为255(白色)
	cv::Rect rect1(100, 100, 100, 100);
	imgB1(rect1) = cv::Scalar(255);
	cv::imshow("img0", imgB0);
	cv::imshow("img1", imgB1);
	cv::waitKey(0);
	// 逻辑运算
	cv::Mat myAnd, myOr, myXor, myNot, imgNot;
	cv::bitwise_not(imgB0, myNot);
	cv::bitwise_and(imgB0, imgB1, myAnd);
	cv::bitwise_or(imgB0, imgB1, myOr);
	cv::bitwise_xor(imgB0, imgB1, myXor);
	cv::bitwise_not(img0, imgNot);
	cv::imshow("myNot", myNot);
	cv::imshow("myAnd", myAnd);
	cv::imshow("myOr", myOr);
	cv::imshow("myXor", myXor);
	cv::imshow("img0", img0);
	cv::waitKey(0);
}

void opencv4_advance::Threshold(cv::Mat & img)
{
	cv::Mat gray;
	cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
	cv::Mat img_B, img_B_V, gray_B, gray_B_V, gray_T, gray_T_V, gray_Trunc;
	// 彩色图像二值化
	cv::threshold(img, img_B, 125, 255, cv::THRESH_BINARY);
	cv::threshold(img, img_B_V, 125, 255, cv::THRESH_BINARY_INV);
	cv::imshow("img_B", img_B);
	cv::imshow("img_B_V", img_B_V);
	
	//灰度图BINARY二值化, THRESH_BINARY大于maxVal, 为maxVal，其他值为0
	cv::threshold(gray, gray_B, 125, 255, cv::THRESH_BINARY);
	cv::threshold(gray, gray_B_V, 125, 255, cv::THRESH_BINARY_INV);
	cv::imshow("gray_B", gray_B);
	cv::imshow("gray_B_V", gray_B_V);

	// 灰度图像TOZERO变换, THRESH_TOZERO大于thresh, 为src(x,y), 其他值为0
	cv::threshold(gray, gray_T, 125, 255, cv::THRESH_TOZERO);
	cv::threshold(gray, gray_T_V, 125, 255, cv::THRESH_TOZERO_INV);
	cv::imshow("gray_T", gray_T);
	cv::imshow("gray_T_V", gray_T_V);

	// 灰度图像TRUNC变换, THRESH_TRUNC大于thresh, 为thresh, 其他值为src(x,y)
	cv::threshold(gray, gray_Trunc, 125, 255, cv::THRESH_TRUNC);
	cv::imshow("gray_Trunc", gray_Trunc);

	// 灰度图像大律法和三角形法二值法
	cv::Mat img_Thr_O, img_Thr_T;
	cv::threshold(gray, img_Thr_O, 100, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
	cv::threshold(gray, img_Thr_T, 100, 255, cv::THRESH_BINARY | cv::THRESH_TRIANGLE);
	cv::imshow("img_Thr_O", img_Thr_O);
	cv::imshow("img_Thr_T", img_Thr_T);

	// 灰度图像自适应二值化
	cv::Mat adaptive_mean, adaptive_gauss;
	cv::adaptiveThreshold(gray, adaptive_mean, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, 55, 0);
	cv::adaptiveThreshold(gray, adaptive_gauss, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, 55, 0);
	cv::imshow("adaptive_mean", adaptive_mean);
	cv::imshow("adaptive_gauss", adaptive_gauss);
	cv::waitKey(0);

}

void opencv4_advance::LookupTable(cv::Mat &img)
{
	// lut第一层
	uchar lutFirst[256];
	for (int i = 0; i < 256; i++) {
		if (i <= 100)
			lutFirst[i] = 0;
		if (i > 100 && i <= 200)
			lutFirst[i] = 100;
		if (i > 200)
			lutFirst[i] = 255;
	}
	cv::Mat lutOne(1, 256, CV_8UC1, lutFirst);
	// lut第二层
	uchar lutSecond[256];
	for (int i = 0; i < 256; i++) {
		if (i <= 100)
			lutSecond[i] = 0;
		if (i > 100 && i <= 150)
			lutSecond[i] = 100;
		if (i > 150 && i <= 200)
			lutSecond[i] = 150;
		if (i > 200)
			lutSecond[i] = 255;
	}
	cv::Mat lutTwo(1, 256, CV_8UC1, lutSecond);
	// lut第三层
	uchar lutThird[256];
	for (int i = 0; i < 256; i++) {
		if (i <= 100)
			lutThird[i] = 0;
		if (i > 100 && i <= 200)
			lutThird[i] = 200;
		if (i > 200)
			lutThird[i] = 255;
	}
	cv::Mat lutThree(1, 256, CV_8UC1, lutThird);
	
	// 三通道的LUT矩阵
	std::vector<cv::Mat> mergeMats;
	mergeMats.push_back(lutOne);
	mergeMats.push_back(lutTwo);
	mergeMats.push_back(lutThree);
	cv::Mat LutThree;
	cv::merge(mergeMats, LutThree);
	// 计算图像的查找表
	cv::Mat gray, out0, out1, out2;
	cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
	cv::LUT(gray, lutOne, out0);
	cv::LUT(img, lutOne, out1);
	cv::LUT(img, LutThree, out2);
	cv::imshow("out0", out0);
	cv::imshow("out1", out1);
	cv::imshow("out2", out2);
	cv::waitKey(0);
}

void opencv4_advance::img_concat(cv::Mat & img0, cv::Mat & img1)
{

}

