#include <iostream>
#include <string>
#include<map>
using namespace std;

class PasswordManger
{
public:
	PasswordManger(string program) {
		this->program = program;
	}
	void run();
	

private:
	map<string, string> passwd;
	void insert();
	void login();
	string program;

}; //end of class PasswordManger

void PasswordManger::run()
{
	cout << "***********암호관리 프로그램" << program << "을 시작합니다. *********" << endl;
	while (true)
	{
		cout << "삽입:1  검사:2 종료:3>>";
		int menu;
		cin>> menu;
		switch (menu)
		{
		case 1:insert();
			break;
		case 2:login();
			break;
		case 3: 
			cout << "프로그램을 종료합니다" << endl;
			return;
		}//endof switch

	}//end of while

}// end of run

void PasswordManger::insert()
{
	while (true)
	{
		
		cout << "이름 암호>>";
		string name, pass;
		cin >> name >> pass;
		if (passwd.find(name) != passwd.end()) {
			cout << name << "의 암호를 수정할 수 없습니다." << endl;
			break;
		}// end of if
		else {
			passwd.insert(make_pair(name, pass));
			break;
		}//end of else


	}//end of while
}//end of insert

void PasswordManger::login()
{
	
		cout << "이름?  ";
		string name;
		cin >> name;
		if ((passwd.find(name)) == passwd.end()) {
			cout<<name<<"을 찾을수 없습니다."<<endl;
			
		}//end of if
		else {
			while (true)
			{
				cout << "암호?";
				string pass;
				cin >> pass;
				if (pass == passwd[name]) {
					cout << "통과!" << endl;
					break;
				}
				else {
					cout << "실패!" << endl;
				}
			}// end of while

		}//end of else
	
	

}//end of login

int main() {
	PasswordManger Who("WHO");
	Who.run();




}