#include "opencv2/opencv.hpp"
#include <iostream>


using namespace cv;
using namespace std;

int main() {


	Mat img1 = imread("dog.bmp");
	cout << "img1�� dog.bmp�� �ҷ��ɴϴ�." << endl;

	Mat img2 = img1;		//���� ���� ����Ʈ��ũ
	cout << "Mat img2 = img1�� ����Ͽ� �����մϴ�." << endl;
	Mat img3;				
	img3 = img1;			//�������� ����Ʈ ��ũ
	cout << "img3 = img1�� ����Ͽ� �����մϴ�." << endl;

	

	Mat img4 = img1.clone();	//�������� �ϵ帵ũ
	Mat img5;
	img1.copyTo(img5);			//�������� �ϵ帵ũ

	img1.setTo(Scalar(0, 255, 255));	// yellow

	imshow("img1", img1);	
	imshow("img2", img2);
	imshow("img3", img3);
	imshow("img4", img4);
	imshow("img5", img5);
	

	waitKey();
	destroyAllWindows();
}