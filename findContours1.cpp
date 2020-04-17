#include <iostream>
#include <opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	cv::Mat srcMat = imread("rim.png", 1);
	cv::Mat binMat;

	//大津法
	threshold(srcMat, binMat, 125, 255, THRESH_BINARY);

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(binMat, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

	imshow("srcMat", srcMat);
	imshow("binMat", binMat);
	waitKey(0);
}
