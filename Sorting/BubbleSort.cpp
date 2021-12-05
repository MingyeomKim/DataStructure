#include <iostream>
using namespace std;

void exchangeSort(int n, int *S) {

	for (int i = 0; i < n; i++)
	{ // 0���� n-1 �迭 �ε������� ��ȸ
		for (int j = 0; j < n - (i + 1); j++) {
			// i��° ��ȸ������ i��° ū �ͱ��� ��ȸ�ϸ� ��
			if (S[j] > S[j + 1]) {
				//int temp = S[j];
				//S[j] = S[j + 1];
				//S[j + 1] = temp;
				swap(S[j], S[j + 1]);
			}
		}
	}

}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {

	int n; cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	exchangeSort(n, arr);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	return 0;
}

