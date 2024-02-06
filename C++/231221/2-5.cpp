#include <iostream>
using namespace std;

int main() {
	cout << "문자를 입력받으시오(100개 미만)";
	char charater[100];
	cin.getline(charater, 100, '\n');
	int x_num=0;
	for (int i = 0; i < 100; i++)
	{
		if (charater[i] == 'x')x_num++;
	}
	cout << "x의 갯수는 " << x_num;
}
