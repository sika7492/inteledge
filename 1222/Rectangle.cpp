#include <iostream>
using namespace std;

class Rectangle
{
public:
	int width, height;
	int getarea();
	



};

int Rectangle::getarea()
{
	return width * height;
}

int main() {
	Rectangle rect;
	rect.width = 10;
	rect.height = 5;
	cout << "사각형의 넓이는" << rect.getarea() << "입니다";

}

