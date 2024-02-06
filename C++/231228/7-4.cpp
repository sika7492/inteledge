#include <iostream>
#include<string>

using namespace std;

class Book
{
public:
	Book(string title = " ", int price = 0, int page = 0) { this->title = title, this->price = price, this->page = page; }
	void show() { cout << title << " " << price << " " << page << endl; }
	string gettitle() { return title; }
	friend bool operator <  (string op1,Book op2);

private:
	string title;
	int price, page;
};

bool operator < (string op1, Book op2)
{
	if (op1 < op2.title)return true;
	
	return false;
}


int main() {
	Book a("청춘", 20000, 300);
	string b;
	cout << "책 이름을 입력하세여 >>";
	getline(cin, b);
	if (b < a)
		cout << a.gettitle() << "이" << b << "보다 뒤에 있었구나" << endl;



}

