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

	cout << " \n �ΰ��� ������ �Է��Ͻÿ�>>";
	int a, b;
	cin >> a >> b;
	int n;
	n = biiger(a, b);
	cout << " �ΰ��� ������ ū���ڴ� " << n << "�Դϴ�.";
	if (div3(n) == 1)cout << n << "�� 3�� ����Դϴ�.\n";
	else cout << n << "�� 3�� ����� �ƴմϴ�.\n";
}