#include <iostream>
using namespace std;

class Accmulator
{
public:
	Accmulator(int value) { this->value = value; }
	Accmulator& add(int n);
	int get() { return value; }

private:
	int value;
};

int main() {
	Accmulator acc(10);
	acc.add(5).add(6).add(7);
	cout << acc.get();
}

Accmulator& Accmulator::add(int n)
{
	value += n;
	return *this;
	
}
