#pragma once
// 헤더 파일이 중복으로 include 되는 것을 방지하기 위하여 #pragma once 전처리기 추가
#include <iostream>
#include <string>
using namespace std;

class Media {
	friend ostream& operator<< (ostream&, const Media*);
	// 입출력 연산자 오버로딩. 
	// 표준 라이브러리인 iostream에 정의되어 있는 클래스 ostream의 내부 멤버 변수에 접근할 수 없으므로 전역함수 오버로딩을 수행.
private:
	string title; // namespace에 정의된 string을 사용.
	int length;
public:
	static int count;
	// 객체가 생성될 때마다 count에 1이 더해진다. 즉 객체의 개수를 나타내는 멤버 변수 
	// 객체의 존재와 무관하게 이미 Static 메모리 영역에 존재한다.

	//constructors
	Media(string title, int length);
	//destructor
	// 상속 관계에서 자식 클래스의 소멸자를 정의할 때 virtual을 사용해야 함.
	// 최상위 클래스에서는 굳이 virtual을 사용하지 않아도 무방하다 
	virtual ~Media();

	// 멤버 변수를 지정하는 set 함수
	void setLength(int length);
	void setTitle(string title);
	// 멤버 변수를 반환하는 get 함수
	int getLength();
	string getTitle();

	// 최상위 클래스에서는 굳이 virtual을 사용하지 않아도 무방하나, 가독성을 위해서 virtual 표시
	// const를 사용해서 멤버 변수 변경의 여지를 없애준다. 
	virtual void play() const;


	// mp[3] = *mp[1] + mp[2] 연산자 오버로딩 구현 
	Media* operator+(const Media*);
	// 포인터 자료형을 리턴해야 하므로 반환 자료형은 Media *이며
	// Media * 자료형인 mp[2]가 피연산자이므로 Media * 자료형으로 받는다. 이때 값의 변경을 방지하기 위해 const 형으로 매개변수를 받도록 한다. 
	void operator=(const Media*);
	// *mp[1] + mp[2]의 결과로 반환된 Media * 자료형의 객체를 받아오므로 매개변수는 다음과 같다. 
	// 반환을 할 필요가 없으니 void 반환형 지정. 
};