#include<iostream>
using namespace std;

int main(void) {
	int a = 1;
	int* ptr1 = &a;
	int* ptr2 = ptr1;
	// ptr1 포인터 변수의 값을 복사

	cout << "a = " << a << " *ptr1 = " << *ptr1 << " *ptr2 = " << *ptr2 << endl;
	a++; // 변수를 이용한 접근 
	cout << "a = " << a << " *ptr1 = " << *ptr1 << " *ptr2 = " << *ptr2 << endl;
	(*ptr1)++; // 포인터를 이용한 접근
	cout << "a = " << a << " *ptr1 = " << *ptr1 << " *ptr2 = " << *ptr2 << endl;
	(*ptr2)++;
	cout << "a = " << a << " *ptr1 = " << *ptr1 << " *ptr2 = " << *ptr2 << endl;

	return 0;
}