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
	Account a("kitea", 1, 5000); //id1번 잔액 5000 이름이 케이트인 계좌 생성
	a.deposit(50000);			// 저금
	cout << a.getOwenr() << "의 잔액은" << a.inquiry() << endl;
	int money = a.withdraw(20000);//출금 20000
	cout<<a.getOwenr()<<"의 잔액은" << a.inquiry() << endl;

}