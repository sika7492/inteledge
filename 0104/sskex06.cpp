#include<iostream>
using namespace std;


void ex6(int num) {
	for (int i = 0; i < 9; i++)
	{
		int tmp = i + 1;
		cout << num << " * " << tmp << " = " << num * tmp << endl;
	}
}

int main() {
	while (true)
	{
		int number;
		cout << "1~9������ ������ �Է��ϼ���>>";
		try {
			cin >> number;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(100, '\n');
				throw "���ڿ� �Է� ";

			}
			if ((number <= 9) && (number >= 1)) {
				ex6(number);
			}
			else {
				throw   "1~9�� �ƴ� �����Է�";
			}

		}
		catch (const char* s) {
			cout <<   s<<": ����ó�� �߻� :" << endl;
		}


	}
	




}