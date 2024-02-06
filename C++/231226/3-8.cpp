#include <iostream>
#include <string>
using namespace std;

class Integer
{
public:
	Integer(int a);
	Integer(string a);
	int get();
	int set(int a);
	bool isEven();
	

private:
	int number;
};

Integer::Integer(int a)
{
	number = a;
}

Integer::Integer(string a)
{
	number = stoi(a);
}

int Integer::get()
{
	return number;
}

int Integer::set(int a)
{
	number = a;
	return number;
}

bool Integer::isEven()
{	
	if ((number % 2) == 0)
		return true;
	else return false;
}




int main() {
	Integer n(30);
	cout << n.get() << ' ';
	n.set(50);
	cout << n.get() << ' ';

	Integer m("300");
	cout << m.get() << ' ';
	cout << m.isEven();


}
