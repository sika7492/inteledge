#include <iostream>
#include <string>
using namespace std;
#include "3.3.h"

Account::Account(string n, int b, int c)
{
	name = n;
	money = c;
	id = b;
}

int Account::deposit(int k)
{
	money += k;
	return money;
}


int Account::withdraw(int k)
{
	money -= k;
	return money;
}

int Account::inquiry()
{
	return money;
}

int main() {
	Account a("kitea", 1, 5000); //id1�� �ܾ� 5000 �̸��� ����Ʈ�� ���� ����
	a.deposit(50000);			// ����
	cout << a.getOwenr() << "�� �ܾ���" << a.inquiry() << endl;
	int money = a.withdraw(20000);//��� 20000
	cout<<a.getOwenr()<<"�� �ܾ���" << a.inquiry() << endl;

}