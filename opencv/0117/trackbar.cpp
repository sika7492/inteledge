#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void on_level_change(int pos, void* userdata);
int main() {
	Mat img = Mat::zeros(800, 800, CV_8UC1);

	namedWindow("image");
	createTrackbar("level", "image", 0, 32, on_level_change, (void*)&img);

	imshow("image", img);
	waitKey();

	return 0;
}

void on_level_change(int pos, void* userdata)
{
	Mat img = *(Mat*)userdata;

	img.setTo(pos * 8);
	imshow("image", img);
}
