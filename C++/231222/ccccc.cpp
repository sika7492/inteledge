#include <iostream>
using namespace std;

#include "ccccc.h"

cccc::cccc()
{
	radius = 1;
	cout << "�������� " << radius << "�� ������" << endl;
}

cccc::cccc(int r)
{
	radius = r;
	cout << "�������� " << radius << "�� ������" << endl;
}

double cccc::getarea()
{
	return 3.14*radius* radius;
}
