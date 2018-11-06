#include<opencv2/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<iostream>

using namespace std;
using namespace cv;

bool ROI_AddImage()
{
	Mat srcImage1 = imread("../cat.jpg");
	Mat logoImage = imread("../logo.jpg");

	if (!srcImage1.data)
	{
		cout << "read src image error!" << endl;
		return false;
	}
	if (!logoImage.data)
	{
		cout << "read src image error!" << endl;
		return false;
	}

	Mat imgROI = srcImage1(Rect(0, 0, logoImage.cols, logoImage.rows));
	Mat mask = imread("../logo.jpg", 0);//加载掩膜，灰度图
	//imshow("mask", mask);//黑白图像

	logoImage.copyTo(imgROI, mask);//复制掩膜到ROI

	namedWindow("<1>利用ROI实现图像叠加到示例窗口");
	imshow("<1>利用ROI实现图像叠加到示例窗口", srcImage1);

	return true;
}
#if 0
int main()
{
	ROI_AddImage();

	waitKey(0);

	return 0;
}
#endif