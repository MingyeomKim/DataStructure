#include<iostream>
using namespace std;

int main(void) {
	int a = 1;
	int* ptr1 = &a;
	int* ptr2 = ptr1;
	// ptr1 ������ ������ ���� ����

	cout << "a = " << a << " *ptr1 = " << *ptr1 << " *ptr2 = " << *ptr2 << endl;
	a++; // ������ �̿��� ���� 
	cout << "a = " << a << " *ptr1 = " << *ptr1 << " *ptr2 = " << *ptr2 << endl;
	(*ptr1)++; // �����͸� �̿��� ����
	cout << "a = " << a << " *ptr1 = " << *ptr1 << " *ptr2 = " << *ptr2 << endl;
	(*ptr2)++;
	cout << "a = " << a << " *ptr1 = " << *ptr1 << " *ptr2 = " << *ptr2 << endl;

	return 0;
}