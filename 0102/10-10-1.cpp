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
	Nation n[] = { Nation("�̱�", "�ͽ���"), Nation("����", "����"), Nation("������", "�ĸ�"),
		   Nation("�߱�", "������"), Nation("�Ϻ�", "����"), Nation("���þ�", "��ũ��"),
		   Nation("�����", "���������"), Nation("����", "������"), Nation("�߽���", "�߽��ڽ�Ƽ") };
	for (int i = 0; i < 9; i++)
		v.push_back(n[i]);

	srand((unsigned)time(0)); // ���� �ʱ�ȭ
}

void NationGame::run()
{
	cout << "������ ���� ���߱� ���� ����" << endl;
	list();
}

void NationGame::input()
{
	string nation ,capital;
	cout << "����  " << v.size() << "���� ���� �ԷµǾ��ֽ��ϴ�." << endl;
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
	cout << "�����Է� : 1. ����: 2. ����: 3. ";
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
		cout << v[index].getnatrion() << "�� ������";
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



