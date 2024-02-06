#include <iostream>
using namespace std;
template <class T1>
T1* concat(T1 x[], int xsize, T1 y[], int ysize) {

	T1* tmp=new T1[xsize + ysize];
	for (int i = 0; i < xsize; i++)
	{
		tmp[i] = x[i];

	}
	for (int i = 0; i < ysize; i++)
	{
		tmp[xsize+i] = y[i];

	}
	return tmp;

}

int main() {
	int a[] = {1,2,3,4,5};
	int sizea = sizeof(a) / sizeof(a[0]);
	int b[] = { 6,7,8,9,10 };
	int sizeb = sizeof(b) / sizeof(b[0]);

	int*c = concat(a, sizea, b, sizeb);
	for (int i = 0; i < sizea+sizeb; i++)
	{
		cout << c[i] << " ";
	}

	delete[]c;




}