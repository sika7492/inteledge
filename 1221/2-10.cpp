#include <iostream>
#include <cstring>
using namespace std;

int main() {
	cout << "���ڿ� �Է�>>";
	string name;
	cin >> name;
	int n = size(name);
	for (int i = 1; i < n ; i++)
	{
		cout << name.substr(0, i)<<"\n";
	}
	



}