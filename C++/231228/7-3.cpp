#include <iostream>
#include<string>

using namespace std;

class Book
{
public:
	Book(string title = " ", int price = 0, int page = 0) { this->title = title, this->price = price, this->page = page; }
	void show() { cout << title << " " << price << " " << page << endl; }
	string gettitle() { return title; }
	bool operator ! ();
	
private:
	string title;
	int price, page;
};

bool Book::operator!()
{
	if (this->price == 0)return true;
	return false;
}// end of operator!()   0원인지 비교하는 연산자 함수

int main() {
	Book book("벼룩시장", 0, 50); 

	if (!book) cout << "가격은 0원이다." << endl;



}