#include <iostream>
#include <fstream>
using namespace std;

int main() {
	const char* file = "c:\\windows\\system.ini";

	ifstream fin(file);
	if (!fin) {
		cout << file << " 열기 오류" << endl;
		return 0;
	}
	int count = 0;
	int c;
	while ( !fin.eof()) { // EOF를 만날 때까지 문자 읽기			
		c = fin.get();
		cout << (char)c;
		count++;
	}
	cout << "읽은 바이트 수는 " << count << endl;
	fin.close(); // 파일 닫기
}
