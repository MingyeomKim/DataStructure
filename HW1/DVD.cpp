#include "DVD.h"
#include <iostream>
using namespace std;

// DVD�� ���� Ŭ������ Media�� ��� �̴ϼ� �������� �̿��� �Բ� �ʱ�ȭ
DVD::DVD(string title, int length, string license)
	:Media(title, length), license(license)
{
}

// �Ҹ���
DVD::~DVD()
{ 
	cout << "DVD �Ҹ��ڰ� ȣ��Ǿ����ϴ�. " << endl;
}

// DVD�� ��� ���� license�� �����ϴ� set�Լ�
void DVD::setLicense(string license) {
	this->license = license;
}

// DVD�� ��� ���� license�� ��ȯ�ϴ� get�Լ�
string DVD::getLicense()
{
	return license;
}

void DVD::play() const{
	cout << "DVD�� play�ǰ� �ֽ��ϴ�." << endl;
}//overriding ����� �����Ͽ� DVD Ŭ������ play�� ����ǵ��� �Ѵ�. 