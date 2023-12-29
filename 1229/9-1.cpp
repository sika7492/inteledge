#include <iostream>
using namespace std;

class Converter
{
public:
	Converter(double ratio) { this->ratio = ratio; }
	void run() {
		double src;
		cout << getSourceString() << "��" << getDestString() << "�� �ٲߴϴ�.";
		cout << getSourceString() << "�� �Է��ϼ���>>";
		cin >> src;
		cout << "��ȯ ���  :  " << convert(src) << getDestString() << endl;
 }


protected:
	double ratio;
	virtual double convert(double src) = 0;
	virtual string getSourceString() = 0;
	virtual string getDestString() = 0;
};

class WonToDollar : public Converter
{
public:
	WonToDollar(double ratio) : Converter(ratio) {
		source = "��"; dest="�޷�";
	}
	virtual double convert(double src) { return src/ratio ; }
	virtual string getSourceString() { return source; }
	virtual string getDestString() { return dest; }

private:
	string source,dest;
};

int main() {

	WonToDollar wd(1010);
	wd.run();



}


