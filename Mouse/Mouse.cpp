#define _CRT_SECURE_NO_WARNINGS
#include<opencv2/opencv.hpp>

using namespace cv;

#define WINDOW_NAME "程序窗口"

void onMouseHandle(int events, int x, int y, int flags, void* param);
void DrawRect(Mat &img, Rect box);
void ShowHelp();

Rect g_rect;
bool g_bDrawingBox = false;
RNG g_rng(12345);

int main(int argc, char** argv)
{
	g_rect = Rect(-1, -1, 0, 0);
	Mat srcImage(600, 800, CV_8UC3), tempImage;
	srcImage.copyTo(tempImage);
	srcImage = Scalar::all(0);

	namedWindow(WINDOW_NAME);
	setMouseCallback(WINDOW_NAME, onMouseHandle, (void*)&srcImage);

	while (1)
	{
		srcImage.copyTo(tempImage);
		if (g_bDrawingBox)
			DrawRect(tempImage, g_rect);
		imshow(WINDOW_NAME, tempImage);
		if (waitKey(10)==27)
		{
			break;
		}
	}
	return 0;
}

void onMouseHandle(int events, int x, int y, int flags, void* param)
{
	Mat &img = *(Mat*)param;
	switch (events)
	{
	case EVENT_MOUSEMOVE:
	{
		if (g_bDrawingBox)
		{
			g_rect.width = x - g_rect.x;
			g_rect.height = x - g_rect.y;
		}
	}
	break;
	case EVENT_LBUTTONDOWN:
	{
		g_bDrawingBox = true;
		g_rect = Rect(x, y, 0, 0);//起始点
	}
	break;
	case EVENT_LBUTTONUP:
	{
		g_bDrawingBox = false;
		if (g_rect.width<0)
		{
			g_rect.x += g_rect.width;
			g_rect.width *= -1;
		}
		if (g_rect.height<0)
		{
			g_rect.y += g_rect.height;
			g_rect.height *= -1;
		}
		//draw
		DrawRect(img, g_rect);
	}
	break;
	}
}

void DrawRect(Mat &img, Rect box)
{
	rectangle(img,box.tl(), box.br(),
		Scalar(g_rng.uniform(0, 255),
			g_rng.uniform(0, 255),
			g_rng.uniform(0, 255)));//颜色随机
}
