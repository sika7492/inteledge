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
	cout << "******�׺������� �����մϴ�*****" << endl;
	name = new string[2];
	cout << "ù���� ���� �̸�>>";
	cin >> name[0];
	cout << "�ι��� ���� �̸�>>";
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
				cout << name[i] << "���� �¸�";
				return;
			}
			else cout << "�ƽ�����" << endl;



		}
		

	}
}

int main() {
	GamblingGame king;
	king.run();
}

