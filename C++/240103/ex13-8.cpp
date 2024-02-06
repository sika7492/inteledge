#include <iostream>
#include<string>
using namespace std;

class MyException
{
public:
	MyException(int n, string f, string m) {
		lineNo = n; func = f; msg = m;
	}
	void print() {
		cout << func << ":" << lineNo << "," << msg << endl;
	}


private:
	int lineNo;
	string func, msg;
};

class DivedeByZeroException :public MyException
{
public:
	DivedeByZeroException(int lineNo, string func, string msg) :MyException(lineNo, func, msg) {}


};

class InvlidInputException : public MyException
{
public:
	InvlidInputException(int lineNo, string func, string msg) : MyException(lineNo, func, msg) {}

};
class CharInputException :public MyException
{
public:
	CharInputException(int lineNo, string func, string msg) : MyException(lineNo, func, msg) {}
	

private:

};



int main() {
	while (true)
	{
		int x=0, y=0;
		try {
			
			cout << "�������� �մϴ�. �ΰ��� ���� ������ �Է��ϼ���>>";
			cin >> x >>y;
			if (cin.fail()) {
				
				cin.clear();
				cin.ignore(100, '\n');
				throw CharInputException(59, "main()", "�߸��� ���� �Է��Ͽ����ϴ�.");
			}
			
			
			if ((x < 0) || (y < 0)) {
				throw InvlidInputException(64, "main()", "���� ���� ���� �߻�");
			}	//end of if 

			if (y == 0)
			{
				throw DivedeByZeroException(69, "main()", "0���� ������ ���� �߻�");
			}	//end of if 
			cout << (double)x / (double)y<<endl;
		}	//end of try

		catch (DivedeByZeroException& e) {
			e.print();
			
		}
		catch (InvlidInputException& e) {
			e.print();
		}
		catch (CharInputException& e) {
			e.print();
		}

	}

}