#include "ArrayVector.h"

// ArrayVector의 생성자, capacity와 n을 0으로 초기화하고 A 포인터 변수를 할당한다. 
ArrayVector::ArrayVector(int cap)
    :capacity(cap), n(0){
    A = new Elem[capacity];
}

// 현재 벡터 내 요소의 개수를 출력하는 함수
int ArrayVector::getN() const {
    return n;
}

// ArrayVector의 용량을 세팅하는 함수
void ArrayVector::setCapacity(int cap) {
    capacity = cap;
}

// ArrayVector이 비어있는 지 확인하는 힘수
bool ArrayVector::empty() const {
    return getN() == 0;
}

// A 포인터 변수의 i번째 인덱스에 접근하는 연산자 오버로딩 
Elem& ArrayVector::operator[] (int i) {
    return A[i];
}

// A 포인터 변수의 i번째 인덱스에 접근하는 at 함수
Elem& ArrayVector::at(int i) throw(IndexOutOfBounds) {
    if (i < 0 || i > n)
        throw IndexOutOfBounds("illegal index in function at()");
    // 접근하려는 인덱스가 지정된 범위 내에 없다면 IndexOutOfBounds 예외를 throw한다. 
    return A[i];
}

// N만큼 ArrayVector의 용량을 확장하는 함수
void ArrayVector::reserve(int N) { 
    if (capacity >= N) return; 
    Elem* B = new Elem[N]; // B 포인터를 새롭게 동적할당 (크기 = N) 
    for (int j = 0; j < n; j++)
        B[j] = A[j]; // 배열의 값을 for 루프를 돌며 복사한다. 
    if (A != NULL) delete[] A;  // 기존 A 포인터의 메모리를 해제하고
    A = B;  //  만들어 놓았던 B 포인터로 다시 할당한다. 
    capacity = N;
}

// i번째 인덱스에 e Element 삽입
void ArrayVector::insert(int i, const Elem& e) {
    if (n >= capacity)
        reserve(max(1, 2 * capacity));
    // 현재 위치가 capacity보다 크면 Vector의 크기를 두 배로 늘린다. 
    for (int j = n - 1; j >= i; j--) 
        A[j + 1] = A[j];
    // 스택의 순서 한 칸씩 당기기
    A[i] = e;
    n++; // 현재 위치 1 증가
}

// ArrayVector에서 i번째 인덱스를 삭제하는 erase함수
void ArrayVector::erase(int i) {
    for (int j = i + 1; j < n; j++)
        A[j - 1] = A[j];
    // 삭제한 인덱스를 기준으로 한 칸씩 당긴다. 
    n--; // 현재 요소의 개수를 1씩 감소한다.
}