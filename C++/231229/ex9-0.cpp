#include <iostream>


using namespace std;

class Shape
{
public:
	virtual void draw(){  cout << "Shape�� �׸���" << endl;  }
	 

};

class Circle : public Shape
{
public:
	virtual void draw() {
		cout << "Circle�� �׸���"<<endl;
	}


};

class Rect : public Shape
{
public:
	virtual void draw() { cout << "Rect�� �׸���" << endl; }


};

class Line : public Shape
{
public:
	virtual void draw() { cout << "Line�� �׸���" << endl; }


};
void paint(Shape* p) {
	p->draw();
}
int main() {


	Circle a, * pDer;
	pDer = &a;
	Shape* pBase;
	pBase = pDer;
	paint(new Shape());
	paint(new Circle());
	paint(new Rect());
	paint(new Line());
	paint(pBase);
}

