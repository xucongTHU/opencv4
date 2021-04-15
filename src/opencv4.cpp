#include "opencv4.h"
#include <iostream>

using namespace std;
void opencv4::image_property()
{
	// cv::Mat img;
	// 创建640行, 480列的3通道矩阵, 数据类型8-bit unsigned char
	cv::Mat img(cv::Size(460, 640), CV_8UC3, cv::Scalar(255, 0, 0));
	// img.create(3, 5, CV_8UC3);
	// 设置3个通道的值，分别为1,2,3
	// img.setTo(cv::Scalar(1,2,3));
	cv::imshow("image", img);
	cv::waitKey(0);
	// std::cout << "mat " << "\n" << img << std::endl;
	std::cout << "图像的通道 " << img.channels() << std::endl;  // 3
	std::cout << "图像的宽度 " << img.cols << std::endl;		   // 4
	std::cout << "图像的高度 " << img.rows << std::endl;		   // 6
	std::cout << "图像的维度 " << img.dims << std::endl;        // 2
	cout << "每个元素的字节数 " << img.elemSize() << endl;
	cout << "数据类型 " << (img.elemSize() / img.channels()) * 8 << endl;
}

void opencv4::Mat_create()
{
	// 1. Size(cols, rows)创建, 列在前，行在后
	cv::Mat image(cv::Size(2, 3), CV_8UC3, cv::Scalar(1, 2, 3));
	std::cout << "Mat矩阵 " << std::endl << image << std::endl;
	// 2. 已有矩阵构造
	cv::Mat image1(image);
	std::cout << "复制构造Mat类 " << std::endl << image1 << std::endl;
	// 3. 构造已有Mat类的子类, mat(m, rowRange, colRange)
	cv::Mat image2(image, cv::Range(0, 3), cv::Range::all());
	std::cout << "Mat类的子类 " << std::endl << image2 << std::endl;
}

