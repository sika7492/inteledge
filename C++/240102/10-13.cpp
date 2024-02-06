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
	cout << "���� ���� ���α׷�"<<program<< "�� �����մϴ�." << endl;
	while (true)
	{
		cout << "�Է�:1, ��ȸ:2, ����:3 >>";
		int index;
		cin >> index;
		if (checkInputError())continue;
		switch (index)
		{
		case 1:insert();
			break;
		case 2:search();
			break;
		case 3:cout << "���α׷��� �����մϴ�" << endl;
			return;
		}

	}
}

bool Score::checkInputError()
{
	if (cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
	cout << "�Է� ����" << endl;
	return true; // ���� ����
    }
	else return false;
}

void Score::insert()
{
	string name;
	int score;
	while (true)
	{
		cout << "�̸��� ����>>";
		cin >> name >> score;
		if (checkInputError())continue;
		if (scoremap.find(name) != scoremap.end()) {
			cout << name << "�� ������ �����Ҽ� ����" << endl;
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
		cout << "�̸�>>>";
		cin >> name;
		if (scoremap.find(name) == scoremap.end())
		{
			cout << name << "�� ������ �ҷ��ü������ϴ�." << endl;
			break;
		}
		else {
			cout << name<<"�� ������ "<<scoremap[name] << endl;
			break;
		}
	}
	

}

int main() {
	Score high("High Score");
	high.run();


}
