#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Data
{
public:
	Data(int a, int b, int c);
	Data(string a);
	int getYear();
	int getMonth();
	int getDay();
	void show();
private:
	int y, m, d;
};

Data::Data(int a, int b, int c)
{
	y = a, m = b, d = c;
}

Data::Data(string a)
{
	int index = a.find("/");
	string A = a.substr(0, index);
	int index1 = a.find("/", index + 1);
	string B = a.substr(index+1, index1-index-1);
	string C = a.substr(index1+1, a.length());

	y = stoi(A);
	m = stoi(B);
	d = stoi(C);
}

int Data::getYear()
{
	return y;
}

int Data::getMonth()
{
	return m;
}

int Data::getDay()
{
	return d;
}

void Data::show()
{
	cout << y << "³â" << m << "¿ù" << d << "ÀÏ" << endl;
}








int main() {

	Data birth(2014, 3, 20);
	Data independenceday("1945/8/15");
	independenceday.show();
	cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << endl;
}

