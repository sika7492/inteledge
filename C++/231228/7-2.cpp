#include <iostream>
#include<string>

using namespace std;

class Book
{
public:
	Book(string title = " ", int price = 0, int page = 0) { this->title = title, this->price = price, this->page = page; }
	void show() { cout << title << " " << price << " " << page << endl; }
	string gettitle() { return title; }
	bool operator == (int op2);
	bool operator == (string op2);
	bool operator == (Book op2);
private:
	string title;
	int price, page;
};

bool Book::operator==(int op2)
{
	if (this->price==op2)return true;
	else return false;
	
}

bool Book::operator==(string op2)
{
	if (this->title == op2)return true;
	else return false;

}

bool Book::operator==(Book op2)
{
	/*
		Book tem =*this

		if(tem==op2)  는 불가능
	
	
	*/


	if (this->title == op2.title) {
		if (this->price == op2.price) {
			if (this->page == op2.page)return true;
		}
	}
	return false;

}


int main() {
	Book a("명품 c++", 30000, 500), b("고품 c++", 30000, 500);
	if (a == 30000) cout << "정가 30000원" << endl;              //가격비교
	if (a == "명품 c++") cout << "명품 c++" << endl;              //타이틀 비교
	if (a == b) cout << "같은 책입니다." << endl;              // 클래스 비교
}
