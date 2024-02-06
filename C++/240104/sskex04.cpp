#include<iostream>
#include<string>
#include<vector>
using namespace std;

class BankAccount
{
public:
	BankAccount(int id, string name, int money) {
		this->id = id; this->name = name; this->money = money;

	}
	~BankAccount() {  }
	void setAccount(int id, string name, int money) {
		this->id = id; this->name = name; this->money = money;
	}
	int getid() { return id; }
	int getMoney() { return money; }
	string getName() { return name; }


	void addMoney(int money) {
		this->money += money;
	}	//입금


	void subMoney(int money) {
		if (this->money < money)
		{
			cout << "잔액이 부족합니다" << endl;
			return;
		}
		else {
			this->money -= money;
		}
	}	//출금
	void search() {
		cout << "계좌번호와 예금주명을 입력하세요>>";
		int id; string name;
		cin >> id >> name;

	}

private:
	
	string  name;	//예금주
	int  money;	//계좌번호 잔액
	int id;

};

class BankManger
{
public:
	BankManger() { cout << "은행이 열렸습니다."; }
	~BankManger() { cout << "은행이 닫혔습니다"; }
	void run();

private:
	vector<BankAccount>bank;
	void setBankAccount();
	void addBankAccount();
	void subBankAccount();
	void show();
	
};

void BankManger::run()
{
	while (true)
	{
		cout << "계좌 등록 : 1  출금 : 2 입금 : 3  잔액조회 :4  (-1을 입력하시면 폐점합니다.)";
		int menu;
		cin >> menu;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "문자열을 입력하였습니다. 다시 입력해주세요" << endl;
			continue;
		}
		
		switch (menu)
		{
		case 1:setBankAccount();
			break;
		case 2: subBankAccount();
			break;
		case 3: addBankAccount();
			break;
		case 4:show();
			break;
		case -1: 
			exit(0);
			break;
		default:
			break;
		}
		

	}
	
}

void BankManger::setBankAccount()
{
	int id = bank.size()+1;
	int money=0;
	string name;
	cout << "이름을 기입해주세요";
	cin >> name;
	cout << "계좌 번호는 (" << id << ") 입니다" << endl;
	BankAccount p (id, name, money);
	cout << "추가로 계좌에 입금하시겠습니까?";
	string yes;
	cin >> yes;
	if (yes == "yes") {
		cin >> money;
		p.addMoney(money);
	}
	bank.push_back(p);
}

void BankManger::addBankAccount()
{
	int id;
	string name;
	cin >> id >> name;
	cout << "계좌번호와 이름을 입력하세요";
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "문자열을 입력하였습니다. 다시 입력해주세요" << endl;
		return;
	}

	if (bank[id - 1].getName() == name)
	{
		int money;
		cout << "입금할 금액을 입력하세요" << endl;
		cin >> money;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "문자열을 입력하였습니다. 다시 입력해주세요" << endl;
			return;
		}
		bank[id - 1].addMoney(money);

		cout << "잔액은 " << bank[id - 1].getMoney() << "원 입니다" << endl;
		

	}
	

}

void BankManger::subBankAccount()
{
	{
		int id;
		string name;
		cout << "계좌번호와 이름을 입력하세요";
		cin >> id >> name;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "문자열을 입력하였습니다. 다시 입력해주세요" << endl;
			return;
		}

		if (bank[id - 1].getName() == name)
		{
			int money;
			cout << "출금할 금액을 입력하세요" << endl;
			cin >> money;
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "문자열을 입력하였습니다. 다시 입력해주세요" << endl;
				return;
			}
			if (bank[id - 1].getMoney() < money) {
				cout << "잔액이 부족합니다" << endl;
				return;
			}
			bank[id - 1].subMoney(money);
			cout << "잔액은 " << bank[id - 1].getMoney() << "원 입니다" << endl;


		}

	}
}

void BankManger::show()
{
	int id;
	string name;
	cout << "계좌번호와 이름을 입력하세요";
	cin >> id >> name;
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "문자열을 입력하였습니다. 다시 입력해주세요" << endl;
		return;
	}

	if (bank[id-1].getName() == name)
	{
		cout <<"잔액은 "<< bank[id - 1].getMoney() << "원 입니다" << endl;
	}

	
}

int main() {

	BankManger ssk;
	ssk.run();



}



