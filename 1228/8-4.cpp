#include <iostream>
#include <string>

using namespace std;

class Point
{
	int x, y;
public:
	Point(int x, int y) { this->x = x; this->y = y; }
	int getX() { return x; }
	int getY() { return y; }
	void set(int x, int y) { this->x = x; this->y = y; }
protected:
	void move(int x, int y) { this->x = x; this->y = y; }

};//end of class Point

class ColorPoint : public Point
{
public:
	ColorPoint(int x=0, int y=0, string color="BLACK") : Point(x, y) { this->color = color; }
	void setColor(string color) { this->color = color; }
	void show() { cout << this->color << "색으로 (" << getX() << "," << getY() << ")에 위치한점입니다." << endl; }

private:
	string  color;

}; //end of class ColorPoint

int main() {

	ColorPoint zeroPoint;
	zeroPoint.show();

	ColorPoint cp(5, 5);
	cp.set(10, 20);
	cp.setColor("Blue");
	cp.show();






}//end of main