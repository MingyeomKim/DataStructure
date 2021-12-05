#include <iostream>
using namespace std;


int main() {
	char str1[4] = "abc";
	char* str2 = "abc";
	// 프로젝트 > 속성 > C/C++ > 언어 > 준수모드 > 아니오 로 변경

	str1[1] = 'D';
	//str2[1] = 'd';
	// 포인터 상수의 값을 변경할 수 없다. 

	cout << str1 << " " << str2 << endl;

	return 0;
}