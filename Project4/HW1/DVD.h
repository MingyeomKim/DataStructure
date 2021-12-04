#pragma once
#include <iostream>
using namespace std;
#include "Media.h" // ������� include�� �ֵ���ǥ ����ϱ�

class DVD : public Media {
private:
	string license;
public:
	//constructors
	DVD(string title, int length, string license);
	//desturctor
	// virtual Ű���带 ����ؼ� DVD�� �Ҹ��ڰ� ���������� ȣ��ǵ��� ����
	virtual ~DVD();
	
	// DVD�� ��� ������ license�� ����, ��ȯ�ϴ� set/get�Լ� 
	void setLicense(string license);
	string getLicense();

	virtual void play() const;
};
