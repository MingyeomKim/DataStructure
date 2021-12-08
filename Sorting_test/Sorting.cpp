#include <iostream>
using namespace std;

// Bubble Sort란 ? 
/*
	배열의 제일 마지막 요소부터 시작해서, 
	그 앞의 요소랑 차례차례 비교한다. 
	뒤에 것 보다 앞에 게 더 작으면 유지, 뒤에 것이 더 작으면 Swap
*/

// 오름차순으로 구현
void BubbleSort(int * arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - (i + 1); j++) { // 
			if (arr[j] < arr[j + 1]) { // 더 큰 것을 뒤로 넘기면(arr[i] > arr[i + 1]) 오름차순 배열 반대로 하면 내림차순
				// 앞의 요소가 뒤의 요소보다 더 큰 경우, swap
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

/*
Insertion Sort 
정렬된 배열과 정렬되지 않은 배열을 구분, 
정렬되지 않은 배열의 첫 요소를 정렬된 배열에서 비교해, 적절한 위치에 Insert한다.

*/

void InsertSort(int* arr, int n) {
	int i;
	// i는 sort안 된 배열을 순회
	// j는 sort된 배열을 순회
	for (i = 1; i < n; i++) {
		int temp = arr[i]; // 반드시 변수에 담아서 사용, Insert시 현재의 값이 분실?될 수 있다. 
		int j = i - 1; // sort된 배열의 가장 마지막 요소
		while (j >= 0 && arr[j] > temp) {
			arr[j + 1] = arr[j]; // sort된 배열을 하나씩 오른쪽으로 Shift
			j--;
		}
		arr[j + 1] = temp; // 끼워넣기 
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
	for (int i = 0; i < n - 1; i++) { // min의 값은 제일 마지막에서 두번째까지만 설정하는 걸로!
		int min = i; // 최솟값은 인덱스로 존재 
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min]) { // 최솟값 비교
				min = j; // 최솟값의 인덱스를 새로 설정 
			}
		}
		// min값이 새롭게 정해진 경우
		int temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
		// 버그 : 현재 min값이 제일 커서 min = i값인 경우에도 swap이 실행된다. 
	}
}

void printArray(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
		}
	cout << endl;
}

// mergeSort 복습하기
void merge(int* U, int* V, int* arr, int h, int m) {
	int i, j, k; // 각각 U, V, arr의 index
	i = 0; j = 0; k = 0;
	while (i < h && j < m) { // 배열의 size와 인덱스가 같을 수 없다.
		if (U[i] < V[j]) {
			arr[k] = U[i]; // 작은 것을 우선으로 하여 넣는다. 
			i++; k++;
		}
		else { // V[j]가 같거나 작은 경우
			arr[k] = V[j]; // 작은 것을 우선으로 하여 arr에 넣는다. 
			j++; k++;
		}
	}

	if (i >= h) { // U를 전부 순회하고 V에 요소가 남았을 경우 
		while (j < m) {
			arr[k] = V[j];
			j++; k++;
		}
	}
	else if(j >= m){ // V를 전부 순회하고 U에 요소가 남았을 경우
		while (i < h) {
			arr[k] = U[i];
			i++; k++;
		}
	}

}

void mergeSort(int* arr, int n) {
	const int h = n / 2, m = n - h; 
	if (n > 1) {

		int* U = new int[h]; // 왼쪽 
		int* V = new int[m];  // 오른쪽
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
QuickSort 설명
1.  pivot과 left, right 값을 지정한다. 
2. left는 오른쪽으로, right는 왼쪽으로 순회하면서
3. 순회할 때마다 pivot과 값을 비교, left는 pivot보다 값이 작으면 stop, right는 pivot보다 값이 크면 stop. 
*/

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


// pivot을 제일 앞의 요소로 설정
void quickSort(int* arr, int a, int b) { // a : 배열의 시작, b : 배열의 끄 
	if (a >= b) return; 
	int pivot = arr[a];
	int left = a + 1; 
	int right = b;
	while (left <= right) // left > right가 되면 while문 종료
	{
		while (left <= right && arr[left] <= pivot) { // left의 값이 pivot보다 크면 Stop
			left++; // left의 값이 pivot보다 클 때 (뒤로 넘기기)
		}
		while (left <= right && arr[right] > pivot) { // right 값이 pivot보다 작으면 Stop
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
	// pivot과 right 값을 바꿔준다. 
	// 왜 right 값이냐? : right는 pivot보다 작을 때 Stop한다. 즉 Stop되어 있는 상태에서 right는 항상 pivot보다 작으므로, 
	// 앞쪽에 있는 pivot과 위치를 바꾸어주어야 정렬이 된다. 

	quickSort(arr, a, left -1);
	quickSort(arr, left, b);

	//이게 왜 돼?????? ㅋㅎㅋㅎㅋㅎㅋㅎ
}

 // Quick Sort 내림차순으로 구현 (pivot은 맨 오른쪽 껄로)
void QuickSort_naerim(int* arr, int a, int b) {
	if (a >= b) return; // a와 b를 비교했을 때 같은 숫자이거나 a가 더 크면 return 
	int pivot = arr[b];
	int left = a;
	int right = b - 1;
	while (left <=  right) { // 등호를 붙여줘야 내림차순이 잘 구현된다. 왜? 
		while (left <= right && arr[left] >= pivot) // left가 pivot보다 작을 때 Stop
			left++;
		while (left <= right && arr[right] <= pivot) // right가 pivot보다 클 때 Stop
			right--;
		if (left < right) {
			swap(arr[left], arr[right]);
		}
	}
	swap(arr[left], arr[b]);
	// pivot보다 작은 애를 뒤에 놔둬야 한다. 
	QuickSort_naerim(arr, a, left - 1);
	QuickSort_naerim(arr, left + 1, b);

}

// 시험을 대비해 강의노트 코드 그대로 구현한 함수
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
	// left와 right가 엇갈린 상태일 때
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