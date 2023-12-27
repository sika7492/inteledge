#include <iostream>
using namespace std;

class containor
{
public:
	containor() { size = 10; }
	void file() { size = 10; }
	void consume() { size--; }
	int getsize() { return size; }


private:
	int size;
};
class coffeevendingmachine
{
public:
	void run();


private:
	
	void fill();
	void selectespresso();
	void selectamericano();
	void selectsugarcoffee();
	void show();
	containor tong[3];
};



void coffeevendingmachine::run()
{
	cout << "******Ŀ�����Ǳ⸦ �۵��մϴ�*********" << endl;
	while (true)
	{
		cout << "�޴��� �����ּ��� (1:���������� 2:�Ƹ޸�ī�� 3:����Ŀ�� 4:�ܷ����� 5:ä���";
		int menu;
		cin >> menu;
		switch (menu)
		{
		case 1 :selectespresso();
			break;
		case 2:selectamericano();
			break;
		case 3:selectsugarcoffee();
			break;
		case 4: show();
			break;
		case 5:fill();
			break;
		default:
			break;
		}

	}
}

void coffeevendingmachine::fill()
{
	for (int i = 0; i < 3; i++)
	{
		tong[i].file();
		
	}
	
}

void coffeevendingmachine::selectespresso()
{
	if ((tong[0].getsize() - 1) < 0 || (tong[1].getsize() - 1) < 0) 
		cout << "���ᰡ�����մϴ�."<<endl;
	else {

		tong[0].consume();
		tong[1].consume();
		cout << "���������ҵ弼��\n";
	}
}

void coffeevendingmachine::selectamericano()
{
	if ((tong[0].getsize() - 1) < 0 || (tong[1].getsize() - 2) < 0)
		cout << "���ᰡ�����մϴ�." << endl;
	else {

		tong[0].consume();
		tong[1].consume();
		tong[1].consume();
		cout << "�Ƹ޸�ī��弼��\n";
		
	}
	
}

void coffeevendingmachine::selectsugarcoffee()
{
	if ((tong[0].getsize() - 1) < 0 || (tong[1].getsize() - 2) < 0|| (tong[2].getsize() - 1) < 0)
		cout << "���ᰡ�����մϴ�." << endl;
	else {
		tong[0].consume();
		tong[1].consume();
		tong[1].consume();
		tong[2].consume();
		cout << "����Ŀ�ǵ弼��\n";
	}

}

void coffeevendingmachine::show()
{
	cout << "Ŀ��" << tong[0].getsize() << "��" << tong[1].getsize() << "����" << tong[2].getsize() << endl;
}


int main() {

	coffeevendingmachine coffee;
	coffee.run();




}