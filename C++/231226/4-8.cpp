#include <iostream>
using namespace std;

class circle8
{
public:
	circle8();
	void  setradius(int r);
	double getarea();
private:
	int radius;
};

circle8::circle8()
{
	radius = 1;
}

void circle8::setradius(int r)
{
	radius = r;
}

double circle8::getarea()
{
	return 3.14 * radius * radius;
}


int main() {
	cout << "���� ������>>";
	int n;
	cin >> n;
	circle8* c = new circle8[n];
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		cout << "�� " << i + 1 << "�� �������� >> ";
		int ra;
		cin >> ra;
		c[i].setradius(ra);

		if (c[i].getarea() > 100)count++;

	}
	cout << "������ 100���� ū���� " << count << "�� �Դϴ�";





}
