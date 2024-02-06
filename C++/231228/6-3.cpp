#include <iostream>

using namespace std;

int big(int a = 0, int b = 0, int c = 0) {

	if ((a >= b) && (a >= c))return a;
	else if ((b >= a) && (b >= c))return b;
	else return c;

}

int main() {
	int x = big(3, 5);
	int y = big(300, 60);
	int z = big(30, 60, 50);

	cout << x << " " << y << " " << z << endl;





}