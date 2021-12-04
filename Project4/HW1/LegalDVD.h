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
	//���� Ŭ������ Media�� DVD Ŭ�������� �Ҹ��ڸ� ���������� ȣ���ϱ� ���� �����Լ� ���
	virtual ~LegalDVD();

	// LegalDVD�� ������� copyright�� �����ϴ� set �Լ�
	void setCopyright(string copyright);
	// LegalDVD�� ��� ���� copyright�� ��ȯ�ϴ� get�Լ�
	string getCopyright();
	// �������̵� �� play �Լ�, LegalDVD�� ������ Ư¡�� ����� �� �ֵ��� �Ѵ�. 
	virtual void play() const;
};