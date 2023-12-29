#include <iostream>
using namespace std;

class Converter
{
public:
	Converter(double ratio) { this->ratio = ratio; }
	void run() {
		double src;
		cout << getSourceString() << "을" << getDestString() << "로 바꿉니다.";
		cout << getSourceString() << "읇 입력하세요>>";
		cin >> src;
		cout << "변환 결과  :  " << convert(src) << getDestString() << endl;
	}


protected:
	double ratio;
	virtual double convert(double src) = 0;
	virtual string getSourceString() = 0;
	virtual string getDestString() = 0;
};

class KmToMile : public Converter
{
public:
	KmToMile(double ratio) : Converter(ratio) {
		source = "km"; dest = "mile";
	}
	virtual double convert(double src) { return src /ratio; }
	virtual string getSourceString() { return source; }
	virtual string getDestString() { return dest; }

private:
	string source, dest;
};


int main() {

	KmToMile kmtoMile(1.609344);
	kmtoMile.run();



}
