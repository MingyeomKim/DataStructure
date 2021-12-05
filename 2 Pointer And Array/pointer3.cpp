#include <iostream>
using namespace std;

// pointer swap
int main() {
	int a = 1;
	int b = 2;
	int* ptra = &a;
	int* ptrb = &b;
	int* temp;

	cout << "before : *ptra = " << *ptra << ", *ptrb = " << *ptrb << endl;

	temp = ptra;
	ptra = ptrb;
	ptrb = temp;
	
	cout << "after : *ptra = " << *ptra << ", *ptrb = " << *ptrb << endl;

	return 0;
}