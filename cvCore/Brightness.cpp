#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

//g(x)=a*f(x)+b , a :���棬����ͼ��Աȶȣ�b :ƫ�ã�����ͼ������

//g(i,j)=a*f(i,j)+b

#define WINDOW_NAME "Ч��ͼ����"
#define WINDOW_NAME2 "ԭʼͼ����"

static void on_ContrastAndBright(int, void*);
static void ShowHelpText();

int g_nContrastValue;
int g_nBrightValue;
Mat g_srcImage, g_dstImage;

int main()
{
	g_srcImage = imread("../cat.jpg");
	if (!g_srcImage.data)
	{
		cout << "read file err" << endl;
		return -1;
	}
	g_dstImage = g_srcImage.clone();// Mat::zeros(g_srcImage.size(), g_srcImage.type());
	g_nContrastValue = 100;
	g_nBrightValue = 0;

	namedWindow(WINDOW_NAME);
	createTrackbar("�Աȶȣ�", WINDOW_NAME, &g_nContrastValue, 300, on_ContrastAndBright);
	createTrackbar("��  �ȣ�", WINDOW_NAME, &g_nBrightValue, 200, on_ContrastAndBright);

	imshow(WINDOW_NAME2, g_srcImage);
	while (char(waitKey(1))!='q'){}
	return 0;
}

static void on_ContrastAndBright(int, void*)
{
	//��������
	namedWindow(WINDOW_NAME2);
	for (int y = 0; y < g_srcImage.rows; y++)
	{
		for (int x=0;x<g_srcImage.cols;x++)
		{
			for (int c = 0; c < 3; c++)
			{
				g_dstImage.at<Vec3b>(y, x)[c] = saturate_cast<uchar>((g_nContrastValue*0.01)*
					(g_srcImage.at<Vec3b>(y, x)[c]) + g_nBrightValue);
			}
		}
	}
	imshow(WINDOW_NAME, g_dstImage);
}