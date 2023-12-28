/*프렌드를 활용하여 7-1의 결과와 같게 코딩*/




#include <iostream>
#include<string>

using namespace std;

class Book
{
public:
	Book(string title = " ", int price = 0, int page = 0) { this->title = title, this->price = price, this->page = page; }
	void show() { cout << title << " " << price << " " << page << endl; }
	string gettitle() { return title; }
	friend Book operator += (Book& op1, int op2);    //
	friend Book operator-= (Book& op1, int op2);	//
private:
	string title;
	int price, page;
};
Book operator+=(Book& op1, int op2)
{
	op1.price += op2;
	return op1;
}

Book operator-=(Book& op1, int op2)
{
	op1.price -= op2;
	return op1;
}


int main() {
	Book a("청춘", 20000, 300), b("미래", 30000, 500);
	a += 500;
	b -= 500;
	a.show();
	b.show();



}




