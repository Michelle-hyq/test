#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;
int main()
{
	cv::Mat srcMat = imread("D:/image/timg1.jpg");
	//imshow("src", srcMat);
	int height = srcMat.rows;
	int width = srcMat.cols;
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			uchar average = (srcMat.at<Vec3b>(j, i)[0] + srcMat.at<Vec3b>(j, i)[1] + srcMat.at<Vec3b>(j, i)[2] / 3);
			srcMat.at<Vec3b>(j, i)[0] = srcMat.at<Vec3b>(j, i)[1];
			srcMat.at<Vec3b>(j, i)[1] = srcMat.at<Vec3b>(j, i)[2];
			srcMat.at<Vec3b>(j, i)[2] = srcMat.at<Vec3b>(j, i)[0];

		}
	}
	namedWindow("src", WINDOW_NORMAL);
	imshow("src", srcMat);
	waitKey(0);
	return 0;
}/**/