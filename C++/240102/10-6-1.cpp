#include <iostream>
using namespace std;

template<class T>
T* remove(T src[], int sizeSrc, T minus[], int sizeMinus, int& retSize) {
	int k = 0;
	T* p = new T[sizeSrc]; // src와 같은 크기의 배열 할당
	for (int i = 0; i < sizeSrc; i++) {
		int j;
		for (j = 0; j < sizeMinus; j++)
			if (src[i] == minus[j])
				break;
		if (j == sizeMinus) { // src[i] 값이 minus 배열에 없음
			p[k] = src[i];
			k++;
		}
	}
	retSize = k; // 리턴할 배열의 크기 결정
	if (k == 0) {
		delete[] p;
		return NULL;
	}
	T* q = p;
	if (sizeSrc != retSize) {
		q = new T[k]; // 새로 배열 할당
		for (int i = 0; i < k; i++)
			q[i] = p[i]; //배열 복사
		delete[] p; // 처음 할당받은 배열 반환
	}
	return q;
}

int main() {
	// remove() 함수를 int로 구체화하는 경우
	cout << "정수 배열 {1,2,3,4}에서 정수 배열 {-3,5,10,1,2,3}을 뺍니다" << endl;

	int x[] = { 1,2,3,4 };
	int y[] = { -3,5,10,1,2,3 };
	int retSize;

	int* p = remove(x, 4, y, 6, retSize);
	if (retSize == 0) {
		cout << "모두 제거되어 리턴하는 배열이 없습니다." << endl;
		return 0;
	}
	else {
		for (int i = 0; i < retSize; i++)
			cout << p[i] << ' ';
		cout << endl;

		delete[] p; // 할당받은 배열 반환
	}
	cout << endl;


	// remove() 함수를 double로 구체화하는 경우
	cout << "실수 배열 {1.0, 2.0, 3.2, 4.8, 5.0, 6.0, 7.0, 99.9}에서 " << endl;
	cout << "실수 배열 {3.5, 4.8, 1.0, 2.0, 3.0}을 뺍니다" << endl;

	double x2[] = { 1.0, 2.0, 3.2, 4.8, 5.0, 6.0, 7.0, 99.9 };
	double y2[] = { 3.5, 4.8, 1.0, 2.0, 3.0 };

	double* q = remove(x2, 8, y2, 5, retSize);
	if (retSize == 0) {
		cout << "모두 제거되어 리턴하는 배열이 없습니다." << endl;
	}
	else {
		for (int i = 0; i < retSize; i++)
			cout << q[i] << ' ';
		cout << endl;

		delete[] q; // 할당받은 배열 반환
	}
}