#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	const char* file = "c:\\windows\\system.ini";


	ifstream fin(file);
	if (!fin) {
		cout << file << "���� ����";
		return 0;
	}

	cout << "�б� ����" << endl;
	ofstream fout("c:\\temp\\system.txt");
	if (!fout) {
		cout << "c:\\temp\\system.txt" << "���� ����";
		return 0;
	}
	int buf;
	string ch;
	while ((buf = fin.get()) != EOF)
	{
		buf = toupper(buf);
		cout << (char)buf;
		fout.put(buf);
	}
	
	//while (getline(fin, ch)) {
	//	cout << ch<<endl;
	//}

	cout << "���峡" << endl;
	fout.close();
	fin.close();
}
	