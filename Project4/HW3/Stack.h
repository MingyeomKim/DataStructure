#include "ArrayVector.h"
#pragma once


// ArrayVector�� �̿��ؼ� ������ Stack Ŭ���� 
class Stack {
public:
	Stack(int = 0);
	~Stack();
	void push(const Elem& elem);
	// ������ i��° �ε����� elem ����
	void pop();
	Elem top() const throw(StackEmptyException);
	bool empty();
	int size();
private: 
	ArrayVector *vector; // vector �����
};

// Stack�� ������, capacity�� ���� �޾� vector�� capacity�� �ʱ�ȭ�Ѵ�. 
Stack::Stack(int capacity) 
	: vector (new ArrayVector)
{
	vector->setCapacity(capacity);
}

// ��������� vector�� �޸𸮸� �������ش�. 
Stack::~Stack() {
	delete vector;
}

void Stack::push(const Elem& elem) {
	// insert �Լ� ������, capacity�� �ʰ��Ͽ��� ��� �뷮�� �� �� ������Ű�� �ڵ尡 �����Ƿ�, stackFull�� ����� ���ܸ� ���� ó������ �ʴ´�. 
	vector->insert(vector->getN(), elem);
	// Stack�� Ư�� �� push�� LIFO�� ������� ����Ǳ� ������ ���� ��ġ���� 1��ŭ Ŀ�� �κп� elem�� �����Ѵ�. 
	// getN�� ȣ���ؼ� ���� vector�� ����� ������ insert �Լ��� �Ű������� �ִ´�. 
}

void Stack::pop() {
	// vector�� empty()������ ��쿡�� POP�� ������ �� �����Ƿ� ���� Ŭ������ throw�Ѵ�. 
	if (vector->empty())  throw  StackEmptyException("Pop from empty stack");
	vector->erase(vector->getN() + 1); // vector�� ���� ��ġ�� �ε����� �ִ� ��Ҹ� ����
}

// Stack�� size�� ��ȯ�ϴ� �Լ�, n�� ���� �����Ѵ�. 
int Stack::size() {
	return vector->getN();
}

// Stack�� ���� ������ ��Ҹ� ��ȯ�ϴ� top()�Լ�
Elem Stack::top() const throw(StackEmptyException)
{
	// vector�� ����ִ� ��쿡�� StackEmptyException ���� ó�� Ŭ������ throw�Ѵ�. 
	if (vector->empty())
		throw StackEmptyException("Top from empty stack ");
	return vector->at(vector->getN() - 1);
	// ������ size���� 1���� ���� �ε����� �����Ͽ� ��ȯ
}

// Stack�� ������� vector�� ����ִ��� Ȯ���ϴ� �Լ�
bool Stack::empty() {
	return vector->empty();
}