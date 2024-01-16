#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	RotatedRect rr1(Point2f(40, 30), Size2f(40, 20), 30.f);

	Point2f pts[4];
	rr1.points(pts);

	Rect br = rr1.boundingRect();
	cout << "rr1 의 사이즈 " << rr1.size<<endl;
	cout << "rr1 의 중심   " << rr1.center << endl;
	cout << "rr1 의 각도   " << rr1.angle << endl;
	cout << "rr1 좌표는 ";
	for (int i = 0; i < 4; i++)
	{
		cout << pts[i] << " ";
	}
	cout << endl;
	cout << "rr1의 바운딩 박스의 크기 :"<< br << endl;

}