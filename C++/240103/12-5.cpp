#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool finderror(string line) {
	for (int i = 0; i < line.size(); i++)
	{
		if ((line[i] == '/') && (line[i + 1] == '/'))return false;

	}
	return true;

}

int main() {
	
	ifstream fin("12-5source.cpp");
	if (!fin) {
		cout << "12-5source.cpp�� ���� �����ϴ�" << endl;
		return 0;
	}
	string line;
	while (getline(fin, line)) {
		if (finderror(line)) {
			cout << line << endl;
		}
		
	}
	fin.close();

}