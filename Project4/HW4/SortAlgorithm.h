#pragma once
#include "ArrayVector.h"
#include <iostream>
using namespace std;

void swap(int& a, int& b);
template <typename T>
void printVector(int n, ArrayVector<T> S);

// Insertion Sort
template <typename T>
void insert(int i, int j, ArrayVector<T>& S) { 
	// j 를 i 인덱스 앞에 끼워 넣는 insert 함수 
	T temp = S[j]; // insert하기 위해 잠시 temp 변수에 i번째 값을 넣는다. 
	for (int k = j - 1; k >= i; k--) {
		S[k + 1] = S[k];
	} // 순회를 돌면서 insert로 인해서 밀린
	S[i] = temp;
}

template <typename T>
void InsertionSort(int n, ArrayVector<T>& S) {
	for (int i = 1; i < n; i++) {
		// 제일 첫번째 요소는 정렬되어있는 상태로 간주
		T elem = S[i];  // 비정렬 배열의 제일 첫 요소 
			// 정렬 안되어있는 배열의 제일 처음요소를 정렬 배열에 삽입(정렬, 비정렬 배열은 하나의 배열에있음)
		for (int j = 0; j < i; j++) {
			if (S[j] < elem) {
				continue;
			}
			else if (S[j] >= elem) {
				// 끼워넣기
				while (true) {
					if (S[j] != elem)
						break;
					j++;
				}
				insert(j, i, S);
				break;
				// j 자리의 앞에 elem을 끼워 넣는다 .
			}
		}
	}
}


// Selection Sort
template <typename T>
void SelectionSort(int n, ArrayVector<T>&S) {
	for (int i = 0; i < n; i++) {
		int smallest = i; // 정렬되지 않은 부분에서의 첫 요소
		for (int j = i + 1; j < n; j++) {
			if (S[j] < S[smallest]) {
				smallest = j;
			}
		} // 순회를 돌며, i번째 값의 다음 배열에서 가장 작은 값을 찾는다. 
		swap(S[smallest], S[i]);
	} // i번째 값과 가장 작은 값을 Swap한다. 
}

// start는 U 배열의 사이즈, end는 V 배열의 사이즈
template <typename T>
void Merge(ArrayVector <T>& S, int start, int center, int end) {
	ArrayVector<T> temp; // 병합된 요소를 담을 temporary Arrayvector
	int i = start;
	int j = center + 1;
	int k = 0; // temp의 인덱스를 나타냄.
	while (i <= center && j <= end) {
		if (S[i] <= S[j]) {
			temp.insert(k++, S[i++]);
		} // 오른쪽 배열이 더 크면 왼쪽 배열의 값을 temp에 넣고 k와 i를 1 증가시킨다. 
		else {
			temp.insert(k++, S[j++]);
		}// 왼쪽 배열이 더 크면 왼쪽 배열의 값을 temp에 넣고 k와 j를 1 증가시킨다. 
	}
	while (i <= center) {
		temp.insert(k++, S[i++]);
	} // i값이 center까지 미치지 못하였으면 왼쪽 배열의 값이 덜 담긴 것,
	// center까지 닿을 때 까지 insert한다.
	while (j <= end) {
		temp.insert(k++, S[j++]);
	} // j값이 end까지 미치지 못하였으면 오른쪽 배열의 값이 덜 담긴 것,
	// center까지 닿을 때 까지 insert한다.
	// copy
	for (int i = start; i <= end; i++) {
		S[i] = temp[i - start];
	}

}

// MergeSort
template <typename T>
void MergeSort(ArrayVector<T>& S, int start, int end) {
	if (start < end) { // 중단점은 start와 end가 같아졌을 때이다. 
		int center = (start + end) / 2; // 배열의 중간 인덱스를 정의
		MergeSort(S, start, center); // 왼쪽 배열 재귀호출
		MergeSort(S, center + 1, end); // 오른쪽 배열 재귀호출 
		Merge(S, start, center, end);  // 반환된 배열을 함수 Call을 내려훑어가며 병합
	}
} 



// Quick Sort
template <typename T>
void QuickSort(ArrayVector<T>& arr, int start, int end) {
	if (start >= end) return; // 중단점은 start와 end가 같아졌을 때이다.
	T pivot = arr[end]; //pivot값은 배열의 가장 마지막 요소이다. 
	int left = start; // 왼쪽에서부터 순회할 인덱스
	int right = end - 1; // 오른쪽에서부터 순회할 인덱스
	while (left <= right) { // left와 right가 만나면 순회를 중지한다. 
		while (left <= right && arr[left] <= pivot)
			left++; // left값이 pivot보다 작으면 넘어간다. 
		while (left <= right && arr[right] >= pivot)
			right--; // right값이 pivot보다 크면 넘어간다. 
		if (left < right) // while문을 탈출하였고, left< right인 정상적인 상황이라면
			swap(arr[left], arr[right]);
		// 왼쪽 값과 오른쪽 값을 swap
		else
			break;
	}
	// left와 pivot의 값을 swap하면 pivot은 자기 자리를 찾게 된다. 
	swap(arr[left], arr[end]);
	// 왼쪽, 오른쪽 배열에 대해서 재귀호출을 하여 start=end가 될때까지 반복한다. 
	QuickSort(arr, start, left - 1);
	QuickSort(arr, left + 1, end);
}


void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

template <typename T>
void printVector(int n,  ArrayVector<T> S) {
	for (int i = 0; i < n; i++) {
		cout << S.at(i) << " ";
	}
	cout << endl;
}
