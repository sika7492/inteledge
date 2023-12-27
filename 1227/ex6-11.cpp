#include <iostream>
using namespace std;

class Circle
{
public:
	Circle(int r=1);
	~Circle() { numOfCircles--; }
	static int getNumofCrilces() { return numOfCircles; }
private:
	static int numOfCircles;
	int radius;
};

Circle::Circle(int r)
{
	radius = r;
	numOfCircles++;
}

int Circle::numOfCircles = 0;

int main() {
	Circle* p = new Circle[10];

	cout << "���� ���� = " << Circle::getNumofCrilces() << endl;


	delete[]p;
	cout << "���� ���� = " << Circle::getNumofCrilces() << endl;
	Circle a;
	cout << "���� ���� = " << Circle::getNumofCrilces() << endl;
	Circle b;
	cout << "���� ���� = " << Circle::getNumofCrilces() << endl;




}

