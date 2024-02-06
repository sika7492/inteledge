#include <iostream>
#include <vector>
using namespace std;

int main() {

	vector<int>v;
	int num;
	int avg=0;
	while (true) {
		cout << "정수를 입력하세요 (0)을 입력하면 종료>>";
		cin >> num;
		if (num == 0)break;
		v.push_back(num);
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
			avg += v[i];
			if (i == v.size() - 1)
			{
				avg = avg / v.size();
				cout << "평균 =  " << avg << endl;

			}

		}


	}
	cout << "종료합니다" << endl;
}