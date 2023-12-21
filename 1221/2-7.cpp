#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char pass[11];
	string passwd = "yes";
	
	while (true)
	{
		cout << "종료하고싶으면 yes를 입력하세요>>";
		cin.getline(pass, 11,'\n');
		if (pass==passwd) {
			cout << "종료합니다";
			break;
		}
		
		


	}


}