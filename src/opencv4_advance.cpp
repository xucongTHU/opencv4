#include "opencv4_advance.h"
#include <vector>

using namespace std;
void opencv4_advance::color_space(cv::Mat &img)
{
	cv::Mat gray, HSV, YUV, Lab, img32;
	img.convertTo(img32, CV_32F, 1.0 / 255); // ��CV_8U����ת��ΪCV_32F����
	//img32.convertTo(img, CV_8U, 255);
	cv::cvtColor(img32, HSV, cv::COLOR_BGR2HSV);
	cv::cvtColor(img32, YUV, cv::COLOR_BGR2YUV);
	cv::cvtColor(img32, Lab, cv::COLOR_BGR2Lab);
	cv::cvtColor(img32, gray, cv::COLOR_BGR2GRAY);
	
	cv::imshow("ԭͼ", img32);
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
	cv::Mat imgs0, imgs1, imgs2;  // ���ڴ���������͵Ľ��
	cv::Mat imgv0, imgv1, imgv2;  // ���ڴ��vector���͵Ľ��
	cv::Mat result0, result1, result2;  // ��ͨ���ϲ��Ľ��

	// ������������Ķ�ͨ��������ϲ�
	cv::Mat imgs[3];
	cv::split(img, imgs);
	imgs0 = imgs[0];
	imgs1 = imgs[1];
	imgs2 = imgs[2];
	//cv::imshow("RGB-Bͨ��", imgs0);
	//cv::imshow("RGB-Gͨ��", imgs1);
	//cv::imshow("RGB-Rͨ��", imgs2);
	imgs[2] = img;  // �������е�ͼ��ͨ������ɲ�һ��
	cv::merge(imgs, 3, result0);
	//cv::imshow("result0", result0);  // imshow�����ʾ4��ͨ��, ��ʹ��Image Watch�鿴, debug�����öϵ㣬veiw->��������->Image Watch
	cv::Mat zero = cv::Mat::zeros(img.rows, img.cols, CV_8UC1);
	imgs[0] = zero;
	imgs[2] = zero;
	cv::merge(imgs, 3, result1);
	cv::imshow("result1", result1);  // �ϲ���ʾ���

	// ����vector�����Ķ�ͨ��������ϲ�
	std::vector<cv::Mat> imgv;
	cv::split(HSV, imgv);
	imgv0 = imgv.at(0);
	imgv1 = imgv.at(1);
	imgv2 = imgv.at(2);
	//cv::imshow("HSV-Hͨ��", imgv0);
	//cv::imshow("HSV-Sͨ��", imgv1);
	//cv::imshow("HSV-Vͨ��", imgv2);
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
	cout << "img�����ֵ��: " << maxVal << " " << "�ھ�����λ��: " << maxIdx << endl;
	cout << "img����Сֵ��: " << minVal << " " << "�ھ�����λ��: " << minIdx << endl;

	// Ѱ�Ҷ�ͨ�������е���ֵ
	cv::Mat imgs_re = imgs.reshape(1, 4);  // ����ͨ�������ɵ�ͨ������
	cv::minMaxLoc(imgs_re, &minVal, &maxVal, &minIdx, &maxIdx);
	cout << "imgs�����ֵ��: " << maxVal << " " << "�ھ�����λ��: " << maxIdx << endl;
	cout << "imgs����Сֵ��: " << minVal << " " << "�ھ�����λ��: " << minIdx << endl;
}

void opencv4_advance::mean_Stddev()
{
	float a[12] = { 1,2,3,4,5,10,6,7,8,9,10,0 };
	cv::Mat img = cv::Mat(3, 4, CV_32FC1, a);
	cv::Mat imgs = cv::Mat(2, 3, CV_32FC2, a);
	cout << "mat" << imgs << endl;
	cout << "��mean��ȡͼ���ƽ��ֵ" << endl;
	cv::Scalar mymean;
	mymean = cv::mean(imgs);   // mean����û�з���ֵ
	cout << "imgsƽ��ֵ=" << mymean << endl;
	cout << "imgs��һͨ����ƽ��ֵ=" << mymean[0] << " "
		<< "imgs�ڶ�ͨ����ƽ��ֵ=" << mymean[1] << endl << endl;
	cout << "��meanStsDevͬʱ��ȡͼ���ƽ��ֵ�ͱ�׼��" << endl;
	cv::Mat mymeanMat, myStddevMat;
	cv::meanStdDev(img, mymeanMat, myStddevMat);
	cout << "imgƽ��ֵ=" << mymeanMat << endl;
	cout << "img��׼��=" << myStddevMat << endl;
	cv::meanStdDev(imgs, mymeanMat, myStddevMat);
	cout << "imgsƽ��ֵ=" << mymeanMat << endl;
	cout << "imgs��׼��=" << myStddevMat << endl;
}

