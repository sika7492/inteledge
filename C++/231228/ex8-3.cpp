#include <iostream>
#include <string>
using namespace std;

class Tv
{
public:
	Tv() { size = 20; }
	Tv(int size) { this->size = size; }
	int getsize() { return size; }

private:
	int size;
};

class WideTv : public Tv
{
private:
	bool videoin;
public:
	WideTv(int size, bool videoin) :Tv(size) {
		this->videoin = videoin;
	}
	bool getVideoin() { return videoin; }


};

class SmartTv : public WideTv
{
public:
	SmartTv(int size,  string ipAddr) :WideTv(size,true)
	{
		this->ipAddr = ipAddr;
	}

	string getipAddr() { return ipAddr; }
	

private:
	string ipAddr;
};

int main() {
	

	SmartTv htv(32, "192.168.0.1");

	cout << "size  =" << htv.getsize() <<endl ;
	cout << "videoin  =" <<boolalpha<< htv.getVideoin() << endl;
	cout << "Ip  =" << htv.getipAddr() << endl;
}


