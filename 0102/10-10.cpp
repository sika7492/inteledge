#include <iostream>
#include <vector>
#include <string>
#include<cstdio>
#include<ctime>
using namespace std;



int main() {
	cout << "������ ���� ���߱� ���� ����" << endl;
	vector<string>x;
	vector<string>y;
	string contry;
	string city;
	string input;
	vector<string>::iterator it;
	srand((unsigned)time(0));

	x.push_back("����");
	y.push_back("������");
	x.push_back("�̱�");
	y.push_back("������");

	while (true)
	{
		cout << "�����Է� : 1. ����: 2. ����: 3. " ;
		int menu;
		cin >> menu;
		if (menu == 3)break;
		
		if (menu == 1) {
			cout << "����  " << x.size() << "���� ���� �ԷµǾ��ֽ��ϴ�." << endl;
			while (true)
			{
				
				cout << x.size() +1<< ">>>";
				cin >> contry >> city;
				bool inputyn=true;
				for (it = x.begin(); it != x.end(); it++)
				{
					if (contry == *it) {
						inputyn = false;
						if (inputyn)cout << "alread exists !!" << endl;
						break;
					}
				
					
				}//end of for ox
				if ((contry == "no") && (city == "no")) {
					break;
				}//end of if nono 
				if (inputyn) {
					x.push_back(contry);
					y.push_back(city);
					
					
				}//end of if input yn
			}//end of while
		}// end of if menu1

		if (menu == 2) {
			while (true)
			{
				int qqq = rand() % x.size();
				cout << x[qqq] << "�� ������";
				cin >> city;
				if (city == "exit")break;
				if (y[qqq] == city) {
					cout << "Corret" << endl;
				}
				else cout << "no!!" << endl;

			}//end of while
			
		
		
		}//end of menu2;

	}
}