#include <iostream>
using namespace std;

int main() {

	cout << "5개의 실수를 입력받아라 >>";

	float a;
	float b;
	float c;
	float d;
	float e;
	cin >> a >> b>>c>>d>>e;
	float f=0;
	if ((a > b)&&(a>c)&&(a>d)&&(a>e))f = a;
	else if ((a < b) && (b > c) && (b > d) && (b > e))f = b;
	else if ((a < c) && (b < c) && (c > d) && (c > e))f = c;
	else if ((a < d) && (d > b) && (d > c) && (d > e))f = d;
	else if ((a < e) && (e > b) && (e > c) && (e > d))f = e;

	cout << "큰수는 = " << f;




}
