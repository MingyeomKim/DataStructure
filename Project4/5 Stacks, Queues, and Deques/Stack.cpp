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
	StackFullException(const string& msg)  // �� const�� ���̴°���
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
			throw StackEmptyException("������ ��������Ƿ� top�� ������ �� �����ϴ�. ");
		return S[t];
	}
	void push(const T& obj) {
		if (max == size())
			throw StackFullException("������ ���� �� �����Ƿ� push�� ������ �� �����ϴ�. ");
		t++;
		S[t] = obj;
	}
	T& pop() {
		if (isEmpty())
			throw StackEmptyException("������ ��������Ƿ� pop�� ������ �� �����ϴ� .");
		T o = S[t];
		t--;
		return o;
	}

};