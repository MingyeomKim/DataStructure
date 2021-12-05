#include <iostream>
using namespace std;
// quick sort

void quicksort(int * arr, int start, int end) {
	if (start >= end) return;
	int pivot = arr[end];
	int left = start;
	int right = end - 1; // pivot을 제외하고 제일 마지막 요소
	while (left <= right) { // left = right인 경우가 왜 속하는 지 생각하기
		while (left <= right && arr[left] <= pivot)
			left++;
		while (left <= right && arr[right] >= pivot)
			right--;
		if (left < right)
			swap(arr[left], arr[right]);
		else
			break;
	}
	swap(arr[left], arr[end]);

	quicksort(arr, start, left - 1);
	quicksort(arr, left + 1, end);
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	int q;
	cin >> q;
	int* a = new int[q];
	for (int i = 0; i < q; i++) {
		cin >> a[i];
	}

	quicksort(a, 0, 7);

	for (int i = 0; i < 8; i++) {
		cout << a[i] << endl;
	}
 	return 0;
}

