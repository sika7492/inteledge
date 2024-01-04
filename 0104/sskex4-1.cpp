#include<iostream>
#include<string>
#include<vector>
using namespace std;

void CharInputError() {
	if (cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		throw "문자열 입력 ";

	}
}

class BankAccount
{
public:
	BankAccount(int id, string name, int money) {
		this->id = id; this->name = name; this->money = money;
		cout << "프로그램을 시작합니다." << endl;

	}
	~BankAccount() { cout << "프로그램을 종료합니다" << endl; }
	void setAccount(int id, string name, int money) {
		this->id = id; this->name = name; this->money = money;
	}
	int getId() { return id; }
	int getMoney() { return money; }
	string getName() { return name; }


	void addMoney(int money) {

		this->money += money;
		cout << getName() << "님의 계좌번호 " << getId() << " 의 잔액은 " << getMoney() << " 원 입니다." << endl;
	}	//입금


	void subMoney(int money) {
		if (this->money < money)
		{
			cout << "잔액이 부족합니다" << endl;
			cout << getName() << "님의 계좌번호 " << getId() << " 의 잔액은 " << getMoney() << "원 입니다." << endl;
			return;
		}
		else {
			
			this->money -= money;
			cout << getName() << "님의 계좌번호 " << getId() << " 의 잔액은 " << getMoney() << "원 입니다." << endl;
		}
	}	//출금
	void show() {
		cout << getName() << "님의 계좌번호 " << getId() << " 의 잔액은 " << getMoney() << "원 입니다." << endl;
	}

	

private:
	
	string  name;	//예금주
	int  money;	//계좌번호 잔액
	int id;

};

int main() {
	 
	BankAccount a(1, "song", 5000);
	a.show();
	int money;
	try {
		cout << "입금할 금액을 입력하세요>> ";
		cin >> money;
		CharInputError();
		a.addMoney(money);
		cout << "출금할 금액을 입력하세요 >> ";
		cin >> money;
	
	CharInputError(); 
	a.subMoney(money);
	}
	catch (const char* s) {
		cout << s << ": 예외처리 발생 :" << endl;
	}

}

