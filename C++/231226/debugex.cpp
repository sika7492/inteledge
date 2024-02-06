#include <iostream>
#include<stdio.h>
using namespace std;
void swap(int x, int y) {

	int tmp;
	tmp = x;
	x = y;
	y = tmp;

}
void swap(int* x, int* y) {
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

int main() {
	int a = 1, b = 6;
	swap(a, b);
	cout << "a =" << a << "b =" << b << endl;
	swap(&a, &b);
	cout << "a =" << a << "b =" << b << endl;
}