#include <iostream>
#include <fstream>
using namespace std;



int main() {

	ifstream fin("c:\\windows\\system.ini",ios::in | ios::binary);
	if (!fin) {
		cout << "c:\\windows\\system.ini을 열수없습니다." << endl;
		return 0;
	}
	ofstream fout("c:\\temp\\system.txt",ios::out | ios::binary);
	if (!fout) {
		cout << "c:\\temp\\system.txt 을 열수없습니다." << endl;
		return 0;
	}
	fin.seekg(0, ios::end);
	int n = fin.tellg();
	fin.seekg(0, ios::beg);

	int ncopy = n / 10;


	char *ch=new char[ncopy];
	int point=0;
	

	cout << "복사 시작" << endl;

	for (int i = 0; i < 10; i++)
	{
		fin.read(ch, ncopy);
		int real = fin.gcount();
		fout.write(ch, ncopy);
		cout << "." << real << "B ";
		cout << (i + 1) * 10 << "%" << endl;
		if (real < ncopy) {
			fout << endl << "12-6실습문제";
			break;
		}


	}
	delete[]ch;
	fin.close();
	fout.close();




}