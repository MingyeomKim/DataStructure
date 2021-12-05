#include "ArrayVector.h"

// ArrayVector�� ������, capacity�� n�� 0���� �ʱ�ȭ�ϰ� A ������ ������ �Ҵ��Ѵ�. 
ArrayVector::ArrayVector(int cap)
    :capacity(cap), n(0){
    A = new Elem[capacity];
}

// ���� ���� �� ����� ������ ����ϴ� �Լ�
int ArrayVector::getN() const {
    return n;
}

// ArrayVector�� �뷮�� �����ϴ� �Լ�
void ArrayVector::setCapacity(int cap) {
    capacity = cap;
}

// ArrayVector�� ����ִ� �� Ȯ���ϴ� ����
bool ArrayVector::empty() const {
    return getN() == 0;
}

// A ������ ������ i��° �ε����� �����ϴ� ������ �����ε� 
Elem& ArrayVector::operator[] (int i) {
    return A[i];
}

// A ������ ������ i��° �ε����� �����ϴ� at �Լ�
Elem& ArrayVector::at(int i) throw(IndexOutOfBounds) {
    if (i < 0 || i > n)
        throw IndexOutOfBounds("illegal index in function at()");
    // �����Ϸ��� �ε����� ������ ���� ���� ���ٸ� IndexOutOfBounds ���ܸ� throw�Ѵ�. 
    return A[i];
}

// N��ŭ ArrayVector�� �뷮�� Ȯ���ϴ� �Լ�
void ArrayVector::reserve(int N) { 
    if (capacity >= N) return; 
    Elem* B = new Elem[N]; // B �����͸� ���Ӱ� �����Ҵ� (ũ�� = N) 
    for (int j = 0; j < n; j++)
        B[j] = A[j]; // �迭�� ���� for ������ ���� �����Ѵ�. 
    if (A != NULL) delete[] A;  // ���� A �������� �޸𸮸� �����ϰ�
    A = B;  //  ����� ���Ҵ� B �����ͷ� �ٽ� �Ҵ��Ѵ�. 
    capacity = N;
}

// i��° �ε����� e Element ����
void ArrayVector::insert(int i, const Elem& e) {
    if (n >= capacity)
        reserve(max(1, 2 * capacity));
    // ���� ��ġ�� capacity���� ũ�� Vector�� ũ�⸦ �� ��� �ø���. 
    for (int j = n - 1; j >= i; j--) 
        A[j + 1] = A[j];
    // ������ ���� �� ĭ�� ����
    A[i] = e;
    n++; // ���� ��ġ 1 ����
}

// ArrayVector���� i��° �ε����� �����ϴ� erase�Լ�
void ArrayVector::erase(int i) {
    for (int j = i + 1; j < n; j++)
        A[j - 1] = A[j];
    // ������ �ε����� �������� �� ĭ�� ����. 
    n--; // ���� ����� ������ 1�� �����Ѵ�.
}