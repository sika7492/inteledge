#include<iostream>

using namespace std;

template <class T>
T biggest(T a[],int size) {
	T tmp = a[0];
	for (int i = 0; i < size; i++)
	{
		if (tmp < a[i])tmp = a[i];
	}
	return tmp;
	
}



int main() {
	int a[] = { 1,2,3,4,5,6,7,8,9 };
	int sizea = sizeof(a) / sizeof(a[0]);

	char b[] = { 'a','b','c','d','A' };
	int sizeb = sizeof(b) / sizeof(b[0]);
	double c[]= { 1.2,2.5,3.7,4.2,5,6,7,8,9.4 };
	int sizec = sizeof(c) / sizeof(c[0]);
	cout << "int �迭 a�� ���� ū���� " << biggest(a, sizea) << endl;
	cout << "char �迭 b�� ���� ū���� " << biggest(b, sizeb) << endl;
	cout << "double �迭 c�� ���� ū���� " << biggest(c, sizec) << endl;

}