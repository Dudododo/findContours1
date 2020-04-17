#include <iostream>
#include <opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	cv::Mat srcMat = imread("rim.png", 1);
	cv::Mat binMat, dstMat;

	cvtColor(srcMat, dstMat, COLOR_BGR2GRAY);
	threshold(dstMat, binMat, 140, 255, THRESH_BINARY);
	
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	cv::findContours(binMat, contours, RETR_LIST, CHAIN_APPROX_NONE);
	//绘制轮廓
	for (int i = 0; i < contours.size(); i++)
	{
		RotatedRect rbox = minAreaRect(contours[i]);
		if (fabs(rbox.size.width  / rbox.size.height - 1) < 0.1 && rbox.size.width > 15 && rbox.size.height > 15)
			drawContours(srcMat, contours, i, Scalar(0, 255, 255), -1, 8);
	}
	
	imshow("srcMat", srcMat);
	imshow("binMat", binMat);
	waitKey(0);
}
