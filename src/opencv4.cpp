#include "opencv4.h"
#include <iostream>

using namespace std;
void opencv4::image_property()
{
	// cv::Mat img;
	// ����640��, 480�е�3ͨ������, ��������8-bit unsigned char
	cv::Mat img(cv::Size(460, 640), CV_8UC3, cv::Scalar(255, 0, 0));
	// img.create(3, 5, CV_8UC3);
	// ����3��ͨ����ֵ���ֱ�Ϊ1,2,3
	// img.setTo(cv::Scalar(1,2,3));
	cv::imshow("image", img);
	cv::waitKey(0);
	// std::cout << "mat " << "\n" << img << std::endl;
	std::cout << "ͼ���ͨ�� " << img.channels() << std::endl;  // 3
	std::cout << "ͼ��Ŀ�� " << img.cols << std::endl;		   // 4
	std::cout << "ͼ��ĸ߶� " << img.rows << std::endl;		   // 6
	std::cout << "ͼ���ά�� " << img.dims << std::endl;        // 2
	cout << "ÿ��Ԫ�ص��ֽ��� " << img.elemSize() << endl;
	cout << "�������� " << (img.elemSize() / img.channels()) * 8 << endl;
}

void opencv4::Mat_create()
{
	// 1. Size(cols, rows)����, ����ǰ�����ں�
	cv::Mat image(cv::Size(2, 3), CV_8UC3, cv::Scalar(1, 2, 3));
	std::cout << "Mat���� " << std::endl << image << std::endl;
	// 2. ���о�����
	cv::Mat image1(image);
	std::cout << "���ƹ���Mat�� " << std::endl << image1 << std::endl;
	// 3. ��������Mat�������, mat(m, rowRange, colRange)
	cv::Mat image2(image, cv::Range(0, 3), cv::Range::all());
	std::cout << "Mat������� " << std::endl << image2 << std::endl;
}

