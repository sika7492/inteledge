#include <iostream>
using namespace std;

int main() {
	cout << "���ڸ� �Է¹����ÿ�(100�� �̸�)";
	char charater[100];
	cin.getline(charater, 100, '\n');
	int x_num=0;
	for (int i = 0; i < 100; i++)
	{
		if (charater[i] == 'x')x_num++;
	}
	cout << "x�� ������ " << x_num;
}
