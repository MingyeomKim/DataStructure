#include <iostream>
using namespace std;


int isInclude(string* a, int a_size, string b) { // ���� a ���� string b�� �����ϴ� ���Ұ� �ִ��� üũ�ϴ� �Լ� 
	for (int i = 0; i < a_size; i++) {
		if (!a[i].compare(b))
			return 1;
	}
	return 0;
}


int main() {
	int n; cin >> n; // ���� S�� ���ԵǾ��ִ� ���ڿ� ����
	int m; cin >> m; // �־����� ���ڿ�

	string* set = new string[n];
	string a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		set[i] = a;
	} // ����
	int count = 0;
	for (int i = 0; i < m; i++) {
		cin >> a;
		if (isInclude(set, n, a)) {
			count++;
		}
	}
	cout << count << endl;
	
	return 0;
}