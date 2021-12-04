#include "VTR.h"
#include <iostream>
using namespace std;

VTR::VTR(string title, int length, string format)
	:Media(title, length), format(format)
{ // 멤버 이니셜라이저를 이용해서 상속 클래스인 Media의 멤버 변수, format 멤버 변수를 초기화
}

// 가상함수로 선언한 VTR 소멸자
VTR::~VTR()
{ 
	cout << "VTR소멸자가 호출되었습니다. " << endl;
}

// VTR의 멤버 변수 format을 변경하는 set함수
void VTR::setFormat(string format) {
	this->format = format;
}

// VTR의 멤버 변수 format을 반환하는 get 함수 
string VTR::getFormat() {
	return format;
}

// 가상함수로 선언한 오버라이딩 된 함수 play
void VTR::play() const{
	cout << "VTR이 play되고 있습니다." << endl;
}
