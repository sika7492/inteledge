#include <iostream>
#include <vector>
using namespace std;

int main() {

	vector<int>v;
	int num;
	int avg=0;
	while (true) {
		cout << "������ �Է��ϼ��� (0)�� �Է��ϸ� ����>>";
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
				cout << "��� =  " << avg << endl;

			}

		}


	}
	cout << "�����մϴ�" << endl;
}