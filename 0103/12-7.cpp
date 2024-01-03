#include<iostream>
#include<fstream>
using namespace std;


int main() {

	ifstream fin("c:\\windows\\system.ini",ios::in | ios::binary);
	if (!fin) {
		cout << "c:\\windows\\system.ini을 열수없습니다." << endl;
		return 0;
	}
	ofstream fout("c:\\temp\\system12-7.txt", ios::out | ios::binary);
	if (!fout) {
		cout << "c:\\temp\\system12-7.txt 을 열수없습니다." << endl;
		return 0;
	}
	fin.seekg(0, ios::end);
	int size = fin.tellg();

	cout << "거꾸로 사본저장 시작" << endl;
	for (int i = 0; i < size; i++)
	{
		fin.seekg(size - 1 - i, ios::beg);
		int c = fin.get();
		fout.put((char)c);
		

	}

	cout << "거꾸로 사본저장 끝" << endl;
	

	fin.close();
	fout.close();

	



}