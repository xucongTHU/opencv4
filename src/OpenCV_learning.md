### OpenCV
OpenCV是一个开源的计算机视觉库

## OpenCV模块
1. Core
包含OpenCV库的基础结构以及基本操作
2. Improc
图像处理模块，包含基本的图像转换，包括滤波以及类似的卷积操作
3. Highgui
包含用来显示图像或者简单的输入的用户交互函数
4. Video
包含读取和写视频流的函数
5. Calib3d
包括校准单个、双目以及多个相机的算法实现
6. Feature2d
包含用于检测、描述以及匹配特征点的算法
7. Objectect
包含检测特定目标，比如人脸或者行人的算法。可以训练检测器并用来检测其他物体
8. M1
机器学习模块本身是一个非常完备的模块，包含大量的机器学习算法实现并且这些算法都能和OpenCV的数据类型自然交互
9. Flann
"快速最邻近库"。包含一些你也许不会直接使用的方法，但是其他模块中的函数会调用它在数据集中进行最邻近搜索
10. GPU
GPU模块主要是函数在CUDA GPU上的优化实现，此外，还有一些仅用于GPU的功能
11. Photo
这是一个相当新的模块，包含计算摄影学的一些函数工具
12. Skitching
精巧的图像拼接流程实现
13. Nonfree(open3.x中，被移植到opencv_contrib)
Dnn: 深度神经网络
Face: 人脸识别
Text: 文本检测以及识别，基于许多开源的OCR算法
Rgbd: 处理由Kinect或者其他深度传感器（或者简单的由双目匹配得到的）获取的RGB+深度图像
Bioinspired: 一些基于生物学启发的视觉技术
ximgproc和xphoto: 先进的图像处理以及计算摄影学方法
tracking: 现代目标追踪算法


