#include <iostream>

using namespace std;


template <class T1>
bool equalArrays(T1 x[], T1 y[], int size) {

	for (int i = 0; i < size; i++)
	{
		if (x[i] != y[i]) {
			return false;
		}

	}
	return true;
}
int main() {

	int x[] = { 1,2,3,4,5 };
	int y[] = { 1,2,3,4,5 };

	if (equalArrays(x, y, 5))cout << "같다" << endl;
	else cout << "다르다" << endl;




}