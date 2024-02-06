#include <iostream>
using namespace std;
class Rectangle {
public:
	int width, height;
	bool isSquare();
	Rectangle();
	Rectangle(int w);
	Rectangle(int w,int h);
};
Rectangle::Rectangle():Rectangle(1){}
Rectangle::Rectangle(int w) {
	width = w;
	height = w;

}
Rectangle::Rectangle(int w,int h) {
	width = w;
	height = h;

}
bool Rectangle::isSquare(){
	if (width == height)return true;
	else return false;

}

int main() {
	Rectangle rect1;
	Rectangle rect2(7,8);
	Rectangle rect3(10);

	if (rect1.isSquare()) cout << "rect1은 정사각형이다." << endl;
	if (rect2.isSquare()) cout << "rect2은 정사각형이다." << endl;
	if (rect3.isSquare()) cout << "rect3은 정사각형이다." << endl;
}