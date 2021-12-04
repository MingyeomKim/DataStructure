#pragma once
#include "DVD.h"
#include <iostream>
using namespace std;

class LegalDVD :public DVD {
private:
	string copyright;
public:
	//constructor
	LegalDVD(string title, int length, string license, string copyright);
	//destructor
	//상위 클래스인 Media와 DVD 클래스에서 소멸자를 정상적으로 호출하기 위해 가상함수 사용
	virtual ~LegalDVD();

	// LegalDVD의 멤버변수 copyright를 변경하는 set 함수
	void setCopyright(string copyright);
	// LegalDVD의 멤버 변수 copyright를 반환하는 get함수
	string getCopyright();
	// 오버라이딩 된 play 함수, LegalDVD의 고유한 특징을 출력할 수 있도록 한다. 
	virtual void play() const;
};