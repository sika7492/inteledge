#include <iostream>

using namespace std;

template <class T>
T* remove(T scr[], int sizeSrc, T minus[], int sizeMinus, int& retSize) {
	int num=0;
	T* p = new T[sizeSrc];

	for (int i = 0; i < sizeSrc; i++)
	{
		for (int j = 0; j < sizeMinus; j++)
		{
			if (scr[i] == minus[j]) {
				break;
			}//end of if
			if (j==sizeMinus-1)
			{
				p[num] = scr[i];
				num++;
				
			}
		}// end of for minus array



	}//end of for scr array
	retSize = num;

	if (num == 0)
	{
		delete[]p;
		return NULL;
	}
	T* q = p;
	if (sizeSrc != retSize) {
		q = new T[num];
		for (int i = 0; i < num; i++)
		{
			q[i] = p[i];
		}

		delete[]p;
	}
	return q;



	


}

int main() {

	int a[] = {1,2,3,4,5,6,7,8,9,10};
	int b[] = {3,5,7,9};
	int sizea = sizeof(a) / sizeof(a[0]);
	int sizeb = sizeof(b) / sizeof(b[0]);
	int sizec;
	int* c =remove(a, sizea, b, sizeb, sizec);
	cout << "배열 a {1,2,3,4,5,6,7,8,9,10}에서 배열 b {3,5,7,9}의 정수를 삭제" << endl;
	for (int i = 0; i < sizec; i++)
	{
		cout << c[i] << " ";
	}
	cout << endl;
	delete[]c;
	double d[] = { 1,2,3.2,4,5.0,6.2,7.5,9.1,9.7,10 };
	double e[] = { 3.2,5.1,7.5,9.7,1,2 };
	int sized = sizeof(d) / sizeof(d[0]);
	int sizee = sizeof(e) / sizeof(e[0]);
	int sizef;
	double* f = remove(d, sizea, e, sizeb, sizec);
	cout << "배열 d { 1,2,3.2,4,5.0,6.2,7.5,9.1,9.7,10 에서 배열e{ 3.2,5.1,7.5,9.7,1,2 }의 숫자를 삭제" << endl;
	for (int i = 0; i < sizec; i++)
	{
		cout << f[i] << " ";
	}
	delete[]f;




}