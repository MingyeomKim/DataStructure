#include "stack.cpp"
#include <iostream>
using namespace std;

int* arr; // �ְ����� ���� ���� �迭
int n; // �迭�� ũ��
int* ans; //������ ���� ���� �迭

/*
Stock Span Algorithm�̶�?
1. Ư�� �Ⱓ������ �ְ� �߿���, Ư������ �����Ѵ�.
2. Ư������ �������� �ռ� ���� �߿��� �ְ��� ���� ���ų� ���� �͵��� ���� ����Ѵ�.
3. ���� ���� �ش� ���� '����'�� �ȴ�.
*/


// Quadratic-Time Algorithm 
void QuadraticStokSpan(int* arr, int size) {

	for (int i = 0; i < size; i++) {
		int count = 1;
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j] < arr[i])
				count++;
			else
				break;
		}
		ans[i] = count;
	}
}

/*
�ǻ� �ڵ�
for(i:�迭�� ó������ ������ ��ȸ){
	int count = 0;
	for(j:0���� i-1���� ��ȸ){
		if(arr[j] < arr[i])
			count ++;
		else
			break;
	}
	ans[i] = count;
	// i��°���� �ְ� ������ count�Դϴ�.
}
*/
// ��ģ ����Ʈ : �ڱ� �ڽŵ� �����Ͽ� ����ؾ� �Ѵ�. ��� count�� �ʱⰪ�� 1



// Linear-Time Algorithm (Stack ���) 
void LinearStockSpan(int* arr, int size) {
	Stack<int> D;
	D.push(0);
	int h;
	ans[0] = 1;
	for (int i = 1; i < size; i++) {
		while (!D.isEmpty()) {
			if (arr[D.top()] < arr[i]) {
				D.pop();
			}
			else {
				break;
			}
		}
		if (D.isEmpty())
			h = -1;
		else
			h = D.top();
		ans[i] = i - h;
		D.push(i);
	}
}

/*
�ǻ� �ڵ�

// Stack�� '���� ����Ʈ' i �ε����� ��ȸ�ϸ鼭, ���� ���� pop�� ���̹Ƿ�, ���� �ְ��� ���� �ε����� ���������� ���ÿ� �������� ���̴�.

// Intial Setting
Stack�� ���� ó�� ���� �ε����� �ְ�, ans �迭�� 0��° �ε����� '1'�� �߰�

for(1���� size-1���� arr�迭�� ��ȸ) {
	int count = 1; // i��° �ְ� ���� ������ �� �ռ� ���� �߿��� �ְ� ���� ���� �͵��� ���� (���� �ְ��� �����ϹǷ� 1�� �ʱ�ȭ)

	while(!Stack.isEmpty()){ // ������ �� ��������� �ڵ����� ����

	if(arr[Stack.top()] < arr[i]){
		count++;
		Stack.pop();
	} else{ // ���� ������ ���� ���ؼ� ���� �ε����� �� ������, �׋����� count�� ���� ans �迭�� �ְ� ���� ������ �Ѿ��.
		ans[i] = count;
		break;
	}
	}
}
*/

// �� �ڵ忡�� ���� : count�� ans �迭�� �ʱ�ȭ�ߴµ�, Stack���� ũ�Ⱑ ���� �� �ƿ� pop�� �ع����� ������ �� �ڿ� �ε������� Ž���� �� pop�Ǿ���� ���� �ְ��鿡 ���ؼ� �߸� count�Ǵ� ������ �߻���
// �ذ� : ans ������ '�ε���'�� �������� ����, h��� ������ ���� ������ ���Ϸ��� �ε����������� ���ʷ� ������ �̵��ϸ鼭, ū �ְ��� ������ �� i - h�� ans �迭�� �־� i �ְ����� ���� ���̵��� ������ ���Ѵ�. 

int main() {
	cin >> n;
	arr = new int[n];
	ans = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	/*
	// ���� �Է�
	7
	9 6 2 4 1 5 8

	// ���� ���
	1 1 1 2 1 4 6
	*/
	LinearStockSpan(arr, n);
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}

	return 0;
}