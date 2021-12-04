
#include "LegalDVD.h"
#include <iostream>
using namespace std;

LegalDVD::LegalDVD(string title, int length, string license, string copyright)
	:DVD(title, length, license), copyright(copyright)
{// LegalDVD는 DVD에서 상속된 클래스이므로, 멤버 이니셜라이저를 이용해 LegalDVD 멤버 변수 뿐만 아니라 DVD의 멤버 변수도 함께 초기화한다. 
}

// 가상함수로 선언한 LegalDVD의 소멸자
LegalDVD::~LegalDVD()
{ 
	cout << "Legal DVD 소멸자가 호출되었습니다. " << endl;
}

void LegalDVD::setCopyright(string copyright)
{ // this포인터를 이용해 멤버 변수 copyright를 초기화한다. 
	this->copyright = copyright;
}

string LegalDVD::getCopyright() {
	return copyright;
}// LegalDVD의 멤버 변수 copyright를 반환

void LegalDVD::play() const{
	cout << "LegalDVD가 play되고 있습니다. " << endl;
}//overriding 기능을 구현하여 LegalDVD 클래스의 play가 실행되도록 한다. 

