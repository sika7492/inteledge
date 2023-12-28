#include <iostream>
using namespace std;


class Color
{
public:
	Color(int red=0, int blue=0, int green=0) {
		this->red = red; this->blue = blue; this->green = green;
	}
	void show() { cout << red << " " << blue << " " << green << endl; }
	Color operator +(Color op2);
	bool operator ==(Color op2);
private:
	int red, blue, green;
};
Color Color::operator+(Color op2)
{
	Color tmp;
	tmp.red = this->red + op2.red;
	tmp.blue = this->blue + op2.blue;
	tmp.green = this->green + op2.green;
	return tmp;
}
bool Color::operator==(Color op2)
{
	if (this->red == op2.red) {
		if (this->blue == op2.blue) {
			if (this->green == op2.green)
				return true;
		}
	}
	return false;
}






int main() {
	Color red(255, 0, 0), blue(0, 0, 255), c;
	c = red + blue;
	c.show();

	Color fuchsia(255, 0, 255);
	if (c == fuchsia)
		cout << "보라색 맞음" << endl;
	else
		cout << "보라색 아님" << endl;
}


