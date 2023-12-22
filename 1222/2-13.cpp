#include <iostream>
using namespace std;

int main() {
	cout << "***** 승리장에 오신것을 환영합니다********\n\n\n";
	while (true)
	{
		int menu = 0;
		int people = 0;
		cout << "\n짜장:1  짬뽕:2  군만두:3  종료:4>>";
		
		cin >> menu;
		if (menu == 4) {
			cout << "영업종료";
			break;
		}//end of if menu 4 
		if ((menu != 4) && (menu != 3) && (menu != 2) && (menu != 1)) {
			{
				cout << "다시주문";
				continue;
			}
		}//end of if menu select fales
		

		cout << "몇인분  ";
		cin >> people;
		if (people >0) {
			switch (menu)
			{
			case	1: {

				cout << "짜짱" << people << "인분";
			}
					 break;
			case	2: cout << "짜짱" << people << "인분";

		
					 break;
			case	3: cout << "짜짱" << people << "인분";

					 break;
			default:
				break;
			}//end of switch

		}//end of if
		else  cout << "다시주문";
	}//end of while
}//end of main

