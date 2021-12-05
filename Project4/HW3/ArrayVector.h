#pragma once
#include <iostream>
using namespace std;

// ArrayVector의 예외를 처리하는 RuntimeException 예외처리 클래스
class RuntimeException {
private:
	string errorMsg;
public:
	RuntimeException(const string& err) {
		errorMsg = err;
	}
	string getMessage() const {
		return errorMsg;
	}
};

// StackEmptyException은 RuntimeException을 상속받아 에러 메세지를 출력한다. 
class StackEmptyException : public RuntimeException {
public:
	StackEmptyException(const string& err)
		:RuntimeException(err) {}
};

// IndexOutOfBounds은 RuntimeException을 상속받아 에러 메세지를 출력한다. 
class IndexOutOfBounds : public RuntimeException {
public:
	IndexOutOfBounds(const string& err)
		:RuntimeException(err) {}
};

typedef char Elem;
// 추후에 int가 아닌 다른 타입으로 코딩한다고 생각했을 때 일일이 찾아서 바꾸지 않기 위해 Elem이라는 타입을 새로 정의하여 사용한다. 
class ArrayVector {
public:
	ArrayVector(int = 10);
	int getN() const;
	void setCapacity(int = 0);
	bool empty() const;
	Elem& operator[] (int i);
	Elem& at(int i) throw(IndexOutOfBounds);
	void erase(int i);
	void insert(int i, const Elem& e);
	void reserve(int N);
private:
	int capacity; // 용량
	int n;  // 요소의 개수
	Elem* A; //  저장소
};