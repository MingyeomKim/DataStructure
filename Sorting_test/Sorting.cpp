#include <iostream>
using namespace std;

// Bubble Sort�� ? 
/*
	�迭�� ���� ������ ��Һ��� �����ؼ�, 
	�� ���� ��Ҷ� �������� ���Ѵ�. 
	�ڿ� �� ���� �տ� �� �� ������ ����, �ڿ� ���� �� ������ Swap
*/

// ������������ ����
void BubbleSort(int * arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - (i + 1); j++) { // 
			if (arr[j] < arr[j + 1]) { // �� ū ���� �ڷ� �ѱ��(arr[i] > arr[i + 1]) �������� �迭 �ݴ�� �ϸ� ��������
				// ���� ��Ұ� ���� ��Һ��� �� ū ���, swap
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

/*
Insertion Sort 
���ĵ� �迭�� ���ĵ��� ���� �迭�� ����, 
���ĵ��� ���� �迭�� ù ��Ҹ� ���ĵ� �迭���� ����, ������ ��ġ�� Insert�Ѵ�.

*/

void InsertSort(int* arr, int n) {
	int i;
	// i�� sort�� �� �迭�� ��ȸ
	// j�� sort�� �迭�� ��ȸ
	for (i = 1; i < n; i++) {
		int temp = arr[i]; // �ݵ�� ������ ��Ƽ� ���, Insert�� ������ ���� �н�?�� �� �ִ�. 
		int j = i - 1; // sort�� �迭�� ���� ������ ���
		while (j >= 0 && arr[j] > temp) {
			arr[j + 1] = arr[j]; // sort�� �迭�� �ϳ��� ���������� Shift
			j--;
		}
		arr[j + 1] = temp; // �����ֱ� 
	}	
}

void InsertSort_naerim(int* arr, int n) {

	for (int i = 1; i < n; i++) {
		int temp = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > temp) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
}


void selectionSort(int* arr, int n) {
	for (int i = 0; i < n - 1; i++) { // min�� ���� ���� ���������� �ι�°������ �����ϴ� �ɷ�!
		int min = i; // �ּڰ��� �ε����� ���� 
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min]) { // �ּڰ� ��
				min = j; // �ּڰ��� �ε����� ���� ���� 
			}
		}
		// min���� ���Ӱ� ������ ���
		int temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
		// ���� : ���� min���� ���� Ŀ�� min = i���� ��쿡�� swap�� ����ȴ�. 
	}
}

void printArray(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
		}
	cout << endl;
}

// mergeSort �����ϱ�
void merge(int* U, int* V, int* arr, int h, int m) {
	int i, j, k; // ���� U, V, arr�� index
	i = 0; j = 0; k = 0;
	while (i < h && j < m) { // �迭�� size�� �ε����� ���� �� ����.
		if (U[i] < V[j]) {
			arr[k] = U[i]; // ���� ���� �켱���� �Ͽ� �ִ´�. 
			i++; k++;
		}
		else { // V[j]�� ���ų� ���� ���
			arr[k] = V[j]; // ���� ���� �켱���� �Ͽ� arr�� �ִ´�. 
			j++; k++;
		}
	}

	if (i >= h) { // U�� ���� ��ȸ�ϰ� V�� ��Ұ� ������ ��� 
		while (j < m) {
			arr[k] = V[j];
			j++; k++;
		}
	}
	else if(j >= m){ // V�� ���� ��ȸ�ϰ� U�� ��Ұ� ������ ���
		while (i < h) {
			arr[k] = U[i];
			i++; k++;
		}
	}

}

void mergeSort(int* arr, int n) {
	const int h = n / 2, m = n - h; 
	if (n > 1) {

		int* U = new int[h]; // ���� 
		int* V = new int[m];  // ������
		for (int i = 0; i < h; i++) {
			U[i] = arr[i];
		}
		for (int j = 0; j < m; j++) {
			V[j] = arr[h + j];
		}
		mergeSort(U, h);
 		mergeSort(V, m);
		merge(U, V, arr, h, m);
	}
	
}

/*
QuickSort ����
1.  pivot�� left, right ���� �����Ѵ�. 
2. left�� ����������, right�� �������� ��ȸ�ϸ鼭
3. ��ȸ�� ������ pivot�� ���� ��, left�� pivot���� ���� ������ stop, right�� pivot���� ���� ũ�� stop. 
*/

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


// pivot�� ���� ���� ��ҷ� ����
void quickSort(int* arr, int a, int b) { // a : �迭�� ����, b : �迭�� �� 
	if (a >= b) return; 
	int pivot = arr[a];
	int left = a + 1; 
	int right = b;
	while (left <= right) // left > right�� �Ǹ� while�� ����
	{
		while (left <= right && arr[left] <= pivot) { // left�� ���� pivot���� ũ�� Stop
			left++; // left�� ���� pivot���� Ŭ �� (�ڷ� �ѱ��)
		}
		while (left <= right && arr[right] > pivot) { // right ���� pivot���� ������ Stop
			right--;
		} 
		if (left < right) {
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}
	}
	int temp = arr[right];
	arr[right] = arr[a];
	arr[a] = temp;
	// pivot�� right ���� �ٲ��ش�. 
	// �� right ���̳�? : right�� pivot���� ���� �� Stop�Ѵ�. �� Stop�Ǿ� �ִ� ���¿��� right�� �׻� pivot���� �����Ƿ�, 
	// ���ʿ� �ִ� pivot�� ��ġ�� �ٲپ��־�� ������ �ȴ�. 

	quickSort(arr, a, left -1);
	quickSort(arr, left, b);

	//�̰� �� ��?????? ����������������
}

 // Quick Sort ������������ ���� (pivot�� �� ������ ����)
void QuickSort_naerim(int* arr, int a, int b) {
	if (a >= b) return; // a�� b�� ������ �� ���� �����̰ų� a�� �� ũ�� return 
	int pivot = arr[b];
	int left = a;
	int right = b - 1;
	while (left <=  right) { // ��ȣ�� �ٿ���� ���������� �� �����ȴ�. ��? 
		while (left <= right && arr[left] >= pivot) // left�� pivot���� ���� �� Stop
			left++;
		while (left <= right && arr[right] <= pivot) // right�� pivot���� Ŭ �� Stop
			right--;
		if (left < right) {
			swap(arr[left], arr[right]);
		}
	}
	swap(arr[left], arr[b]);
	// pivot���� ���� �ָ� �ڿ� ���־� �Ѵ�. 
	QuickSort_naerim(arr, a, left - 1);
	QuickSort_naerim(arr, left + 1, b);

}

// ������ ����� ���ǳ�Ʈ �ڵ� �״�� ������ �Լ�
void QuickSort_gangno(int* arr, int a, int b) {
	if (a >= b) return;
	int p = arr[b];
	int left = a;
	int right = b - 1;
	while (left < right) {
		while (left <= right && arr[left] <= p)
			left++;
		while (left <= right && arr[right] >= p)
			right--;
		if (left < right) {
			swap(arr[left], arr[right]);
		}
	}
	// left�� right�� ������ ������ ��
	swap(arr[left ], arr[b]);
	
	QuickSort_gangno(arr, a, left - 1);
	QuickSort_gangno(arr, left + 1, b);
}


int main() {
	int arr[8] = { 31,24,63,45,17,85,96,50 };
	//QuickSort_gangno(arr, 0, 7);
	InsertSort_naerim(arr, 7);
	printArray(arr, 8);

	return 0;
}