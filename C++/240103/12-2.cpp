#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	const char *file = "c:\\windows\\system.ini";
	string line = " : ";

	ifstream fin(file);
	if (!fin) {
		cout << file << "열기 오류";
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
