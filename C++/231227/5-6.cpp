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
		cout << "M을발견하지못함" << endl;
		return 0;
	}
	loc = 'm';
	cout << "M을 m으로 변환" << endl;
	cout << s << endl;



}