#include <iostream>
using namespace std;

class Color
{
public:
	Color();
	Color(int r,int g, int b);
	void setColor(int r, int g, int b);
	void show() { cout << red << ' ' << green << ' ' << blue << endl; }
private:
	int red, green, blue;
};

Color::Color()
{
	red= green=blue=0;
}

Color::Color(int r, int g, int b)
{
	red=r, green=g, blue=b;
}

void Color::setColor(int r, int g, int b)
{
	red = r, green = g, blue = b;
}

int main() {
	Color screenColor(255, 0, 0);
	Color *p;
	p = &screenColor;
	p->show();
	Color colors[3];
	p = colors;

	p->setColor(255, 0, 0);
	(p+1)->setColor(0, 255, 0);
	(p + 2)->setColor(0, 0, 255);

	p->show();
	(p + 1)->show();
	(p + 2)->show();

}