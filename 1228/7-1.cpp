#include <iostream>
#include<string>

using namespace std;

class Book
{
public:
	Book(string title = " ", int price = 0, int page = 0) { this->title = title, this->price = price, this->page = page; }
	void show() { cout << title << " " << price << " " << page << endl; }
	string gettitle() { return title; }
	Book& operator += (int op2);
	Book& operator-= (int op2);
private:
	string title;
	int price, page;
};
Book& Book::operator+=(int op2)
{
	this->price += op2;
	return *this;
}

Book& Book::operator-=(int op2)
{
	this->price -= op2;
	return *this;
}


int main() {
	Book a("รปรแ", 20000, 300), b("นฬทก", 30000, 500);
	a += 500;
	b -= 500;
	a.show();
	b.show();



}




