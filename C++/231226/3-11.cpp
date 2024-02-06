#include <iostream>
#include "3-11Box.h"
using namespace std;


int main() {

	Box b(10, 2);
	b.draw();
	cout << endl;
	b.setSize(7, 4);
	b.seFill('^');
	b.draw();



}