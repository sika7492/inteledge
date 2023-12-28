#include <iostream>
#include <string>

using namespace std;


class Circle
{
public:
	Circle(int radius = 1) { this->radius = radius; }
	int getRadius() { return radius; }
	double getArea() { return 3.14 * radius * radius; }
	void setRadius(int radius) { this->radius = radius; }

private:
	int radius;
};

class NamedCircle : public Circle
{
public:
	
	NamedCircle(int size=0, string name="") :Circle(size) {
		this->name = name;
	}
	void show() { cout << "�������� " << "�� " << this->name << endl; }
	string getname() { return name; }
	void setname(string name) {
		this->name = name;
	}
	
private:
	string name;
};

void biggerArea(NamedCircle p[], int size)
{
	int id = 0;
	for (int i = 0; i < size; i++)
	{
		if (p[i].getRadius() > p[id].getRadius())
			id = i;
	}
	cout << "������ ���� ū ���ڴ� " << p[id].getname() << "�Դϴ�" << endl;
}


int main() {
	NamedCircle pizza[5];
	cout << "5���� ���� �������� ���� �̸��� �Է��ϼ���" << endl;
	for (int i = 0; i < 5; i++)
	{
		int a;
		string b;
		cout << i + 1 << ">>";
		cin >> a >> b;
		pizza[i].setRadius(a);
		pizza[i].setname(b);
	}
	biggerArea(pizza, 5);





}