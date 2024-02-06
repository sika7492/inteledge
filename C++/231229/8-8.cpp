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
			cout << "������ �����Ͽ� ����Ʈ �Ҽ������ϴ�" << endl;
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
			cout << "��ũ�� �����Ͽ� ����Ʈ �Ҽ������ϴ�" << endl;
		}
			
		if (print(page)) {
			availableInk -= page;
			cout << "����Ʈ�Ͽ����ϴ�." << endl;
		}
		
	}
	void show() {
		cout << "��ũ :" << getmodel() << " ," << getmanufacturer() << ", �������� " << getavailableCount() << " , ������ũ " << availableInk << endl;
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
			cout << "��ʰ� �����Ͽ� ����Ʈ �Ҽ������ϴ�" << endl;
		}
		if (print(page)) {
			this->availableToner -= page;
			cout << "����Ʈ�Ͽ����ϴ�." << endl;
		}
		
		
	}
	void show() {
		cout << "������ :" << getmodel() << " ," << getmanufacturer() << ",���� ����" <<getavailableCount() << " ,���� ���" << availableToner << endl;
	}

private:
	int availableToner;
};

int main() {
	InkPrinter a("officejet  v40", "HP", 5, 10);
	TonerPrinter b("SCL-6x45", "�Ｚ����", 3, 20);

	cout << "���� �۵����� 2���� �����ʹ� �Ʒ��Ͱ���" << endl;
	a.show();
	b.show();
	while (true)
	{
		cout << "������ (1:��ũ,2:������)�� �ż� �Է�>>" ;
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
			cout << "�߸��� �Է��Դϴ�" << endl;
			break;
		}
		a.show();
		b.show();
		cout << "����Ҳ��� y �Է�>>";
		string y;
		cin >> y;
		if (y != "y")break;

	}



}