void opencv4::Mat_Value()
{
	// Mat类的赋值, Scalar变量的个数大于通道数, 超过部分不读取，小于通道数，以0补充
	cv::Mat image(cv::Size(2, 3), CV_8UC3, cv::Scalar(1, 2, 3));
	std::cout << "构造Mat赋值 " << std::endl << image << std::endl;
	image = cv::Mat::ones(cv::Size(2, 3), CV_8UC3);
	std::cout << "构造Mat赋值 " << std::endl << image << std::endl;
	std::cout << "Mat访问 " << image.at<cv::Vec3b>(2) << std::endl;
	/*
	// 访问数组, 第二行指向第一个元素第一个通道的指针
	std::cout << "指针访问 " << image.ptr<cv::Vec3b>(2) << std::endl;
	// 类型转换
	cv::Mat m1;
	image.convertTo(m1, CV_16FC3, 1, 0);
	std::cout << m1.at<cv::Vec3s>(2, 1) << std::endl;
	cv::Mat m2(m1);
	m2.push_back(m1);
	std::cout << "Mat元素添加 " << std::endl << m2 << std::endl;
	*/
	// Mat赋值
	cv::Mat a = (cv::Mat_<int>(3,3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);
	cv::Mat b = (cv::Mat_<double>(2, 3) << 1.0, 2.1, 3.2, 4.0, 5.1, 6.2);
	cout << "枚举法赋值a " << endl << a << endl;
	cout << "枚举法赋值b " << endl << b << endl;
	cv::Mat c = cv::Mat_<int>(3, 3);
	for (int i = 0; i < c.rows; i++) {
		for (int j = 0; j < c.cols; j++) {
			c.at<int>(i, j) = i + j;
		}
	}
	cout << "循环法赋值c " << endl << c << endl;

	float a1[8] = { 5,6,7,8,1,2,3,4 };
	cv::Mat b1 = cv::Mat(2, 2, CV_32FC2, a1);
	cv::Mat c1 = cv::Mat(2, 4, CV_32FC1, a1);
	cout << "数组赋值b1 " << endl << b1 << endl;
	cout << "数组赋值c1 " << endl << c1 << endl;

}

void opencv4::Mat_Operate()
{
	// Mat类的加减乘除
	cv::Mat a = (cv::Mat_<int>(3, 3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);
	cv::Mat b = (cv::Mat_<int>(3, 3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);
	cv::Mat c = (cv::Mat_<double>(3, 3) << 1.0, 2.1, 3.2, 4.0, 5.1, 6.2, 2, 2, 2);
	cv::Mat d, e, f, g;
	d = a + b;
	e = a - b;
	f = 2 * a;
	g = c / 2.0;
	g = b.mul(a);
	cout << "Mat算术运算d= \n" << d << endl << "e= \n" << e << endl << "f= \n" << f << endl << "g= \n" << g << endl;
}

void opencv4::Mat_element()
{
	// at方法读取Mat类矩阵元素
	cv::Mat a = (cv::Mat_<uchar>(3, 3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);
	int value = (int)a.at<uchar>(0, 0);
	cout << "单通道Mat元素 " << value << endl;
	cv::Mat b(3, 4, CV_8UC3, cv::Scalar(0, 0, 1));
	cv::Vec3b vc3 = b.at<cv::Vec3b>(0, 0);
	int first = (int)vc3.val[0];
	int second = (int)vc3.val[1];
	int third = (int)vc3.val[2];
	cout << "Mat " << endl << b << endl;
	cout << "多通道Mat元素\n" << first << endl << second << endl << third << endl;
	
	// ptr方法读取Mat元素
	for (int i = 0; i < b.rows; i++) {
		uchar* ptr = b.ptr<uchar>(i);
		for (int j = 0; j < b.cols*b.channels(); j++) {
			printf("Ptr[%d][%d] = %d\n", i, j,(int)ptr[j]);
		}
	}
	// Ptr指针读取第2行第3个数
	cout << (int)b.ptr<uchar>(1)[2] << endl;
	// 迭代器访问Mat类矩阵元素
	cv::MatIterator_<uchar> it = a.begin<uchar>();
	cv::MatIterator_<uchar> it_end = a.end<uchar>();
	for (int i = 0; it != it_end; it++) {
		cout << (int)(*it) << " ";
		if ((++i%a.cols) == 0)    // 换行, 3x3输出
			cout << endl;
	}
	// 矩阵元素的地址定位方式访问元素
	// (int)(*(b.data + b.step[0] * row + b.step[1] * col + channel));
	int element = (int)(*(b.data + b.step[0] * 1 + b.step[1] * 1 + 1));
	cout << "Mat元素地址定位 " << element << endl;
}

void opencv4::video_Read()
{
	
	cv::VideoCapture video(0);
	while (true)
	{
		cv::Mat frame, frame_gray;
		// 获取当前时刻相机拍摄到的图像
		video >> frame;
		// 视频的每一帧进行图像预处理，转化为灰度图
		cv::cvtColor(frame, frame_gray, cv::COLOR_BGR2GRAY);
		// 高斯模糊
		cv::Mat frame_gauss;
		cv::GaussianBlur(frame_gray, frame_gauss, cv::Size(5, 5), 0, 0);
		// 边缘检测
		cv::Mat dx, dy;
		cv::Scharr(frame_gauss, dx, CV_16S, 1, 0);
		cv::Scharr(frame_gauss, dy, CV_16S, 0, 1);
		cv::Mat frame_canny;
		cv::Canny(dx, dy, frame_canny, 1, 3);
		cv::imshow("video", frame_canny);
		cv::waitKey(1000 / video.get(cv::CAP_PROP_FPS));
		cout << "FPS: " << video.get(cv::CAP_PROP_FPS) << endl;
		printf("width=%d, hight=%d\n", frame_gray.cols,frame_gray.rows);
	}
}

void opencv4::image_save()
{
	cv::Mat img(480, 640, CV_8UC4);
	CV_Assert(img.channels() == 4);
	for (int i = 0; i < img.rows; ++i) {
		for (int j = 0; j < img.cols; ++j) {
			cv::Vec4b& bgra = img.at<cv::Vec4b>(i, j);
			// 每个像素的4个通道赋值
			bgra[0] = UCHAR_MAX;  // 蓝色通道
			bgra[1] = cv::saturate_cast<uchar>((float(img.cols - j)) / ((float)img.cols)*UCHAR_MAX);  //绿色通道
			bgra[2] = cv::saturate_cast<uchar>((float(img.rows - i)) / ((float)img.rows)*UCHAR_MAX);  //红色通道
			bgra[3] = cv::saturate_cast<uchar>(0.5*(bgra[1] + bgra[2]));  //Alpha通道
		}
	}
	vector<int> compression_params;
	compression_params.push_back(cv::IMWRITE_PNG_COMPRESSION);
	compression_params.push_back(9);
	bool result = cv::imwrite("alpha.png", img, compression_params);
	if (!result) {
		cout << "保存成PNG格式图像失败" << endl;
	}

	cout << "保存成功" << endl;
}

void opencv4::video_save()
{
	cv::Mat img;
	cv::VideoCapture video(0);
	// 读取视频
	if (!video.isOpened())
	{
		cout << "打开摄像头失败" << endl;
	}
	video >> img;  // 获取图像
	// 检测是否成功获取图像
	if (!img.empty())
	{
		cout << "获取图像成功" << endl;
	}

	bool isColor = (img.type() == CV_8UC3);
	// 视频保存
	cv::VideoWriter writer;
	// 视频的编码格式
	int codec = cv::VideoWriter::fourcc('M', 'J', 'P', 'G');
	double fps = 25.0;
	string filename = "live.avi";
	writer.open(filename, codec, fps, img.size(), isColor);  // 创建保存视频文件的视频流
	if (!writer.isOpened())
	{
		cout << "打开视频失败，请确认是否合法" << endl;
	}
	while (true)
	{
		if (!video.read(img)) {
			cout << "摄像头断开或者视频读取完成" << endl;
			break;
		}
		//writer << img;
		writer.write(img);
		cv::imshow("Live", img);
		char c = cv::waitKey(50);
		if (c == 27)
			break;
	}
	video.release();
	writer.release();

}

void opencv4::xml_yaml_save()
{
	// XML是元标记语言，YMAL是以数据为中心的语言
	system("color F0");
	//string filename = "datas.xml";
	string filename = "datas.yaml";
	cv::FileStorage fwrite(filename, cv::FileStorage::WRITE);
	// 存入矩阵Mat类型的数据
	cv::Mat mat = cv::Mat::eye(3, 3, CV_8U);
	fwrite.write("mat", mat);
	//fwrite << "mat" << mat;
	float x = 100;
	fwrite << "x" << x;
	// 存入字符串数据，节点名称为str
	string str = "Learn OpenCV4";
	fwrite << "str" << str;
	// 存入数组，节点名称为number_array
	fwrite << "number_array" << "[" << 4 << 5 << 6 << "]";
	// 存入多节点，节点名称为multi_nodes
	fwrite << "multi_nodes" << "{" << "month" << 8 << "day" << 28 << "year" << 2019 << "time" << "[" << 0 << 1 << 2 << 3 << "]" << "}";
	// 关闭文件
	fwrite.release();

	// 以读取的模式打开文件
	cv::FileStorage fread(filename, cv::FileStorage::READ);
	if (!fread.isOpened()) {
		cout << "打开文件失败，请确认文件名称是否正确" << endl;
	}
	// 读取文件中的数据
	float xRead;
	fread["x"] >> xRead;
	cout << "x=" << xRead << endl;
	// 读取字符串数据
	string strRead;
	fread["str"] >> strRead;
	cout << "str=" << strRead << endl;
	// 读取含多个数据的number_array节点
	cv::FileNode filenode = fread["number_array"];
	cout << "number_array=[";
	// 循环遍历每个数据
	for (cv::FileNodeIterator i = filenode.begin(); i != filenode.end(); i++) {
		float a;
		*i >> a;
		cout << a << " ";
	}
	cout << "]" << endl;
	// 读取Mat类
	cv::Mat matRead;
	fread["mat="] >> matRead;
	cout << "mat=" << matRead << endl;
	// 读取多个子节点的节点数据，不使用FileNode和迭代器读取
	cv::FileNode filenode1 = fread["multi_nodes"];
	int month = (int)filenode1["month"];
	int day = (int)filenode1["day"];
	int year = (int)filenode1["year"];
	cout << "multi_nodes:" << endl << "month=" << month << " day=" << day << " year=" << year << endl;
	cout << "time=[";
	for (int i = 0; i < 4; i++) {
		int a = (int)filenode1["time"][i];
		cout << a << " ";
	}
	cout << "]" << endl;
	// 关闭文件
	fread.release();

}
