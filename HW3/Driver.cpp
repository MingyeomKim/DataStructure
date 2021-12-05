#include <iostream>
#include "ArrayVector.h"
#include "DLinkedList.h"
#include "Stack.h"
using namespace std;

//함수 선언
void StockSpan(int* arr, int size);
int PIS(char a);
int PIE(char a);
string postfix(string exp);

int main() {
	// ArrayVector에서 IndexOfBounds 예외를 처리하기 위한 try catch문으로 설계
	try {
		/*
		* (1) ArrayVector가 정상 동작함을 보일 것.
		*/ 
		cout << "ArrayVector 실습" << endl;
		// capacity = 0, n = 0, capacity 용량 만큼의 Elem 타입의 A 포인터 동적할당
		ArrayVector first(3);

		cout << first.getN() << endl; // 0
		cout << first.empty() << endl; // 1
		first.insert(0, '0'); // A[0] = 0
		first.insert(1, '1');
		first.insert(2, '2');
		first.insert(3, '3');
		// capacity를 넘는 개수의 정수가 들어가도 reserve 함수에 의해 용량이 확장되어 정상 작동.
		cout << first.getN() << endl; // 4
		cout << first[1] << endl; // 1
		cout << first.at(1) << endl; // 1
		first.erase(1);
		cout << first.getN() << endl; // 3
		cout << first.at(1) << endl; // 2
	} // ArrayVector 객체 내부의 값에 접근할 때 인덱스 오류가 발생하였을 경우 throw를 받아 실행하는 catch문.
	catch (const IndexOutOfBounds& e) {
		cout << "Error occured : " << e.getMessage() << endl;
	}
	
	/*
	* (2) DoublyLinkedList가 정상적으로 동작함을 보일 것.
	*/
	cout << endl << "DLinkedList 실습" << endl;
	DLinkedList second; // header,trailer 노드 생성, header의 next와 trailer의 prev를 각각 trailer와 header로 설정
	second.addBack("1");
	second.addBack("2");
	second.addFront("3");
	second.addFront("4");
	// 4 3 1 2
	cout << second.front() << endl; // 4
	cout << second.back() << endl; // 2
	
	second.removeFront(); // 4 삭제
	second.removeBack(); // 2 삭제

	cout << second.front() << endl; // 3
	cout << second.back() << endl; // 1

	cout << second.empty() << endl; // 0(비어있는 상태가 아니므로)


	try {
		/*
		* (3) ArrayVector를 이용해서 스택을 구현
		*/
		cout << "ArrayVector을 이용한 스택 구현" << endl;
		Stack third(3); // capacity = 3인 Stack 생성
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
		* (3) 가) ArrayVector를 이용하여 Stock Span 알고리즘 구현
		*/
		cout << endl << "ArrayVector을 이용한 Stock Span 알고리즘 구현" << endl;
		int arr1[7] = { 9,5,2,3,1,4,7 };
		int arr2[5] = { 5,2,8,1,4 };
		StockSpan(arr1,7);
		cout << endl;
		StockSpan(arr2,5);
		cout << endl;


		/*
		* (3) 나) ArrayVector를 이용하여 후위표기식 변환 알고리즘 구현
		*/
		cout << endl << "ArrayVector을 이용한 후위표기식 변환 알고리즘 구현 " << endl;
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


// 스택을 이용한 StockSpan 알고리즘
void StockSpan(int* arr, int size) {
	Stack D; // '승자 리스트', 특정 날짜를 기준으로 앞의 날과 주식 값을 비교해 값이 큰 날짜를 넣는다. 
	int h; // 현재 날짜 i를 기준으로 비교할 날짜를 가리키는 h 변수
	int* ans = new int[size]; // 각 날짜 i의 스팬 값을 대입할 ans 배열
	try { 
		for (int i = 0; i < size; i++) {
			while (!D.empty()) {
				if (arr[D.top()] <= arr[i]) // Stack의 마지막 요소가 해당 날짜의 요소보다 작으면
					D.pop(); // D.top() 요소를 pop하여 그 다음의 요소와 해당 날짜의 요소의 값을 비교한다. 
				else
					break;
			}
			if (D.empty()) // 탐색을 시작하는 시점에서는 D 스택이 비어있으므로, 
				h = -1; // h = -1로 초기화해준다. 
			else
				h = D.top(); // D 스택의 마지막 원소를 h값에 대입하여, 해당 날짜의 스팬을 정하는 기준이 되는 날짜를 저장한다. 
			ans[i] = i - h; // 스팬
			D.push(i); // 스택에 현재 인덱스를 push한다. 
		}
	}
	catch (const IndexOutOfBounds& e) {
		cout << "Error occured : " << e.getMessage() << endl;
	} // ArrayVector에서 IndexOutOfBounds 예외가 발생할 경우를 대비한 try catch문
	for (int i = 0; i < size; i++) {
		cout << ans[i] << " ";
	} // ans의 값을 출력한다. 
}

// 각 연산자 간의 스택 내 우선순위를 출력하는 PIS 함수
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

// 각 연산자 간의 수식 내 우선순위를 출력하는 PIE 함수
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

// 중위 표현식을 후위 표현식으로 변형하는 postfix 함수 
// 연산자를 스택에 담고, 피연산자이면 그대로 출력한다. 
string postfix(string exp) {
	int j = 0; // exp 문자열의 인덱스 
	Stack stack; // 중위 표기식의 연산자를 담을 stack 생성
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
			if (!stack.empty()) { // stack이 비어있지 않을 경우에만 동작하도록 하여, StackEmptyException을 피한다. 
				while (PIS(stack.top()) >= PIE(a)) {
					// 기존에 스택에 존재하는 연산자의 우선순위가 새로 들어온 문자의 우선순위보다 높은 경우
					ans.push_back(stack.top());
					stack.pop();
					// 후위 표기식 문자열에 스택의 가장 상단에 있는 값을 넣고, 스택에서 삭제한다. 
					if (stack.empty()) break;
					// 스택에 값이 비어있는 경우, while문을 종료한다. 
				}
			} // 스택에 연산자를 push한다. 
			stack.push(a);
			break;
		// closing 연산자가 입력되었을 경우
		case ')':
			// 스택의 empty() 여부를 선행으로 판단해, 스택이 비어있을 경우에는 top함수를 호출치 않도록 한다. 
			while (stack.empty() || stack.top() != '(') {
				ans.push_back(stack.top());
				stack.pop();
				// closing 연산자가 들어오면 opening 연산자를 만날 때까지 stack을 순회하며 문자열에 연산자를 넣고, pop한다.
			}
			stack.pop(); // '('를 제거해준다.
			break;
		// NULL 값이 입력되었을 경우
		case '\0':
			while (!stack.empty()) { // stack이 비어있지 않을 경우 (추가로 pop될 연산자가 남아있다)
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
