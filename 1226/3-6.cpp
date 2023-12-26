#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

class EvenRandom
{
public:
	EvenRandom();
	int next();
	int nextInRange(int a, int b);

};

EvenRandom::EvenRandom()
{
	srand((unsigned)time(0));
}

int EvenRandom::next()
{
	int k = rand();
	if ((k % 2) == 1)k=k - 1;
	return k;
}

int EvenRandom::nextInRange(int a, int b)
{
	int range = b - a + 1;
	int k= (a + rand() % range) ;
	if ((k % 2) == 1)k=k - 1;
	return k;
}


int main() {
	EvenRandom r;
	cout << "--0���� " << RAND_MAX << "������ ��������(¦��) 10�� -- " << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next();
		cout << n << ' ';
	}
	cout << endl << endl << "--2���� 10������ ���� ����(¦��) 10��--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 10);
		cout << n << ' ';
	}
	cout << endl;
}
