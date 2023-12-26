#include <iostream>
#include <string>
using namespace std;

class person10
{
public:
	person10() { name = ""; }
	person10(string name) { this-> name = name; }
	string getname() { return name; }
	void setname(string name) { this->name = name; }

private:
	string name;
};

class Family
{
public:
	Family(string name, int size);
	void show();
	~Family();
	void setname(int index, string name);
private:
	
	person10 * p;
	int size;
	string name;
};

Family::Family(string name, int size)
{
	this->name = name;
	this->size = size;
	p = new person10[size];
	
}

void Family::show()
{
	cout <<name<<"가족은 다음과 같이 " << size << "명 입니다\n";
	for (int i = 0; i < size; i++)
	{
		cout << p[i].getname() << "  ";
	}
}

Family::~Family()
{
	delete[] p;
}

void Family::setname(int index, string name)
{
	p[index].setname(name);
}


int main() {

	Family* simpson = new Family("simson", 3);
	simpson->setname(0, "mr.simson");
	simpson->setname(1, "mrs.simson");
	simpson->setname(2, "Bart.simson");
	simpson->show();
	
}