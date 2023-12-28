#include <iostream>

using namespace std;


class MyVector
{
public:
	MyVector(int n = 100,int val = 100);
	~MyVector();
	int getsize() { return size; }
	int getmem() { return mem[0]; }
private:
	int* mem;
	int size;
};



MyVector::MyVector(int n, int val)
{
	mem = new int[n];
	size = n;
	for (int i = 0; i < n; i++)
	{
		mem[i] = val;
	}

}

MyVector::~MyVector()
{
	
	delete[]mem;
}

int main() {

	MyVector test1, test2(10, 10), test3(50, 50);
	cout << "테스트 각 size 크기 test1 " << test1.getsize() << " test2 " << test2.getsize() << " test3 " << test3.getsize() << endl;
	cout << "테스트 각 mem[0] 크기 test1 " << test1.getmem() << " test2 " << test2.getmem() << " test3 " << test3.getmem() << endl;



}