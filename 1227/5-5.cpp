#include <iostream>

using namespace std;

class Circle
{
public:
	
	Circle(int radius) { this->radius = radius; }
	void setRadius(int radius) { this->radius = radius; }
	int getRadius() { return radius; }
	double getArea() { return 3.14 * radius * radius; }
	void show() { cout << "반지름이 " << radius << "인 원"<< endl; }

private:
	int radius;
};
void icreaseBy(Circle& a, Circle b) {
	int r = a.getRadius() + b.getRadius();
	a.setRadius(r);
}

int main() {
	Circle x(10), y(5);
	icreaseBy(x, y);
	x.show();



}
