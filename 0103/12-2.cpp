#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	const char *file = "c:\\windows\\system.ini";
	string line = " : ";

	ifstream fin(file);
	if (!fin) {
		cout << file << "���� ����";
		return 0;
	}
	string buf;
	int count = 1;
	while (getline(fin,buf))
	{
		
		cout << count << line << buf << endl;
		count++;
	}
	fin.close();

}
