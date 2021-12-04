#include <iostream>
#include "ArrayVector.h"
#include "DLinkedList.h"
#include "Stack.h"
using namespace std;

//�Լ� ����
void StockSpan(int* arr, int size);
int PIS(char a);
int PIE(char a);
string postfix(string exp);

int main() {
	// ArrayVector���� IndexOfBounds ���ܸ� ó���ϱ� ���� try catch������ ����
	try {
		/*
		* (1) ArrayVector�� ���� �������� ���� ��.
		*/ 
		cout << "ArrayVector �ǽ�" << endl;
		// capacity = 0, n = 0, capacity �뷮 ��ŭ�� Elem Ÿ���� A ������ �����Ҵ�
		ArrayVector first(3);

		cout << first.getN() << endl; // 0
		cout << first.empty() << endl; // 1
		first.insert(0, '0'); // A[0] = 0
		first.insert(1, '1');
		first.insert(2, '2');
		first.insert(3, '3');
		// capacity�� �Ѵ� ������ ������ ���� reserve �Լ��� ���� �뷮�� Ȯ��Ǿ� ���� �۵�.
		cout << first.getN() << endl; // 4
		cout << first[1] << endl; // 1
		cout << first.at(1) << endl; // 1
		first.erase(1);
		cout << first.getN() << endl; // 3
		cout << first.at(1) << endl; // 2
	} // ArrayVector ��ü ������ ���� ������ �� �ε��� ������ �߻��Ͽ��� ��� throw�� �޾� �����ϴ� catch��.
	catch (const IndexOutOfBounds& e) {
		cout << "Error occured : " << e.getMessage() << endl;
	}
	
	/*
	* (2) DoublyLinkedList�� ���������� �������� ���� ��.
	*/
	cout << endl << "DLinkedList �ǽ�" << endl;
	DLinkedList second; // header,trailer ��� ����, header�� next�� trailer�� prev�� ���� trailer�� header�� ����
	second.addBack("1");
	second.addBack("2");
	second.addFront("3");
	second.addFront("4");
	// 4 3 1 2
	cout << second.front() << endl; // 4
	cout << second.back() << endl; // 2
	
	second.removeFront(); // 4 ����
	second.removeBack(); // 2 ����

	cout << second.front() << endl; // 3
	cout << second.back() << endl; // 1

	cout << second.empty() << endl; // 0(����ִ� ���°� �ƴϹǷ�)


	try {
		/*
		* (3) ArrayVector�� �̿��ؼ� ������ ����
		*/
		cout << "ArrayVector�� �̿��� ���� ����" << endl;
		Stack third(3); // capacity = 3�� Stack ����
		third.push(1);
		third.push(2);
		third.push(3);
		// 3 2 1 
		cout << third.size() << endl; // 3
		cout << third.top() << endl; // NULL
		third.pop();
		third.pop();
		third.pop();
		cout << third.empty() << endl; // 1
		
		/*
		* (3) ��) ArrayVector�� �̿��Ͽ� Stock Span �˰��� ����
		*/
		cout << endl << "ArrayVector�� �̿��� Stock Span �˰��� ����" << endl;
		int arr1[7] = { 9,5,2,3,1,4,7 };
		int arr2[5] = { 5,2,8,1,4 };
		StockSpan(arr1,7);
		cout << endl;
		StockSpan(arr2,5);
		cout << endl;


		/*
		* (3) ��) ArrayVector�� �̿��Ͽ� ����ǥ��� ��ȯ �˰��� ����
		*/
		cout << endl << "ArrayVector�� �̿��� ����ǥ��� ��ȯ �˰��� ���� " << endl;
		string infix1 = "A*(B+C)/D";
		string infix2 = "A+B*C";
		cout << postfix(infix1) << endl;
		cout << postfix(infix2) << endl;
	}
	catch (const StackEmptyException& e) {
		cout << "Error occured : " << e.getMessage() << endl; 
	} 
	catch (const IndexOutOfBounds& e) {
		cout << "Error occured : " << e.getMessage() << endl;
	}
	
	return 0;
}


