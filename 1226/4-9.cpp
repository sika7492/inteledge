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
	cout << "�̸��� ��ȭ ��ȣ�� �Է����ּ���." << endl;
	int num=3;
	person* p = new person[num];
	for (int i = 0; i < num; i++)
	{
		cout << "��� " << i+1 << ">>";
		string a,b;
		cin >> a >> b;
		p[i].set(a, b);
	}
	cout << "������� �̸��� ";
	for (int i = 0; i < num; i++)
	{
		cout << p[i].getname()<<' ';
	}
	cout << "\n ��ȭ��ȣ�� �˻��մϴ�. �̸��� �Է��ϼ���>>";
	string na;
	cin >> na;
	for (int i = 0; i < num; i++)
	{
		if (p[i].getname() == na)cout << "��ȭ��ȣ�� " << p[i].gettel();
	}






}

