#include<iostream>

#include"opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main() {
	Vec<uchar, 3>p1, p2(0, 0, 255);
	cout << "p1:" << p1 << endl;
	cout << "p2:" << p2 << endl;
	p1.val[0] = 100;
	cout << "p1:" << p1 << endl;
	p1.val[1] = 100;
	cout << "p1:" << p1 << endl;



}