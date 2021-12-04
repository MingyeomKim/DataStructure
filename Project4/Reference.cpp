#include <iostream>
using namespace std;
// 포인터를 이용한 Call By Reference
void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

// 레퍼런스를 이용한 Call By Reference
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
// 포인터 연산 X, 안전하다. 
// 함수의 호출 형태가 일반 Call by Value 함수와 동일하여 구분하기 어렵다. 


int main() {
	int a = 10;
	int* ptr = &a;
	int& ref = a; // 별명

	//int& ref1;  // 반드시 선언과 함께 초기화되어야 한다. 
	//int& ref2 = 3;  // 상수에 별명을 붙일 수 없다. 
	int val;
	int& ref1 = val; // 초기화되지 않은 변수의 별명은 당연히 붙일 수 있다. 

	int b = 4;
	int c = 7;
	swap(&b, &c);
	cout << b << ' ' << c << endl;

}