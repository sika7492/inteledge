#include <iostream>

using namespace std;

template <class T>
bool search(T x, T y[], int size) {
	for (int i = 0; i < size; i++)
	{
		if (y[i] == x)return true;
	}
	return false;
}

int main() {
	int x[] = {1,10,100,5,4};
	if (search(100, x, 5))cout << "100�� �迭 x�� ���ԵǾ��ֽ��ϴ�";
	else cout << "100�� �迭x�� ���ԵǾ����� �ʽ��ϴ�.";
}