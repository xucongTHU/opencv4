#include "opencv4.h"
#include "opencv4_advance.h"

#include <iostream>

#include <opencv2/opencv.hpp>


using namespace std;
int main(int argc, char** argv)
{
	
	cv::Mat image;
	image = cv::imread("D:/OrangePlan/ADAS/Algorithm/opencv4/data/lena.png");
	if (image.empty())
	{
		std::cout << "请输入正确的图片" << std::endl;
		return -1;
	}
	cv::Mat image1;
	image1 = cv::imread("D:/OrangePlan/ADAS/Algorithm/opencv4/data/noobcv.jpg");

	// 类函数调用, 在::运算符之前必须使用类名。调用成员函数是在对象上使用点运算符(.)
	
	/* opencv4 基础篇 */
	opencv4_basic::opencv4_basic opencv4_basic;
	//opencv4_basic.opencv4_test1(image);
	//opencv4_basic.image_property();
	//opencv4_basic.Mat_create();
	//opencv4_basic.Mat_Value();
	//opencv4_basic.Mat_Operate();
	//opencv4_basic.Mat_element();
	//opencv4_basic.video_Read();
	//opencv4_basic.image_save();
	//opencv4_basic.video_save();
	//opencv4_basic.xml_yaml_save();

	/* opencv4 进阶篇 */
	// 图像的基本操作
	opencv4_advance::opencv4_advance_operation opencv4_advance_operation;
	//opencv4_advance_operation.color_space(image);
	//opencv4_advance_operation.split_merge(image);
	//opencv4_advance_operation.find_Mat_minmax();
	//opencv4_advance_operation.mean_Stddev();
	//opencv4_advance_operation.image_operate(image, image1);
	//opencv4_advance_operation.Threshold(image);
	//opencv4_advance_operation.LookupTable(image);
	//opencv4_advance_operation.img_concat();
	//opencv4_advance_operation.img_transform(image1);
	//opencv4_advance_operation.img_rol(image, image1);
	//opencv4_advance_operation.Pyramid(image);

	// 图像的滤波
	opencv4_advance::opencv4_advance_imgfilter opencv4_advance_imgfilter;
	//opencv4_advance_imgfilter.img_filter(image);
	opencv4_advance_imgfilter.img_noise(image, 10000);
	return 0;
}

