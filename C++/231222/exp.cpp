
#include "exp.h"

Exp::Exp()
{
	num1 = 1;
	num2 = 1;
}

Exp::Exp(int a)
{
	num1 = a;
	num2 = 1;
}

Exp::Exp(int a, int b)
{
	num1 = a;
	num2 = b;
}

int Exp::getValue()
{
	int a=num1;
	for (int i = 1;  i < num2;  i++)
	{
		a=a* num1;
	}

	return a;
}

int Exp::getBase()
{
	return num1;
}

int Exp::getExp()
{
	return num2;
}

bool Exp::equals(Exp b)
{	
	if(getValue()==b.getValue())
	return true;
}
