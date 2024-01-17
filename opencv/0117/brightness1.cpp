#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;
void brightness1();
void brightness2();
void brightness3();
void brightness4();
void on_brightness(int pos, void* userdata);

int main() {
	//brightness1();
	//brightness2();
	//brightness3();
	brightness4();
}
void brightness1() {
	Mat img1 = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (img1.empty()) {
		cerr << "파일읽기 실패" << endl;
		return;
	}

	Mat img1_dst = img1 + 100;
	imshow("img1", img1);
	imshow("img1_dst", img1_dst);
	imwrite("img1_dst.bmp", img1_dst);

	waitKey();

	destroyAllWindows();

}
void brightness2() {
	Mat img2 = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (img2.empty()) {
		cerr << "파일읽기 실패" << endl;
		return;
	}

	Mat img2_dst(img2.rows,img2.cols,img2.type());
	for (int i = 0; i < img2.cols; i++)
	{
		for (int j = 0; j < img2.rows; j++)
		{
			img2_dst.at<uchar>(i,j) = img2.at<uchar>(i, j) + 100;
		}

	}
	imshow("img2", img2);
	imshow("img2_dst", img2_dst);
	imwrite("img2_dst.bmp", img2_dst);

	waitKey();

	destroyAllWindows();

}
void brightness3()
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	Mat dst(src.rows, src.cols, src.type());

	for (int j = 0; j < src.rows; j++) {
		for (int i = 0; i < src.cols; i++) {
			dst.at<uchar>(j, i) = saturate_cast<uchar>(src.at<uchar>(j, i) + 100);
		}
	}

	imshow("src", src);
	imshow("dst", dst);
	waitKey();

	destroyAllWindows();
}
void brightness4()
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	namedWindow("dst");
	createTrackbar("Brightness", "dst", 0, 100, on_brightness, (void*)&src);
	on_brightness(0, (void*)&src);

	waitKey();
	destroyAllWindows();
}
void on_brightness(int pos, void* userdata)
{
	Mat src = *(Mat*)userdata;
	Mat dst = src + pos;

	imshow("dst", dst);
}
