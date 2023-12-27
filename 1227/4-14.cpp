#include <iostream>
#include <cstdlib>
#include <string>
#include<ctime>


using namespace std;


class GamblingGame
{
public:
	GamblingGame();
	~GamblingGame();
	void run();
	

private:
	string* name;
	int* num;

};

GamblingGame::GamblingGame()
{
	


}

GamblingGame::~GamblingGame()
{
	delete[]name,num;
}

void GamblingGame::run()
{
	cout << "******겜블링게임을 시작합니다*****" << endl;
	name = new string[2];
	cout << "첫번쨰 선수 이름>>";
	cin >> name[0];
	cout << "두번쨰 선수 이름>>";
	cin >> name[1];
	num = new int[3];
	srand((unsigned)time(0));

	while (true)
	{
		for (int i = 0; i < 2; i++)
		{
			
			cout << name[i] << ":<Enter>";
			char buf[1000];
			cin.getline(buf, 999);

			
			for (int j = 0; j < 3; j++)
			{
				num[j] = rand() % 3;

			}
			cout << "\t\t" << num[0] << "\t" << num[1] << "\t" << num[2]<< "\t" ;
			if ((num[0] == num[1]) &&(num[1] == num[2])) {
				cout << name[i] << "님의 승리";
				return;
			}
			else cout << "아쉽군요" << endl;



		}
		

	}
}

int main() {
	GamblingGame king;
	king.run();
}

