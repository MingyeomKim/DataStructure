#include <iostream>
using namespace std;

void printArray(int* S, int n) {
	for (int i = 0; i < n; i++) {
		cout << S[i] << " ";
	}
	cout << endl;
}

void Insertion(int n, int* S) {
	int i, j;
	int x;
	for (i = 1; i < n; i++) {
		x = S[i];
		j = i - 1;
		while	(S[j] > x) {
			S[j + 1] = S[j];
			j--;
		}
		S[j + 1] = x;
	}
}

int main() {

	int n; cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	Insertion(n, arr);

	printArray(arr, n);
	return 0;
}