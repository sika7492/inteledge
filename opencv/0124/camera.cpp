#include <iostream>
#include "opencv2/opencv.hpp"


using namespace std;
using namespace cv;

void ex01();
void ex2();
void edge();

int main() {

	//ex01();
	ex2();
	//edge();
}

void ex01() {


	
	VideoCapture cap(1, CAP_DSHOW);
	cap.set(cv::CAP_PROP_FRAME_WIDTH, 1280);
	cap.set(cv::CAP_PROP_FRAME_HEIGHT, 720);
	if (!cap.isOpened()) {
		cerr << "Camera open failed!" << endl;
		return;
	}


	Mat  dst, frame, frame_gray;

	while (true)
	{
		cap >> frame;
		if (frame.empty()) {
			cerr << "에러" << endl;
			return;

		}

		cvtColor(frame, frame_gray, COLOR_BGR2GRAY);  //frame 값을 그레이스케일로 변경

		threshold(frame_gray, dst,55,255,THRESH_BINARY);	//임계값 55로 이진화를 하고 dst에 저장
		
		imshow("frame", frame);								//각각의 영상을 출력
		imshow("frame_gray", frame_gray);
		imshow("dst", dst);

		if (waitKey(1) == 27)						//esc입력시 while문종료
			break;



	}//end of while

	destroyAllWindows();
}
void ex2() {

	VideoCapture cap(1, CAP_DSHOW);
	cap.set(cv::CAP_PROP_FRAME_WIDTH, 1280);
	cap.set(cv::CAP_PROP_FRAME_HEIGHT, 720);
	if (!cap.isOpened()) {
		cerr << "Camera open failed!" << endl;
		return;
	}

	Mat   frame;
	cout << "손바닥을 카메라에 두고 esc키로 저장" << endl;
	while (true)
	{
		cap >> frame;
		if (frame.empty()) {
			cerr << "에러" << endl;
			return;

		}
		//imshow 함수로 카메라를 화면에 불러오고 esc가 입력되면 그 화면이 저장되면서 while문이 종료된다.
		imshow("frame", frame);
		if (waitKey(1) == 27) {
			imwrite("hand.bmp", frame);
			break;
		}
	}//end of while

	destroyAllWindows();

	//저장된 손바닥 사진을 불러온다.
	Mat hand = imread("hand.bmp");
	if (hand.empty()) {
		cerr << "hand.bmp 파일읽기 실패" << endl;
		return;
	}

	Mat hand_gray;
	cvtColor(hand, hand_gray, COLOR_BGR2GRAY);
	/*Mat binary;
	threshold(hand_gray, binary, 100, 255, THRESH_BINARY_INV |THRESH_OTSU);

	vector<vector<Point>> contours;
	findContours(binary, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	for (const auto& contour : contours)
	{
		drawContours(hand, vector<vector<Point>>{contour}, -1, cv::Scalar(0, 0, 255), cv::FILLED);
	}
	imshow("binary", binary);
	imshow("hand", hand);
	imshow("hand_gray", hand_gray);*/
	Mat hand_blur;
	Mat hand_edges;
	GaussianBlur(hand_gray, hand_blur, Size(3, 3), 0);
	Canny(hand_blur, hand_edges, 120, 200, 3, false);
	


	cout << "아무키나 입력하면 종료합니다." << endl;
	waitKey();
	return;









}



void edge() {				

	VideoCapture cap(1, CAP_DSHOW);
	cap.set(cv::CAP_PROP_FRAME_WIDTH, 1280);
	cap.set(cv::CAP_PROP_FRAME_HEIGHT, 720);
	if (!cap.isOpened()) {
		cerr << "Camera open failed!" << endl;
		return;
	}


	Mat frame_blur;
	Mat  dst, frame, frame_gray;
	Mat edges, mask, redImg;

	while (true)
	{
		cap >> frame;
		if (frame.empty()) {
			cerr << "에러" << endl;
			return;

		}

		//frame 값을 그레이스케일로 변경이후 가우시안 블러와 캔디 함수를 활용하여 엣지를 검출한다.
		cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
		GaussianBlur(frame_gray, frame_blur, Size(3, 3), 0);
		Canny(frame_blur, edges, 120, 200, 3, false);


		// Create a mask from the edges image
		mask = edges != 0;


		//redImg 는 frame의 사이즈로 레드 이미지 생성 이후 copyTo함수를 이용하여 frame에 엣지출력
		//copyTo(dst, mask, Stream::Null())
		redImg = Mat(frame.size(), frame.type(), Scalar(0, 0, 255));			
		redImg.copyTo(frame, mask);

		
		imshow("Canny edge detection", edges);
		imshow("frame", frame);
		if (waitKey(1) == 27)
			break;
	}//end of while

	destroyAllWindows();
}







