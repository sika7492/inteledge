#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;


void new_alpa_or_num();

int main() {
	cout << "아래에 한줄을 입력하시요 (exit를 입력하면 종료합니다.)" ;
	while (true)
	{
		string text;
		cout << "\n>>>";
		getline(cin, text);
		if (text == "exit")break;
		
		srand((unsigned)time(0));
		int n = rand();
		n = n % text.length();
		;
		int c = rand() % 26;
		char changechar = 'a' + c;
		if (text[n]== 'a' + c)
			changechar = 'A' + c;
		text[n] = changechar;
		
		cout << text<<endl;


	}


	



}



