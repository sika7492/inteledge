#include <iostream>
using namespace std;

class Circle
{
public:
	Circle(int radius = 1) { this->radius = radius; }
	int getRadisu() { return radius; }
	

private:
	int radius;
};

template <class T>
T bigger(T a, T b) {
	if (a > b)return a;
	else return b;

}
Circle bigger(Circle a, Circle b) {
	if (a.getRadisu() > b.getRadisu())return a;
	else return b;
}

int main() {
	int a = 20, b=50, c;
	c = bigger(a, b);
	cout << "20과 50중 큰값은" << c << endl;
	Circle waffle(10), pizza(20), y;
	y = bigger(waffle, pizza);
	cout << "waffle과 피자중 큰것의 반지름은 " << y.getRadisu() << endl;
}