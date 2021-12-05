#include <iostream>
using namespace std;
#pragma once 

class StackException {
private:
	string msg;
public:
	StackException(string message) {
		msg = message;
	}
	string getMessage() const {
		return msg;
	}
};

class StackFullException :public StackException {
public:
	StackFullException(const string& msg)  // 왜 const를 붙이는거쥐
		:StackException(msg)
	{ }
};

class StackEmptyException : public StackException {
public:
	StackEmptyException(const string& msg)
		:StackException(msg)
	{}
};

template <typename T>
class Stack {
private:
	T* S;
	int max;
	int t;
public:
	Stack(int max = 10) {
		this->max = max;
		S = new int[max];
		t = 0;
	}
	~Stack() {
		delete S;
	}
	int size() const {
		return t + 1;
	}
	bool isEmpty() const {
		return t < 0;
	}
	const T& top() throw(StackEmptyException) {
		if (isEmpty())
			throw StackEmptyException("스택이 비어있으므로 top을 실행할 수 없습니다. ");
		return S[t];
	}
	void push(const T& obj) {
		if (max == size())
			throw StackFullException("스택이 가득 차 있으므로 push를 실행할 수 없습니다. ");
		t++;
		S[t] = obj;
	}
	T& pop() {
		if (isEmpty())
			throw StackEmptyException("스택이 비어있으므로 pop을 실행할 수 없습니다 .");
		T o = S[t];
		t--;
		return o;
	}

};