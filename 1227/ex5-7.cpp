#include <iostream>
using namespace std;

class Circle
{
public:
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	void setRadius(int radius){ this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }

private:
	int radius;
};
void readRadius(Circle& c) {
	int r;
	cout << "���� ������ �������� �Է��ϼ���;";
	cin >> r;
	c.setRadius(r);


}
int main() {

	Circle donut;
	readRadius(donut);
	cout << "donut�� ���� =" << donut.getArea() << endl;
}
