#include "opch10word.h"
#include<iostream>;


Word::Word(string english, string korea )
{
	this->korea = korea; this->english = english;
}

string Word::getEnglish()
{
	return english;
}

string Word::getKorea()
{
	return korea;
}
