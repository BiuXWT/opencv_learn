#define _CRT_SECURE_NO_WARNINGS
#include<opencv2/core/core.hpp>
#include<opencv2/opencv.hpp>

using namespace cv;

#define WINDOW_NAME "【线性混合示例】"

const int g_nMaxAlphaValue = 100;
int g_nAlphaValueSlider;
double g_dAlphaValue;
double g_dBetaValue;

//存储图像的变量
Mat g_srcImage;
Mat g_srcImage2;
Mat g_dstImage;

void on_Trackbar(int, void*)
{
	g_dAlphaValue = (double)g_nAlphaValueSlider / g_nMaxAlphaValue;
	g_dBetaValue = 1.0 - g_dAlphaValue;

	addWeighted(g_srcImage, g_dAlphaValue, g_srcImage2, g_dBetaValue,0.,g_dstImage);
	imshow(WINDOW_NAME, g_dstImage);
}

int main(int argc, char* argv[])
{
	g_srcImage = imread("1.jpg");
	g_srcImage2 = imread("2.jpg");

	if (nullptr==g_srcImage.data)
	{
		printf("读取图片1错误\n");
		return -1;
	}
	if (nullptr == g_srcImage2.data)
	{
		printf("读取图片2错误\n");
		return -1;
	}

	g_nAlphaValueSlider = 70;
	namedWindow(WINDOW_NAME);

	char TrackBarName[50];
	sprintf(TrackBarName, "透明值 ");

	createTrackbar(TrackBarName, WINDOW_NAME, &g_nAlphaValueSlider,
		g_nMaxAlphaValue, on_Trackbar);

	on_Trackbar(g_nAlphaValueSlider, 0);
	waitKey(0);

	return 0;
}