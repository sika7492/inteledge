#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	const char* file = "c:\\windows\\system.ini";


	ifstream fin(file);
	if (!fin) {
		cout << file << "열기 오류";
		return 0;
	}

	cout << "읽기 시작" << endl;
	ofstream fout("c:\\temp\\system.txt");
	if (!fout) {
		cout << "c:\\temp\\system.txt" << "열기 오류";
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

	cout << "저장끝" << endl;
	fout.close();
	fin.close();
}
	