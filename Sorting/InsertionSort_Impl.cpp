#include <iostream>
using namespace std;
void insert(int, int, int*, int );
void printArray(int *, int);
// Insertion Sort

void InsertionSort(int n, int* S) {
	for (int i = 1; i < n; i++) {
		// 제일 첫번째 요소는 정렬되어있는 상태로 간주
		int elem = S[i];  // 비정렬 배열의 제일 첫 요소 
			// 정렬 안되어있는 배열의 제일 처음요소를 정렬 배열에 삽입(정렬, 비정렬 배열은 하나의 배열에있음)
		for (int j = 0; j < i; j++) {
			if (S[j] < elem) {
				continue;
			}
			else if (S[j] >= elem) {
				// 끼워넣기 
				insert(j, i, S, n);
				break;
				// j 자리의 앞에 elem을 끼워 넣는다 .
			}
			cout << i << "번째 반복에서 " << j << "번째 순회를 돌고 있습니다. " << endl;
			printArray(S, n);
			cout << endl;
		}
	}

}

void printArray(int* S, int n) {
	for (int i = 0; i < n; i++) {
		cout << S[i] << ' ';
	}
	cout << endl;
}

void insert(int i, int j, int * S,int n) { // j 를 i 인덱스 앞에 끼워 넣는다.
	int temp = S[j];
	for (int k = j -1; k >= i; k--) {
		S[k + 1] = S[k];
	}
	S[i] = temp;
} 


int main() {

	
	int n; cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	

	InsertionSort(n, arr);

	printArray(arr, n);
	return 0;
}

/*

7
13 7 9 3 11 6 12

*/