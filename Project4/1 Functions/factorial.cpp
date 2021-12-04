#include <iostream>
using namespace std;

// 재귀로 구현 
// 시간 복잡도 : O(n), 공간 복잡도 : O(n)
int fact_recursion(int n) {
	if (n == 1)
		return 1;
	else
		return fact_recursion(n - 1) * n;
}

// 반복문으로 구현
// 시간 복잡도 : O(n), 공간 복잡도 : O(1)
int fact_loop(int n) {
	int num = 1;
	for (int i = 1; i <= n; i++) {
		num *= i;
	}
	return num;
}

int main() {
	int num; cin >> num;
	int val1 = fact_recursion(num);
	int val2 = fact_loop(num);
	cout << val1 << " " << val2 << endl;

	return 0;
}