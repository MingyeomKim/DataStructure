#include <iostream>
using namespace std;

int main() {
	int i;
	int point[] = { 95, 88, 76 };
	int* ptr;

	ptr = point;

	//point = &i; 
	// point�� '������ ���'
	ptr = &i; 
	// ptr �� '������ ����'


	char* cptr = NULL;
	cout << hex << (int)cptr << endl; // 0
	cptr++;
	cout << hex << (int)cptr; // 1	
	
}