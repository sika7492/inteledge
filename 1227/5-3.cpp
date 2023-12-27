#include <iostream>
using namespace std;

void combine(string& i, string& j, string& k) {
	k = i;
	k.append(" ");
	k.append(j);
}


int main() {
	string text1("I love you"), text2("very much");
	string text3;
	combine(text1, text2, text3);
	cout << text3;//I love you very much

}