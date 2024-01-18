
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;


Point pt01d, pt02d;
Mat img;
Mat dst;
Mat frame, inversed;


int a, b, c, d;
void on_mouse(int event, int x, int y, int flags, void*);
void camera_in();
int main()
{
	camera_in();
}
void camera_in()
{
	VideoCapture cap(1);

	if (!cap.isOpened()) {
		cerr << "Camera open failed!" << endl;
		return;
	}

	cout << "Frame width: " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
	cout << "Frame height: " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;
	


	//Mat frame, inversed;
	while (true) {
		cap >> frame;
		if (frame.empty())
			break; 
		dst = frame(Rect(c, d, a, b));
		if (!dst.empty()) {			//dst 읽기 실패 예외처리
			imshow("dst", dst);
			
		}
		
		
		//inversed = ~frame;
		setMouseCallback("frame", on_mouse);
		
		//dst = frame(Rect(c, d, a, b));
		//if(dst.empty())			//dst 읽기 실패
		//	break;
		//							///처리되지 않은 예외 발생(0x00007FF880D44FD9, ex2.exe): Microsoft C++ 예외: cv::Exception, 메모리 위치 0x0000001BE79DF220
		//imshow("dst", dst);		//
		imshow("frame", frame);
		//imshow("inversed", inversed);
		
		if (waitKey(10) == 27) // ESC key
			break;
	}

	destroyAllWindows();
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
		dst = frame(Rect(c, d, a, b));					//사진 캡처는 가능
		imshow("dst", dst);
		//Size size_dst(a, b);				
	
		
		
		//imshow("dst", dst);
		//imwrite("captured_image.bmp", dst);

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





