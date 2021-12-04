#include <iostream>
using namespace std;

int cnt = 0;

void moveHanoi(char from, char temp, char to, int n) {
	if (n == 1) {
		++cnt;
		cout << cnt << " : " << "���� " << from << " ����" << to << "���� ���� " << "1�� �̵�" << endl;
		return;
	}
	moveHanoi(from, to, temp, n - 1);
	cout << cnt << " : " << "���� " << from << " ����" << to << "���� ���� " << n <<"�� �̵�" << endl;
	moveHanoi(temp, from, to, n - 1);
}

int main() {

	moveHanoi('A', 'B', 'C', 3);

	return 0; 

}