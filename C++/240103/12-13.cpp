#include <iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

class Find
{
public:
	Find(const char* f) {
		fin.open(f);
		if (!fin) {
			cout << f << "������ �б� ����" << endl;
			exit(0);
		}	// end of if ���� �б� ���н� ����;
		string line;
		while (getline(fin, line))
		{
			v.push_back(line);
		}	// end of while vector v �� ���� ���κ��� �Է�;	

		cout << f << "���� �б� �Ϸ�" << endl;

	}	//end of  Find ������ 

	~Find() { fin.close(); }	// �Ҹ��� ���� �ݱ�;
	void run();

private:
	vector<string>v;
	ifstream fin;
	void search(string word);
	bool exist(string word);

};

void Find::run()
{
	cout << "�˻��� �����մϴ�. �ܾ �Է����ּ���" << endl;
	while (true)
	{
		cout << "�ܾ�>>";
		string word;
		cin >> word;
		if (word == "exit")return;
		if (exist(word)) search(word);



	}

}

void Find::search(string word)
{
	int length = (int)word.length();
	for (int i = 0; i < v.size(); i++)
	{
		
			
			int count = 0;
			for (int j = 0; j < length; j++)
			{
				string sercondword = v[i];
				if (word[j] != sercondword[j])break;
				else count++;
				
				if (count == length) cout << v[i] << endl;
			} //end of for �Ѱ��� ���ڸ� �ٲ� ������ ����Ѵ�;

			

	}	//end of for

}	//end of search

bool Find::exist(string word)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == word) {
			
			return true;
		}

	}
	cout << "�߰��Ҽ�����" << endl;
	return false;
} //end of exist

int main() {


	Find word("c:\\Temp\\words.txt");
	word.run();




}

