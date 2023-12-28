#include <iostream>
#include <string>

using namespace std;

class point
{
public:
	void set(int x, int y) { this->x = x, this->y = y; }
	void show() { cout << " " << x << " " << y << endl; }
private:
	int x, y;
};

class colorpoint : public point
{
public:
	void setcolor(string color) { this->color = color; }
	void showcolor();
private:
	string color;
};

void colorpoint::showcolor()
{
	cout << " " << color;
	show();
}

int main() {


	colorpoint cp;
	colorpoint* pDer;
	point* pBase = &cp;

	pBase->set(3, 4);
	pBase->show();

	pDer = (colorpoint*)pBase;
	pDer->setcolor("red");
	pDer->showcolor();





}
