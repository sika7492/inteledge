#include "opencv2/opencv.hpp"
#include <iostream>


using namespace cv;
using namespace std;

int main() {

	Mat img1 = imread("cat.bmp");

	if (img1.empty()) {
		cerr << "Image load failed!" << endl;
		return 0;
	}

	Mat img2 = img1(Rect(220, 120, 340, 240));					//��������
	Mat img3 = img1(Rect(220, 120, 340, 240)).clone();

	img2 = ~img2;												//img2�� ��ȭ�� img2���� �����

	imshow("img1", img1);
	imshow("img2", img2);
	imshow("img3", img3);
	cout << "cat.bmp �κ� �������� ����" << endl;
	imwrite("cat2.bmp",img1);

	waitKey();
	destroyAllWindows();
	

}