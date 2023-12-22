#include <iostream>
using namespace std;

class CoffeeMachine

{
public:
	CoffeeMachine(int a,int b,int c);
	void show();
	void dringkEspresso();
	void dringkAmericano();
	void dringkSugarCoffee();
	void fill();

private:
	int coffee, water, sugar;
};

CoffeeMachine::CoffeeMachine(int a, int b, int c)
{
	coffee = a;
	water = b;
	sugar = c;
}

void CoffeeMachine::show()
{
	cout << "커피머신상태, 커피:" << coffee << "   물 " << water << "  설탕" << sugar << endl;
}

void CoffeeMachine::dringkEspresso()
{
	coffee -= 2;
	water -= 1;

}

void CoffeeMachine::dringkAmericano()
{
	coffee -= 1;
	water -= 2;
}

void CoffeeMachine::dringkSugarCoffee()
{
	coffee -= 1;
	water -= 2;
	sugar -= 1;
}

void CoffeeMachine::fill()
{
	coffee = 10, water = 10, sugar = 10;
}

int main() {

	CoffeeMachine java(5, 10, 3);
	java.dringkEspresso();
	java.show();
	java.dringkAmericano();
	java.show();
	java.dringkSugarCoffee();
	java.show();
	java.fill();
	java.show();
}

