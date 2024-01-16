#include "opencv2/opencv.hpp"
#include <iostream>


using namespace cv;
using namespace std;

int main() {


	Mat img1 = imread("dog.bmp");
	cout << "img1에 dog.bmp을 불러옵니다." << endl;

	Mat img2 = img1;		//얕은 복사 소프트링크
	cout << "Mat img2 = img1를 사용하여 복사합니다." << endl;
	Mat img3;				
	img3 = img1;			//얕은복사 소프트 링크
	cout << "img3 = img1를 사용하여 복사합니다." << endl;

	

	Mat img4 = img1.clone();	//깊은복사 하드링크
	Mat img5;
	img1.copyTo(img5);			//깊은복사 하드링크

	img1.setTo(Scalar(0, 255, 255));	// yellow

	imshow("img1", img1);	
	imshow("img2", img2);
	imshow("img3", img3);
	imshow("img4", img4);
	imshow("img5", img5);
	

	waitKey();
	destroyAllWindows();
}