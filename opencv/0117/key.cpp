#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {

	Mat img = imread("lenna.bmp");
	if (img.empty()) {
		cerr << "image load failed" << endl;
		return -1;
	}

	namedWindow("img");
	imshow("img", img);

	while (true) {
		int keycode = waitKey();

		if (keycode == 'i' || keycode == 'I') {
			img = ~img;
			imshow("img",img);
		}
		else if (keycode == 27 || keycode == 'q' || keycode == 'q') {
			break;
		}
	}
	return 0;


}