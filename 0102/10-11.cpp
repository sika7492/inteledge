#include <iostream>
#include<string>
#include<vector>
using namespace std;


class Book
{
public:
	Book(int year, string book, string writor) {
		this->year = year, this->book = book, this->writor = writor;
	}
	int getyear() { return year; }
	string getbook() { return book; }
	string getwritor() { return writor; }

	

private:
	int year;
	string book, writor;
};

int main() {
	vector<Book>v;

	cout << "입고할책을 입력하세요 년도에 -1을 입력하면 입고를 종료합니다." << endl ;
	int year;
	string title;
	string writor;

	while (true)
	{
		cout << "년도>>";
		cin >> year; cin.ignore(); // '\n' 키를 키 버퍼에서 제거 한다.
		if (year == -1)
			break;
		cout << "책이름>>";
		getline(cin, title);
		cout << "저자>>";
		getline(cin, writor);
		Book n(year, title, writor);
		v.push_back(n);

	}

	cout << "총입고된 책은 " << v.size() << "입니다" << endl;

	cout << "검색하고자 하는 저자의 이름은>>";
	getline(cin, writor);
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].getwritor() == writor) {
			cout << v[i].getyear() <<" " << v[i].getbook() << " " << v[i].getwritor() << " " << endl;
		}
	}
	cout << "검색하고자 하는 책의 이름은>>";
	getline(cin, title);
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].getbook() == title) {
			cout << v[i].getyear() << " " << v[i].getbook() << " " << v[i].getwritor() << " " << endl;
		}
	}




}