#include <iostream>
using namespace std;

int main() {
	char c = 'a';
	short s = 1;
	int i = 10;
	float f = 3.14f;
	double d = 3.141592;

	char* ptrc = &c;
	short* ptrs = &s;
	int* ptri = &i;
	float* ptrf = &f;
	double* ptrd = &d; 

	*ptrc = *ptrc + 1;  // b
	(*ptrs)++;  // 2
	(*ptri)++; // 11
	*ptrf = 5.0; // 5.0
	*ptrd = f * f; // 25

	cout << "c = " << c << ", s = " << s << ", i = " << i << ", f = " << f << ", d = " << d << endl;
	cout << "*ptrc = " << *ptrc << ", *ptrs = " << *ptrs << ", *ptri = " << *ptri << ", *ptrf = " << *ptrf << ", *ptrd = " << *ptrd << endl;

	return 0;
}