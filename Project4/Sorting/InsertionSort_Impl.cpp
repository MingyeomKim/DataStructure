#include <iostream>
using namespace std;
void insert(int, int, int*, int );
void printArray(int *, int);
// Insertion Sort

void InsertionSort(int n, int* S) {
	for (int i = 1; i < n; i++) {
		// ���� ù��° ��Ҵ� ���ĵǾ��ִ� ���·� ����
		int elem = S[i];  // ������ �迭�� ���� ù ��� 
			// ���� �ȵǾ��ִ� �迭�� ���� ó����Ҹ� ���� �迭�� ����(����, ������ �迭�� �ϳ��� �迭������)
		for (int j = 0; j < i; j++) {
			if (S[j] < elem) {
				continue;
			}
			else if (S[j] >= elem) {
				// �����ֱ� 
				insert(j, i, S, n);
				break;
				// j �ڸ��� �տ� elem�� ���� �ִ´� .
			}
			cout << i << "��° �ݺ����� " << j << "��° ��ȸ�� ���� �ֽ��ϴ�. " << endl;
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

void insert(int i, int j, int * S,int n) { // j �� i �ε��� �տ� ���� �ִ´�.
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