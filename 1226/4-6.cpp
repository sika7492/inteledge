#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "아래에 한줄을 입력하시요 (exit를 입력하면 종료합니다.)";
	while (true)
	{
		string text;
		cout << "\n>>>";
		getline(cin, text);
		if (text == "exit") break;
		char temp;
		int size = text.length();
		for (int i = 0; i < size/2; i++)
		{
			temp=text[i];
			text[i] = text[size - i - 1];
			text[size - i - 1] = temp;
		}
		cout << text << endl;

	}
}