#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char pass[11];
	string passwd = "yes";
	
	while (true)
	{
		cout << "�����ϰ������ yes�� �Է��ϼ���>>";
		cin.getline(pass, 11,'\n');
		if (pass==passwd) {
			cout << "�����մϴ�";
			break;
		}
		
		


	}


}