#include <iostream>
using namespace std;

class Point
{
public:
	Point(int x = 0, int y = 0) {
		this->x = x, this->y = y;
	}
	friend istream& operator >>(istream& ins, Point& a) {
		cout << "x ÁÂÇ¥ >>";
		ins >> a.x;
		cout << "y ÁÂÇ¥ >>";
		ins >> a.y;
		return ins;
	}
	friend ostream& operator <<(ostream& stream, Point a) {
		stream << "(" << a.x << "," << a.y << ")";
		return stream;
	}



private:
	int x, y;
};

int main() {

	Point p;
	cin >> p;
	cout << p;



}