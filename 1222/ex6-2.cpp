#include <iostream>
using namespace std;

int big(int a, int b) {
	if (a > b)return a;
	else return b;

}

bool div3(int n) {
	if (n % 3 == 0) {
		return true;
	}
	else return false;

}

int main() {

	int a, b,c;

	cout << "두정수를 입력하시요>>";
	cin >> a >> b;
	c = big(a, b);
	cout << a << "와" << b << "중에 큰값은" << c << "입니다" << endl;
	if (div3(c) == 1)cout << c << "는 3의 배수입니다.";
	else cout << c << "는 3의 배수가 아닙니다.";
	

}