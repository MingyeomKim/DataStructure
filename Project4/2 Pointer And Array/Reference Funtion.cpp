#include <iostream>
using namespace std;

int& addOne(int& val) {
	val++;
	return val; // reference ������ ��ȯ
}

int& function(void) { // ���⸦ int ��ȯ���� ��ġ�� �Ʒ� int &ref2 = fucntion() �κп��� ������ ����
	int val = 10;
	return val; // �Ϲ� ������ ��ȯ 
}

int main() {
	int n = 3;
	int& ref = addOne(n);
	// ref�� n�� ���� �����̴�. 
	cout << n << " " << ref << endl; // 4 4 
	cout << (ref == n) << endl; // 1

	int& ref2 = function();
	cout << ref2 << endl; // 10
}