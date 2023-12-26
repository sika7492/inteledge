#include <iostream>
#include "3-11Box.h"
using namespace std;

Box::Box(int w, int h)
{
	setSize(w, h); fill = '*';
}

void Box::seFill(char f)
{
	fill = f;
}

void Box::setSize(int w, int h)
{
	width = w, height = h;
}

void Box::draw()
{
	for (int i = 0; i < height; i++)
	{
		for (int m = 0; m < width; m++)cout << fill;
		cout << endl;
	}
}
