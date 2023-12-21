#include <iostream>
using namespace std;

int main() {
	int n;
	int j;
	for (j = 1; j < 10; j++) {
		for (n = 1; n < 10; n++) {
			cout << n << "x" << j << "=" << n * j<<"	";
		}
		cout << "\n";
	}
}