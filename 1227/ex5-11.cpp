#include <iostream>
#include <string>
using namespace std;


class Person
{
public:
	Person(int id, const string* name);
	Person(const Person& person);
	~Person();
	void changName(const string* name);
	void show() { cout << id << "," << name << endl; }

private:
	string* name;
	int id;
};

Person::Person(int id, const string* name)
{
	this->id = id;
	int len = name->length();
	this->name = new string;
	
}

Person::Person(const Person& person)
{
	this->id = person.id;
	int len = strlen(person.name);
	this->name = new char[len + 1];
	strcpy(this->name, person.name);
	cout << "���� ������ ���� ���� ��ü�� �̸�" << this->name << endl;
}

Person::~Person()
{
	if(name)delete[] name;
}

void Person::changName(const string* name)
{
	if (strlen(name) > strlen(this->name))
		return;
	strcpy(this->name, name);
}

int main() {

	Person father(1, "Kitea");
	Person daughter(father);
	cout << "daghter ��ü �������� " << endl;
	father.show();
	daughter.show();

	daughter.changName("Grace");
	cout << "�� �̸��� �׷��̽��� ����" << endl;
	father.show();
	daughter.show();




}

