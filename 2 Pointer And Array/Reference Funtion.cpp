#include <iostream>
using namespace std;

int& addOne(int& val) {
	val++;
	return val; // reference 변수를 반환
}

int& function(void) { // 여기를 int 반환으로 고치면 아래 int &ref2 = fucntion() 부분에서 컴파일 에러
	int val = 10;
	return val; // 일반 변수를 반환 
}

int main() {
	int n = 3;
	int& ref = addOne(n);
	// ref와 n은 같은 변수이다. 
	cout << n << " " << ref << endl; // 4 4 
	cout << (ref == n) << endl; // 1

	int& ref2 = function();
	cout << ref2 << endl; // 10
}