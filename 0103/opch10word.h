#pragma once
#include <string>
using namespace std;
class Word
{
public:
	Word(string english,string korea);
	string getEnglish();
	string getKorea();
	

private:
	string korea;
	string english;
};

