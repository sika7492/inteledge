#include <iostream>
using namespace std;

#include "ccccc.h"

cccc::cccc()
{
	radius = 1;
	cout << "반지름이 " << radius << "인 원생성" << endl;
}

cccc::cccc(int r)
{
	radius = r;
	cout << "반지름이 " << radius << "인 원생성" << endl;
}

double cccc::getarea()
{
	return 3.14*radius* radius;
}
