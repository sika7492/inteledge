#include <iostream>
#include "3-12ram.h"
using namespace std;

Ram::Ram()
{
	mem[100*1024] = 0;
	size = sizeof(mem);
}

Ram::~Ram()
{
	cout << "�޸� ���ŵ�" << endl;
}

char Ram::read(int address)
{
	return mem[address];
}

void Ram::write(int address, char value)
{
	mem[address] = value;
}
