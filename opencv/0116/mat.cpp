#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {




	Mat img1; 	// empty matrix

	Mat img2(200, 300, CV_8UC1);		// unsigned char, 1-channel
	Mat img3(200, 300, CV_8UC3);		// unsigned char, 3-channels
	Mat img4(Size(300, 200), CV_8UC3);	// Size(width, height)

	Mat img5(200, 300, CV_8UC1, Scalar(128));		// initial values, 128		//c1 그레이 스케일
	Mat img6(200, 300, CV_8UC3, Scalar(0, 0, 255));	// initial values, red		// c3 트루칼라

	Mat mat1 = Mat::zeros(3, 3, CV_32SC1);	// 0's matrix
	Mat mat2 = Mat::ones(3, 3, CV_32FC1);	// 1's matrix
	Mat mat3 = Mat::eye(3, 3, CV_32FC1);	// identity matrix

	float data[] = { 1, 2, 3, 4, 5, 6 };
	Mat mat4(2, 3, CV_32FC1, data);

	Mat mat5 = (Mat_<float>(2, 3) << 1, 2, 3, 4, 5, 6);
	Mat mat6 = Mat_<uchar>({ 2, 3 }, { 1, 2, 3, 4, 5, 6 });

	mat4.create(4, 4, CV_8UC3);	// uchar, 3-channels
	mat5.create(4, 4, CV_32FC1);	// float, 1-channel

	mat4 = Scalar(255, 0, 0);
	mat5.setTo(1.f);

	if (img1.empty())
		cout << "img1은 비어있다" << endl;
	else imshow("img1", img1);
	imshow("img2", img2);
	imshow("img3", img3);
	imshow("img4", img4);
	imshow("img5", img5);
	imshow("img6", img6);

	cout << "mat1:\n" << mat1 << endl;
	cout << "mat2:\n" << mat2 << endl;
	cout << "mat3:\n" << mat3 << endl;
	cout << "mat4:\n" << mat4 << endl;
	cout << "mat5:\n" << mat5 << endl;

	waitKey();
}