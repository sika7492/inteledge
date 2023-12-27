#include <iostream>
#include <string>
using namespace std;

class Buffer
{
public:
	Buffer(string text) { this->text = text; }
	void add(string next) { this->text += next; }
	void print() { cout << text << endl; }
	Buffer& append(Buffer& a, string b);
private:
	string text;
};

int main() {

	Buffer buf("Hello");
	Buffer& temp = buf.append(buf, "guys");
	temp.print();
	buf.print();



}

Buffer& Buffer::append(Buffer& a, string b)
{
	a.add(b);
	return a;
}
