#include <iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

int main() {
	const char* file = "c:\\temp\\php.ini";

	fstream fin(file, ios :: in );
	if (!fin) {
		cout << file << "파일 열기 실패" << endl;
		return 0;
	}
	string line;
	vector<string>v;
	while (getline(fin,line))
	{
		v.push_back(line);

	}
	fin.close();
	string line3 = v[2];
	int pos=line3.find("=");
	string newline3= line3.substr(pos+1, 4);
	cout <<"변경전 : "<< newline3<<endl;
	if (newline3 == "1521") {
		newline3 = "3306";
	}
	else if (newline3 == "3306") {
		newline3 = "1521";
	}
	cout << "변경후 : " << newline3<<endl;
	for (int i = 0; i < 4; i++)
	{
		line3[pos + i + 1] = newline3[i];
	}

	v[2] = line3;		

	fstream fout(file, ios::out);
	if (!fout) {
		cout << file << "파일 열기 실패" << endl;
		return 0;
	}

	int size = v.size();

	for (int i = 0; i < size; i++)
	{
		const char* c = v[i].c_str();
		int length = v[i].length();

		fout.write(c, length);
		fout.put('\n');
	}
	fout.close();
	

}