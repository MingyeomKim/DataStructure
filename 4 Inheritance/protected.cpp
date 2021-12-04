#include <iostream>
using namespace std;

class Shape {
private:
	int price;
protected:
	double x, y;
public:
	char* owner;
	Shape(const Shape& s);
	Shape(int don = 0, double x = 0, double y = 0, char* s = "you");
	~Shape();
	void showPrice() const;
};

class Circle : public Shape {
	double radius; // default는 private
public:
	Circle(double r = 0)
		: Shape(1, 2, 3, "circle")
	{
		cout << "circle의 default destructor" << endl;
		radius = r;
		x = 10;
		y = 20;
	}
	double getArea() {
		return radius * radius;
	}
};
int main() {
	Shape* shp = new Circle;
	Circle* c = new Circle;
	shp->showPrice();
	c->showPrice();
	//shp->getArea(); // Error! 상위 클래스에서 하위 클래스의 멤버 함수에 접근할 수 없다. 
	c->getArea();
}