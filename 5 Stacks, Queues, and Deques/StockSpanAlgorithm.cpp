#include "stack.cpp"
#include <iostream>
using namespace std;

int* arr; // 주가들의 값을 담을 배열
int n; // 배열의 크기
int* ans; //스팬의 값을 담을 배열

/*
Stock Span Algorithm이란?
1. 특정 기간동안의 주가 중에서, 특정일을 선택한다.
2. 특정일을 기준으로 앞선 날들 중에서 주가의 값이 같거나 작은 것들의 수를 계산한다.
3. 계산된 값은 해당 일의 '스팬'이 된다.
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
의사 코드
for(i:배열의 처음부터 끝까지 순회){
	int count = 0;
	for(j:0부터 i-1까지 순회){
		if(arr[j] < arr[i])
			count ++;
		else
			break;
	}
	ans[i] = count;
	// i번째일의 주가 스팬은 count입니다.
}
*/
// 놓친 포인트 : 자기 자신도 포함하여 계산해야 한다. 고로 count의 초기값은 1



// Linear-Time Algorithm (Stack 사용) 
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
의사 코드

// Stack은 '승자 리스트' i 인덱스를 순회하면서, 작은 것을 pop할 것이므로, 가장 주가가 높은 인덱스가 최종적으로 스택에 남아있을 것이다.

// Intial Setting
Stack에 제일 처음 날의 인덱스를 넣고, ans 배열의 0번째 인덱스에 '1'을 추가

for(1부터 size-1까지 arr배열을 순회) {
	int count = 1; // i번째 주가 값과 비교했을 때 앞선 날들 중에서 주가 값이 작은 것들의 개수 (현재 주가도 포함하므로 1로 초기화)

	while(!Stack.isEmpty()){ // 스택이 텅 비어있으면 자동으로 종료

	if(arr[Stack.top()] < arr[i]){
		count++;
		Stack.pop();
	} else{ // 스택 내부의 값과 비교해서 현재 인덱스가 더 작으면, 그떄까지 count된 값을 ans 배열에 넣고 다음 턴으로 넘어간다.
		ans[i] = count;
		break;
	}
	}
}
*/

// 이 코드에서 버그 : count로 ans 배열을 초기화했는데, Stack에서 크기가 작을 시 아예 pop을 해버리기 때문에 그 뒤에 인덱스에서 탐색할 때 pop되어버린 작은 주가들에 대해서 잘못 count되는 문제가 발생함
// 해결 : ans 대입을 '인덱스'를 기준으로 실행, h라는 변수가 현재 스팬을 구하려는 인덱스에서부터 차례로 앞으로 이동하면서, 큰 주가가 나왔을 때 i - h를 ans 배열에 넣어 i 주가보다 낮은 아이들의 개수를 구한다. 

int main() {
	cin >> n;
	arr = new int[n];
	ans = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	/*
	// 예제 입력
	7
	9 6 2 4 1 5 8

	// 예제 출력
	1 1 1 2 1 4 6
	*/
	LinearStockSpan(arr, n);
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}

	return 0;
}