#include <iostream>
using namespace std;
// �����͸� �̿��� Call By Reference
void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

// ���۷����� �̿��� Call By Reference
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
// ������ ���� X, �����ϴ�. 
// �Լ��� ȣ�� ���°� �Ϲ� Call by Value �Լ��� �����Ͽ� �����ϱ� ��ƴ�. 


int main() {
	int a = 10;
	int* ptr = &a;
	int& ref = a; // ����

	//int& ref1;  // �ݵ�� ����� �Բ� �ʱ�ȭ�Ǿ�� �Ѵ�. 
	//int& ref2 = 3;  // ����� ������ ���� �� ����. 
	int val;
	int& ref1 = val; // �ʱ�ȭ���� ���� ������ ������ �翬�� ���� �� �ִ�. 

	int b = 4;
	int c = 7;
	swap(&b, &c);
	cout << b << ' ' << c << endl;

}