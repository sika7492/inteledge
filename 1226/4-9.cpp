#include <iostream>
#include <string>
using namespace std;

class person
{
public:
	person();
	string getname() { return name; }
	string gettel() { return tel; }
	void set(string name, string tel);

private:
	string name;
	string tel;
};

person::person()
{
	name = tel = "0";
}

void person::set(string name, string tel)
{
	this-> name = name;
	this->tel = tel;
}

int main() {
	cout << "이름과 전화 번호를 입력해주세요." << endl;
	int num=3;
	person* p = new person[num];
	for (int i = 0; i < num; i++)
	{
		cout << "사람 " << i+1 << ">>";
		string a,b;
		cin >> a >> b;
		p[i].set(a, b);
	}
	cout << "모든사람의 이름은 ";
	for (int i = 0; i < num; i++)
	{
		cout << p[i].getname()<<' ';
	}
	cout << "\n 전화번호를 검색합니다. 이름을 입력하세요>>";
	string na;
	cin >> na;
	for (int i = 0; i < num; i++)
	{
		if (p[i].getname() == na)cout << "전화번호는 " << p[i].gettel();
	}






}

