#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {

	Range r1(0, 10);

	int a = r1.size();
	if (r1.empty()) {
		cout << "r1�� start�� end�� ����" << endl;
	}
	else cout<< "r1�� start�� end�� �ٸ���" << endl;
	cout << "r1�� ������ :" << a << endl;
	cout <<"r1�� ��ǥ"<< r1 << endl;

}