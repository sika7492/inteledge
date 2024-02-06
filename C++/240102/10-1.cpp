#include <iostream>

using namespace std;

template <class T>
T biggest(T x[], int size)
{
	T big= x[0];
	for (int i = 0; i < size; i++)
	{
		if (x[i] > big)big = x[i];
	}
	return big;
}
int main() {
	
	int x[] = { 1,10,100,5,4 };
	int size = sizeof(x)/sizeof( x[0]);

	cout << biggest(x, size) << endl;



}
