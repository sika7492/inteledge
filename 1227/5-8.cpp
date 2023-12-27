#include <iostream>
using namespace std;

class MyInSteak
{
public:
	MyInSteak();
	MyInSteak(int size);
	MyInSteak(const MyInSteak& s);
	~MyInSteak();
	bool push(int n);
	bool pop(int& n);
private:
	int *p;
	int tos;
	int size;
};

MyInSteak::MyInSteak()
{
	tos = 0;
	size = 10;
	p = new int[size];
}

MyInSteak::MyInSteak(int size)
{
	tos = 0;
	this->size = size;
	p = new int[size];
}

MyInSteak::MyInSteak(const MyInSteak& s)
{
	size = s.size;
	tos = s.tos;
	p = new int[size];
}

MyInSteak::~MyInSteak()
{
	delete[]p;
}

bool MyInSteak::push(int n)
{
	if (tos == size)
		return false;
	else {
		p[tos] = n;
		tos++;
		return true;
	}
}
bool MyInSteak::pop(int& n)
{
	if (tos == 0)return false;
	else {
		tos--;
		n = p[tos];

		return true;
	}
}

int main() {
	MyInSteak a(10);
	a.push(10);
	a.push(20);
	MyInSteak b = a;
	b.push(30);

	int n  ;
	a.pop(n);
	cout << "스택 a에서 펍한 값" << n << endl;
	b.pop(n);
	cout << "스택 b에서 펍한 값" << n << endl;
}