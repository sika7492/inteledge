#include <iostream>
#include <string>
using namespace std;


int main() {
	char name[100];
	string oldname;
	string newname;

	cout << "5���� �̸��� ';'���� �����Ͽ� �Է��ϼ���\n>>";
	for (int i = 0; i < 5; i++)
	{
		cin.getline(name, 100, ';');
		newname = name;
		cout << i + 1 << " : " + newname + " " << endl;
		if (newname > oldname)oldname = newname;

	}
	cout << "���� �� �̸��� " + newname + "�Դϴ�";
		
}