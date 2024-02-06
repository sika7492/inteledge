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
	}	//�Ա�


	void subMoney(int money) {
		if (this->money < money)
		{
			cout << "�ܾ��� �����մϴ�" << endl;
			return;
		}
		else {
			this->money -= money;
		}
	}	//���
	void search() {
		cout << "���¹�ȣ�� �����ָ��� �Է��ϼ���>>";
		int id; string name;
		cin >> id >> name;

	}

private:
	
	string  name;	//������
	int  money;	//���¹�ȣ �ܾ�
	int id;

};

class BankManger
{
public:
	BankManger() { cout << "������ ���Ƚ��ϴ�."; }
	~BankManger() { cout << "������ �������ϴ�"; }
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
		cout << "���� ��� : 1  ��� : 2 �Ա� : 3  �ܾ���ȸ :4  (-1�� �Է��Ͻø� �����մϴ�.)";
		int menu;
		cin >> menu;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "���ڿ��� �Է��Ͽ����ϴ�. �ٽ� �Է����ּ���" << endl;
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
	cout << "�̸��� �������ּ���";
	cin >> name;
	cout << "���� ��ȣ�� (" << id << ") �Դϴ�" << endl;
	BankAccount p (id, name, money);
	cout << "�߰��� ���¿� �Ա��Ͻðڽ��ϱ�?";
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
	cout << "���¹�ȣ�� �̸��� �Է��ϼ���";
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "���ڿ��� �Է��Ͽ����ϴ�. �ٽ� �Է����ּ���" << endl;
		return;
	}

	if (bank[id - 1].getName() == name)
	{
		int money;
		cout << "�Ա��� �ݾ��� �Է��ϼ���" << endl;
		cin >> money;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "���ڿ��� �Է��Ͽ����ϴ�. �ٽ� �Է����ּ���" << endl;
			return;
		}
		bank[id - 1].addMoney(money);

		cout << "�ܾ��� " << bank[id - 1].getMoney() << "�� �Դϴ�" << endl;
		

	}
	

}

void BankManger::subBankAccount()
{
	{
		int id;
		string name;
		cout << "���¹�ȣ�� �̸��� �Է��ϼ���";
		cin >> id >> name;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "���ڿ��� �Է��Ͽ����ϴ�. �ٽ� �Է����ּ���" << endl;
			return;
		}

		if (bank[id - 1].getName() == name)
		{
			int money;
			cout << "����� �ݾ��� �Է��ϼ���" << endl;
			cin >> money;
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "���ڿ��� �Է��Ͽ����ϴ�. �ٽ� �Է����ּ���" << endl;
				return;
			}
			if (bank[id - 1].getMoney() < money) {
				cout << "�ܾ��� �����մϴ�" << endl;
				return;
			}
			bank[id - 1].subMoney(money);
			cout << "�ܾ��� " << bank[id - 1].getMoney() << "�� �Դϴ�" << endl;


		}

	}
}

void BankManger::show()
{
	int id;
	string name;
	cout << "���¹�ȣ�� �̸��� �Է��ϼ���";
	cin >> id >> name;
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "���ڿ��� �Է��Ͽ����ϴ�. �ٽ� �Է����ּ���" << endl;
		return;
	}

	if (bank[id-1].getName() == name)
	{
		cout <<"�ܾ��� "<< bank[id - 1].getMoney() << "�� �Դϴ�" << endl;
	}

	
}

int main() {

	BankManger ssk;
	ssk.run();



}



