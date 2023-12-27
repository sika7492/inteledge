#include <iostream>
#include <string>
using namespace std;

class Circle12
{
public:
	double getArea() { return 3.14 * radius * radius; }
	string getName() { return name; }
	void setCricle(string name, int radius);
private:
	int radius;
	string name;

};

void Circle12::setCricle(string name, int radius)
{
	this->name = name;
	this->radius = radius;
}
class CircleManger
{
public:
	CircleManger(int n);
	~CircleManger();
	void serchByName();
	void serchByArea();

private:
	int size;
	Circle12* p;
};

CircleManger::CircleManger(int n)
{	
	this->size = n;
	p = new Circle12[size];
	for (int  i = 0; i < size; i++)
	{
		cout << "�� " << i + 1 << "�� �̸��� ������";
		string name;
		int radius;
		cin >> name>>radius;
		p[i].setCricle(name, radius);
	}
}

CircleManger::~CircleManger()
{
	delete[]p;
}

void CircleManger::serchByName()
{
	cout << "�˻��ϰ��� �ϴ� ���� �̸�";
	string name;
	cin >> name;
	for (int i = 0; i < size; i++)
	{
		if (p[i].getName() == name)cout << p[i].getName() << "�� ������ " << p[i].getArea()<<endl;
	}
}

void CircleManger::serchByArea()
{
	cout << "�ּ� ������ ������ �Է��Ͻÿ�>>";
	int area;
	cin >> area;
	for (int i = 0; i < size; i++)
	{
		if (p[i].getArea() > area)cout << p[i].getName() << "�� ������ " << p[i].getArea() << ',';
	}
}


int main() {

	cout << "���� ���� >>";
	int size;
	cin >> size;
	CircleManger kim(size);
	kim.serchByName();
	kim.serchByArea();




}