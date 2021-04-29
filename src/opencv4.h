#pragma once
#include <opencv2/opencv.hpp>

namespace opencv4_basic {
class opencv4_basic
{
public:
	cv::Mat image;
	// opencv4 ��������
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
		img_private = img;                      // ������������غ���������˽��������ı���
		cv::imshow("lena", img_private);
		cv::waitKey(0);
	}*/
	//friend void opencv(opencv4_basic opencv);   // ��Ԫ����
private:
	cv::Mat img_private;                  // ˽������������, ֻ�ܱ������Ԫ��������
};

//public�̳�, �����public��Ա����������Ȼ��public, �����private��Ա���ܱ����������

}  // namespace opencv4_basic