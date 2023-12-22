#pragma once
class Account
{
public:
	Account(string n, int b, int c);
	int deposit(int k);
	string getOwenr() { return  name; }
	int withdraw(int k);
	int inquiry();

private:
	int money,id;
	string name;
};

