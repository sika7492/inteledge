#include "opencv2/opencv.hpp"
#include <iostream>


using namespace std;
using namespace cv;

void on_unsharp_mask(int pos, void* userdata);
int main() {
	
	Mat src = imread("rose.bmp",IMREAD_GRAYSCALE);			//rose.bmp를 그레이스케일로 불러옴
	if (src.empty()) {										//rose.bmp를 불러오지 못했거나 파일이 비어있다면 예외처리 발생
		cerr << "error: rose.bmp 파일 읽기 실패" << endl;
		return -1;
	}//end of if

	imshow("src", src);										//입력 영상을 출력한다.

	namedWindow("dst");										//

	//createTrackbar 함수에서 직접 1~8을 지정할수없어 0~7로 지정하고 on_unsharp_mask 함수 안에서 pos값을 1을 더한다.
	//setTrackbarPos 마찬가지로 중간값 4로 지정하기 위해 3을 지정.
	createTrackbar("Trackbar", "dst", 0, 7, on_unsharp_mask, (void*)&src);	
	setTrackbarPos("Trackbar", "dst", 3);
	waitKey();
	destroyAllWindows();


}//end of main

void on_unsharp_mask(int pos,void*userdata) {
	
	Mat src = *(Mat*)userdata;
	
	//가우시안 필터의 표준편차 sigma 값을 pos+1 로 설정하고 필터링을 수행한다
	Mat blurred;
	int sigma = pos+1;
	GaussianBlur(src, blurred, Size(), (double)sigma);
	
	//언샤프 마스크 필터링을 수행한다
	float alpha = 1.f;
	Mat dst = (1 + alpha) * src - alpha * blurred;

	cout << "sigma :" << sigma << endl;		//sigma 값을 cmd에 출력
	imshow("dst", dst);
	imwrite("blurred.bmp", blurred);		//가우시안필터를 이용한 블러링 영상을 blurred.bmp에 저장


}// end of on_unsharp_mask