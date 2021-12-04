#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>S) {
	for (int i = 0; i < S.size(); i++) {
		cout << S[i] << ' ';
	}
	cout << endl;
}

void merge(vector <int>& S, vector<int>& U, vector<int>& V) {
	size_t i = 0;
	size_t j = 0;
	while (i < U.size() && j < V.size()) {
		if (U.at(i) < V.at(j)) {
			S.push_back(U.at(i++));
		}
		else {
			S.push_back(V.at(j++));
		}
	}
	while (i < U.size()) {
		// U ���Ϳ� ���Ұ� ������ ��
		S.push_back(U.at(i++));
	}
	while (j < V.size()) {
		S.push_back(V.at(j++));
	}
}

void mergeSort(vector<int>& S) {

	if (S.size() <= 1)
		return;

	auto iter = S.begin() + S.size() / 2;
	//int center = (start + end) / 2;
	//vector<int> U, V;

	//vector<int> U(S.begin(), S.begin() + center);
	//vector<int> V(S.begin() + center , U.end());

	/*
	for (int i = start; i < center; i++) {
		U.push_back(S[i]);
		V.push_back(S[i + center]);
	}*/
	vector<int> U(S.begin(), iter);
	vector<int> V(iter, S.end());

	mergeSort(U);
	mergeSort(V);

	S.clear();
	merge(S, U, V);

}




int main() {
	vector <int> arr = { 27,10,12,20,25,13,15 };

	mergeSort(arr);

	for (int i = 0; i < 7; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}