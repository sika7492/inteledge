#include <iostream>
using namespace std;

void half(double &a) {
	a = a / 2;
}

int main() {

	double n = 20;
	half(n);
	cout << n;



}