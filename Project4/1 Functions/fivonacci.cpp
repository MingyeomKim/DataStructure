#include <iostream>
using namespace std;

int fivo(int n) {
	if (n <= 1)
		return n;
	else
		return fivo(n - 1) + fivo(n - 2);
}

// show num index's fivonacci. 
int main() {
	int num; cin >> num;
	cout << fivo(num) << endl;

	return 0;
}