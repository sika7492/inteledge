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
	cout << "******커피자판기를 작동합니다*********" << endl;
	while (true)
	{
		cout << "메뉴를 눌러주세요 (1:에스프레소 2:아메리카노 3:설탕커피 4:잔량보기 5:채우기";
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
		cout << "원료가부족합니다."<<endl;
	else {

		tong[0].consume();
		tong[1].consume();
		cout << "에스프레소드세요\n";
	}
}

void coffeevendingmachine::selectamericano()
{
	if ((tong[0].getsize() - 1) < 0 || (tong[1].getsize() - 2) < 0)
		cout << "원료가부족합니다." << endl;
	else {

		tong[0].consume();
		tong[1].consume();
		tong[1].consume();
		cout << "아메리카노드세요\n";
		
	}
	
}

void coffeevendingmachine::selectsugarcoffee()
{
	if ((tong[0].getsize() - 1) < 0 || (tong[1].getsize() - 2) < 0|| (tong[2].getsize() - 1) < 0)
		cout << "원료가부족합니다." << endl;
	else {
		tong[0].consume();
		tong[1].consume();
		tong[1].consume();
		tong[2].consume();
		cout << "설탕커피드세요\n";
	}

}

void coffeevendingmachine::show()
{
	cout << "커피" << tong[0].getsize() << "물" << tong[1].getsize() << "설탕" << tong[2].getsize() << endl;
}


int main() {

	coffeevendingmachine coffee;
	coffee.run();




}