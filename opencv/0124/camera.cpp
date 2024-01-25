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
			cerr << "����" << endl;
			return;

		}

		cvtColor(frame, frame_gray, COLOR_BGR2GRAY);  //frame ���� �׷��̽����Ϸ� ����

		threshold(frame_gray, dst,55,255,THRESH_BINARY);	//�Ӱ谪 55�� ����ȭ�� �ϰ� dst�� ����
		
		imshow("frame", frame);								//������ ������ ���
		imshow("frame_gray", frame_gray);
		imshow("dst", dst);

		if (waitKey(1) == 27)						//esc�Է½� while������
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
	cout << "�չٴ��� ī�޶� �ΰ� escŰ�� ����" << endl;
	while (true)
	{
		cap >> frame;
		if (frame.empty()) {
			cerr << "����" << endl;
			return;

		}
		//imshow �Լ��� ī�޶� ȭ�鿡 �ҷ����� esc�� �ԷµǸ� �� ȭ���� ����Ǹ鼭 while���� ����ȴ�.
		imshow("frame", frame);
		if (waitKey(1) == 27) {
			imwrite("hand.bmp", frame);
			break;
		}
	}//end of while

	destroyAllWindows();

	//����� �չٴ� ������ �ҷ��´�.
	Mat hand = imread("hand.bmp");
	if (hand.empty()) {
		cerr << "hand.bmp �����б� ����" << endl;
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
	


	cout << "�ƹ�Ű�� �Է��ϸ� �����մϴ�." << endl;
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
			cerr << "����" << endl;
			return;

		}

		//frame ���� �׷��̽����Ϸ� �������� ����þ� ���� ĵ�� �Լ��� Ȱ���Ͽ� ������ �����Ѵ�.
		cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
		GaussianBlur(frame_gray, frame_blur, Size(3, 3), 0);
		Canny(frame_blur, edges, 120, 200, 3, false);


		// Create a mask from the edges image
		mask = edges != 0;


		//redImg �� frame�� ������� ���� �̹��� ���� ���� copyTo�Լ��� �̿��Ͽ� frame�� �������
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







