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
		cout << "1~9까지의 정수를 입력하세요>>";
		try {
			cin >> number;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(100, '\n');
				throw "문자열 입력 ";

			}
			if ((number <= 9) && (number >= 1)) {
				ex6(number);
			}
			else {
				throw   "1~9가 아닌 숫자입력";
			}

		}
		catch (const char* s) {
			cout <<   s<<": 예외처리 발생 :" << endl;
		}


	}
	




}