#include <iostream>
#include <string>
using namespace std;

int main() {
	string passwd;
	cout << "����ȣ�� �Է��Ͻÿ�>>";
	cin >>passwd;
	string passwd2;
	cout << "����ȣ�� �ٽ� �� �� �Է��ϼ���.>>";
	cin >> passwd2;

	if (passwd == passwd2)cout << "�����ϴ�.";
	else cout<<"Ʋ���ϴ�.";



}

