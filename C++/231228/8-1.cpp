#include <iostream>
#include <string>

using namespace std;


class Circle
{
public:
	Circle(int radius = 1) { this->radius = radius; }
	int getRadius() { return radius; }
	double getArea() { return 3.14 * radius * radius; }
	void setRadius(int radius){ this->radius = radius; }

private:
	int radius;
};

class NamedCircle : public Circle
{
public:
	NamedCircle(int size, string name) :Circle(size) {
		this->name = name;
	}
	void show() { cout << "반지름이 " <<  "인 " << this->name << endl; }

private:
	string name;
};

int main() {

	NamedCircle waffle(3, "waffle");
	waffle.show();




}

