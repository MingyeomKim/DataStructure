#include <iostream>
using namespace std;

class Shape {
private:
	int id;
	int price;
	double x, y;
public:
	char* owner;
	Shape(const Shape& s);
	Shape(int _id, int don = 0 , double x = 0, double y = 0, char* s = "you");
	Shape& operator=(const Shape& s);
	~Shape();
};

Shape::Shape(const Shape& s)
	:id(s.id)
{
	cout << "복사 생성자 호출" << endl;
	price = s.price;
	owner = new char[strlen(s.owner) + 1];
	//strcpy(owner, s.owner);
}

Shape::Shape(int _id, int don, double x, double y, char* s) {
	cout << "4인자 생성자 호출" << endl;
	id = _id;
	price = don;
	this->x = x;
	this->y = y;
	owner = new char[strlen(s) + 1];
	//strcpy(owner, s);
}

// 이거 중요함 !!
// 대입 시, 멤버 변수 owner가 동일한 메모리를 가리킬 가능성이 있음. 이를 방지하기 위한 Deep copy 대입 연산자 오버로딩
Shape& Shape::operator=(const Shape& s) {
	if (this == &s) { // 주소끼리 비교 
		return * this;
	} // self assignment시 문제 되는 것 : owner에서 delete되고 없어진 owner 변수를 재사용하게 된다. 
	id = s.id;
	price = s.price;
	x = s.x;
	y = s.y;

	delete owner;
	// 이미 할당된 메모리 ("you")해제

	owner = new char[strlen(s.owner) + 1];
	//strcpy(owner, s.owner);
	return *this;
}

Shape::~Shape() {
	delete owner;
}

int main() {
	Shape shp1(1, 0, 1, 2, "first");
	Shape shp2(2);
	shp2 = shp1;
	cout << shp1.owner << endl;
	cout << shp2.owner << endl;
	return 0;
}