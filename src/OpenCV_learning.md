### OpenCV
OpenCV��һ����Դ�ļ�����Ӿ���

## OpenCVģ��
1. Core
����OpenCV��Ļ����ṹ�Լ���������
2. Improc
ͼ����ģ�飬����������ͼ��ת���������˲��Լ����Ƶľ������
3. Highgui
����������ʾͼ����߼򵥵�������û���������
4. Video
������ȡ��д��Ƶ���ĺ���
5. Calib3d
����У׼������˫Ŀ�Լ����������㷨ʵ��
6. Feature2d
�������ڼ�⡢�����Լ�ƥ����������㷨
7. Objectect
��������ض�Ŀ�꣬���������������˵��㷨������ѵ������������������������
8. M1
����ѧϰģ�鱾����һ���ǳ��걸��ģ�飬���������Ļ���ѧϰ�㷨ʵ�ֲ�����Щ�㷨���ܺ�OpenCV������������Ȼ����
9. Flann
"�������ڽ���"������һЩ��Ҳ����ֱ��ʹ�õķ�������������ģ���еĺ���������������ݼ��н������ڽ�����
10. GPU
GPUģ����Ҫ�Ǻ�����CUDA GPU�ϵ��Ż�ʵ�֣����⣬����һЩ������GPU�Ĺ���
11. Photo
����һ���൱�µ�ģ�飬����������Ӱѧ��һЩ��������
12. Skitching
���ɵ�ͼ��ƴ������ʵ��
13. Nonfree(open3.x�У�����ֲ��opencv_contrib)
Dnn: ���������
Face: ����ʶ��
Text: �ı�����Լ�ʶ�𣬻�����࿪Դ��OCR�㷨
Rgbd: ������Kinect����������ȴ����������߼򵥵���˫Ŀƥ��õ��ģ���ȡ��RGB+���ͼ��
Bioinspired: һЩ��������ѧ�������Ӿ�����
ximgproc��xphoto: �Ƚ���ͼ�����Լ�������Ӱѧ����
tracking: �ִ�Ŀ��׷���㷨


