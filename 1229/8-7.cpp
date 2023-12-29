#include <iostream>
using namespace std;


class BaseMemory
{
public:
	BaseMemory(int size) { mem = new char[size]; }
	~BaseMemory() { delete[]mem; }
	char read(int index) { return mem[index]; }
	void wirte(int index, char val) { mem[index] = val; }
private:
	char* mem;
};
class Rom : public BaseMemory
{
public:
	Rom(int size, char burn[], int index) :BaseMemory(size) {
		for (int  i = 0; i < index; i++)wirte(i, burn[i]);
		
	}


private:

};
class Ram : public BaseMemory
{
public:
	Ram(int size) : BaseMemory(size){}
	

private:

};





int main() {

	char x[5] = { 'h','e','l','l','o' };
	Rom biosRom(1024 * 10, x, 5);   //10kb의 rom메모리 ,배열 x로 초기화
	Ram mainMemory(1024 * 1024);

	for (int i = 0; i < 5; i++)mainMemory.wirte(i, biosRom.read(i));

	for (int i = 0; i < 5; i++)cout << mainMemory.read(i);

	//결과값 
	//hello
}