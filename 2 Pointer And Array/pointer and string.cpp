#include <iostream>
using namespace std;


int main() {
	char str1[4] = "abc";
	char* str2 = "abc";
	// ������Ʈ > �Ӽ� > C/C++ > ��� > �ؼ���� > �ƴϿ� �� ����

	str1[1] = 'D';
	//str2[1] = 'd';
	// ������ ����� ���� ������ �� ����. 

	cout << str1 << " " << str2 << endl;

	return 0;
}