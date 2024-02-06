
#include <iostream>
using namespace std;

class Rect;
class RectManager;

class Rect                   //사각형 너비와 길이
{
public:
	Rect(int width, int height) { this->width = width, this->height = height; }
	friend RectManager;
	void show() { cout << width << ' ' << height; }

private:
	int width;
	int height;
};


class RectManager
{
public:
	void copy(Rect& a, Rect& b);
	bool equal(Rect a, Rect b);
private:

};

void RectManager::copy(Rect& a, Rect& b)
{
	a.width = b.width;
	a.height = b.height;
}

bool RectManager::equal(Rect a, Rect b)
{
	if (a.width == b.width && a.height == b.height)return true;
	else return false;
}




int main() {
	Rect a(3, 4), b(5, 6);
	RectManager man;

	man.copy(b, a);
	if (man.equal( a, b)) cout << "equal" << endl;
	else cout << "not equal" << endl;



}








