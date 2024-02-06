#include<iostream>
#include<string>
#include<vector>
using namespace std;

void CharInputError() {
	if (cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		throw "���ڿ� �Է� ";

	}
}

class BankAccount
{
public:
	BankAccount(int id, string name, int money) {
		this->id = id; this->name = name; this->money = money;
		cout << "���α׷��� �����մϴ�." << endl;

	}
	~BankAccount() { cout << "���α׷��� �����մϴ�" << endl; }
	void setAccount(int id, string name, int money) {
		this->id = id; this->name = name; this->money = money;
	}
	int getId() { return id; }
	int getMoney() { return money; }
	string getName() { return name; }


	void addMoney(int money) {

		this->money += money;
		cout << getName() << "���� ���¹�ȣ " << getId() << " �� �ܾ��� " << getMoney() << " �� �Դϴ�." << endl;
	}	//�Ա�


	void subMoney(int money) {
		if (this->money < money)
		{
			cout << "�ܾ��� �����մϴ�" << endl;
			cout << getName() << "���� ���¹�ȣ " << getId() << " �� �ܾ��� " << getMoney() << "�� �Դϴ�." << endl;
			return;
		}
		else {
			
			this->money -= money;
			cout << getName() << "���� ���¹�ȣ " << getId() << " �� �ܾ��� " << getMoney() << "�� �Դϴ�." << endl;
		}
	}	//���
	void show() {
		cout << getName() << "���� ���¹�ȣ " << getId() << " �� �ܾ��� " << getMoney() << "�� �Դϴ�." << endl;
	}

	

private:
	
	string  name;	//������
	int  money;	//���¹�ȣ �ܾ�
	int id;

};

int main() {
	 
	BankAccount a(1, "song", 5000);
	a.show();
	int money;
	try {
		cout << "�Ա��� �ݾ��� �Է��ϼ���>> ";
		cin >> money;
		CharInputError();
		a.addMoney(money);
		cout << "����� �ݾ��� �Է��ϼ��� >> ";
		cin >> money;
	
	CharInputError(); 
	a.subMoney(money);
	}
	catch (const char* s) {
		cout << s << ": ����ó�� �߻� :" << endl;
	}

}

