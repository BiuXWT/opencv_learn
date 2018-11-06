#include <opencv2/opencv.hpp>

using namespace cv;

#if 0
uchar table[256] = { 0 };
void makeTable(int dev)
{
	for (int i = 0; i < 256; ++i)
	{
		table[i] = dev *( i / dev);
	}
}



int main()
{

}
#endif