#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat mat1 = Mat::zeros(3, 4, CV_8UC1);

	cout << "mat1: �ʱⰪ\n" << mat1 << endl;

	for (int i = 0; i < mat1.rows; i++)
	{
		for (int j = 0; j < mat1.cols; j++)
		{
			mat1.at<uchar>(i, j)++;
		}
	}	//end of for mat.at

	cout << "\n at()�Լ��� Ȱ���Ͽ� mat1�� ������ +1 \nmat1 :\n " << mat1 << endl;

	for (int i = 0; i < mat1.rows; i++)
	{
		uchar* p = mat1.ptr<uchar>(i);
		for (int j = 0;  j < mat1.cols;  j++)
		{
			p[j]++;
		}

	}
	cout << "\n ptr()�Լ��� Ȱ���Ͽ� mat1�� ������ +1 \nmat1 :\n " << mat1 << endl;


}