#include "Media.h" // Media 헤더파일 include
#include "VTR.h"
#include <iostream>
#include <string>
using namespace std;

// Media 클래스 생성자, 두 가지 멤버 변수에 대한 입력을 받는다.
Media::Media(string title = "Default", int length = 0)
	: title(title), length(length)
{ // 멤버 이니셜라이저를 이용한 멤버 변수 초기화 
	count++; 
}// 객체를 생성할 때마다 생성자가 호출되므로, 생성자 내부 정의에서 count값을 1씩 증가시킨다. 

// 소멸자
Media::~Media() {
	cout << "Media 소멸자가 호출되었습니다. " << endl;
	count--;
}

// 멤버 변수 length의 값을 지정하는 setLength 함수
void Media::setLength(int length)
{ // this 포인터와 arrow 연산자를 이용한 멤버 변수 length 접근 후 변경
	this->length = length;
}

// 멤버 변수 title의 값을 지정하는 setTitle 함수
void Media::setTitle(string title)
{ // this 포인터와 arrow 연산자를 이용한 멤버 변수 title 접근 후 변경
	this->title = title;
}
	
// length 멤버 변수를 불러오는 getLength 함수
int Media::getLength() {
	return length;
}

// title 멤버 변수를 불러오는 getTitle 함수
string Media::getTitle() {
	return title;
}

// 단순 출력문에서 멤버 변수가 사용되었을 경우 값 변경을 방지하기 위해 const 사용
void Media::play () const {
	cout << "Media 클래스의 play 함수가 호출되었습니다." << endl;
}



// Media + 연산자 오버로딩
Media* Media::operator+(const Media* mp) {
	Media* temp = new VTR("Disney", getLength() + mp->length, "mkv");
	// this 객체에서 Title은 그대로, Length값에서 매개변수로 들어온 mp 변수의 Length와 더해서 임시의 변수 temp를 정의한다. 
	return temp;
}

/*
Media* Media::operator+(const Media* mp) {
	this->length += mp->length;
	return this;
}
*/


// mp = *mp[1] + mp[2]에서 +연산자 오버로딩에서 반환된 temp 객체를 매개변수에 넣음으로써, 대입 연산자 오버로딩 수행
void Media::operator=(const Media* temp)
{ // 매개변수에는 mp[1]이 들어오게 된다. 
	cout << "= 연산자 오버로딩 실행 " << endl;
	setLength(temp->length);
	delete temp;
	// 새로 할당한 temp의 쓰임(length 값 업데이트)을 다했으니 메모리를 해제해준다. 
}

// 전역함수로 정의한 출력 연산자 오버로딩D
ostream& operator<<(ostream& output, const Media* media)
{
	media->play(); // virtual을 사용해서 media 포인터의 실제 객체의 타입에 따라 다른 출력이 나오도록 구현한다. 
	return output; 
	// 중복 출력이 가능하기 위해 ostream 객체를 리턴해준다. 
}