#include <iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
	string number = "012456789", integer = "integer";

	ofstream fout("c:\\temp\\test1.txt");
	if (!fout){
		cout << "c:\\temp\\test1.txt ������ ���� �����ϴ�.";
		return 0;

	}
	fout << number << endl;
	fout << integer << endl;
	fout.close();




}