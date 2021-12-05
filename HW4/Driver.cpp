#include <iostream>
#include <ctime>
#include <cstdlib>
#include <map>
#include <list>
using namespace std;
#include "SortAlgorithm.h"

// 함수 선언
void print_sorted_ArrayVector();
void verify_stable_Algorithm();
ArrayVector<int> generate_random_ArrayVector(int = 10);
void compare_Algorithm(int  = 10);

int main() {
	
	// 강의노트에 있는 배열의 예시를 사용하였음.
	cout << "각 정렬 알고리즘을 작성한 후 정렬이 정상 작동함을 보일 것." << endl;
	print_sorted_ArrayVector();
	cout << endl;

	cout << "중복을 허용하여 10개의 element로 이루어진 데이터셋을 임의로 구성하여 각 알고리즘이 stable한 지를 제시할 것." << endl;
	verify_stable_Algorithm();
	cout << endl;

	cout << "데이터셋을 random하게 생성하고 데이터 셋의 크기를 변화시켜가면서 알고리즘의  성능을 비교할 것." << endl;
	compare_Algorithm(100); // 백
	cout << endl;
	compare_Algorithm(1000); // 천
	cout << endl;
	compare_Algorithm(10000); // 만
	cout << endl;
	compare_Algorithm(100000); // 십 만
	cout << endl;
	compare_Algorithm(1000000); // 백 만
	cout << endl;
	compare_Algorithm(10000000); // 천 만
	cout << endl;
	compare_Algorithm(100000000); // 억
	cout << endl;
	compare_Algorithm(1000000000); // 십 억
	cout << endl;
	compare_Algorithm(10000000000); // 백 억

	return 0;
}

void print_sorted_ArrayVector() {
	// Insertion Sort Test 
	ArrayVector <int> insertionSortTest = { 13,7,9,3,11,6,12 };
	InsertionSort(7, insertionSortTest);
	printVector(7, insertionSortTest);

	//Selection Sort Test
	ArrayVector<int> selectionSortTest = { 13,7,9,3,11,6,12 };
	SelectionSort(7, selectionSortTest);
	printVector(7, selectionSortTest);

	// Merge Sort Test
	ArrayVector<int> mergeSortTest = { 7,2,9,4,3,8,6,1 };
	MergeSort(mergeSortTest, 0, 7);
	printVector(8, mergeSortTest);

	// Quick Sort Test
	ArrayVector<int> quickSortTest = { 31,24,17,45,50,85,96,63 };
	QuickSort(quickSortTest, 0, 7);
	printVector(8, quickSortTest);
}


void verify_stable_Algorithm() {
	/// <summary>
	/// struct Pair {
	///		int key;
	///		char value;
	/// }
	/// </summary>
	ArrayVector<Pair> dataSet = {
		{5,'a'},
		{8,'b'},
		{2,'c'},
		{5,'d'},
		{1,'e'},
		{10,'f'},
		{3,'g'},
		{7,'h'},
		{8,'i'},
		{1,'k'}
	};
	ArrayVector<Pair> test;
	// Insertion Sort
	cout << "Insertion Sort" << endl;
	test.copy(dataSet);
	InsertionSort(10, test);
	printVector(10, test);

	//Selection sort
	cout << "Selection Sort" << endl;
	test.copy(dataSet);
	SelectionSort(10, test);
	printVector(10, test);

	// Merge Sort
	cout << "Merge Sort" << endl;
	test.copy(dataSet);
	MergeSort(test, 0, 9);
	printVector(10, test);

	// Quick Sort
	cout << "Quick Sort" << endl;
	test.copy(dataSet);
	QuickSort(test, 0, 9);
	printVector(10, test);
}




// 1. random 데이터 생성하는 코드
ArrayVector<int> generate_random_ArrayVector(int size) {
	ArrayVector<int> random;
	srand(time(NULL)); // 시드 값 생성
	for (int i = 0; i < size; i++) {
		random.insert(i, rand() % 10000000000);
	} // 최대 size만큼 random 배열을 만들 것임.
	return random;
}
// 2. 데이터 셋의 크기를 변화시키면서 알고리즘의 성능 비교
void compare_Algorithm(int size) {

	ArrayVector<int> random = 	generate_random_ArrayVector(size);
	ArrayVector<int> temp;
	cout << "The Time Complexity of a Random ArrayVector of size " << size << " are : " << endl;

	// 너무 오랜 시간이 걸리는 부분은 size의 값을 제한하여 출력하였습니다.
	clock_t start, end;
	// Insertion Sort 
	if (size < 100000) { // 10만 size의 배열에서 Insertion Sort는 약 1276.57초의 시간이 걸림. 
		temp.copy(random);
		start = clock(); // 처음 시간을 start에 저장 
		InsertionSort(size, temp);
		end = clock(); // Sort 후 시간을 end에 저장
		cout << "Insertion Sort's Execution Time : " << (double)(end - start) / CLOCKS_PER_SEC << endl;
		// CLOCKS_PER_SEC 매크로를 이용해서 Sorting 시간을 출력한다. 
	}
	
	// Selection Sort
	if (size < 1000000) { // 100만 size의 배열에서 Selection Sort는 약 139.691초의 시간이 걸린다. 
		temp.copy(random);
		start = clock();
		SelectionSort(size, temp);
		end = clock();
		cout << "Selection Sort's Execution Time : " << (double)(end - start) / CLOCKS_PER_SEC << endl;
	}

	// Merge Sort 
	temp.copy(random);
	start = clock();
	MergeSort(temp, 0, size-1);
	end = clock();
	cout << "Merge Sort's Execution Time : " << (double)(end - start) / CLOCKS_PER_SEC << endl;

	// Quick Sort
	temp.copy(random);
	start = clock();
	QuickSort(temp, 0, size - 1);
	end = clock();
	cout << "Quick Sort's Execution Time : " << (double)(end - start) / CLOCKS_PER_SEC << endl;
}