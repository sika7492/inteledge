#include <iostream>
#include<string>

using namespace std;

class Book
{
public:
	Book(string title = " ", int price = 0, int page = 0) { this->title = title, this->price = price, this->page = page; }
	void show() { cout << title << " " << price << " " << page << endl; }
	string gettitle() { return title; }
	friend bool operator == (Book op1,int op2);
	friend bool operator == (Book op1, string op2);
	friend bool operator == (Book op1, Book op2);
private:
	string title;
	int price, page;
};

bool operator==(Book op1, int op2)
{
	if (op1.price == op2)return true;
	else return false;

}

bool operator==(Book op1, string op2)
{
	if (op1.title == op2)return true;
	else return false;

}

bool operator==(Book op1, Book op2)
{

	if (op1.title == op2.title) {
		if (op1.price == op2.price) {
			if (op1.page == op2.page)return true;
		}
	}
	return false;

}


int main() {
	Book a("��ǰ c++", 30000, 500), b("��ǰ c++", 30000, 500);
	if (a == 30000) cout << "���� 30000��" << endl;              //���ݺ�
	if (a == "��ǰ c++") cout << "��ǰ c++" << endl;              //Ÿ��Ʋ ��
	if (a == b) cout << "���� å�Դϴ�." << endl;              // Ŭ���� ��
}
