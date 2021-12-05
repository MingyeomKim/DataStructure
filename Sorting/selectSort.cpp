#include <iostream>
using namespace std;

void selectionSort(int n, int* S) {
	for (int i = 0; i < n; i++) {
		int smallest = i; // 정렬되지 않은 부분에서의 첫 요소
		for (int j = i + 1; j < n; j++) {
			if (S[j] < S[smallest]) {
				smallest = j;
			}
		}
		swap(S[smallest], S[i]);
	}
}


void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}


void printArray(int* S, int n) {
	for (int i = 0; i < n; i++) {
		cout << S[i] << ' ';
	}
	cout << endl;
}



int main() {
	int n; cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	selectionSort(n, arr);

	printArray(arr, n);
	return 0;
}