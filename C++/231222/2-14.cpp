#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int money=0;
	while (true)
	{

	
		int number=0;
		char menu[100];
		cout << "\n에스프레소 2000원 아메리카노 2300원 카푸치노 2500원\n주문은>>";
		cin >> menu >> number;
		if (strcmp(menu, "에스프레소")==0) {
			cout << 2000 * number << "입니다. 맛있게드세요";
			money += number * 2000;
		}
		else if (strcmp(menu, "아메리카노")==0) {
			cout << 2300 * number << "입니다. 맛있게드세요";
			money += number * 2300;
		}
		else if (strcmp(menu, "카푸치노")==0) {
			cout << 2500 * number << "입니다. 맛있게드세요";
			money += number * 2500;
		}
		else cout << "다시주문하세요";

		if (money >= 20000) {
			cout << "\n오늘매출은" << money << "입니다 영업을 종료합니다.";
			break;
		}
	}//end of while
	
}