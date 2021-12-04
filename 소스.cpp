#include <iostream>
using namespace std;


int main() {
	int a = 10;
	int* ptr = &a;
	int& ref = a;

	a++;
	cout << "ref : " << ref << endl;
	cout << "a : " << a << endl;

	ref++;
	cotu << "ref : " << ref << endl;
}