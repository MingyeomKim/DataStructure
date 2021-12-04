#include <iostream>
using namespace std;


int main() {
	const float PI = 3.141592;

	int i = 12;
	int j = 12, k = 0;

	const int* ptr1 = &i; // 가리키는 곳을 상수화
	//*ptr = 30; // Error 
	포인터가 가리키는 곳을 역참조해서 접근해 변경했을 때 에러가 발생한다.
		i = 30; // i의 값을 변경할 수 있다. 
	ptr1 = &j; // 주솟값을 변경할 수 있다. 

	int const* ptr2 = &j; // 포인터 상수화
	ptr2 = &k; // 포인터가 가리키는 곳을 변경할 수 있다. 
	//*ptr2 = 30; // Error
	포인터가 가리키는 곳을 역참조해서 접근해 변경했을 때 에러가 발생한다.

		j = 30; // 변수의 값을 직접 변경하는 것은 가능 

}