#include "opch10test.h"
#include <iostream>
#include <cstdio>
#include<ctime>

WordTest::WordTest()
{
	Word wordlist[] = { Word("love", "사랑"), Word("animal", "동물"), Word("human", "인간"),
			Word("emotion", "감정"), Word("stock", "주식"), Word("trade", "거래"),
			Word("society", "사회"), Word("baby", "아기"), Word("honey", "애인"),
			Word("dall", "인형"), Word("bear", "곰"), Word("picture", "사진"), Word("painting", "그림"),
			Word("fault", "오류"), Word("example", "보기"), Word("eye", "눈"), Word("statue", "조각상") };

	for (int i = 0; i < 13; i++) {
		v.push_back(wordlist[i]);
	}
}

void WordTest::run()
{
	cout << "영어 어휘 테스트를 시작합니다. 1~4외 다른 입력시 종료합니다" << endl;
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
				
		}// end of for 4가지 보기 출력;
			

		

		int x;
		cin >> x;
		if ((x <1) || (x >4)) {
			cout << "종료합니다" << endl;
			break;
		}

		if ((num+1 ) == x) {
				cout << "정답입니다" << endl;
		}
		else cout << "틀렸습니다" << endl;
		
		
			


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
