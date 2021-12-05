#include "DVD.h"
#include <iostream>
using namespace std;

// DVD의 상위 클래스인 Media를 멤버 이니셜 라이저를 이용해 함께 초기화
DVD::DVD(string title, int length, string license)
	:Media(title, length), license(license)
{
}

// 소멸자
DVD::~DVD()
{ 
	cout << "DVD 소멸자가 호출되었습니다. " << endl;
}

// DVD의 멤버 변수 license를 변경하는 set함수
void DVD::setLicense(string license) {
	this->license = license;
}

// DVD의 멤버 변수 license를 반환하는 get함수
string DVD::getLicense()
{
	return license;
}

void DVD::play() const{
	cout << "DVD가 play되고 있습니다." << endl;
}//overriding 기능을 구현하여 DVD 클래스의 play가 실행되도록 한다. 