## opencvͼ����ʾ�봦��
1. ��˹ģ��
cv::GaussianBlur(cv::InputArray src, cv::OutputArray dst, cv::Size ksize, double sigmaX, double sigmaY)
src- input image, depth:CV_U, CV_16U, CV_16S, CV_32F or CV_64F
dst- out image, size and type��input imageһ��
ksize- Gaussian kernel size
sigmaX- X�����Gaussian kernel standard deviation
sigmaY- Y�����Gaussian kernel standard deviation
���ӣ�
cv::GaussianBlur(image, out, cv::Size(5,5), 3,3)
����ͼ��5x5��С�ĸ�˹��ģ�����ұ�д��out�����С���˹�˵Ĵ�С��������������Ϊ��˹��������串�����������������
����һ�ε���cv::GaussianBlur()��ʱ�����ڱ���������ʱ�Ĵ洢�ռ䣬����out����ͬʱ��Ϊ��������
2. ������
��ͼ����ж�ν�������Ҫ����һ���߶ȿռ䣬��һ�����Ǽ�����Ӿ����ڴ���������Ŀ��߶ȱ仯�ĳ����ֶ�֮һ��
������(����һ��ͼ�񲢶�ÿ�����ؽ��в���)��Ч�ں�һϵ�����庯�����о��(��Щ������Ϊ����ֵ").������Ѹ�Ƶ������������ź�(ͼ��
ͨ��һ����ͨ�˲����������źŴ���ʹ���ܹ��ڲ���Ƶ��֮�ڡ�
��opencv�У���˹ģ���Լ�������ͨ��cv::pyrDown()������ʵ�֣�ͼ��߶�Ϊԭͼ���1/2��
3. canny��Ե��������һ����ͨ����(�Ҷ�)ͼ��
cv::cvtColor(cv::InputArray src, cv::OutputArray dst, int code)
src- ����ͼ��
dst- ���ͼ��
code- ���ColorConversionCodes�����磺cv::COLOR_BGR2GRAY. BGRͼ��ת��Ϊ��ͨ����gray�Ҷ�ͼ��
cv::Canny(Inputarray src, OutputArray edges, threshold1, threshold2, 3, true)
������ԭͼһ����С�ĵ�ͨ���Ҷ�ͼ��
4. ��ȡ����ֵ
intensity = img_rgb.at<cv::Vec3b>(int row, int col);
row�У�col�е�����ֵ��
uchar blue = intensity[0];
uchar green = intensity[1];
uchar red = intensity[2];
5. д��AVI�ļ�
cv::VideoWriter������Ҫ�õ���ԭ��Ƶÿ�벥�ŵ�֡���Լ�ͼ���ߣ�
cv::VideoWriter writer;
writer.open(filename, fourcc, fps, size)
filename- �½���Ƶ�ļ����ļ���
fourcc- ��Ƶ���뷽ʽ����Ƶ�Ը��ַ�ʽѹ����OpenCV�ṩ��CV_FOURCC('M','J','P','G')
fps- ֡��
size- ͼ���С

## opencv��������
# ��������-�̶�������Vec��
cv::Vec<>��ԭ��������࣬���̶�������
��cv::Vec{2,3,4,6}{b,w,s,i,f,d}��ʽ������������6������������д�ĺ��壺
b = unsigned char
w = unsigned short
s = short
i = int
f = float
d = double

# ��������-Point��
Point��ͨ��������cv::Point2i��cv::Point3f�ȱ�����ʵ�����ģ����һ����ĸ��ԭ��(b��һ���޷����ַ���
s��һ�������ͣ�i��һ��32λ���ͣ�f��һ��32λ��������d��һ��64λ��������
Point��֧�ֵĲ���
���캯��          - cv::Point2i p;
���ƹ��캯��      - cv::Point3f p2(p1);
ֵ���캯��        - cv::Point3d p(x0, x1, x2);
����ɹ̶�������  - (cv::Vec3f) p;
��Ա����          - p.x, p.y;
���		  - float x = p1.dot(p2);
���              - p1.cross(p2);

# ��������-Scalar��
cv::Scalar����ά���ࡣ

# ��������-size��
size�������Point�໥��ת�����������ڣ�
Point������ݳ�Ա��x��y, ��size���ֶ�Ӧ�ĳ�Ա��width��height.
size����3��������cv::Size, cv::Size2i, cv::Size2f. cv::Size��cv::Size2i�ǵȼ۵ģ���ʾ������С�����һ���Ǳ�ʾ32λ�����С��
size��֧�ֵĲ���
Ĭ�Ϲ��캯��      - cv::Size sz;
���ƹ��캯��      - cv::Size sz2(sz1);
ֵ���캯��        - cv::Size2f sz(w,h);
��Ա����          - sz.width; sz.height;
�������          - sz.area();
size�಻֧��ת�����̶������࣬ Point��͹̶����������ת����size��

# ��������-������Rect��
���������Point��ĳ�Աx��y(�������Ͻ�)��size��ĳ�Աwidth��height(���εĴ�С)
cv::Rectֱ��֧�ֵĲ���
Ĭ�Ϲ��캯��       - cv::Rect r;
���ƹ��캯��       - cv::Rect r2(r1);
ֵ���캯��         - cv::Rect(x,y,w,h);
����ʼ��ʹ�С���� - cv::Rect(p, sz);
�������Խǹ���     - cv::Rect(p1, p2);
��Ա����           - r.x; r.y; r.width; r.height;
�������           - r.area();
# ��������-RotatedRect��
cv::RotatedRect�����һ�����ĵ�cv::Point2f��һ����Сcv::Size2f��һ������ĽǶ�float������
���и�������(float)�ĽǶȴ���ͼ�������ĵ���ת�ĽǶȡ�
cv::RotatedRect��������Ϊԭ��ģ�cv::Rectλ�����Ͻ�Ϊԭ��
cv::RotatedRectֱ��֧�ֵĲ���
Ĭ�Ϲ��캯��	   - cv::RotatedRect rr();
���ƹ��캯��       - cv::RotatedRect rr2(rr1);
�������㹹��       - cv::RotatedRect(p1, p1);
ֵ���캯����point,
size, angle        - cv::RotatedRect rr(p, sz, theta);
��Ա����           - rr.center, rr.size, rr.angle
# ��������-�̶�������
cv::Matx<>, ������ʽΪcv::Matx{1,2,...}{1,2,...}{f,d}, ���е����ֿ�����1��6֮����κ�����β������ĸ��֮ǰ������һ����
cv::Matx֧�ֵĲ���
Ĭ�Ϲ��캯��       - cv::Matx33f m33f;
���ƹ��캯��       - cv::Matx22d m22d(n22d);
ֵ���캯��         - cv::Matx21f m(x0, x1);
����ͬԪ�صľ���   - m33f = cv::Matx33f::all(x);
ȫ�����           - m23d = cv::Matx23d::zeros();
ȫһ����           - m16f = cv::Matx16f::ones();

### cv::Mat��
cv::Mat�������Ϊ����ά�ȵ�����ʹ�ã������ݿ��Կ������԰���դ��ɨ��˳��洢��nά����
cv::Mat                                  - Ĭ�Ϲ��캯��
cv::Mat(int rows, int cols, int type)    - ָ�����͵Ķ�ά����
cv::Mat(
  int rows, int cols, int type,
  const Scalar&s)                        - ָ�����͵Ķ�ά���飬��ָ����ʼ��ֵ
cv::Mat(cv::Size sz, int type)           - Size()����Mat�࣬��С��szָ��������ǰ�����ں�
