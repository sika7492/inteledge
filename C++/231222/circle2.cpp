#include <iostream>
using namespace std;

class circle
{
public:
	int radius ; 
	circle();
	circle(int r);
	double	getarea();


};
circle::circle() : circle(1) {}
circle::circle(int r) {
	radius = r;
	return
}
double circle::getarea()
{
	return 3.14 * radius * radius;
}

int main() {

	circle pai;
	pai.radius = 1;
	cout << "파이의 넓이는 " << pai.getarea() << endl;
	circle pizza;
	pizza.radius = 10;
	cout << "피자의 넓이는 " << pizza.getarea() << endl;

}
