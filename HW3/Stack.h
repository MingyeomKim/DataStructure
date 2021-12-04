#include "ArrayVector.h"
#pragma once


// ArrayVector를 이용해서 구현한 Stack 클래스 
class Stack {
public:
	Stack(int = 0);
	~Stack();
	void push(const Elem& elem);
	// 스택의 i번째 인덱스에 elem 삽입
	void pop();
	Elem top() const throw(StackEmptyException);
	bool empty();
	int size();
private: 
	ArrayVector *vector; // vector 저장소
};

// Stack의 생성자, capacity의 값을 받아 vector의 capacity를 초기화한다. 
Stack::Stack(int capacity) 
	: vector (new ArrayVector)
{
	vector->setCapacity(capacity);
}

// 멤버변수인 vector의 메모리를 해제해준다. 
Stack::~Stack() {
	delete vector;
}

void Stack::push(const Elem& elem) {
	// insert 함수 내에서, capacity를 초과하였을 경우 용량을 두 배 증가시키는 코드가 있으므로, stackFull일 경우의 예외를 따로 처리하지 않는다. 
	vector->insert(vector->getN(), elem);
	// Stack의 특성 상 push는 LIFO의 방식으로 진행되기 때문에 현재 위치에서 1만큼 커진 부분에 elem을 삽입한다. 
	// getN을 호출해서 현재 vector의 요소의 개수를 insert 함수의 매개변수로 넣는다. 
}

void Stack::pop() {
	// vector이 empty()상태인 경우에는 POP을 진행할 수 없으므로 예외 클래스를 throw한다. 
	if (vector->empty())  throw  StackEmptyException("Pop from empty stack");
	vector->erase(vector->getN() + 1); // vector의 현재 위치의 인덱스에 있는 요소를 제거
}

// Stack의 size를 반환하는 함수, n의 값을 리턴한다. 
int Stack::size() {
	return vector->getN();
}

// Stack의 가장 마지막 요소를 반환하는 top()함수
Elem Stack::top() const throw(StackEmptyException)
{
	// vector가 비어있는 경우에는 StackEmptyException 예외 처리 클래스를 throw한다. 
	if (vector->empty())
		throw StackEmptyException("Top from empty stack ");
	return vector->at(vector->getN() - 1);
	// 스택의 size보다 1보다 작은 인덱스에 접근하여 반환
}

// Stack의 멤버변수 vector가 비어있는지 확인하는 함수
bool Stack::empty() {
	return vector->empty();
}