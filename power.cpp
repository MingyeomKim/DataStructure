#include <iostream>
using namespace std;
// Linear Recursion


int power(int x, int n) {
	if (n == 0)
		return 1;
	else
		return power(x, n - 1) * n;
} // x ^ n

int power_logn(int x, int n) {
	int temp;
	if (n == 0)
		return 1;
	if (n % 2) {
		temp = power(x, (n - 1) / 2);
		return x * temp * temp;
	}
	else {
		temp = power(x, n / 2);
		return temp * temp;
	}
}

int main() {
	cout << power(2, 6) << endl;
	cout << power_logn(2, 5) << endl;

	return 0;
}