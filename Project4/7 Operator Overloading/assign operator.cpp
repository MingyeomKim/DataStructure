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
	cout << "���� ������ ȣ��" << endl;
	price = s.price;
	owner = new char[strlen(s.owner) + 1];
	//strcpy(owner, s.owner);
}

Shape::Shape(int _id, int don, double x, double y, char* s) {
	cout << "4���� ������ ȣ��" << endl;
	id = _id;
	price = don;
	this->x = x;
	this->y = y;
	owner = new char[strlen(s) + 1];
	//strcpy(owner, s);
}

// �̰� �߿��� !!
// ���� ��, ��� ���� owner�� ������ �޸𸮸� ����ų ���ɼ��� ����. �̸� �����ϱ� ���� Deep copy ���� ������ �����ε�
Shape& Shape::operator=(const Shape& s) {
	if (this == &s) { // �ּҳ��� �� 
		return * this;
	} // self assignment�� ���� �Ǵ� �� : owner���� delete�ǰ� ������ owner ������ �����ϰ� �ȴ�. 
	id = s.id;
	price = s.price;
	x = s.x;
	y = s.y;

	delete owner;
	// �̹� �Ҵ�� �޸� ("you")����

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