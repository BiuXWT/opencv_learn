#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace cv;

int main()
{
	Mat cat = imread("../cat.jpg", CV_LOAD_IMAGE_ANYCOLOR | CV_LOAD_IMAGE_ANYDEPTH);
	namedWindow("cat");
	imshow("cat", cat);

	//����ͼ����
	Mat pic = imread("../logo.jpg");
	Mat imgROI;
	imgROI = cat(Rect(0, 0, pic.cols, pic.rows));
	addWeighted(imgROI, 0.5/*imgROI ��͸���� 1 ��͸��*/, 
				pic,	0.5/*pic ��͸����*/, 0., imgROI);
	imshow("ROI", imgROI);
	imshow("double", cat);

	//����ͼ��
	//imwrite("../cat_logo.jpg", cat);

	waitKey(0);
	return 0;
}