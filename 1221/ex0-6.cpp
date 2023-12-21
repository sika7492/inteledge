#include <iostream>
using namespace std;

int biiger(int a, int b) {
	if (a > b) return a;
	else return b;
}

int div3(int n) {
	if ((n % 3) == 0) return true;
	else return false;

}

int main() {

	cout << " \n 두개의 정수를 입력하시요>>";
	int a, b;
	cin >> a >> b;
	int n;
	n = biiger(a, b);
	cout << " 두개의 정수중 큰숫자는 " << n << "입니다.";
	if (div3(n) == 1)cout << n << "은 3의 배수입니다.\n";
	else cout << n << "은 3의 배수가 아닙니다.\n";
}