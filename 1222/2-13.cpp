#include <iostream>
using namespace std;

int main() {
	cout << "***** �¸��忡 ���Ű��� ȯ���մϴ�********\n\n\n";
	while (true)
	{
		int menu = 0;
		int people = 0;
		cout << "\n¥��:1  «��:2  ������:3  ����:4>>";
		
		cin >> menu;
		if (menu == 4) {
			cout << "��������";
			break;
		}//end of if menu 4 
		if ((menu != 4) && (menu != 3) && (menu != 2) && (menu != 1)) {
			{
				cout << "�ٽ��ֹ�";
				continue;
			}
		}//end of if menu select fales
		

		cout << "���κ�  ";
		cin >> people;
		if (people >0) {
			switch (menu)
			{
			case	1: {

				cout << "¥¯" << people << "�κ�";
			}
					 break;
			case	2: cout << "¥¯" << people << "�κ�";

		
					 break;
			case	3: cout << "¥¯" << people << "�κ�";

					 break;
			default:
				break;
			}//end of switch

		}//end of if
		else  cout << "�ٽ��ֹ�";
	}//end of while
}//end of main

