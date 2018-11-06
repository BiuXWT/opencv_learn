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
	Mat mask = imread("../logo.jpg", 0);//������Ĥ���Ҷ�ͼ
	//imshow("mask", mask);//�ڰ�ͼ��

	logoImage.copyTo(imgROI, mask);//������Ĥ��ROI

	namedWindow("<1>����ROIʵ��ͼ����ӵ�ʾ������");
	imshow("<1>����ROIʵ��ͼ����ӵ�ʾ������", srcImage1);

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