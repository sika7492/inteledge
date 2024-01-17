#include<iostream>

#include"opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main() {

	Scalar gray = 128;

	cout << "gray: " << gray << endl;

	Scalar yellow(0, 255, 255);

	cout << "yellow: " << yellow << endl;
	Mat img1(256, 256, CV_8SC3, yellow);
	for (int i = 0; i < 4; i++)
	{
		cout << yellow[i] << endl;
	}
	
}