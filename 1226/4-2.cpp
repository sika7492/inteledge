#include <iostream>
using namespace std;




int main() {
	cout << "���� 5�� �Է�";
	
	int* p = new int[5];
	for (int i = 0; i < 5; i++)
	{
		cin >> p[i];
	}
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		sum += p[i];
	}
	cout << "��� = " << sum / 5;
	
}