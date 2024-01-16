#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	float data[] = { 1,1,2,3 };
	Mat mat1(2, 2, CV_32FC1, data);
	cout << "mat1:\n" << mat1 << endl;

	Mat mat2 = mat1.inv();
	cout << "mat2: mat1의 역행열\n" << mat2 << endl;

	cout << "mat1.t(): mat1의 전치행렬\n" << mat1.t() << endl;
	cout << "mat1+3:\n" << mat1+3 << endl;
	cout << "mat1+mat2:\n" << mat1+mat2 << endl;
	cout << "mat1 *mat2:\n" << mat1*mat2 << endl;


}