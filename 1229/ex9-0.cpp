#include <iostream>


using namespace std;

class Shape
{
public:
	virtual void draw(){  cout << "Shape을 그린다" << endl;  }
	 

};

class Circle : public Shape
{
public:
	virtual void draw() {
		cout << "Circle을 그린다"<<endl;
	}


};

class Rect : public Shape
{
public:
	virtual void draw() { cout << "Rect을 그린다" << endl; }


};

class Line : public Shape
{
public:
	virtual void draw() { cout << "Line을 그린다" << endl; }


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

