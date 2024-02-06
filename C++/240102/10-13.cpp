#include <iostream>
#include<string>
#include<map>
using namespace std;

class Score
{
public:
	Score(string program) {
		this->program = program;
	}
	void run();
	
	

private:
	string program;
	map<string, int> scoremap;
	bool checkInputError();
	void insert();
	void search();

};





void Score::run()
{
	cout << "점수 관리 프로그램"<<program<< "을 시작합니다." << endl;
	while (true)
	{
		cout << "입력:1, 조회:2, 종료:3 >>";
		int index;
		cin >> index;
		if (checkInputError())continue;
		switch (index)
		{
		case 1:insert();
			break;
		case 2:search();
			break;
		case 3:cout << "프로그램을 종료합니다" << endl;
			return;
		}

	}
}

bool Score::checkInputError()
{
	if (cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
	cout << "입력 오류" << endl;
	return true; // 오류 있음
    }
	else return false;
}

void Score::insert()
{
	string name;
	int score;
	while (true)
	{
		cout << "이름과 점수>>";
		cin >> name >> score;
		if (checkInputError())continue;
		if (scoremap.find(name) != scoremap.end()) {
			cout << name << "의 점수를 수정할수 없음" << endl;
			break;
		}
		
		scoremap.insert(make_pair(name, score));
		break;

	}
}

void Score::search()
{
	string name;

	while (true)
	{
		cout << "이름>>>";
		cin >> name;
		if (scoremap.find(name) == scoremap.end())
		{
			cout << name << "의 점수를 불러올수없습니다." << endl;
			break;
		}
		else {
			cout << name<<"의 점수는 "<<scoremap[name] << endl;
			break;
		}
	}
	

}

int main() {
	Score high("High Score");
	high.run();


}
