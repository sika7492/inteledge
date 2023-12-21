#include <iostream>
#include <string>
using namespace std;

int main() {
	string passwd;
	cout << "새암호를 입력하시요>>";
	cin >>passwd;
	string passwd2;
	cout << "새암호를 다시 한 번 입력하세요.>>";
	cin >> passwd2;

	if (passwd == passwd2)cout << "같습니다.";
	else cout<<"틀립니다.";



}

