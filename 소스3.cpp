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
	Point& operator++(); //  �� ����
	Point operator++(int); // �� ����
	friend Point& operator --(Point& p);
	void Point::showXY() {
		cout << x << " " << y << endl;
	}
};
// Point��ü���� ������ ��� ������ �����ε�
Point Point::operator+(const Point& p) {
	Point temp(x + p.x, y + p.y);
	return temp;
}

// Point ��ü + ��� ���� �� ������ �����ε� (����Լ�)
Point Point::operator+(int val) {
	Point temp(x + val, y + val);
	return temp;
}
// ��� + Point ��ü (�����Լ�)
Point operator+(int val, Point& p) {
	return p + val;
}

//������
Point& Point::operator++() {
	x++;
	y++;
	return *this; // �������� ��ü ���۷����� ����
}

// �Ŀ��� ����
Point Point::operator++(int) {
	Point temp(x, y); // ���� 
	x++;
	y++;
	return temp;
}

// �����Լ��� ���� ������ ����
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