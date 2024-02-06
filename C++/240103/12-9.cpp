#include <iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

class Readfile
{
public:
	Readfile(const char* f) {
		fin.open(f, ios::in | ios::binary);
		if (!fin) {
			cout << f << "���� ����";
			exit(0);
		}	//end of if 

		string line;
		while (getline(fin, line)) { // �� ������ �о� ���ڿ� line�� ����
			v.push_back(line); // line�� ���ڿ��� ���Ϳ� ����
			
		}
		cout << f << "���� �б� �Ϸ�" << endl;
	}
	~Readfile() {
		fin.close();
		
	}
	void show(int line) {
		cout << v[line] << endl;
	}
	int getsize(int line) {
		return v[line].size();

	}
	void run();
	

private:
	ifstream fin;
	vector<string>v;

};






void Readfile::run(){
cout << "���� ��ȣ�� �Է��ϼ���. 1���� ���� ���� �Է��ϸ� ����" << endl;
while (true) {
	cout << ": ";
	int lineno;
	cin >> lineno; // ���� ��ȣ �Է�
	if (lineno > (int)v.size()) continue; // ���� ��ȣ�� ���� ũ�⺸�� ũ�� ���� ����
	else if (lineno < 1) { // ���� ��ȣ�� 0���� �۰ų� ������ 
		cout << "���� �մϴ�." << endl;
		break;
	}
	cout << v.at(lineno - 1) << endl; // ���� ��ȣ�� �ش��ϴ� ���� ���
 }
}





int main() {

	
	    Readfile findline("c:\\windows\\system.ini");
		findline.run();
	}