## opencv图像显示与处理
1. 高斯模糊
cv::GaussianBlur(cv::InputArray src, cv::OutputArray dst, cv::Size ksize, double sigmaX, double sigmaY)
src- input image, depth:CV_U, CV_16U, CV_16S, CV_32F or CV_64F
dst- out image, size and type与input image一致
ksize- Gaussian kernel size
sigmaX- X方向的Gaussian kernel standard deviation
sigmaY- Y方向的Gaussian kernel standard deviation
例子：
cv::GaussianBlur(image, out, cv::Size(5,5), 3,3)
输入图像被5x5大小的高斯核模糊并且被写入out变量中。高斯核的大小必须是奇数，因为高斯卷积会在其覆盖区域的中心输出结果
在下一次调用cv::GaussianBlur()的时候，由于被分配了临时的存储空间，所以out可以同时作为输入和输出
2. 降采样
对图像进行多次降采样，要建立一个尺度空间，这一方法是计算机视觉用于处理传感器和目标尺度变化的常用手段之一。
降采样(创建一个图像并对每个像素进行采样)等效于和一系列脉冲函数进行卷积(这些函数视为”峰值").这样会把高频分量引入输出信号(图像）
通过一个高通滤波器来限制信号带宽，使其能够在采样频率之内。
在opencv中，高斯模糊以及降采样通过cv::pyrDown()函数来实现，图像高度为原图像的1/2，
3. canny边缘检测器输出一个单通道的(灰度)图像
cv::cvtColor(cv::InputArray src, cv::OutputArray dst, int code)
src- 输入图像
dst- 输出图像
code- 详见ColorConversionCodes，例如：cv::COLOR_BGR2GRAY. BGR图像转换为单通道的gray灰度图像
cv::Canny(Inputarray src, OutputArray edges, threshold1, threshold2, 3, true)
生成与原图一样大小的单通道灰度图像
4. 读取像素值
intensity = img_rgb.at<cv::Vec3b>(int row, int col);
row行，col列的像素值；
uchar blue = intensity[0];
uchar green = intensity[1];
uchar red = intensity[2];
5. 写入AVI文件
cv::VideoWriter建立需要用到（原视频每秒播放的帧数以及图像宽高）
cv::VideoWriter writer;
writer.open(filename, fourcc, fps, size)
filename- 新建视频文件的文件名
fourcc- 视频编码方式，视频以各种方式压缩。OpenCV提供宏CV_FOURCC('M','J','P','G')
fps- 帧率
size- 图像大小

## opencv数据类型
# 基础类型-固定向量类Vec类
cv::Vec<>，原语的容器类，即固定向量类
有cv::Vec{2,3,4,6}{b,w,s,i,f,d}形式的声明，其中6种数据类型缩写的含义：
b = unsigned char
w = unsigned short
s = short
i = int
f = float
d = double

# 基础类型-Point类
Point类通过类似于cv::Point2i和cv::Point3f等别名来实例化的，最后一个字母的原语(b是一个无符号字符，
s是一个短整型，i是一个32位整型，f是一个32位浮点数，d是一个64位浮点数）
Point类支持的操作
构造函数          - cv::Point2i p;
复制构造函数      - cv::Point3f p2(p1);
值构造函数        - cv::Point3d p(x0, x1, x2);
构造成固定向量类  - (cv::Vec3f) p;
成员访问          - p.x, p.y;
点乘		  - float x = p1.dot(p2);
叉乘              - p1.cross(p2);

# 基础类型-Scalar类
cv::Scalar是四维点类。

# 基础类型-size类
size类可以与Point类互相转换。区别在于：
Point类的数据成员是x和y, 而size类种对应的成员是width和height.
size类有3个别名，cv::Size, cv::Size2i, cv::Size2f. cv::Size和cv::Size2i是等价的，表示整数大小。最后一个是表示32位浮点大小。
size类支持的操作
默认构造函数      - cv::Size sz;
复制构造函数      - cv::Size sz2(sz1);
值构造函数        - cv::Size2f sz(w,h);
成员访问          - sz.width; sz.height;
计算面积          - sz.area();
size类不支持转换到固定向量类， Point类和固定向量类可以转换成size类

# 基础类型-矩阵类Rect类
矩阵类包含Point类的成员x和y(矩形左上角)和size类的成员width和height(矩形的大小)
cv::Rect直接支持的操作
默认构造函数       - cv::Rect r;
复制构造函数       - cv::Rect r2(r1);
值构造函数         - cv::Rect(x,y,w,h);
由起始点和大小构造 - cv::Rect(p, sz);
由两个对角构造     - cv::Rect(p1, p2);
成员访问           - r.x; r.y; r.width; r.height;
计算面积           - r.area();
# 基础类型-RotatedRect类
cv::RotatedRect类包含一个中心点cv::Point2f、一个大小cv::Size2f和一个额外的角度float的容器
其中浮点类型(float)的角度代表图形绕中心点旋转的角度。
cv::RotatedRect是以中心为原点的，cv::Rect位于左上角为原点
cv::RotatedRect直接支持的操作
默认构造函数	   - cv::RotatedRect rr();
复制构造函数       - cv::RotatedRect rr2(rr1);
从两个点构造       - cv::RotatedRect(p1, p1);
值构造函数，point,
size, angle        - cv::RotatedRect rr(p, sz, theta);
成员访问           - rr.center, rr.size, rr.angle
# 基础类型-固定矩阵类
cv::Matx<>, 基础格式为cv::Matx{1,2,...}{1,2,...}{f,d}, 其中的数字可以是1到6之间的任何数，尾部的字母与之前的类型一样。
cv::Matx支持的操作
默认构造函数       - cv::Matx33f m33f;
复制构造函数       - cv::Matx22d m22d(n22d);
值构造函数         - cv::Matx21f m(x0, x1);
含相同元素的矩阵   - m33f = cv::Matx33f::all(x);
全零矩阵           - m23d = cv::Matx23d::zeros();
全一矩阵           - m16f = cv::Matx16f::ones();

### cv::Mat类
cv::Mat类可以作为任意维度的数组使用，其数据可以看作是以按照栅格扫描顺序存储的n维数组
cv::Mat                                  - 默认构造函数
cv::Mat(int rows, int cols, int type)    - 指定类型的二维数组
cv::Mat(
  int rows, int cols, int type,
  const Scalar&s)                        - 指定类型的二维数组，并指定初始化值
cv::Mat(cv::Size sz, int type)           - Size()构造Mat类，大小由sz指定，列在前，行在后
