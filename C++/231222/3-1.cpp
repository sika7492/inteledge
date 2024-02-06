#include <iostream>
using namespace std;

class Tower
{
public:
	Tower();
	Tower(int a);
	int getHeight();

private:
	int  h;

};

Tower::Tower()
{
	h = 1;

}

Tower::Tower(int a)
{
	h = a;
}

int Tower::getHeight()
{
	return h;
}







int main() {
	Tower myTower;
	Tower seoulTower(100);
	cout << "높이는 " << myTower.getHeight() << "미터" << endl;
	cout << "높이는 " << seoulTower.getHeight() << "미터" << endl;


}