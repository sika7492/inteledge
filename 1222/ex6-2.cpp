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

	cout << "�������� �Է��Ͻÿ�>>";
	cin >> a >> b;
	c = big(a, b);
	cout << a << "��" << b << "�߿� ū����" << c << "�Դϴ�" << endl;
	if (div3(c) == 1)cout << c << "�� 3�� ����Դϴ�.";
	else cout << c << "�� 3�� ����� �ƴմϴ�.";
	

}