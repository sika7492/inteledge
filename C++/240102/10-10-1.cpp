#include <iostream>
#include <vector>
#include <string>
#include<cstdio>
#include<ctime>
using namespace std;

class Nation
{
public:
	Nation(string nation, string capital) {
		this-> nation=nation, this->capital = capital;
	}
	string getnatrion() { return nation; }
	string getcapital() { return capital; }
	

private:
	string nation, capital;
};
class NationGame
{
public:
	NationGame();
	void run();


private:
	vector<Nation>v;
	void input();
	void list();
	void quiz();
	//bool exist(string capital);
};

NationGame::NationGame()
{
	Nation n[] = { Nation("미국", "와싱턴"), Nation("영국", "런던"), Nation("프랑스", "파리"),
		   Nation("중국", "베이찡"), Nation("일본", "도쿄"), Nation("러시아", "모스크바"),
		   Nation("브라질", "브라질리아"), Nation("독일", "베를린"), Nation("멕시코", "멕시코시티") };
	for (int i = 0; i < 9; i++)
		v.push_back(n[i]);

	srand((unsigned)time(0)); // 랜덤 초기화
}

void NationGame::run()
{
	cout << "나라의 수도 맞추기 게임 시작" << endl;
	list();
}

void NationGame::input()
{
	string nation ,capital;
	cout << "현재  " << v.size() << "개의 나라가 입력되어있습니다." << endl;
	while (true)
	{

		cout << v.size() + 1 << ">>>";
		cin >> nation >> capital;
		bool inputyn = true;
		for (int i=0; i<v.size(); i++)
		{
			if (nation == v[i].getnatrion()) {
				inputyn = false;
				if (inputyn)cout << "alread exists !!" << endl;
				break;
			}


		}//end of for ox
		if ((nation == "no") && (capital == "no")) {
			break;
		}//end of if nono 
		if (inputyn) {
			Nation n(nation, capital);
			v.push_back(n);
		}//end of if input yn


		}//end of while
}


void NationGame::list()
{
	cout << "정보입력 : 1. 퀴즈: 2. 종료: 3. ";
	int menu;
	while (true)
	{
		cin >> menu;
		switch (menu)
		{
		case 1:input();
			break;
		case 2:quiz();
			break;
		case 3:return;


		}

	}
	
}

void NationGame::quiz()
{
	while (true)
	{
		int index = rand() % v.size();
		cout << v[index].getnatrion() << "의 수도는";
		string capital;
		cin >> capital;
		if (capital == "exit")break;
		if (v[index].getcapital() == capital) {
			cout << "Corret" << endl;
		}
		else cout << "no!!" << endl;

	}//end of while
}

int main() {
	NationGame game;
	game.run();

}



