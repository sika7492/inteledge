#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

Mat img;
Point pt01d,pt02d;
void on_mouse(int event, int x, int y ,int flags, void*);

int main(void) {
	img = imread("lenna.bmp");
	if (img.empty()) {
		cerr << "파일읽기 실패" << endl;
		return -1;
	}

	namedWindow("img");
	setMouseCallback("img", on_mouse);

	imshow("img", img);

	waitKey();
	imwrite("mouse.bmp", img);
	return 0;

}
void on_mouse(int event, int x, int y ,int flags, void*) {

	switch (event)
	{
	case EVENT_LBUTTONDOWN:
		pt01d = Point(x, y);
		cout << "EVENT_LBUTTONDOWN: " << x << "," << y << endl;
		break;
	case EVENT_LBUTTONUP:
		cout << "EVENT_LBUTTONUP: " << x << "," << y << endl;
		rectangle(img, pt01d, pt02d, Scalar(0, 255, 255), 2);
		imshow("img", img);
		
		break;
	case EVENT_MOUSEMOVE:
		if (flags & EVENT_FLAG_LBUTTON) {
			pt02d = Point(x, y);
			
			
		}
		break;
	default:
		break;
	}

}