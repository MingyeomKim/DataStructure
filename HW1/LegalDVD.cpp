
#include "LegalDVD.h"
#include <iostream>
using namespace std;

LegalDVD::LegalDVD(string title, int length, string license, string copyright)
	:DVD(title, length, license), copyright(copyright)
{// LegalDVD�� DVD���� ��ӵ� Ŭ�����̹Ƿ�, ��� �̴ϼȶ������� �̿��� LegalDVD ��� ���� �Ӹ� �ƴ϶� DVD�� ��� ������ �Բ� �ʱ�ȭ�Ѵ�. 
}

// �����Լ��� ������ LegalDVD�� �Ҹ���
LegalDVD::~LegalDVD()
{ 
	cout << "Legal DVD �Ҹ��ڰ� ȣ��Ǿ����ϴ�. " << endl;
}

void LegalDVD::setCopyright(string copyright)
{ // this�����͸� �̿��� ��� ���� copyright�� �ʱ�ȭ�Ѵ�. 
	this->copyright = copyright;
}

string LegalDVD::getCopyright() {
	return copyright;
}// LegalDVD�� ��� ���� copyright�� ��ȯ

void LegalDVD::play() const{
	cout << "LegalDVD�� play�ǰ� �ֽ��ϴ�. " << endl;
}//overriding ����� �����Ͽ� LegalDVD Ŭ������ play�� ����ǵ��� �Ѵ�. 

