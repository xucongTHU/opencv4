#include <opencv2/opencv.hpp>
#include <iostream>
#include "opencv4.h"
#include "opencv4_advance.h"

using namespace std;
int main(int argc, char** argv)
{
	
	cv::Mat image;
	image = cv::imread("D:/OrangePlan/ADAS/Algorithm/opencv4/data/lane.jpg");
	if (image.empty())
	{
		std::cout << "请输入正确的图片" << std::endl;
		return -1;
	}
	cv::Mat image1;
	image1 = cv::imread("D:/OrangePlan/ADAS/Algorithm/opencv4/data/noobcv.jpg");
	/*
	cv::namedWindow("test", cv::WINDOW_AUTOSIZE);
	cv::imshow("test", image);
	cv::waitKey(0);
	*/
	// 类函数调用, 在::运算符之前必须使用类名。调用成员函数是在对象上使用点运算符(.)
	/*opencv4 opencv;              // 创建一个对象
	opencv.opencv4_test(image);  // 调用类函数成员，图像显示
	opencv.image_property();
	opencv.Mat_create();
	opencv.Mat_Value();*/
	
	/* opencv4 基础篇 */
	opencv4_test opencv4_test;
	//opencv4_test.opencv4_test1(image);
	//opencv4_test.image_property();
	//opencv4_test.Mat_create();
	//opencv4_test.Mat_Value();
	//opencv4_test.Mat_Operate();
	//opencv4_test.Mat_element();
	//opencv4_test.video_Read();
	//opencv4_test.image_save();
	//opencv4_test.video_save();
	//opencv4_test.xml_yaml_save();

	/* opencv4 进阶篇 */
	opencv4_advance opencv4_advance;
	//opencv4_advance.color_space(image);
	//opencv4_advance.split_merge(image);
	//opencv4_advance.find_Mat_minmax();
	//opencv4_advance.mean_Stddev();
	//opencv4_advance.image_operate(image, image1);
	//opencv4_advance.Threshold(image);
	opencv4_advance.LookupTable(image);

	return 0;
}

