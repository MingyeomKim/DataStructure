#include <iostream>
#include <string>
#include "stack.cpp"
using namespace std;

Stack<char> a;
Stack<char> b;

//  ABC+*와 같은 식을 정상적으로 연산하기
int eval_postfix(const string& postfix) {
	for (int i = 0; i < postfix.size(); i++) {
		if (postfix[i] > 48 && postfix[i] < 57) {
			a.push(postfix[i]);
		}
		else {
			int left = int(a.pop() - 48); // 좌항
			int right = int(a.pop() - 48);  // 우항
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
				cout << "기본 연산자 이외의 연산자가 입력되었습니다. " << endl;
			}
			a.push(result + 48);
		}
	}
	return a.top() - 48;
}
// ASCII 코드 표 참고

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
		cout << "잘못된 연산자가 입력되었습니다. " << endl;
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
		return 4; // 수식 내에서 (는 우선순위가 가장 빠르다.
	default:
		cout << "잘못된 연산자가 입력되었습니다. " << endl;
	}
}

// 중위 표기식을 후위 표기식으로 변환
// closing, opening 신경 안 쓴 코드
void infix_to_postfix(const string& infix) {
	for (int i = 0; i < infix.size(); i++) {
		if (infix[i] >= 65 && infix[i] <= 90) { // 문자가 들어왔을 때
			cout << infix[i];
		}
		else { // 연산자가 들어왔을 때
			if (!b.isEmpty()) { // 스택에 연산자가 들어있다면
				while (PIS(b.top()) >= PIE(infix[i])) {
					// 스택에 존재하는 연산자의 우선순위가 더 높은 경우 
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


// 중위 표현식을 후위 표현식으로 변형하는 postfix 함수 
// 연산자를 스택에 담고, 피연산자이면 그대로 출력한다. 
string postfix(string exp) {
	int j = 0; // exp 문자열의 인덱스 
	Stack<char> stack; // 중위 표기식의 연산자를 담을 stack 생성
	string ans = ""; // 변환된 후위 표기식을 담을 string 변수 생성 

	// 문자열을 순회하는 while문, NULL 값을 받았을 때가 중단점이 된다. 
	while (true) {
		char a = exp[j];
		switch (a) {
			// opening 연산자가 입력되었을 경우
		case '(':
			stack.push(a); // 별도의 동작 없이 stack 안에 넣는다. 
			break;
			// +, -, *, / 연산자가 입력되었을 경우
		case '+':
		case '-':
		case '*':
		case '/':
			if (!stack.isEmpty()) { // stack이 비어있지 않을 경우에만 동작하도록 하여, StackEmptyException을 피한다. 
				while (PIS(stack.top()) >= PIE(a)) {
					// 기존에 스택에 존재하는 연산자의 우선순위가 새로 들어온 문자의 우선순위보다 높은 경우
					ans.push_back(stack.top());
					stack.pop();
					// 후위 표기식 문자열에 스택의 가장 상단에 있는 값을 넣고, 스택에서 삭제한다. 
					if (stack.isEmpty()) break;
					// 스택에 값이 비어있는 경우, while문을 종료한다. 
				}
			} // 스택에 연산자를 push한다. 
			stack.push(a);
			break;
			// closing 연산자가 입력되었을 경우
		case ')':
			// 스택의 empty() 여부를 선행으로 판단해, 스택이 비어있을 경우에는 top함수를 호출치 않도록 한다. 
			while (stack.isEmpty() || stack.top() != '(') {
				ans.push_back(stack.top());
				stack.pop();
				// closing 연산자가 들어오면 opening 연산자를 만날 때까지 stack을 순회하며 문자열에 연산자를 넣고, pop한다.
			}
			stack.pop(); // '('를 제거해준다.
			break;
			// NULL 값이 입력되었을 경우
		case '\0':
			while (!stack.isEmpty()) { // stack이 비어있지 않을 경우 (추가로 pop될 연산자가 남아있다)
				ans.push_back(stack.top());
				stack.pop();
				// 문자열에 stack 내부의 연산자를 넣어주고, pop한다. 
			}
			return ans; // NULL 값이 입력되었으므로 ans를 반환하여 함수를 종료한다. 
		default: // a = operand인 경우
			ans.push_back(a);
		}
		j++;
	}
}

int main() {

	infix_to_postfix("A+B*C");

	return 0;
}