#include <iostream>
#include <string>
#include "3-10_head.h"

using namespace std;

int main() {
	while (true)
	{
		cout << "두 정수와 연사자를 입력하세요 >>";
		int num1, num2;
		string ch;
		cin >> num1 >> num2 >> ch;
		if (ch == "+") {
			Add a;
			a.setValue(num1, num2);
			
			cout << a.calcultae() << endl;
		}
		else if (ch == "-"){
			Sub s;	
			s.setValue(num1, num2);

		cout << s.calcultae() << endl;
	}
		else if (ch == "*"){
			Mul m;
			m.setValue(num1, num2);

			cout << m.calcultae() << endl;
}
		else if (ch == "/"){
			Div d;
			d.setValue(num1, num2);

			cout << d.calcultae() << endl;
		}
		else continue;


	}


}
