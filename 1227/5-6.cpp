#include <iostream>
#include<string>
using namespace std;




char& find(char a[], char c, bool& success) {
	int ren = strlen(a);
	for (int i = 0; i < ren; i++)
	{
		if (a[i] == c) {
			success = true;
			return a[i];
		}

	}
	return a[0];
	success = false;


}

int main() {
	char s[] = "Mike";
	cout << s << endl;
	bool b = false;
	char& loc = find(s, 'M', b);
	if (b == false) {
		cout << "M���߰���������" << endl;
		return 0;
	}
	loc = 'm';
	cout << "M�� m���� ��ȯ" << endl;
	cout << s << endl;



}