void opencv4_advance::image_operate(cv::Mat & img0, cv::Mat & img1)
{
	// �������Ҷ�ͼ����бȽϼ���
	cv::Mat img0G, img1G, comMinG, comMaxG;
	cv::cvtColor(img0, img0G, cv::COLOR_BGR2GRAY);
	cv::cvtColor(img1, img1G, cv::COLOR_BGR2GRAY);
	cv::max(img0G, img1G, comMaxG);  // �Ա�ͼ��ÿһ��Ԫ�ػҶ�ֵ�Ĵ�С�������ϴ�ĻҶ�ֵ
	cv::min(img0G, img1G, comMinG);  // �Ա�ͼ��ÿһ��Ԫ�ػҶ�ֵ�Ĵ�С��������С�ĻҶ�ֵ
	cv::imshow("comMinG", comMinG);
	cv::imshow("comMaxG", comMaxG);
	cv::waitKey(0);
	// �����ڰ�ͼ�������߼�����
	cv::Mat imgB0 = cv::Mat::zeros(200, 200, CV_8UC1);
	cv::Mat imgB1 = cv::Mat::zeros(200, 200, CV_8UC1);
	cv::Rect rect0(50, 50, 100, 100);
	imgB0(rect0) = cv::Scalar(255);   // imgB0��rect0��������Ϊ255(��ɫ)
	cv::Rect rect1(100, 100, 100, 100);
	imgB1(rect1) = cv::Scalar(255);
	cv::imshow("img0", imgB0);
	cv::imshow("img1", imgB1);
	cv::waitKey(0);
	// �߼�����
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
	// ��ɫͼ���ֵ��
	cv::threshold(img, img_B, 125, 255, cv::THRESH_BINARY);
	cv::threshold(img, img_B_V, 125, 255, cv::THRESH_BINARY_INV);
	cv::imshow("img_B", img_B);
	cv::imshow("img_B_V", img_B_V);
	
	//�Ҷ�ͼBINARY��ֵ��, THRESH_BINARY����maxVal, ΪmaxVal������ֵΪ0
	cv::threshold(gray, gray_B, 125, 255, cv::THRESH_BINARY);
	cv::threshold(gray, gray_B_V, 125, 255, cv::THRESH_BINARY_INV);
	cv::imshow("gray_B", gray_B);
	cv::imshow("gray_B_V", gray_B_V);

	// �Ҷ�ͼ��TOZERO�任, THRESH_TOZERO����thresh, Ϊsrc(x,y), ����ֵΪ0
	cv::threshold(gray, gray_T, 125, 255, cv::THRESH_TOZERO);
	cv::threshold(gray, gray_T_V, 125, 255, cv::THRESH_TOZERO_INV);
	cv::imshow("gray_T", gray_T);
	cv::imshow("gray_T_V", gray_T_V);

	// �Ҷ�ͼ��TRUNC�任, THRESH_TRUNC����thresh, Ϊthresh, ����ֵΪsrc(x,y)
	cv::threshold(gray, gray_Trunc, 125, 255, cv::THRESH_TRUNC);
	cv::imshow("gray_Trunc", gray_Trunc);

	// �Ҷ�ͼ����ɷ��������η���ֵ��
	cv::Mat img_Thr_O, img_Thr_T;
	cv::threshold(gray, img_Thr_O, 100, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
	cv::threshold(gray, img_Thr_T, 100, 255, cv::THRESH_BINARY | cv::THRESH_TRIANGLE);
	cv::imshow("img_Thr_O", img_Thr_O);
	cv::imshow("img_Thr_T", img_Thr_T);

	// �Ҷ�ͼ������Ӧ��ֵ��
	cv::Mat adaptive_mean, adaptive_gauss;
	cv::adaptiveThreshold(gray, adaptive_mean, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, 55, 0);
	cv::adaptiveThreshold(gray, adaptive_gauss, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, 55, 0);
	cv::imshow("adaptive_mean", adaptive_mean);
	cv::imshow("adaptive_gauss", adaptive_gauss);
	cv::waitKey(0);

}

void opencv4_advance::LookupTable(cv::Mat &img)
{
	// lut��һ��
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
	// lut�ڶ���
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
	// lut������
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
	
	// ��ͨ����LUT����
	std::vector<cv::Mat> mergeMats;
	mergeMats.push_back(lutOne);
	mergeMats.push_back(lutTwo);
	mergeMats.push_back(lutThree);
	cv::Mat LutThree;
	cv::merge(mergeMats, LutThree);
	// ����ͼ��Ĳ��ұ�
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

void opencv4_advance::img_concat()
{
	// ��������ĺ�������
	cv::Mat matArray[] = { cv::Mat(1,2,CV_32FC1,cv::Scalar(1)),
						   cv::Mat(1,2,CV_32FC1,cv::Scalar(2))};
	cv::Mat vout, hout;
	cv::vconcat(matArray, 2, vout);
	cout << "ͼ��������������: " << endl << vout << endl;
	cv::hconcat(matArray, 2, hout);
	cout << "ͼ�������������: " << endl << vout << endl;
	// ����ĺ���ƴ��
	cv::Mat A = (cv::Mat_<float>(2, 2) << 1, 7, 2, 8);
	cv::Mat B = (cv::Mat_<float>(2, 2) << 4, 10, 5, 11);
	cv::Mat vC, hC;
	cv::vconcat(A, B, vC);
	cv::hconcat(A, B, hC);
	cout << "���ͼ����������: " << endl << vC << endl;
	cout << "���ͼ���������: " << endl << hC << endl;

}

void opencv4_advance::img_transform(cv::Mat &img)
{
	// ͸�ӱ任�����ڻ����Ӿ������о�, ͨ��3x3�ı任����R����͸�ӱ任
	cv::Point2f src_points[4];
	cv::Point2f dst_points[4];
	// ͨ��Image Watch�鿴�Ķ�ά��4���ǵ�����
	src_points[0] = cv::Point2f(94.0, 374.0);
	src_points[1] = cv::Point2f(507.0, 380.0);
	src_points[2] = cv::Point2f(1.0, 623.0);
	src_points[3] = cv::Point2f(627.0, 627.0);
	// ����͸�ӱ任���ά��4���ǵ������
	dst_points[0] = cv::Point2f(0.0, 0.0);
	dst_points[1] = cv::Point2f(627.0, 0.0);
	dst_points[2] = cv::Point2f(0.0, 627.0);
	dst_points[3] = cv::Point2f(627.0, 627.0);
	cv::Mat Rotation, img_warp;
	Rotation = cv::getPerspectiveTransform(src_points, dst_points);  // ����͸�ӱ任����
	cv::warpPerspective(img, img_warp, Rotation, img.size());  // ͸�ӱ任ͶӰ
	cv::imshow("img_warp", img_warp);
	cv::waitKey(0);

}

void opencv4_advance::img_rol(cv::Mat & img0, cv::Mat & img1)
{
	// ����Ȥ����
	cv::Mat ROI1, ROI2, ROI2_copy, mask, img2, img_copy, img_copy2;
	cv::resize(img1, mask, cv::Size(200, 200));
	img2 = img0; // ǳ����
	// ��������ַ�ʽ
	img0.copyTo(img_copy2);
	cv::copyTo(img0, img_copy, img0);   // mask��ģ������ĳһλ�ò�Ϊ0,����ԭͼ����ͬλ�õ�Ԫ�ص���ͼ��
	// ������ͼ�н�ȡROI�ķ�ʽ
	cv::Rect rect(206, 206, 200, 200);
	ROI1 = img0(rect);  // ��ͼ
	ROI2 = img0(cv::Range(300, 500), cv::Range(300, 500));  // �ڶ��ֽ�ͼ��ʽ
	img0(cv::Range(300, 500), cv::Range(300, 500)).copyTo(ROI2_copy);  // ���
	mask.copyTo(ROI1);
	cv::imshow("����noobcv��ͼ��", img0);
	cv::imshow("ROI��ROI2��Ӱ��", ROI2);
	cv::imshow("�����ROI2_copy", ROI2_copy);
	cv::circle(img0, cv::Point(300, 300), 20, cv::Scalar(0, 0, 255), -1);
	cv::imshow("ǳ������img2", img2);
	cv::imshow("�����img_copy", img_copy);
	cv::imshow("�����img_copy2", img_copy2);
	cv::imshow("��ͼ��ROI1��Ӱ��", ROI1);
	cv::waitKey(0);

}

