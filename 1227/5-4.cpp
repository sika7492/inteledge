#include <iostream>

using namespace std;

bool bigger(int a, int b, int& big) {
	if (a >= b) {
		big = a;
		return true;
	}
	else {
		big = b;
		return false;
	}


}
int main() {
	int num1, num2, num3;
	cout << "두개의 정수를 입력받으시요";
	cin >> num1 >> num2;
	if (bigger(num1, num2, num3)) {
		cout <<"첫번째 숫자가 크고 그 값은 "<< num3 <<"이다"<< endl;
	}
	else cout << "두번째 숫자가 크고 그 값은 " << num3 << "이다" << endl;



}
