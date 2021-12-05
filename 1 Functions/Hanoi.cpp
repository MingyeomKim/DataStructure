#include <iostream>
using namespace std;

int cnt = 0;

void moveHanoi(char from, char temp, char to, int n) {
	if (n == 1) {
		++cnt;
		cout << cnt << " : " << "말뚝 " << from << " 에서" << to << "으로 원반 " << "1을 이동" << endl;
		return;
	}
	moveHanoi(from, to, temp, n - 1);
	cout << cnt << " : " << "말뚝 " << from << " 에서" << to << "으로 원반 " << n <<"을 이동" << endl;
	moveHanoi(temp, from, to, n - 1);
}

int main() {

	moveHanoi('A', 'B', 'C', 3);

	return 0; 

}