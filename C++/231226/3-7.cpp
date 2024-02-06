#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

class SelectRandom
{
public:
	SelectRandom();
	int nexteven();
	int nextevenInRange(int a, int b);
	int nextodd();
	int nextoddInRange(int a, int b);
};

SelectRandom::SelectRandom()
{
	srand((unsigned)time(0));
}

int SelectRandom::nexteven()
{
	int k = rand();
	if ((k % 2) == 1)k = k - 1;
	return k;
}

int SelectRandom::nextevenInRange(int a, int b)
{
	int range = b - a + 1;
	int k = (a + rand() % range);
	if ((k % 2) == 1)k = k - 1;
	return k;
}

int SelectRandom::nextodd()
{
	int k = rand();
	if ((k % 2) == 0)k = k + 1;
	return k;
}

int SelectRandom::nextoddInRange(int a, int b)
{
	int range = b - a + 1;
	int k = (a + rand() % range);
	if ((k % 2) == 0)k = k + 1;
	return k;
}


int main() {
	SelectRandom r;
	cout << "--0에서 " << RAND_MAX << "까지의 랜덤정수(짝수) 10개 -- " << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nexteven();
		cout << n << ' ';
	}
	cout << endl << endl << "--2에서 9까지의 랜덤 정수(홀수) 10개--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextoddInRange(2, 9);
		cout << n << ' ';
	}
	cout << endl;
}
