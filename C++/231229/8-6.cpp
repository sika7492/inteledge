#include <iostream>
using namespace std;

class BaseArray {
private:
	int capacity; // ���� �Ҵ�� �޸� �뷮
	int* mem;
protected:
	BaseArray(int capacity = 100) {
		this->capacity = capacity; mem = new int[capacity];
	}
	~BaseArray() { delete[] mem; }
	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
};

class MyQueue : public BaseArray {
	int head, tail;
	int size; // ���� ť �ȿ� �ִ� �������� ����
public:
	MyQueue(int capacity);
	void enqueue(int n);
	int dequeue();
	int capacity();
	int length();
};

MyQueue::MyQueue(int capacity) : BaseArray(capacity) {
	head = 0; // ������ ��ġ�� head
	tail = -1;  // tail+1 ��ġ���� ������
	size = 0; // �ʱ� ������ 0
}

void MyQueue::enqueue(int n) {
	if (size == capacity())
		return; // queue full error
	put(head, n);
	head++;
	head = head % capacity();
	size++;
}

int MyQueue::dequeue() {
	if (size == 0)
		return -1; // queue empty error
	size--;
	tail++;
	tail = tail % capacity();
	return get(tail);
}

int MyQueue::capacity() {
	return getCapacity();
}

int MyQueue::length() {
	return size;
}

class MyStack : public BaseArray
{
public:
	MyStack(int capacity) : BaseArray(capacity) { size = 0; }
    void push(int n);
	int capacity() { return this->getCapacity(); }
	int length() { return size; }
	int pop();

private:
	int size;
};

void MyStack::push(int n)
{
	if (size == this->getCapacity())
		return;
	this->put(size, n);
	size++;
	
}

int MyStack::pop()
{
	if (size == 0)return-1;
	int tail = size - 1;
	size--;
	return this->get(tail);
}







int main() {
	MyStack mStack(100);
	int n;
	cout << "ť�� ������ 5���� ������ �Է��϶�>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mStack.push(n); 
	}
	cout << "������ �뷮:" << mStack.capacity() << ", ������ ũ��:" << mStack.length() << endl;
	cout << "������ ���Ҹ� ������� ���Ͽ� ����Ѵ�>> ";
	while (mStack.length() != 0) {
		cout << mStack.pop() << ' '; 
	}
	cout << endl << "������ ���� ũ�� : " << mStack.length() << endl;
}


