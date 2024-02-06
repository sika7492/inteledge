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

	cout << "원의 개수 = " << Circle::getNumofCrilces() << endl;


	delete[]p;
	cout << "원의 개수 = " << Circle::getNumofCrilces() << endl;
	Circle a;
	cout << "원의 개수 = " << Circle::getNumofCrilces() << endl;
	Circle b;
	cout << "원의 개수 = " << Circle::getNumofCrilces() << endl;




}

