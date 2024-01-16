#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat img1 = imread("lenna.bmp");
	if (img1.empty()) {
		cout << "�����б� ����" << endl;
		return 0;
	}
	else cout << "lenna.bmp �����б� ���� " << endl;

	cout << "lenna.bmp width:" << img1.cols << endl;
	cout << "lenna.bmp height:" << img1.rows << endl;

	if (img1.type() == CV_8UC1)
		cout << "img1 is a grayscale image." << endl;
	else if (img1.type() == CV_8SC3)
		cout << "img1 is a truecolor image." << endl;

	cout << "lennam.bmp�� �뷮 " << img1.total()*img1.elemSize()<<"����Ʈ" << endl;

	float data[] = { 2.f, 1.414f, 3.f, 1.732f };
	Mat mat1(2, 2, CV_32FC1, data);
	cout << "mat1:\n" << mat1 << endl;







}