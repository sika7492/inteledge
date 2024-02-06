#include <iostream>
using namespace std;

class circle7
{
public:
	circle7();
	void  setradius(int r);
	double getarea();
private:
	int radius;
};

circle7::circle7()
{
	radius = 1;
}

void circle7::setradius(int r)
{
	radius = r;
}

double circle7::getarea()
{
	return 3.14*radius*radius;
}


int main() {
	int n = 3;
	circle7* c = new circle7[n];
	int count =0;
	for (int i = 0; i < n; i++)
	{
		cout << "원 "<<i+1<<"의 반지름은 >> ";
		int ra;
		cin >> ra;
		c[i].setradius(ra);
		
		if (c[i].getarea() > 100)count++;
	
	}
	cout << "면적이 100보다 큰원은 " << count << "개 입니다";


	
	





}

