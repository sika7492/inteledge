#include<iostream>
#include<string>

using namespace std;

class Calculator
{
public:
	Calculator(int num1 = 1, int num2 = 1) {
		this->num1 = num1; this->num2 = num2;
	}		
	~Calculator(){}		
	virtual void show() = 0;
	int getNum1() { return num1; }
	int getNum2() { return num2; }
private:
	int num1, num2;
};
class Adder :public Calculator
{
public:
	Adder(int num1,int num2) : Calculator(num1,num2){}
	~Adder() {}
	virtual void show() {
		
		cout << getNum1() << " + " << getNum2() << " =" << getAdd() << endl;
	}
	
private:
	int getAdd() { return getNum1() + getNum2(); }
};

class Subtract :public Calculator
{
public:
	Subtract(int num1, int num2) : Calculator(num1, num2) {}
	~Subtract(){}
	virtual void show() {

		cout << getNum1() << " - " << getNum2() << " =" << getSub() << endl;
	}
	
private:
	int getSub() { return getNum1() - getNum2(); }
};
class Multiply :public Calculator
{
public:
	Multiply(int num1, int num2) : Calculator(num1, num2) {}
	~Multiply(){}
	virtual void show() {

		cout << getNum1() << " *" << getNum2() << " =" << getMul() << endl;
	}
	
private:
	int getMul() { return getNum1() * getNum2(); }
};
class Divide :public Calculator
{
public:
	Divide(int num1, int num2) : Calculator(num1, num2) {
		if (num2==0)
		{
			cout << "³ª´°¼ÀÀÇ ºÐ¸ð°¡ 0ÀÔ´Ï´Ù ";
			exit(0);
		}
	}
	~Divide() {}
	virtual void show() {

		cout << getNum1() << " / " << getNum2() << " = " << getDiv() << endl;
	}
	
private:
	double getDiv() { return (double)getNum1() * (double)getNum2(); }
};



int main() {

	Adder add(5, 5);
	Subtract sub(9, 2);
	Multiply mul( 5 , 7);
	Divide div(9, 10);
	add.show();
	sub.show();
	mul.show();
	div.show();



}
