#include <iostream>
#include<string>
#include<map>
#include<vector>
#include<cstdio>
#include<fstream>
#include<ctime>
using namespace std;

void error(const char* s) {
	cout << "예외 발생 :" << s << endl;
	const char* file = "c:\\Temp\\errors.txt";
	
	

	fstream fout(file,ios::out | ios::app);
	if (!fout) {
		cout << file << "파일을 열수 없습니다" << endl;
	}

	int size = sizeof(s) / sizeof(s[0]);
	fout.write(s, size);


	fout.close();
	
	
}

class Circle
{
public:
	Circle(int radius, string name) {
		this->name = name; this->radius = radius;
	}
	~Circle() {  }	// 소멸자
	double	getArea() { return 3.14 * radius * radius; }
	string getName() { return name; }
	int getRadius() { return radius; }
private:
	string name;
	int radius;
	
};

class CircleVectorManger
{
public:
	CircleVectorManger(){}
	~CircleVectorManger(){}
	void run();

private:
	vector<Circle*>v;
	void edit();
	void remove();
	void show();

};

void CircleVectorManger::run()
{
	cout << "제목" << endl;
	while (true)
	{
		cout << "메뉴" << endl;
		int menu;
		cin >> menu;
		try {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(100, '\n');
				//cout << "입력 오류 발생" << endl;
				throw "입력오류 발생";
				continue;
			}
		}
		catch (const char* s) {
			error(s);
		}
		switch (menu)
		{
		case 1: edit();
			break;
		case 2: remove();
			break;
		case 3: show();
			break;
		case 4: 
			cout << "종료합니다" << endl;
			exit(0);
			break;
		default:
			break;
		}

	}
	
}

void CircleVectorManger::edit()
{
	cout << "생성하고자하는 원의 반지름과 이름은>>>";
	string name;
	int raidus;
	try {
		cin >> raidus >> name;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(100, '\n');
			//cout << "입력 오류 발생" << endl;
			throw "입력오류 발생";
			return;
		}
		v.push_back(new Circle(raidus, name));
	}
	catch (const char* s) {
		error(s);
	}
}

void CircleVectorManger::remove()
{
	string name;
	cin >> name;
	vector<Circle*>::iterator it = v.begin();
	while (it!=v.end()) {
		Circle* p = *it;
		if (p->getName() == name) {
			it = v.erase(it);
			delete p;
		}
		else it++;

	}
}

void CircleVectorManger::show()
{
	int size = v.size();
	for (int i = 0; i < size; i++)
	{
		cout << v[i]->getName() << endl;

	}
}

int main()
{
	CircleVectorManger game;
	game.run();

}