// ������ �̿��� StockSpan �˰���
void StockSpan(int* arr, int size) {
	Stack D; // '���� ����Ʈ', Ư�� ��¥�� �������� ���� ���� �ֽ� ���� ���� ���� ū ��¥�� �ִ´�. 
	int h; // ���� ��¥ i�� �������� ���� ��¥�� ����Ű�� h ����
	int* ans = new int[size]; // �� ��¥ i�� ���� ���� ������ ans �迭
	try { 
		for (int i = 0; i < size; i++) {
			while (!D.empty()) {
				if (arr[D.top()] <= arr[i]) // Stack�� ������ ��Ұ� �ش� ��¥�� ��Һ��� ������
					D.pop(); // D.top() ��Ҹ� pop�Ͽ� �� ������ ��ҿ� �ش� ��¥�� ����� ���� ���Ѵ�. 
				else
					break;
			}
			if (D.empty()) // Ž���� �����ϴ� ���������� D ������ ��������Ƿ�, 
				h = -1; // h = -1�� �ʱ�ȭ���ش�. 
			else
				h = D.top(); // D ������ ������ ���Ҹ� h���� �����Ͽ�, �ش� ��¥�� ������ ���ϴ� ������ �Ǵ� ��¥�� �����Ѵ�. 
			ans[i] = i - h; // ����
			D.push(i); // ���ÿ� ���� �ε����� push�Ѵ�. 
		}
	}
	catch (const IndexOutOfBounds& e) {
		cout << "Error occured : " << e.getMessage() << endl;
	} // ArrayVector���� IndexOutOfBounds ���ܰ� �߻��� ��츦 ����� try catch��
	for (int i = 0; i < size; i++) {
		cout << ans[i] << " ";
	} // ans�� ���� ����Ѵ�. 
}

// �� ������ ���� ���� �� �켱������ ����ϴ� PIS �Լ�
int PIS(char a) {
	switch (a) {
	case '^':
		return 3;
		break;
	case '*':
	case '/':
		return 2;
		break;
	case '+':
	case '-':
		return 1;
		break;
	case '(':
		return 0;
		break;
	default:
		return -1;
	}
}

// �� ������ ���� ���� �� �켱������ ����ϴ� PIE �Լ�
int PIE(char a) {
	switch (a) {
	case '^':
		return 3;
		break;
	case '*':
	case '/':
		return 2;
		break;
	case '+':
	case '-':
		return 1;
		break;
	case '(':
		return 4;
		break;
	default:
		return -1;
	}

}

// ���� ǥ������ ���� ǥ�������� �����ϴ� postfix �Լ� 
// �����ڸ� ���ÿ� ���, �ǿ������̸� �״�� ����Ѵ�. 
string postfix(string exp) {
	int j = 0; // exp ���ڿ��� �ε��� 
	Stack stack; // ���� ǥ����� �����ڸ� ���� stack ����
	string ans = ""; // ��ȯ�� ���� ǥ����� ���� string ���� ���� 

	// ���ڿ��� ��ȸ�ϴ� while��, NULL ���� �޾��� ���� �ߴ����� �ȴ�. 
	while (true) {
		char a = exp[j];
		switch (a) {
		// opening �����ڰ� �ԷµǾ��� ���
		case '(':
			stack.push(a); // ������ ���� ���� stack �ȿ� �ִ´�. 
			break;
		// +, -, *, / �����ڰ� �ԷµǾ��� ���
		case '+':
		case '-':
		case '*':
		case '/':
			if (!stack.empty()) { // stack�� ������� ���� ��쿡�� �����ϵ��� �Ͽ�, StackEmptyException�� ���Ѵ�. 
				while (PIS(stack.top()) >= PIE(a)) {
					// ������ ���ÿ� �����ϴ� �������� �켱������ ���� ���� ������ �켱�������� ���� ���
					ans.push_back(stack.top());
					stack.pop();
					// ���� ǥ��� ���ڿ��� ������ ���� ��ܿ� �ִ� ���� �ְ�, ���ÿ��� �����Ѵ�. 
					if (stack.empty()) break;
					// ���ÿ� ���� ����ִ� ���, while���� �����Ѵ�. 
				}
			} // ���ÿ� �����ڸ� push�Ѵ�. 
			stack.push(a);
			break;
		// closing �����ڰ� �ԷµǾ��� ���
		case ')':
			// ������ empty() ���θ� �������� �Ǵ���, ������ ������� ��쿡�� top�Լ��� ȣ��ġ �ʵ��� �Ѵ�. 
			while (stack.empty() || stack.top() != '(') {
				ans.push_back(stack.top());
				stack.pop();
				// closing �����ڰ� ������ opening �����ڸ� ���� ������ stack�� ��ȸ�ϸ� ���ڿ��� �����ڸ� �ְ�, pop�Ѵ�.
			}
			stack.pop(); // '('�� �������ش�.
			break;
		// NULL ���� �ԷµǾ��� ���
		case '\0':
			while (!stack.empty()) { // stack�� ������� ���� ��� (�߰��� pop�� �����ڰ� �����ִ�)
				ans.push_back(stack.top());
				stack.pop();
				// ���ڿ��� stack ������ �����ڸ� �־��ְ�, pop�Ѵ�. 
			}
			return ans; // NULL ���� �ԷµǾ����Ƿ� ans�� ��ȯ�Ͽ� �Լ��� �����Ѵ�. 
		default: // a = operand�� ���
			ans.push_back(a);
		}
		j++;
	}
}
