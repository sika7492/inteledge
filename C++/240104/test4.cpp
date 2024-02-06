#include <iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

int main() {
	const char* file = "c:\\windows\\system.ini";
	const char* outfile = "c:\\Temp\\test.txt";

	
	ifstream fin;
	fin.open(file);
	if (!fin) {
		cout<< "line : 13 번  파일 열기 실패";
		return 0;
	}
	fstream fout(outfile, ios::out, ios::binary);
	if (!fout) {
		cout<< "line : 17 번  파일 열기 실패";
	}
	int size = fin.tellg();
	cout << size;




	string str;
	vector<string>v;
	while (getline(fin,str))
	{
	
		v.push_back(str);

	}

	int numsize = v.size();
	for (int i = 0; i < numsize; i++)
	{
		int length = v[i].length();
		const char* b = v[i].c_str();
		
		fout.write(b, length);
		fout.put('\n');
		fout.put('\n');

		
	}
	string k;
	
	for (int i = 0; i < k.length(); i++)
	{
		fout.put(k[i]);
	}
	fin.close();
	fout.close();



}
