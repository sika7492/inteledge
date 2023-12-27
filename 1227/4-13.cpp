#include <iostream>
#include <string>
using namespace std;

class Histogram
{
public:
	Histogram(string text) { this->text = text; }
	void put(string next) { text += next; }
	void putc(char next) { text += next; }
	void print();

private:
	string text;
};

void Histogram::print()
{
	cout << text << endl;
	int rel = text.length();
	int num=0;
	for (int i = 0; i < rel; i++)
	{
		if (text[i] >= 'A' && text[i] <= 'Z')
			text[i] -= ('A' - 'a');
		if (text[i] >= 'a' && text[i] <= 'z')
			num++;
	}
	cout << "ÃÑ ¾ËÆÄºª¼ö " << num << endl;
	
	int ap[26] = { 0 };
	for (int i = 0; i < rel; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if(text[i]==char('a'+j))
			ap[j]++;

		}

	}
	
	for (int j = 0; j < 26; j++)
	{
		cout << char('a'+j) <<"    (" << ap[j] << ")   :";
		for (int i = 0; i < ap[j]; i++) {
			cout << "*";
		}
		cout << endl;
	}

}

int main() {


	Histogram elvisHisto("Wise men say, only fools rush in But I can't help, \n ");
	elvisHisto.put("falling in love with you");
	elvisHisto.putc('-');
	elvisHisto.put("Elvis Presley");
	elvisHisto.print();





}
