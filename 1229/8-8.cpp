#include <iostream>
#include <string>
using namespace std;




class Printer
{
public:
	Printer(string model, string manufacturer, int availableCount) {
		this->model = model; this->manufacturer = manufacturer; this->availableCount = availableCount;
	}
	~Printer(){}
	bool print(int page){
		if ((availableCount - page) < 0) {
			cout << "용지가 부족하여 프린트 할수없습니다" << endl;
			return false;
		}
		availableCount -= page;
		return true;

	}
	string getmodel() { return model; }
	string getmanufacturer() { return manufacturer; }
	int getavailableCount() { return availableCount; }


private:
	string model, manufacturer;
	int printedCount, availableCount;
};
class InkPrinter:public Printer
{
public:
	InkPrinter(string model, string manufacturer, int availableCount, int availableInk) :
		Printer(model, manufacturer, availableCount) {
		this->availableInk = availableInk;
	}

	~InkPrinter() {}
	void inkprint(int page) {
		if (availableInk - page < 0) {
			cout << "잉크가 부족하여 프린트 할수없습니다" << endl;
		}
			
		if (print(page)) {
			availableInk -= page;
			cout << "프린트하였습니다." << endl;
		}
		
	}
	void show() {
		cout << "잉크 :" << getmodel() << " ," << getmanufacturer() << ", 남은종이 " << getavailableCount() << " , 남은잉크 " << availableInk << endl;
	}

private:
	int availableInk;
};

class TonerPrinter : public Printer
{
public:
	TonerPrinter (string model, string manufacturer, int availableCount, int availableToner) :
Printer(model, manufacturer, availableCount) {
		this->availableToner = availableToner;
	}

	~TonerPrinter() {}
	void tonerprint(int page) {
		if (availableToner - page < 0) {
			cout << "토너가 부족하여 프린트 할수없습니다" << endl;
		}
		if (print(page)) {
			this->availableToner -= page;
			cout << "프린트하였습니다." << endl;
		}
		
		
	}
	void show() {
		cout << "레이저 :" << getmodel() << " ," << getmanufacturer() << ",남은 종이" <<getavailableCount() << " ,남은 토너" << availableToner << endl;
	}

private:
	int availableToner;
};

int main() {
	InkPrinter a("officejet  v40", "HP", 5, 10);
	TonerPrinter b("SCL-6x45", "삼성전자", 3, 20);

	cout << "현재 작동중인 2대의 프린터는 아래와같다" << endl;
	a.show();
	b.show();
	while (true)
	{
		cout << "프린터 (1:잉크,2:레이저)와 매수 입력>>" ;
		int menu, page;
		cin >> menu >> page;
		switch (menu)
		{
		case 1:
			a.inkprint(page);
			break;
		case 2:
			b.tonerprint(page);
			break;
		default:
			cout << "잘못된 입력입니다" << endl;
			break;
		}
		a.show();
		b.show();
		cout << "계속할꺼면 y 입력>>";
		string y;
		cin >> y;
		if (y != "y")break;

	}



}



