#include <iostream>
using namespace std;

class Circle
{
public:
	Circle();
	Circle(int r);
	void setRadius(int r){ radius = r; }
	double getArea();

private:
	int radius;
};

Circle::Circle()
{
	radius = 1;
}

Circle::Circle(int r)
{
	radius = r;
}

double Circle::getArea()
{
	return 3.14* radius* radius;
}

int main() {


	Circle carray[3][6];

	carray[0][0].setRadius(10);
	carray[1][0].setRadius(20);
	carray[2][0].setRadius(30);
	carray[0][1].setRadius(10);
	carray[0][2].setRadius(10);
	carray[1][1].setRadius(20);
	carray[1][2].setRadius(20);
	carray[2][2].setRadius(30);
	carray[2][1].setRadius(30);
	int carraysize1 = sizeof(carray) / sizeof(carray[0]);  //[carraysize1][]
	int carraysize2 = sizeof(carray[0]) / sizeof(carray[0][0]);  //[][carraysize2]


	cout << sizeof(carray) << " " << sizeof(carray[0][0]) << " " << sizeof(carray[0]) << endl;
	cout << carraysize1 << " " << carraysize2 << endl;
	
	
	for (int i = 0; i < carraysize1; i++)
	{
		cout << "Circle" << i << " 의 면적은 " << carray[i][0].getArea() << endl;

	}
	Circle *p;
	p = carray[0];
	Circle* pp;
	pp= carray[1];


	Circle** cdp;
	cdp = new Circle * [carraysize2];
	for (int i = 0; i < carraysize2; i++)
		cdp[i] = new Circle;
	Circle** cdp2;
	cdp2 = new Circle * [carraysize2];
	for (int i = 0; i < carraysize2; i++)
		cdp2[i] = new Circle;

	for (int i = 0; i < carraysize2; i++)
	{
		cout << "Circle" << i << " 의 면적은 " << (**cdp).getArea() << endl;
		p++;
	}

	

}

