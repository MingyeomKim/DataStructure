#include <iostream>
#include <string>
#include "stack.cpp"
using namespace std;

Stack<char> a;
Stack<char> b;

//  ABC+*�� ���� ���� ���������� �����ϱ�
int eval_postfix(const string& postfix) {
	for (int i = 0; i < postfix.size(); i++) {
		if (postfix[i] > 48 && postfix[i] < 57) {
			a.push(postfix[i]);
		}
		else {
			int left = int(a.pop() - 48); // ����
			int right = int(a.pop() - 48);  // ����
			int result;
			switch (postfix[i]) {
			case '+':
				result = left + right;
				break;
			case '-':
				result = left - right;
				break;
			case '/':
				result = left / right;
				break;
			case '*':
				result = left * right;
				break;
			default:
				cout << "�⺻ ������ �̿��� �����ڰ� �ԷµǾ����ϴ�. " << endl;
			}
			a.push(result + 48);
		}
	}
	return a.top() - 48;
}
// ASCII �ڵ� ǥ ����

int PIS(char oper) {
	switch (oper) {
	case '^':
		return 3;
	case '*':
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	case '(':
		return 0;
	default:
		cout << "�߸��� �����ڰ� �ԷµǾ����ϴ�. " << endl;
	}
}

int PIE(char oper) {
	switch (oper) {
	case '^':
		return 3;
	case '*':
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	case '(':
		return 4; // ���� ������ (�� �켱������ ���� ������.
	default:
		cout << "�߸��� �����ڰ� �ԷµǾ����ϴ�. " << endl;
	}
}

// ���� ǥ����� ���� ǥ������� ��ȯ
// closing, opening �Ű� �� �� �ڵ�
void infix_to_postfix(const string& infix) {
	for (int i = 0; i < infix.size(); i++) {
		if (infix[i] >= 65 && infix[i] <= 90) { // ���ڰ� ������ ��
			cout << infix[i];
		}
		else { // �����ڰ� ������ ��
			if (!b.isEmpty()) { // ���ÿ� �����ڰ� ����ִٸ�
				while (PIS(b.top()) >= PIE(infix[i])) {
					// ���ÿ� �����ϴ� �������� �켱������ �� ���� ��� 
					cout << b.pop();
					b.push(infix[i]);
					if (b.isEmpty()) break;
				}
			}
			b.push(infix[i]);
		}
	}
	while (!b.isEmpty()) {
		cout << b.top();
		b.pop();
	}
}


// ���� ǥ������ ���� ǥ�������� �����ϴ� postfix �Լ� 
// �����ڸ� ���ÿ� ���, �ǿ������̸� �״�� ����Ѵ�. 
string postfix(string exp) {
	int j = 0; // exp ���ڿ��� �ε��� 
	Stack<char> stack; // ���� ǥ����� �����ڸ� ���� stack ����
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
			if (!stack.isEmpty()) { // stack�� ������� ���� ��쿡�� �����ϵ��� �Ͽ�, StackEmptyException�� ���Ѵ�. 
				while (PIS(stack.top()) >= PIE(a)) {
					// ������ ���ÿ� �����ϴ� �������� �켱������ ���� ���� ������ �켱�������� ���� ���
					ans.push_back(stack.top());
					stack.pop();
					// ���� ǥ��� ���ڿ��� ������ ���� ��ܿ� �ִ� ���� �ְ�, ���ÿ��� �����Ѵ�. 
					if (stack.isEmpty()) break;
					// ���ÿ� ���� ����ִ� ���, while���� �����Ѵ�. 
				}
			} // ���ÿ� �����ڸ� push�Ѵ�. 
			stack.push(a);
			break;
			// closing �����ڰ� �ԷµǾ��� ���
		case ')':
			// ������ empty() ���θ� �������� �Ǵ���, ������ ������� ��쿡�� top�Լ��� ȣ��ġ �ʵ��� �Ѵ�. 
			while (stack.isEmpty() || stack.top() != '(') {
				ans.push_back(stack.top());
				stack.pop();
				// closing �����ڰ� ������ opening �����ڸ� ���� ������ stack�� ��ȸ�ϸ� ���ڿ��� �����ڸ� �ְ�, pop�Ѵ�.
			}
			stack.pop(); // '('�� �������ش�.
			break;
			// NULL ���� �ԷµǾ��� ���
		case '\0':
			while (!stack.isEmpty()) { // stack�� ������� ���� ��� (�߰��� pop�� �����ڰ� �����ִ�)
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

int main() {

	infix_to_postfix("A+B*C");

	return 0;
}