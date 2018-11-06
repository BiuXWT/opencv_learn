#include<opencv2/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<iostream>

using namespace std;
using namespace cv;

void colorReduce1(Mat& inputImage, Mat& outputImage, int div);
void colorReduce2(Mat& inputImage, Mat& outputImage, int div);
void colorReduce3(Mat& inputImage, Mat& outputImage, int div);

int ProcessPixel(int argc, char **argv)
{
	Mat srcImage = imread("../cat.jpg");
	imshow("source image", srcImage);
	moveWindow("source image", 0, 100);

	Mat dstImage;
	dstImage.create(srcImage.rows, srcImage.cols, srcImage.type());

	double time0 = static_cast<double>(getTickCount());

	colorReduce1(srcImage, dstImage, 64);
	//colorReduce2(srcImage, dstImage, 64);
	//colorReduce3(srcImage, dstImage, 64);

	time0 = ((double)getTickCount() - time0) / getTickFrequency();

	cout << "running time is : " << time0 << "sec" << endl;

	imshow("dst image", dstImage);
	moveWindow("dst image", dstImage.cols, 100);

	waitKey(0);

	return 0;
}

void colorReduce1(Mat& inputImage, Mat& outputImage, int div)
{
	outputImage = inputImage.clone();
	int rowNum = outputImage.rows;
	int colNum = outputImage.cols*outputImage.channels();//每行元素个数=列数x通道数

	for (int i = 0; i < rowNum; i++)
	{
		uchar *data = outputImage.ptr<uchar>(i);
		for (int j = 0; j < colNum; j++)
		{
			data[j] = data[j] / div * div + div / 2;
		}
	}

}

void colorReduce2(Mat& inputImage, Mat& outputImage, int div)
{
	outputImage = inputImage.clone();
	Mat_<Vec3b>::iterator it = outputImage.begin<Vec3b>();
	Mat_<Vec3b>::iterator itend = outputImage.end<Vec3b>();

	for (;it!=itend;it++)
	{
		(*it)[0] = (*it)[0] / div * div + div / 2;
		(*it)[1] = (*it)[1] / div * div + div / 2;
		(*it)[2] = (*it)[2] / div * div + div / 2;
	}
}

void colorReduce3(Mat& inputImage, Mat& outputImage, int div)
{
	outputImage = inputImage.clone();
	int rowNum = outputImage.rows;
	int colNum = outputImage.cols;

	for (int i=0;i<rowNum;i++)
	{
		for (int j=0;j<colNum;j++)
		{
			outputImage.at<Vec3b>(i, j)[0] = outputImage.at<Vec3b>(i, j)[0] / div * div + div / 2;
			outputImage.at<Vec3b>(i, j)[1] = outputImage.at<Vec3b>(i, j)[1] / div * div + div / 2;
			outputImage.at<Vec3b>(i, j)[2] = outputImage.at<Vec3b>(i, j)[2] / div * div + div / 2;
		}
	}
}