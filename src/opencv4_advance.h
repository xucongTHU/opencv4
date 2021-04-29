#pragma once
#include <opencv2/opencv.hpp>

namespace opencv4_advance {
/* Í¼ÏñµÄ»ù±¾²Ù×÷ */
class opencv4_advance_operation
{
public:
	void color_space(cv::Mat &img);
	void split_merge(cv::Mat &img);
	void find_Mat_minmax();
	void mean_Stddev();
	void image_operate(cv::Mat &img0, cv::Mat &img1);
	void Threshold(cv::Mat &img);
	void LookupTable(cv::Mat &img);
	void img_concat();
	void img_transform(cv::Mat &img);
	void img_rol(cv::Mat &img0, cv::Mat &img1);
	void Pyramid(cv::Mat &img);
private:
	cv::Mat image;
};

/* Í¼ÏñÂË²¨ */
class opencv4_advance_imgfilter
{
public:
	void img_filter(cv::Mat &img);
	void img_noise(cv::Mat &img, int n);
};

} // namespace opencv4_advance
