#pragma once
class Exp
{
public:
	Exp();
	Exp(int a);
	Exp(int a, int b);
	int getValue();
	int getBase();
	int getExp();
	bool equals(Exp b);


private:
	int num1, num2;

};

