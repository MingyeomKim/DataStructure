#pragma once
#include "Media.h"
#include <iostream>
using namespace std;

class VTR : public Media {
private:
	string format;
public:
	//constructor
	VTR(string title, int length, string format);
	// destructor
	// 상속 관계의 자식 클래스에서 정상적으로 소멸자를 호출하기 위해서는 가상 함수로 지정해야 한다. 
	virtual ~VTR();
	
	// VTR의 멤버 변수인 format의 값을 할당하는 set 함수
	void setFormat(string format);
	// VTR의 멤버 변수인 format의 값을 반환하는 get 함수
	string getFormat();
	// Media 클래스에서 오버라이딩 되어, VTR만의 고유한 출력을 구현.
	virtual void play() const;
};
