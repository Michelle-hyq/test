#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;
void test1_1()//平均
{
	cv::Mat srcMat = imread("D://image/timg1.jpg");
	//imshow("src", srcMat);
	int height = srcMat.rows;
	int width = srcMat.cols;
	for (int j = 0; j < height; j++){
		for (int i = 0; i < width; i++){
			uchar average = (srcMat.at<Vec3b>(j, i)[0] + srcMat.at<Vec3b>(j, i)[1] + srcMat.at<Vec3b>(j, i)[2] / 3);
			srcMat.at<Vec3b>(j, i)[0] = average;
			srcMat.at<Vec3b>(j, i)[1] = average;
			srcMat.at<Vec3b>(j, i)[2] = average;
		}
	}
	namedWindow("src", WINDOW_NORMAL);
	imshow("src", srcMat);
	waitKey(0);
}
void test1_2()//灰度图
{
	cv::Mat srcMat = imread("D://image/timg1.jpg", 0);
	//imshow("src", srcMat);
	int height = srcMat.rows;
	int width = srcMat.cols;
	namedWindow("src", WINDOW_NORMAL);
	imshow("src", srcMat);
	waitKey(0);
}
void test1_3()//灰度图
{
	cv::Mat srcMat = imread("D://image/timg1.jpg");
	int height = srcMat.rows;
	int width = srcMat.cols;
	uchar threshold = 100;
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			uchar average = (srcMat.at<Vec3b>(j, i)[0] + srcMat.at<Vec3b>(j, i)[1] + srcMat.at<Vec3b>(j, i)[2] / 3);
			if (average > threshold) average = 255;
			else average = 0;
			srcMat.at<Vec3b>(j, i)[0] = average;
			srcMat.at<Vec3b>(j, i)[1] = average;
			srcMat.at<Vec3b>(j, i)[2] = average;
		}
	}
	namedWindow("src", WINDOW_NORMAL);
	imshow("src", srcMat);
	waitKey(0);
}
void test1_4()//深复制 浅复制
{
	cv::Mat srcMat = imread("D://image/timg1.jpg");
	cv::Mat deepMat;
	srcMat.copyTo(deepMat);
	cv::Mat shallowMat = srcMat;
	int height = srcMat.rows;
	int width = srcMat.cols;
	uchar threshold = 100;
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			uchar average = (srcMat.at<Vec3b>(j, i)[0] + srcMat.at<Vec3b>(j, i)[1] + srcMat.at<Vec3b>(j, i)[2] / 3);
			if (average > threshold) average = 255;
			else average = 0;
			srcMat.at<Vec3b>(j, i)[0] = average;
			srcMat.at<Vec3b>(j, i)[1] = average;
			srcMat.at<Vec3b>(j, i)[2] = average;
		}
	}
	namedWindow("src", WINDOW_NORMAL);	
	imshow("src", shallowMat);
	waitKey(0);
}
void test2_1()
{
	cv::Mat src_color = imread("D://image/timg2.jpg");
	std::vector<cv::Mat> channels;
	cv::split(src_color, channels);
	cv::Mat B = channels.at(0);
	cv::Mat G = channels.at(1);
	cv::Mat R = channels.at(2);
	cv::imshow("red", R);
	cv::imshow("blue", G);
	cv::imshow("green", B);
	cv::imshow("original Mat", src_color);
	waitKey(0);
}
int test2_2()
{
	VideoCapture cap;
	cap.open("D://image/video1.mp4");
	if(!cap.isOpened());
	{
		std::cout << "不能打开视频文件" << std::endl;
		return-1;
	}
	double fps = cap.get(CAP_PROP_FPS);
	std::cout << "fps" << fps << std::endl;
	while (1)
	{
		cv::Mat frame;
		bool rSucess = cap.read(frame);
		if (!rSucess)
		{
			std::cout << "不能从视频文件读取帧"<<std::endl;
			break;
		}
		else
			cv::imshow("frame", frame);
		waitKey(30);
	}
	
}
int main()
{
	test2_2();
	return 0;
}/**/