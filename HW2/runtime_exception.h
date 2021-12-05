#pragma once
#include <iostream>
using namespace std;
// 가독성을 위해, 예외 처리 클래스와 ArrayStack 클래스를 분리

// RuntimeException 클래스, 하위 클래스가 상속받아 상황에 맞는 예외처리를 가능하게 한다. 
class RuntimeException {
private:
	string errorMsg; // string 타입의 errorMsg, 에러 종류에 맞는 메세지를 담는다. 
public:
	RuntimeException(const string& err) {
		errorMsg = err;
	} // RuntimeException의 생성자, errorMsg 변수를 초기화한다. 
	string getMessage() const {
		return errorMsg;
	} // errorMsg를 반환하는 getMessage() 함수
};

// Stack이 비어있을 때 pop, top 함수를 호출한 경우의 예외 처리 클래스
class StackEmptyException : public RuntimeException {
public:
	StackEmptyException(const string& err) : RuntimeException(err) 
		// Member Initializer로 상위 클래스의 생성자 호출
	{}
};

// Stack이 가득 차 있을 때 push 함수를 호출한 경우의 예외 처리 클래스 
class StackFullException : public RuntimeException {
public:
	StackFullException(const string& err)
		: RuntimeException(err)
		// Member Initializer로 상위 클래스의 생성자 호출
	{}
};

// inline 함수를 사용해서 함수 호출에 사용되는 오버헤드를 절약할 수 있다. 
// RuntimeException의 객체(하위 클래스 객체도 포함)를 출력한 경우 출력 연산자 오버로딩
inline ostream& operator<< (ostream& out, const RuntimeException& e) {
	return out << e.getMessage();
} // 객체의 errorMsg 멤버 변수를 출력한다. 