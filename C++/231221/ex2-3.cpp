#include <iostream>
using namespace std;   // std:: 생략가능

int main() {
	cout << "너비를 입력하시요>>";      

	int width;
	cin >> width;       //width 값을 입력받음

	cout << "높이를 입력하시요 >>";

	int height;
	cin >> height >>width;      //height 값을 입력 받음

	int area = width * height;
	 
 	cout << "면적은 " << area << endl;  
	cout << width;

}