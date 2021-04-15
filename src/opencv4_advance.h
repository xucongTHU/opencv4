#pragma once
#include <opencv2/opencv.hpp>
class opencv4_advance
{
public:
	void color_space(cv::Mat &img);
	void split_merge(cv::Mat &img);
	void find_Mat_minmax();
	void mean_Stddev();
	void image_operate(cv::Mat &img0, cv::Mat &img1);
	void Threshold(cv::Mat &img);
	void LookupTable(cv::Mat &img);
	void img_concat(cv::Mat &img0, cv::Mat &img1);
private:
	cv::Mat image;
};

