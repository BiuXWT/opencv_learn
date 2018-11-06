#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
/*
 * 通道分离
 */
void split_image()
{
	Mat srcImage = imread("../cat.jpg");
	Mat logoImage = imread("../logo.jpg",0);
	Mat imageROI;

	vector<Mat> channels;
	
	//opencv use BGR pannel,usually we use RGB pannel

	split(srcImage, channels);//通道分离

	imageROI = channels.at(2);//Red 

	//imshow("channel 0", imageROI);

	addWeighted(imageROI(Rect(0, 0, logoImage.cols, logoImage.rows)), 1.0, logoImage, 0.5, 0.,
		imageROI(Rect(0, 0, logoImage.cols, logoImage.rows)));

	merge(channels, srcImage);//通道合并

	namedWindow("sample");
	imshow("sample", srcImage);

	waitKey(0);
}

#if 0
int main()
{
	split_image();

	return 0;
}
#endif