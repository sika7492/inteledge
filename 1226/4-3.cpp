#include<iostream>
#include<string>
using namespace std;

int main() {
	cout << "���ڿ� �Է�>>";
	string text;
	getline(cin,text);
	int index = 0;
	int count = 0;
	while (true)
	{
		index=text.find('a', index);
		if (index == -1)break;
		count++;
		index++;

	}


	cout << "���� a�� "<<  count <<"�� �ֽ��ϴ�.";


}