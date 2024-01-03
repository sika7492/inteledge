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
			cout << f << "파일을 읽기 실패" << endl;
			exit(0);
		}	// end of if 파일 읽기 실패시 종료;
		string line;
		while (getline(fin, line))
		{
			v.push_back(line);
		}	// end of while vector v 에 파일 라인별로 입력;	

		cout << f << "파일 읽기 완료" << endl;

	}	//end of  Find 생성자 

	~Find() { fin.close(); }	// 소멸자 파일 닫기;
	void run();

private:
	vector<string>v;
	ifstream fin;
	void search(string word);
	bool exist(string word);

};

void Find::run()
{
	cout << "검색을 시작합니다. 단어를 입력해주세요" << endl;
	while (true)
	{
		cout << "단어>>";
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
			} //end of for 한개의 문자를 바꿔 같으면 출력한다;

			

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
	cout << "발견할수없읍" << endl;
	return false;
} //end of exist

int main() {


	Find word("c:\\Temp\\words.txt");
	word.run();




}

