
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
		//Size size_dst(a, b);				// size_dst(a,b); operator() �Ǵ� �Լ� ������ ���Ŀ� ���� ��ȯ �Լ��� ���� Ŭ���� ������ ��ü�� ���� ȣ���Դϴ�.
											//Size�� �̸� �����ϸ� size_dst = {a, b};  �Ǵ� size_dst.width = a, size_dst.height = b; �̷������� ǥ���ؾ��Ѵ�.
											//����	C2361	'size_dst' �ʱ�ȭ�� 'default' ���̺� ���� �����Ǿ����ϴ�.filter	D : \SONGSIKYEONG\0118\filter\ex01.cpp	85

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
