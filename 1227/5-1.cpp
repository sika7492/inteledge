#include <iostream>

using namespace std;


class Circle
{
public:
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }

private:
	int radius;
};


void swap(Circle &a,Circle &b) {
	Circle tmp;
	tmp = a;
	a = b;
	b = tmp;
	
}


int main() {

	Circle one(10);
	Circle two(20);
	cout << "1�� ���� ������ " << one.getArea() << " 2������ ������" << two.getArea() << endl;
	swap(one, two);
	cout << "1���� 2���� �ٲ�" << endl;
	cout << "1�� ���� ������ " << one.getArea() << " 2������ ������" << two.getArea() << endl;






}

