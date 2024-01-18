
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;


Point pt01d, pt02d;
Mat img;
Mat dst;
Mat frame, inversed;
int w = 400, h = 600;
Point2f srcPts[4], dstPts[4];
int a, b, c, d;
void on_mouse(int event, int x, int y, int flags, void*);
void camera_in();
Mat pers;
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
		if(!pers.empty())warpPerspective(frame, dst, pers, Size(w, h));
		if (!dst.empty()) {			//dst 읽기 실패 예외처리
			imshow("dst", dst);

		}
		

		

	
		setMouseCallback("frame", on_mouse);

		imshow("frame", frame);
		
		if (waitKey(10) == 27) // ESC key
			break;
	}

	destroyAllWindows();
}

void on_mouse(int event, int x, int y, int flags, void*)
{
	static int cnt = 0;

	if (event == EVENT_LBUTTONDOWN) {
		if (cnt < 4) {
			srcPts[cnt++] = Point2f(x, y);

			circle(frame, Point(x, y), 5, Scalar(0, 0, 255), -1);

			if (cnt == 4) {
				

				dstPts[0] = Point2f(0, 0);
				dstPts[1] = Point2f(w - 1, 0);
				dstPts[2] = Point2f(w - 1, h - 1);
				dstPts[3] = Point2f(0, h - 1);

				pers = getPerspectiveTransform(srcPts, dstPts);

				
				
			}
		}
	}
}




