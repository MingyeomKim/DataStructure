#include <iostream>
using namespace std;

class Point {
private:
	int x, y;
public:
	Point(int _x = 0, int _y = 0)
		:x(_x), y(_y) {}
	Point operator+(const Point& p);
	Point operator+(int);
	Point& operator++(); //  전 연산
	Point operator++(int); // 후 연산
	friend Point& operator --(Point& p);
	void Point::showXY() {
		cout << x << " " << y << endl;
	}
};
// Point객체끼리 더했을 경우 연산자 오버로딩
Point Point::operator+(const Point& p) {
	Point temp(x + p.x, y + p.y);
	return temp;
}

// Point 객체 + 상수 했을 때 연산자 오버로딩 (멤버함수)
Point Point::operator+(int val) {
	Point temp(x + val, y + val);
	return temp;
}
// 상수 + Point 객체 (전역함수)
Point operator+(int val, Point& p) {
	return p + val;
}

//선연산
Point& Point::operator++() {
	x++;
	y++;
	return *this; // 역참조한 객체 레퍼런스를 리턴
}

// 후연산 구분
Point Point::operator++(int) {
	Point temp(x, y); // 현재 
	x++;
	y++;
	return temp;
}

// 전역함수로 감소 연산자 구현
Point& operator-- (Point& p) {
	p.x--;
	p.y--;
	return p;
}


int main() {
	Point p1(1, 2);
	Point p2(2, 1);
	Point p3 = p1 + p2;

	p3.showXY();

	return 0;
}