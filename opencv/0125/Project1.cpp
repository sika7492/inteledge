#include "opencv2/opencv.hpp"
#include <iostream>


using namespace std;
using namespace cv;

void on_unsharp_mask(int pos, void* userdata);
int main() {
	
	Mat src = imread("rose.bmp",IMREAD_GRAYSCALE);			//rose.bmp�� �׷��̽����Ϸ� �ҷ���
	if (src.empty()) {										//rose.bmp�� �ҷ����� ���߰ų� ������ ����ִٸ� ����ó�� �߻�
		cerr << "error: rose.bmp ���� �б� ����" << endl;
		return -1;
	}//end of if

	imshow("src", src);										//�Է� ������ ����Ѵ�.

	namedWindow("dst");										//

	//createTrackbar �Լ����� ���� 1~8�� �����Ҽ����� 0~7�� �����ϰ� on_unsharp_mask �Լ� �ȿ��� pos���� 1�� ���Ѵ�.
	//setTrackbarPos ���������� �߰��� 4�� �����ϱ� ���� 3�� ����.
	createTrackbar("Trackbar", "dst", 0, 7, on_unsharp_mask, (void*)&src);	
	setTrackbarPos("Trackbar", "dst", 3);
	waitKey();
	destroyAllWindows();


}//end of main

void on_unsharp_mask(int pos,void*userdata) {
	
	Mat src = *(Mat*)userdata;
	
	//����þ� ������ ǥ������ sigma ���� pos+1 �� �����ϰ� ���͸��� �����Ѵ�
	Mat blurred;
	int sigma = pos+1;
	GaussianBlur(src, blurred, Size(), (double)sigma);
	
	//����� ����ũ ���͸��� �����Ѵ�
	float alpha = 1.f;
	Mat dst = (1 + alpha) * src - alpha * blurred;

	cout << "sigma :" << sigma << endl;		//sigma ���� cmd�� ���
	imshow("dst", dst);
	imwrite("blurred.bmp", blurred);		//����þ����͸� �̿��� ���� ������ blurred.bmp�� ����


}// end of on_unsharp_mask