void opencv4::Mat_Value()
{
	// Mat��ĸ�ֵ, Scalar�����ĸ�������ͨ����, �������ֲ���ȡ��С��ͨ��������0����
	cv::Mat image(cv::Size(2, 3), CV_8UC3, cv::Scalar(1, 2, 3));
	std::cout << "����Mat��ֵ " << std::endl << image << std::endl;
	image = cv::Mat::ones(cv::Size(2, 3), CV_8UC3);
	std::cout << "����Mat��ֵ " << std::endl << image << std::endl;
	std::cout << "Mat���� " << image.at<cv::Vec3b>(2) << std::endl;
	/*
	// ��������, �ڶ���ָ���һ��Ԫ�ص�һ��ͨ����ָ��
	std::cout << "ָ����� " << image.ptr<cv::Vec3b>(2) << std::endl;
	// ����ת��
	cv::Mat m1;
	image.convertTo(m1, CV_16FC3, 1, 0);
	std::cout << m1.at<cv::Vec3s>(2, 1) << std::endl;
	cv::Mat m2(m1);
	m2.push_back(m1);
	std::cout << "MatԪ����� " << std::endl << m2 << std::endl;
	*/
	// Mat��ֵ
	cv::Mat a = (cv::Mat_<int>(3,3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);
	cv::Mat b = (cv::Mat_<double>(2, 3) << 1.0, 2.1, 3.2, 4.0, 5.1, 6.2);
	cout << "ö�ٷ���ֵa " << endl << a << endl;
	cout << "ö�ٷ���ֵb " << endl << b << endl;
	cv::Mat c = cv::Mat_<int>(3, 3);
	for (int i = 0; i < c.rows; i++) {
		for (int j = 0; j < c.cols; j++) {
			c.at<int>(i, j) = i + j;
		}
	}
	cout << "ѭ������ֵc " << endl << c << endl;

	float a1[8] = { 5,6,7,8,1,2,3,4 };
	cv::Mat b1 = cv::Mat(2, 2, CV_32FC2, a1);
	cv::Mat c1 = cv::Mat(2, 4, CV_32FC1, a1);
	cout << "���鸳ֵb1 " << endl << b1 << endl;
	cout << "���鸳ֵc1 " << endl << c1 << endl;

}

void opencv4::Mat_Operate()
{
	// Mat��ļӼ��˳�
	cv::Mat a = (cv::Mat_<int>(3, 3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);
	cv::Mat b = (cv::Mat_<int>(3, 3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);
	cv::Mat c = (cv::Mat_<double>(3, 3) << 1.0, 2.1, 3.2, 4.0, 5.1, 6.2, 2, 2, 2);
	cv::Mat d, e, f, g;
	d = a + b;
	e = a - b;
	f = 2 * a;
	g = c / 2.0;
	g = b.mul(a);
	cout << "Mat��������d= \n" << d << endl << "e= \n" << e << endl << "f= \n" << f << endl << "g= \n" << g << endl;
}

void opencv4::Mat_element()
{
	// at������ȡMat�����Ԫ��
	cv::Mat a = (cv::Mat_<uchar>(3, 3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);
	int value = (int)a.at<uchar>(0, 0);
	cout << "��ͨ��MatԪ�� " << value << endl;
	cv::Mat b(3, 4, CV_8UC3, cv::Scalar(0, 0, 1));
	cv::Vec3b vc3 = b.at<cv::Vec3b>(0, 0);
	int first = (int)vc3.val[0];
	int second = (int)vc3.val[1];
	int third = (int)vc3.val[2];
	cout << "Mat " << endl << b << endl;
	cout << "��ͨ��MatԪ��\n" << first << endl << second << endl << third << endl;
	
	// ptr������ȡMatԪ��
	for (int i = 0; i < b.rows; i++) {
		uchar* ptr = b.ptr<uchar>(i);
		for (int j = 0; j < b.cols*b.channels(); j++) {
			printf("Ptr[%d][%d] = %d\n", i, j,(int)ptr[j]);
		}
	}
	// Ptrָ���ȡ��2�е�3����
	cout << (int)b.ptr<uchar>(1)[2] << endl;
	// ����������Mat�����Ԫ��
	cv::MatIterator_<uchar> it = a.begin<uchar>();
	cv::MatIterator_<uchar> it_end = a.end<uchar>();
	for (int i = 0; it != it_end; it++) {
		cout << (int)(*it) << " ";
		if ((++i%a.cols) == 0)    // ����, 3x3���
			cout << endl;
	}
	// ����Ԫ�صĵ�ַ��λ��ʽ����Ԫ��
	// (int)(*(b.data + b.step[0] * row + b.step[1] * col + channel));
	int element = (int)(*(b.data + b.step[0] * 1 + b.step[1] * 1 + 1));
	cout << "MatԪ�ص�ַ��λ " << element << endl;
}

void opencv4::video_Read()
{
	
	cv::VideoCapture video(0);
	while (true)
	{
		cv::Mat frame, frame_gray;
		// ��ȡ��ǰʱ��������㵽��ͼ��
		video >> frame;
		// ��Ƶ��ÿһ֡����ͼ��Ԥ����ת��Ϊ�Ҷ�ͼ
		cv::cvtColor(frame, frame_gray, cv::COLOR_BGR2GRAY);
		// ��˹ģ��
		cv::Mat frame_gauss;
		cv::GaussianBlur(frame_gray, frame_gauss, cv::Size(5, 5), 0, 0);
		// ��Ե���
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
			// ÿ�����ص�4��ͨ����ֵ
			bgra[0] = UCHAR_MAX;  // ��ɫͨ��
			bgra[1] = cv::saturate_cast<uchar>((float(img.cols - j)) / ((float)img.cols)*UCHAR_MAX);  //��ɫͨ��
			bgra[2] = cv::saturate_cast<uchar>((float(img.rows - i)) / ((float)img.rows)*UCHAR_MAX);  //��ɫͨ��
			bgra[3] = cv::saturate_cast<uchar>(0.5*(bgra[1] + bgra[2]));  //Alphaͨ��
		}
	}
	vector<int> compression_params;
	compression_params.push_back(cv::IMWRITE_PNG_COMPRESSION);
	compression_params.push_back(9);
	bool result = cv::imwrite("alpha.png", img, compression_params);
	if (!result) {
		cout << "�����PNG��ʽͼ��ʧ��" << endl;
	}

	cout << "����ɹ�" << endl;
}

void opencv4::video_save()
{
	cv::Mat img;
	cv::VideoCapture video(0);
	// ��ȡ��Ƶ
	if (!video.isOpened())
	{
		cout << "������ͷʧ��" << endl;
	}
	video >> img;  // ��ȡͼ��
	// ����Ƿ�ɹ���ȡͼ��
	if (!img.empty())
	{
		cout << "��ȡͼ��ɹ�" << endl;
	}

	bool isColor = (img.type() == CV_8UC3);
	// ��Ƶ����
	cv::VideoWriter writer;
	// ��Ƶ�ı����ʽ
	int codec = cv::VideoWriter::fourcc('M', 'J', 'P', 'G');
	double fps = 25.0;
	string filename = "live.avi";
	writer.open(filename, codec, fps, img.size(), isColor);  // ����������Ƶ�ļ�����Ƶ��
	if (!writer.isOpened())
	{
		cout << "����Ƶʧ�ܣ���ȷ���Ƿ�Ϸ�" << endl;
	}
	while (true)
	{
		if (!video.read(img)) {
			cout << "����ͷ�Ͽ�������Ƶ��ȡ���" << endl;
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
	// XML��Ԫ������ԣ�YMAL��������Ϊ���ĵ�����
	system("color F0");
	//string filename = "datas.xml";
	string filename = "datas.yaml";
	cv::FileStorage fwrite(filename, cv::FileStorage::WRITE);
	// �������Mat���͵�����
	cv::Mat mat = cv::Mat::eye(3, 3, CV_8U);
	fwrite.write("mat", mat);
	//fwrite << "mat" << mat;
	float x = 100;
	fwrite << "x" << x;
	// �����ַ������ݣ��ڵ�����Ϊstr
	string str = "Learn OpenCV4";
	fwrite << "str" << str;
	// �������飬�ڵ�����Ϊnumber_array
	fwrite << "number_array" << "[" << 4 << 5 << 6 << "]";
	// �����ڵ㣬�ڵ�����Ϊmulti_nodes
	fwrite << "multi_nodes" << "{" << "month" << 8 << "day" << 28 << "year" << 2019 << "time" << "[" << 0 << 1 << 2 << 3 << "]" << "}";
	// �ر��ļ�
	fwrite.release();

	// �Զ�ȡ��ģʽ���ļ�
	cv::FileStorage fread(filename, cv::FileStorage::READ);
	if (!fread.isOpened()) {
		cout << "���ļ�ʧ�ܣ���ȷ���ļ������Ƿ���ȷ" << endl;
	}
	// ��ȡ�ļ��е�����
	float xRead;
	fread["x"] >> xRead;
	cout << "x=" << xRead << endl;
	// ��ȡ�ַ�������
	string strRead;
	fread["str"] >> strRead;
	cout << "str=" << strRead << endl;
	// ��ȡ��������ݵ�number_array�ڵ�
	cv::FileNode filenode = fread["number_array"];
	cout << "number_array=[";
	// ѭ������ÿ������
	for (cv::FileNodeIterator i = filenode.begin(); i != filenode.end(); i++) {
		float a;
		*i >> a;
		cout << a << " ";
	}
	cout << "]" << endl;
	// ��ȡMat��
	cv::Mat matRead;
	fread["mat="] >> matRead;
	cout << "mat=" << matRead << endl;
	// ��ȡ����ӽڵ�Ľڵ����ݣ���ʹ��FileNode�͵�������ȡ
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
	// �ر��ļ�
	fread.release();

}
