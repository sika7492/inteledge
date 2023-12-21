#include <iostream>
#include <string>
using namespace std;


int main() {
	char name[100];
	string oldname;
	string newname;

	cout << "5명의 이름을 ';'으로 구분하여 입력하세요\n>>";
	for (int i = 0; i < 5; i++)
	{
		cin.getline(name, 100, ';');
		newname = name;
		cout << i + 1 << " : " + newname + " " << endl;
		if (newname > oldname)oldname = newname;

	}
	cout << "가장 긴 이름은 " + newname + "입니다";
		
}