#include <iostream>
using namespace std;

class MyInSteak
{
public:
	MyInSteak();
	bool push(int n);
	bool pop(int& n);
private:
	int p[10];
	int tos;
};

MyInSteak::MyInSteak()
{
	tos = 0;
}

bool MyInSteak::push(int n)
{
	if (tos==10) 
		return false;
	else {
		p[tos] = n;
		tos++;
	return true;
	}
}

bool MyInSteak::pop(int& n)
{
	if (tos==0)return false;
	else  {
		tos--;
		n=p[tos];
		
		return true;
	}
}
int main() {
	MyInSteak a;
	for (int i = 0; i < 11; i++)
	{
		if (a.push(i))cout << i << ' ';
		else cout << endl << i + 1 << "번째 stack full" << endl;

	}
	int n;
	for (int i = 0; i < 11; i++)
	{
		if (a.pop(n))cout << n << ' ';
		else cout << endl << n << "번째 stack enpty" << endl;

	}
	cout << endl;

}

