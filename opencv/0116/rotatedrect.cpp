#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	RotatedRect rr1(Point2f(40, 30), Size2f(40, 20), 30.f);

	Point2f pts[4];
	rr1.points(pts);

	Rect br = rr1.boundingRect();
	cout << "rr1 �� ������ " << rr1.size<<endl;
	cout << "rr1 �� �߽�   " << rr1.center << endl;
	cout << "rr1 �� ����   " << rr1.angle << endl;
	cout << "rr1 ��ǥ�� ";
	for (int i = 0; i < 4; i++)
	{
		cout << pts[i] << " ";
	}
	cout << endl;
	cout << "rr1�� �ٿ�� �ڽ��� ũ�� :"<< br << endl;

}