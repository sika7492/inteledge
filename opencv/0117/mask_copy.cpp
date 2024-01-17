#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {


	Mat src = imread("airplane.bmp", IMREAD_COLOR);
	Mat mask = imread("mask_plane.bmp", IMREAD_GRAYSCALE);
	Mat dst = imread("field.bmp", IMREAD_COLOR);
	if (src.empty() || mask.empty() || dst.empty()) {
		cerr << "파일읽기 실패" << endl;
		return -1;

	}

	src.copyTo(dst, mask);
	imshow("dst", dst);
	imshow("src", src);
	imshow("mask", mask);
	waitKey();
	destroyAllWindows();

}