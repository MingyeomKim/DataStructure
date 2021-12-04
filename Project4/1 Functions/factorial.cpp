#include <iostream>
using namespace std;

// ��ͷ� ���� 
// �ð� ���⵵ : O(n), ���� ���⵵ : O(n)
int fact_recursion(int n) {
	if (n == 1)
		return 1;
	else
		return fact_recursion(n - 1) * n;
}

// �ݺ������� ����
// �ð� ���⵵ : O(n), ���� ���⵵ : O(1)
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