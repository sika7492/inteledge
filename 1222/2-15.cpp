#include <iostream>
#include <cstring>
using namespace std;


int main() {
	while (true) {
		cout << "\n?  ";
		int number1, number2;
		int end;
		char op;
		cin >> number1 >> op >> number2;
		switch (op)
		{
		case '+':end = number1 + number2;
			break;
		case '-':end = number1 - number2;
			break;
		case '*':end = number1 * number2;
			break;
		case '/':end = number1 / number2;
			break;
		case '%':end = number1 % number2;
			break;

		default:
			break;
		}//end of switch
		cout << number1 << op << number2 << "=" << end;
	}
}


