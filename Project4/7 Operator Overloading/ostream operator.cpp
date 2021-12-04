#include <iostream>
using namespace std;

class Point {
private:
	int x, y;
public:
	Point(int _x = 0, int _y = 0)
		:x(_x), y(_y) {}
	void Point::showXY() {
		cout << x << " " << y << endl;
	}
	friend ostream& operator <<(ostream& os, const Point& p);
};

// ostream �����ε��� ������ ���� �Լ� �����ε�
ostream& operator<< (ostream& os, const Point& p) {
	os << "�� ��ǥ�� " << p.x << ", " << p.y << endl;
	return os;
}


int main() {
	Point p(3, 8);
	cout << p << endl;
}