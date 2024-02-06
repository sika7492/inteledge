#include <iostream>
#include<string>

using namespace std;


class Equation
{
public:
	Equation(int number1,  int number2) {
		this->number1 = number1, this->number2 = number2;
	}
	~Equation(){}
	int getNumber1() { return number1; }
	int getNumber2() { return number2; }
	
	void setEquation(int number1, string equation, int number2){ 
		this->number1 = number1, this->number2 = number2;
	}
	virtual void result() = 0;
private:
	
	int number1, number2;
};

class Addition : public Equation

{
public:
	Addition(int number1, int number2) : Equation(number1, number2) {

	}

	~Addition(){}

	virtual void result(){
		cout << getNumber1 << " + " << getNumber2() << " = " << getNumber1() + getNumber2() << endl;

	}
private:

};

class Subtraction : public Equation
{
public:
	Subtraction(int number1, int number2) : Equation(number1, number2) {}
	~Subtraction() {}
	virtual void result() {
		cout << getNumber1 << " - " << getNumber2() << " = " << getNumber1() - getNumber2() << endl;
	}
private:

};
class Multiplication : public Equation
{
public:
	Multiplication(int number1, int number2) : Equation(number1, number2) {}
	~Multiplication(){}
	virtual void result() {
		cout << getNumber1 << " * " << getNumber2() << " = " << getNumber1() * getNumber2() << endl;
	}
private:

};

