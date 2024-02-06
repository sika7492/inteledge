#include <iostream>

using namespace std;

char& find(char s[], int index) {
	return s[index];
}
char  c = 'a';
char& find2() {
	return c;
}

int main() {
	char name[] = "Mike";
	cout << name << endl;
	find(name, 0) = 'S';
	cout << name << endl;
	char& ref = find(name, 2);
	ref = 't';
	cout << name << endl;
	cout << c << endl;
	char a = find2();
	cout << a << endl;
	char& ref2 = find2();
	ref2 = 'M';
	cout << c << endl;
	find2() = 'b';
	cout << a << endl;
	cout << c << endl;


}