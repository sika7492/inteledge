#include <iostream>
using namespace std;   // std:: ��������

int main() {
	cout << "�ʺ� �Է��Ͻÿ�>>";      

	int width;
	cin >> width;       //width ���� �Է¹���

	cout << "���̸� �Է��Ͻÿ� >>";

	int height;
	cin >> height >>width;      //height ���� �Է� ����

	int area = width * height;
	 
 	cout << "������ " << area << endl;  
	cout << width;

}