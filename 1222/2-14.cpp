#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int money=0;
	while (true)
	{

	
		int number=0;
		char menu[100];
		cout << "\n���������� 2000�� �Ƹ޸�ī�� 2300�� īǪġ�� 2500��\n�ֹ���>>";
		cin >> menu >> number;
		if (strcmp(menu, "����������")==0) {
			cout << 2000 * number << "�Դϴ�. ���ְԵ弼��";
			money += number * 2000;
		}
		else if (strcmp(menu, "�Ƹ޸�ī��")==0) {
			cout << 2300 * number << "�Դϴ�. ���ְԵ弼��";
			money += number * 2300;
		}
		else if (strcmp(menu, "īǪġ��")==0) {
			cout << 2500 * number << "�Դϴ�. ���ְԵ弼��";
			money += number * 2500;
		}
		else cout << "�ٽ��ֹ��ϼ���";

		if (money >= 20000) {
			cout << "\n���ø�����" << money << "�Դϴ� ������ �����մϴ�.";
			break;
		}
	}//end of while
	
}