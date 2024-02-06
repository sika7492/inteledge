#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "가위 바위 보 게임을 합니다 . 가위, 바위, 보 중에서 입력하세요" << endl;
	
	string s;
	cout << "로미오 >>";
	cin >> s;

	string t;
	cout << "줄리엣>>";
	cin >> t;

	if (s == "가위" && t == "가위")
		cout << "로미오와 줄리엣은 비겼습니다" << endl;
	if (s == "가위" && t == "바위")
		cout << "줄리엣이 이겼습니다" << endl;
	if (s == "가위" && t == "보")
		cout << "로미오가 이겼습니다" << endl;
	if (s == "보" && t == "가위")
		cout << "줄리엣이 이겼습니다" << endl;
	if (s == "보" && t == "바위")
		cout << "로미오가 이겼습니다" << endl;
	if (s == "보" && t == "보")
		cout << "로미오와 줄리엣은 비겼습니다" << endl;
	if (s == "바위" && t == "보")
		cout << "줄리엣이 이겼습니다" << endl;
	if (s == "바위" && t == "가위")
		cout << "로미오가겼습니다" << endl;
	if (s == "바위" && t == "바위")
		cout << "로미오와 줄리엣은 비겼습니다" << endl;



}