#include <iostream>

using namespace std;

class Sample
{
public:
	Sample(int n) { size = n; p = new int[n]; }
	~Sample();
	void read();
	void write();
	int big();
private:
	int* p;
	int size;
};







int main() {
	Sample s(10);
	s.read();
	s.write();
	cout << "가장 큰 수는 " << s.big() << endl;

}

Sample::~Sample()
{
}

void Sample::read()
{
	for (int i = 0; i < size; i++)
	{
		cin >> p[i];
	}
}

void Sample::write()
{
	for (int  i = 0; i < size; i++)
	{
		cout << p[i] << ' ';
	}
	cout << endl;
}

int Sample::big()
{
	int n = 0;
	for (int i = 0; i < size; i++)
	{
		
		if (p[i] > n)n = p[i];

	}
	return n;
}
