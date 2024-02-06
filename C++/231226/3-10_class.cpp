#include <iostream>


#include "3-10_head.h"



void Add::setValue(int num1, int num2)
{
	a = num1, b = num2;
}

int Add::calcultae()
{
	return a+b;
}



void Sub::setValue(int num1, int num2)
{
	a = num1, b = num2;
}

int Sub::calcultae()
{
	return a-b;
}







void Mul::setValue(int num1, int num2)
{
	a = num1, b = num2;
}

int Mul::calcultae()
{
	return a*b;
}



void Div::setValue(int num1, int num2)
{
	a = num1, b = num2;
}

int Div::calcultae()
{
	return a/b;
}
