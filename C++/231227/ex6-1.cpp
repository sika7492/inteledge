#include <iostream>
using namespace std;

int bigger(int a, int b) {

	if (a >= b)return a;
	return b;
}

double bigger(double a, int b) {

	if (a >= b)return a;
	return b;
}

double bigger(int a, double b) {

	if (a >= b)return a;
	return b;
}
int bigger(int a[], int b) {
	int res = a[0];

	for (int i = 0; i < b; i++)
	{
		if (a[i] > res)res = a[i];
		

	}
	return res;

}

int main() {
	int array[5] = { 1,2,3,4,5 };
	cout << bigger(7, 5) << endl;
	cout << bigger(7.8, 5) << endl;
	cout << bigger(7, 5.8) << endl;
	cout << bigger(array, 5) << endl;


}