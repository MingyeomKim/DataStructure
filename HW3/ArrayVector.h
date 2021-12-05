#pragma once
#include <iostream>
using namespace std;

// ArrayVector�� ���ܸ� ó���ϴ� RuntimeException ����ó�� Ŭ����
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

// StackEmptyException�� RuntimeException�� ��ӹ޾� ���� �޼����� ����Ѵ�. 
class StackEmptyException : public RuntimeException {
public:
	StackEmptyException(const string& err)
		:RuntimeException(err) {}
};

// IndexOutOfBounds�� RuntimeException�� ��ӹ޾� ���� �޼����� ����Ѵ�. 
class IndexOutOfBounds : public RuntimeException {
public:
	IndexOutOfBounds(const string& err)
		:RuntimeException(err) {}
};

typedef char Elem;
// ���Ŀ� int�� �ƴ� �ٸ� Ÿ������ �ڵ��Ѵٰ� �������� �� ������ ã�Ƽ� �ٲ��� �ʱ� ���� Elem�̶�� Ÿ���� ���� �����Ͽ� ����Ѵ�. 
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
	int capacity; // �뷮
	int n;  // ����� ����
	Elem* A; //  �����
};