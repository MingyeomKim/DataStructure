#pragma once
#include <iostream>
using namespace std;
#include "Media.h" // 헤더파일 include시 쌍따옴표 사용하기

class DVD : public Media {
private:
	string license;
public:
	//constructors
	DVD(string title, int length, string license);
	//desturctor
	// virtual 키워드를 사용해서 DVD의 소멸자가 정상적으로 호출되도록 구현
	virtual ~DVD();
	
	// DVD의 멤버 변수인 license를 변경, 반환하는 set/get함수 
	void setLicense(string license);
	string getLicense();

	virtual void play() const;
};
