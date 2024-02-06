#pragma once
#include"opch10word.h"
#include<vector>

class WordTest
{
public:
	WordTest();
	void run();

private:
	vector<Word>v;
	void test();
	bool exist(int n[], int index);
};

