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
	// ��� ������ �ڽ� Ŭ�������� ���������� �Ҹ��ڸ� ȣ���ϱ� ���ؼ��� ���� �Լ��� �����ؾ� �Ѵ�. 
	virtual ~VTR();
	
	// VTR�� ��� ������ format�� ���� �Ҵ��ϴ� set �Լ�
	void setFormat(string format);
	// VTR�� ��� ������ format�� ���� ��ȯ�ϴ� get �Լ�
	string getFormat();
	// Media Ŭ�������� �������̵� �Ǿ�, VTR���� ������ ����� ����.
	virtual void play() const;
};
