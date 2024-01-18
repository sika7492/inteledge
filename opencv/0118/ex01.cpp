
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;


Point pt01d, pt02d;
Mat img;
Mat dst;
Size size_dst;
int a, b, c, d;
void on_mouse(int event, int x, int y, int flags, void*);

int main()
{

	cout << "Hello OpenCV " << CV_VERSION << endl;

	img = imread("lenna.bmp");

	if (img.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	namedWindow("img");

	setMouseCallback("img", on_mouse);
	imshow("img", img);






	waitKey();

	return 0;
}

void on_mouse(int event, int x, int y, int flags, void*) {

	switch (event)
	{
	case EVENT_LBUTTONDOWN:
		pt01d = Point(x, y);
		cout << "EVENT_LBUTTONDOWN:" << x << ", " << y << endl;
		break;
	case EVENT_LBUTTONUP:

		pt02d = Point(x, y);
		if (pt01d.x > pt02d.x) {
			a = pt01d.x - pt02d.x;
			c = pt02d.x;
		}
		else {
			a = pt02d.x - pt01d.x;
			c = pt01d.x;
		}
		if (pt01d.y > pt02d.y) {
			b = pt01d.y - pt02d.y;
			d = pt02d.y;
		}
		else {
			b = pt02d.y - pt01d.y;
			d = pt01d.y;
		}

		cout << a << b;
		//Size size_dst(a, b);				// size_dst(a,b); operator() 또는 함수 포인터 형식에 대한 변환 함수가 없는 클래스 형식의 개체에 대한 호출입니다.
											//Size를 미리 선언하면 size_dst = {a, b};  또는 size_dst.width = a, size_dst.height = b; 이런식으로 표현해야한다.
											//오류	C2361	'size_dst' 초기화가 'default' 레이블에 의해 생략되었습니다.filter	D : \SONGSIKYEONG\0118\filter\ex01.cpp	85

		size_dst = { a, b };

		dst = img(Rect(c, d, a, b));
		imshow("dst", dst);
		imwrite("captured_image.bmp", dst);

		break;
		//case EVENT_MOUSEMOVE:
		//	if (flags & EVENT_FLAG_LBUTTON) {
		//
		//	}
		//	break;
	default:
		break;
	}

}
