#include <iostream>
using namespace std;

class Power
{
public:
	Power(int kick = 0, int punch = 0) { this->kick = kick, this->punch = punch; }
	void show() { cout << kick << "  " << punch << endl; }
	Power operator +(Power op2);
	Power operator *(Power op2);
private:
	int kick;
	int punch;
};



Power Power::operator+(Power op2)
{
	Power tmp;
	tmp.kick = this->kick + op2.kick;
	tmp.punch = this->punch + op2.punch;
	return tmp;
}
Power Power::operator*(Power op2)
{
	Power tmp;
	tmp.kick = this->kick * op2.kick;
	tmp.punch = this->punch * op2.punch;
	return tmp;
}


int main() {

	Power a(4, 5), b(7, 8), c(5,4),d;
	d = a + b*c;                       //연산자의 우선순위는 변하지 않음
	a.show();
	b.show();
	c.show();
	d.show();

}