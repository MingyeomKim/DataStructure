#include "VTR.h"
#include <iostream>
using namespace std;

VTR::VTR(string title, int length, string format)
	:Media(title, length), format(format)
{ // ��� �̴ϼȶ������� �̿��ؼ� ��� Ŭ������ Media�� ��� ����, format ��� ������ �ʱ�ȭ
}

// �����Լ��� ������ VTR �Ҹ���
VTR::~VTR()
{ 
	cout << "VTR�Ҹ��ڰ� ȣ��Ǿ����ϴ�. " << endl;
}

// VTR�� ��� ���� format�� �����ϴ� set�Լ�
void VTR::setFormat(string format) {
	this->format = format;
}

// VTR�� ��� ���� format�� ��ȯ�ϴ� get �Լ� 
string VTR::getFormat() {
	return format;
}

// �����Լ��� ������ �������̵� �� �Լ� play
void VTR::play() const{
	cout << "VTR�� play�ǰ� �ֽ��ϴ�." << endl;
}
