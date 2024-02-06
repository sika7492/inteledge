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
	string buf;
	
	while (getline(fin, buf))
	{
		for (int i = 0; i < buf.size(); i++)
		{
			if ((buf[i] >= 'a') || (buf[i] >= 'z')) {
				buf[i] += ('A' - 'a');
			}
		}	//cout << (char)toupper(ch);  //ch를 int 로 받았음
			
		cout <<  buf << endl;
		
	}
	fin.close();

}
