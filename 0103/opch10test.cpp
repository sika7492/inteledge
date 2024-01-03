#include "opch10test.h"
#include <iostream>
#include <cstdio>
#include<ctime>

WordTest::WordTest()
{
	Word wordlist[] = { Word("love", "���"), Word("animal", "����"), Word("human", "�ΰ�"),
			Word("emotion", "����"), Word("stock", "�ֽ�"), Word("trade", "�ŷ�"),
			Word("society", "��ȸ"), Word("baby", "�Ʊ�"), Word("honey", "����"),
			Word("dall", "����"), Word("bear", "��"), Word("picture", "����"), Word("painting", "�׸�"),
			Word("fault", "����"), Word("example", "����"), Word("eye", "��"), Word("statue", "������") };

	for (int i = 0; i < 13; i++) {
		v.push_back(wordlist[i]);
	}
}

void WordTest::run()
{
	cout << "���� ���� �׽�Ʈ�� �����մϴ�. 1~4�� �ٸ� �Է½� �����մϴ�" << endl;
	test();
}

void WordTest::test()
{
	while (true)
	{
		srand((unsigned)time(0));
		int index = rand() % v.size();
		int num = rand() % 4;
		cout << v[index].getEnglish() << "?" << endl;
		int ex[4]={-1,-1,-1,-1};
		for (int i = 0; i < 4; i++)
		{
			while (true)
			{
				int index2 = rand() % v.size();
				if ((index == index2) || exist(ex, index2))continue;
				else {
					ex[i] = index2;
					break;
				}

			}
		}
		ex[num] = index;
		for (int i = 0; i < 4; i++)
		{
			
				cout << "(" << i + 1 << ") " << v[ex[i]].getKorea();
				
		}// end of for 4���� ���� ���;
			

		

		int x;
		cin >> x;
		if ((x <1) || (x >4)) {
			cout << "�����մϴ�" << endl;
			break;
		}

		if ((num+1 ) == x) {
				cout << "�����Դϴ�" << endl;
		}
		else cout << "Ʋ�Ƚ��ϴ�" << endl;
		
		
			


	}//end of while
	
	
} 
bool WordTest::exist(int n[], int index)
{
	for (int i = 0; i < 4; i++)
	{
		if (n[i] == index)return true;
	}
	return false;
}
//end of test  
