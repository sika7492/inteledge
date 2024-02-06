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
	cout << "int 배열 a의 제일 큰값은 " << biggest(a, sizea) << endl;
	cout << "char 배열 b의 제일 큰값은 " << biggest(b, sizeb) << endl;
	cout << "double 배열 c의 제일 큰값은 " << biggest(c, sizec) << endl;

}