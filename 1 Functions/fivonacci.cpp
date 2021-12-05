#include <iostream>
using namespace std;
#define MAX_SIZE 10
int fivo(int n) {
	if (n <= 1)
		return n;
	else
		return fivo(n - 1) + fivo(n - 2);
} // ��ͷ� ���� Tn = 2 * n/2

// Memoization (�迭�� ���)
int fivo(int n) {
	int i, f[MAX_SIZE];
	f[0] = 0;
	if (n > 0) {
		f[1] = 1;
		for (i = 2; i < n; i++) {
			f[i] = f[i - 1] + f[i - 2];
		}
		return f[n];
	}
}


// show num index's fivonacci. 
int main() {
	int num; cin >> num;
	cout << fivo(num) << endl;

	return 0;
}