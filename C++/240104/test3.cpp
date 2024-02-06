#include <iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

int main() {
	/*const char* file = "c:\\windows\\system.ini";
	const char* outfile = "c:\\Temp\\test.txt";

	fstream fin(file, ios::in);
	if (!fin) {
		throw "line : 13 번  파일 열기 실패";

	}*/

	for (int i = 0; i < 20; i++)
	{
		
			if ((i == 0) || (i == 20 - 1)) {
				for ( int j= 0; j < 20; j++)
				{
					cout << "*";
				}
				cout << endl;
			}
			else {
				cout << "*";
				for (int j = 0; j < 18; j++)
				{
					cout << ' ';
				}
				cout << "*"<<endl;

			}
		
	}

	for (int i = 0; i < 10; i++)
	{
		if (i == 10 - 1) {
			for (int j = 0; j < 10; j++)
			{
				cout << "*";
			}
			cout << "*";
			cout << endl;
		}
		else{ 
			cout << "*";
			for (int j = 0; j < i; j++)
			{
				cout << ' ';
			}
			cout << "*";
			cout << endl;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10-i; j++)
		{
			cout << ' ';
			
		}
		for (int j = 0; j < 2*i-1; j++)
		{
			cout << "*";
		}
		cout << endl;


	}
}

