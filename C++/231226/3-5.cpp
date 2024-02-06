#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

class Random
{
public:
	Random();
	int next();
	int nextInRange(int a,int b);

};

Random::Random()
{
	srand((unsigned)time(0));
}

int Random::next()
{
	return rand();
}

int Random::nextInRange(int a, int b)
{
	int range = b - a + 1;
	return a + rand() % range;
}


int main() {
	Random r;
	cout << "--0에서 " << RAND_MAX << "까지의 랜덤정수 10개 -- " << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next();
		cout << n << ' ';
	}
	cout << endl << endl << "--2에서 4까지의 랜덤 정수 10개--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 4);
		cout << n << ' ';
	}
	cout << endl;

}
