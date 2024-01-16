#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {

	Range r1(0, 10);

	int a = r1.size();
	if (r1.empty()) {
		cout << "r1의 start와 end는 같다" << endl;
	}
	else cout<< "r1의 start와 end는 다르다" << endl;
	cout << "r1의 사이즈 :" << a << endl;
	cout <<"r1의 좌표"<< r1 << endl;

}