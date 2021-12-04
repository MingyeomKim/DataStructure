#include "Media.h" // Media ������� include
#include "VTR.h"
#include <iostream>
#include <string>
using namespace std;

// Media Ŭ���� ������, �� ���� ��� ������ ���� �Է��� �޴´�.
Media::Media(string title = "Default", int length = 0)
	: title(title), length(length)
{ // ��� �̴ϼȶ������� �̿��� ��� ���� �ʱ�ȭ 
	count++; 
}// ��ü�� ������ ������ �����ڰ� ȣ��ǹǷ�, ������ ���� ���ǿ��� count���� 1�� ������Ų��. 

// �Ҹ���
Media::~Media() {
	cout << "Media �Ҹ��ڰ� ȣ��Ǿ����ϴ�. " << endl;
	count--;
}

// ��� ���� length�� ���� �����ϴ� setLength �Լ�
void Media::setLength(int length)
{ // this �����Ϳ� arrow �����ڸ� �̿��� ��� ���� length ���� �� ����
	this->length = length;
}

// ��� ���� title�� ���� �����ϴ� setTitle �Լ�
void Media::setTitle(string title)
{ // this �����Ϳ� arrow �����ڸ� �̿��� ��� ���� title ���� �� ����
	this->title = title;
}
	
// length ��� ������ �ҷ����� getLength �Լ�
int Media::getLength() {
	return length;
}

// title ��� ������ �ҷ����� getTitle �Լ�
string Media::getTitle() {
	return title;
}

// �ܼ� ��¹����� ��� ������ ���Ǿ��� ��� �� ������ �����ϱ� ���� const ���
void Media::play () const {
	cout << "Media Ŭ������ play �Լ��� ȣ��Ǿ����ϴ�." << endl;
}



// Media + ������ �����ε�
Media* Media::operator+(const Media* mp) {
	Media* temp = new VTR("Disney", getLength() + mp->length, "mkv");
	// this ��ü���� Title�� �״��, Length������ �Ű������� ���� mp ������ Length�� ���ؼ� �ӽ��� ���� temp�� �����Ѵ�. 
	return temp;
}

/*
Media* Media::operator+(const Media* mp) {
	this->length += mp->length;
	return this;
}
*/


// mp = *mp[1] + mp[2]���� +������ �����ε����� ��ȯ�� temp ��ü�� �Ű������� �������ν�, ���� ������ �����ε� ����
void Media::operator=(const Media* temp)
{ // �Ű��������� mp[1]�� ������ �ȴ�. 
	cout << "= ������ �����ε� ���� " << endl;
	setLength(temp->length);
	delete temp;
	// ���� �Ҵ��� temp�� ����(length �� ������Ʈ)�� �������� �޸𸮸� �������ش�. 
}

// �����Լ��� ������ ��� ������ �����ε�D
ostream& operator<<(ostream& output, const Media* media)
{
	media->play(); // virtual�� ����ؼ� media �������� ���� ��ü�� Ÿ�Կ� ���� �ٸ� ����� �������� �����Ѵ�. 
	return output; 
	// �ߺ� ����� �����ϱ� ���� ostream ��ü�� �������ش�. 
}