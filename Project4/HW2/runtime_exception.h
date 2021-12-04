#pragma once
#include <iostream>
using namespace std;
// �������� ����, ���� ó�� Ŭ������ ArrayStack Ŭ������ �и�

// RuntimeException Ŭ����, ���� Ŭ������ ��ӹ޾� ��Ȳ�� �´� ����ó���� �����ϰ� �Ѵ�. 
class RuntimeException {
private:
	string errorMsg; // string Ÿ���� errorMsg, ���� ������ �´� �޼����� ��´�. 
public:
	RuntimeException(const string& err) {
		errorMsg = err;
	} // RuntimeException�� ������, errorMsg ������ �ʱ�ȭ�Ѵ�. 
	string getMessage() const {
		return errorMsg;
	} // errorMsg�� ��ȯ�ϴ� getMessage() �Լ�
};

// Stack�� ������� �� pop, top �Լ��� ȣ���� ����� ���� ó�� Ŭ����
class StackEmptyException : public RuntimeException {
public:
	StackEmptyException(const string& err) : RuntimeException(err) 
		// Member Initializer�� ���� Ŭ������ ������ ȣ��
	{}
};

// Stack�� ���� �� ���� �� push �Լ��� ȣ���� ����� ���� ó�� Ŭ���� 
class StackFullException : public RuntimeException {
public:
	StackFullException(const string& err)
		: RuntimeException(err)
		// Member Initializer�� ���� Ŭ������ ������ ȣ��
	{}
};

// inline �Լ��� ����ؼ� �Լ� ȣ�⿡ ���Ǵ� ������带 ������ �� �ִ�. 
// RuntimeException�� ��ü(���� Ŭ���� ��ü�� ����)�� ����� ��� ��� ������ �����ε�
inline ostream& operator<< (ostream& out, const RuntimeException& e) {
	return out << e.getMessage();
} // ��ü�� errorMsg ��� ������ ����Ѵ�. 