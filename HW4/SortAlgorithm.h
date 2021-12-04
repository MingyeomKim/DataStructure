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
	// j �� i �ε��� �տ� ���� �ִ� insert �Լ� 
	T temp = S[j]; // insert�ϱ� ���� ��� temp ������ i��° ���� �ִ´�. 
	for (int k = j - 1; k >= i; k--) {
		S[k + 1] = S[k];
	} // ��ȸ�� ���鼭 insert�� ���ؼ� �и�
	S[i] = temp;
}

template <typename T>
void InsertionSort(int n, ArrayVector<T>& S) {
	for (int i = 1; i < n; i++) {
		// ���� ù��° ��Ҵ� ���ĵǾ��ִ� ���·� ����
		T elem = S[i];  // ������ �迭�� ���� ù ��� 
			// ���� �ȵǾ��ִ� �迭�� ���� ó����Ҹ� ���� �迭�� ����(����, ������ �迭�� �ϳ��� �迭������)
		for (int j = 0; j < i; j++) {
			if (S[j] < elem) {
				continue;
			}
			else if (S[j] >= elem) {
				// �����ֱ�
				while (true) {
					if (S[j] != elem)
						break;
					j++;
				}
				insert(j, i, S);
				break;
				// j �ڸ��� �տ� elem�� ���� �ִ´� .
			}
		}
	}
}


// Selection Sort
template <typename T>
void SelectionSort(int n, ArrayVector<T>&S) {
	for (int i = 0; i < n; i++) {
		int smallest = i; // ���ĵ��� ���� �κп����� ù ���
		for (int j = i + 1; j < n; j++) {
			if (S[j] < S[smallest]) {
				smallest = j;
			}
		} // ��ȸ�� ����, i��° ���� ���� �迭���� ���� ���� ���� ã�´�. 
		swap(S[smallest], S[i]);
	} // i��° ���� ���� ���� ���� Swap�Ѵ�. 
}

// start�� U �迭�� ������, end�� V �迭�� ������
template <typename T>
void Merge(ArrayVector <T>& S, int start, int center, int end) {
	ArrayVector<T> temp; // ���յ� ��Ҹ� ���� temporary Arrayvector
	int i = start;
	int j = center + 1;
	int k = 0; // temp�� �ε����� ��Ÿ��.
	while (i <= center && j <= end) {
		if (S[i] <= S[j]) {
			temp.insert(k++, S[i++]);
		} // ������ �迭�� �� ũ�� ���� �迭�� ���� temp�� �ְ� k�� i�� 1 ������Ų��. 
		else {
			temp.insert(k++, S[j++]);
		}// ���� �迭�� �� ũ�� ���� �迭�� ���� temp�� �ְ� k�� j�� 1 ������Ų��. 
	}
	while (i <= center) {
		temp.insert(k++, S[i++]);
	} // i���� center���� ��ġ�� ���Ͽ����� ���� �迭�� ���� �� ��� ��,
	// center���� ���� �� ���� insert�Ѵ�.
	while (j <= end) {
		temp.insert(k++, S[j++]);
	} // j���� end���� ��ġ�� ���Ͽ����� ������ �迭�� ���� �� ��� ��,
	// center���� ���� �� ���� insert�Ѵ�.
	// copy
	for (int i = start; i <= end; i++) {
		S[i] = temp[i - start];
	}

}

// MergeSort
template <typename T>
void MergeSort(ArrayVector<T>& S, int start, int end) {
	if (start < end) { // �ߴ����� start�� end�� �������� ���̴�. 
		int center = (start + end) / 2; // �迭�� �߰� �ε����� ����
		MergeSort(S, start, center); // ���� �迭 ���ȣ��
		MergeSort(S, center + 1, end); // ������ �迭 ���ȣ�� 
		Merge(S, start, center, end);  // ��ȯ�� �迭�� �Լ� Call�� �����Ⱦ�� ����
	}
} 



// Quick Sort
template <typename T>
void QuickSort(ArrayVector<T>& arr, int start, int end) {
	if (start >= end) return; // �ߴ����� start�� end�� �������� ���̴�.
	T pivot = arr[end]; //pivot���� �迭�� ���� ������ ����̴�. 
	int left = start; // ���ʿ������� ��ȸ�� �ε���
	int right = end - 1; // �����ʿ������� ��ȸ�� �ε���
	while (left <= right) { // left�� right�� ������ ��ȸ�� �����Ѵ�. 
		while (left <= right && arr[left] <= pivot)
			left++; // left���� pivot���� ������ �Ѿ��. 
		while (left <= right && arr[right] >= pivot)
			right--; // right���� pivot���� ũ�� �Ѿ��. 
		if (left < right) // while���� Ż���Ͽ���, left< right�� �������� ��Ȳ�̶��
			swap(arr[left], arr[right]);
		// ���� ���� ������ ���� swap
		else
			break;
	}
	// left�� pivot�� ���� swap�ϸ� pivot�� �ڱ� �ڸ��� ã�� �ȴ�. 
	swap(arr[left], arr[end]);
	// ����, ������ �迭�� ���ؼ� ���ȣ���� �Ͽ� start=end�� �ɶ����� �ݺ��Ѵ�. 
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
