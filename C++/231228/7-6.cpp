#include <iostream>

using namespace std;

class Matrix
{
public:
	Matrix(int a = 0, int b = 0, int c = 0, int d = 0) {
		p[0] = a, p[1] = b, p[2] = c, p[3] = d;
	}
	void show() { cout << "Martix  =  {" << p[0] << " " << p[1] << " " << p[2] << " " << p[3] << endl; }
	Matrix operator +(Matrix op2);
	Matrix& operator +=(Matrix op2);
	bool operator ==(Matrix op2);
private:
	int p[4];
};

Matrix Matrix::operator+(Matrix op2)
{
	Matrix tmp;
	for (int i = 0; i < 4; i++)
	{
		tmp.p[i]= this->p[i] + op2.p[i];

	}
	return tmp;
}

Matrix& Matrix::operator+=(Matrix op2)
{
	for (int i = 0; i < 4; i++)
	{
		this->p[i] += op2.p[i];

	}
	return *this;
}

bool Matrix::operator==(Matrix op2)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->p[i] != op2.p[i])return false;

	}
	return true;
}

int main() {
	Matrix a(1, 2, 3, 4), b(5, 6, 7, 8), c;
	c = a + b;
	a += b;
	a.show(), b.show(), c.show();

	if (a == c)
		cout << "a and c are the same" << endl;



}
