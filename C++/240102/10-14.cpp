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
	cout << "***********��ȣ���� ���α׷�" << program << "�� �����մϴ�. *********" << endl;
	while (true)
	{
		cout << "����:1  �˻�:2 ����:3>>";
		int menu;
		cin>> menu;
		switch (menu)
		{
		case 1:insert();
			break;
		case 2:login();
			break;
		case 3: 
			cout << "���α׷��� �����մϴ�" << endl;
			return;
		}//endof switch

	}//end of while

}// end of run

void PasswordManger::insert()
{
	while (true)
	{
		
		cout << "�̸� ��ȣ>>";
		string name, pass;
		cin >> name >> pass;
		if (passwd.find(name) != passwd.end()) {
			cout << name << "�� ��ȣ�� ������ �� �����ϴ�." << endl;
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
	
		cout << "�̸�?  ";
		string name;
		cin >> name;
		if ((passwd.find(name)) == passwd.end()) {
			cout<<name<<"�� ã���� �����ϴ�."<<endl;
			
		}//end of if
		else {
			while (true)
			{
				cout << "��ȣ?";
				string pass;
				cin >> pass;
				if (pass == passwd[name]) {
					cout << "���!" << endl;
					break;
				}
				else {
					cout << "����!" << endl;
				}
			}// end of while

		}//end of else
	
	

}//end of login

int main() {
	PasswordManger Who("WHO");
	Who.run();




}