#pragma once
#include <iostream>
using namespace std;

// Pair 구조체 정의
struct Pair {
    int key;
    char value;
};

// ArrayVector의 예외를 처리하는 RuntimeException 예외처리 클래스
class RuntimeException {
private:
	string errorMsg;
public:
	RuntimeException(const string& err) {
		errorMsg = err;
	}
	string getMessage() const {
		return errorMsg;
	}
};

// StackEmptyException은 RuntimeException을 상속받아 에러 메세지를 출력한다. 
class StackEmptyException : public RuntimeException {
public:
	StackEmptyException(const string& err)
		:RuntimeException(err) {}
};

// IndexOutOfBounds은 RuntimeException을 상속받아 에러 메세지를 출력한다. 
class IndexOutOfBounds : public RuntimeException {
public:
	IndexOutOfBounds(const string& err)
		:RuntimeException(err) {}
};

template <typename T>
class ArrayVector {
public:
    // ArrayVector의 생성자, capacity와 n을 0으로 초기화하고 A 포인터 변수를 할당한다. 
    ArrayVector(int cap = 10) 
        :capacity(cap), n(0)
    {
        A = new T[capacity];
    }
    void copy(ArrayVector<T>& S) {
        delete A;
        A = new T[S.size()];
        n = S.n;
        capacity = S.capacity;
        for (int i = 0; i < S.size(); i++) {
            A[i] = S[i];
        }
    }

    // std에 정의된 initializer_list에서 ArrayVector의 A 멤버 변수에 대입하도록 복사 생성자를 정의해준다. 
    ArrayVector(const initializer_list<T>&list)
        : ArrayVector(list.size())
    {
        int count = 0;
        for (auto& element : list) 
            A[count++] = element;
        n = list.size();
    } // count의 값을 증가시키면서, 매개변수에 들어온 initializer_list의 요소를 하나하나 복사한다. 
    int size() const {
        // 현재 벡터 내 요소의 개수를 출력하는 함수
        return n;
    }
    // ArrayVector의 용량을 세팅하는 함수
    void setCapacity(int cap= 0) {
        capacity = cap;
    }
    bool empty() const {
        // ArrayVector이 비어있는 지 확인하는 힘수
        return size() == 0;
    }
    // A 포인터 변수의 i번째 인덱스에 접근하는 연산자 오버로딩 
    T& operator[] (int i) {
        return A[i];
    }
    // A 포인터 변수의 i번째 인덱스에 접근하는 at 함수
    T& at(int i) throw(IndexOutOfBounds) {
        if (i < 0 || i > n) {
            cout << "IndexOutOfBosunds Error 발생, 이때의 n의 값은 : " << n << endl;
            throw IndexOutOfBounds("illegal index in function at()");
          }
        // 접근하려는 인덱스가 지정된 범위 내에 없다면 IndexOutOfBounds 예외를 throw한다. 
        return A[i];
    }
    // ArrayVector에서 i번째 인덱스를 삭제하는 erase함수
    void erase(int i) {
        for (int j = i + 1; j < n; j++)
            A[j - 1] = A[j];
        // 삭제한 인덱스를 기준으로 한 칸씩 당긴다. 
        // 삭제한 인덱스를 기준으로 한 칸씩 당긴다. 
        n--; // 현재 요소의 개수를 1씩 감소한다.
    }
    // i번째 인덱스에 e Element 삽입
    void insert(int i, const T& e) {
        if (n >= capacity)
            reserve(max(1, 2 * capacity));
        // 현재 위치가 capacity보다 크면 Vector의 크기를 두 배로 늘린다. 
        for (int j = n - 1; j >= i; j--)
            A[j + 1] = A[j];
        // 스택의 순서 한 칸씩 당기기
        A[i] = e;
        n++; // 현재 위치 1 증가
    }
    // N만큼 ArrayVector의 용량을 확장하는 함수
    void reserve(int N) {
        if (capacity >= N) return;
        T* B = new T[N]; // B 포인터를 새롭게 동적할당 (크기 = N) 
        for (int j = 0; j < n; j++)
            B[j] = A[j]; // 배열의 값을 for 루프를 돌며 복사한다. 
        if (A != NULL) delete[] A;  // 기존 A 포인터의 메모리를 해제하고
        A = B;  //  만들어 놓았던 B 포인터로 다시 할당한다. 
        capacity = N;
    }

private:
	int capacity; // 용량
	int n;  // 요소의 개수 
	T* A; //  저장소
};

// Pair 구조체에 대한 비교 연산을 위한 연산자 오버로딩
bool operator < (const Pair& a, const Pair& b) {
    if (a.key < b.key)
        return true;
    return false;
}
bool operator > (const Pair& a, const Pair& b) {
    if (a.key > b.key)
        return true;
    return false;
}
bool operator <= (const Pair& a, const Pair& b) {
    if (a.key <= b.key)
        return true;
    return false;
}
bool operator >= (const Pair& a, const Pair& b) {
    if (a.key >= b.key)
        return true;
    return false;
}
bool operator == (const Pair& a, const Pair& b) {
    if (a.key == b.key)
        return true;
    return false;
}
bool operator != (const Pair& a, const Pair& b) {
    return a == b ? false : true;
}
// Pair 구조체 객체의 값 출력을 위한 출력 연산자 오버로딩
ostream& operator << (ostream& output, const Pair& b) {
    output << b.key << " " << b.value << endl;
    return output;
}

