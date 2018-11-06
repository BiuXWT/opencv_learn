#include<opencv2/opencv.hpp>

using namespace cv;

void erode_op()//¸¯Ê´
{
	Mat srcImage = imread("cat.jpg");

	Mat element = getStructuringElement(MORPH_RECT, Size(10, 10));
	Mat dstImg;
	erode(srcImage, dstImg, element);
	imshow("pic", dstImg);
	waitKey(0);
}
void blur_op()//Ä£ºý  ¾ùÖµÂË²¨
{
	Mat srcImage = imread("cat.jpg");
	Mat dstImg;
	blur(srcImage, dstImg, Size(7, 7));
	imshow("pic", dstImg);
	waitKey(0);
}

void canny_op()//±ßÔµ¼ì²â
{
	Mat srcImage = imread("cat.jpg");
	Mat dstImage, edge, grayImage;
	dstImage.create(srcImage.size(), srcImage.type());
	cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);

	blur(grayImage, edge, Size(15, 15));
	imshow("edge1 pic", edge);

	Canny(edge, edge, 3, 9, 3);

	imshow("gray pic", grayImage);
	imshow("edge pic", edge);

	waitKey(0);
}

int main(int argc, char** av)
{
	//erode_op();
	//blur_op();
	canny_op();

	return 0;
}