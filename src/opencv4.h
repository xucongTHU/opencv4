#pragma once
#include <opencv2/opencv.hpp>

namespace opencv4_basic {
class opencv4_basic
{
public:
	cv::Mat image;
	// opencv4 基础操作
	void image_property();
	void Mat_create();
	void Mat_Value();
	void Mat_Operate();
	void Mat_element();
	void video_Read();
	void image_save();
	void video_save();
	void xml_yaml_save();
	/*
	void opencv4_test(cv::Mat &img)
	{
		img_private = img;                      // 公有区域定义相关函数，调用私有区域定义的变量
		cv::imshow("lena", img_private);
		cv::waitKey(0);
	}*/
	//friend void opencv(opencv4_basic opencv);   // 友元函数
private:
	cv::Mat img_private;                  // 私有区域定义数据, 只能被类或友元函数访问
};

//public继承, 基类的public成员，派生类仍然是public, 基类的private成员不能被派生类访问

}  // namespace opencv4_basic