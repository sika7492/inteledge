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
	cout << "�ΰ��� ������ �Է¹����ÿ�";
	cin >> num1 >> num2;
	if (bigger(num1, num2, num3)) {
		cout <<"ù��° ���ڰ� ũ�� �� ���� "<< num3 <<"�̴�"<< endl;
	}
	else cout << "�ι�° ���ڰ� ũ�� �� ���� " << num3 << "�̴�" << endl;



}
