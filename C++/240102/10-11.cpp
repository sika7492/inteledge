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

	cout << "�԰���å�� �Է��ϼ��� �⵵�� -1�� �Է��ϸ� �԰� �����մϴ�." << endl ;
	int year;
	string title;
	string writor;

	while (true)
	{
		cout << "�⵵>>";
		cin >> year; cin.ignore(); // '\n' Ű�� Ű ���ۿ��� ���� �Ѵ�.
		if (year == -1)
			break;
		cout << "å�̸�>>";
		getline(cin, title);
		cout << "����>>";
		getline(cin, writor);
		Book n(year, title, writor);
		v.push_back(n);

	}

	cout << "���԰�� å�� " << v.size() << "�Դϴ�" << endl;

	cout << "�˻��ϰ��� �ϴ� ������ �̸���>>";
	getline(cin, writor);
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].getwritor() == writor) {
			cout << v[i].getyear() <<" " << v[i].getbook() << " " << v[i].getwritor() << " " << endl;
		}
	}
	cout << "�˻��ϰ��� �ϴ� å�� �̸���>>";
	getline(cin, title);
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].getbook() == title) {
			cout << v[i].getyear() << " " << v[i].getbook() << " " << v[i].getwritor() << " " << endl;
		}
	}




}