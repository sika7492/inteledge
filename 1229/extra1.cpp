#include <iostream>
using namespace std;


class Square
{
public:
	Square(int width = 1, int height=1) {
		this->width = width; this->height = height;
	}
	~Square(){}
	friend void addSquare(Square square1,Square square2);


private:
	int height, width;
};

void addSquare(Square square1, Square square2)
{
	int addarea = (square1.width * square1.height) + (square2.width * square2.height);
	cout << "µÎ »ï°¢ÇüÀÇ ³ÐÀÌÀÇ ÇÕÀº : " <<addarea<< endl;


}

int main() {

	Square sq1(5, 3), sq2(4, 4);
	addSquare(sq1, sq2);
	



}