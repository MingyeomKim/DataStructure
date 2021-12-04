#include <iostream>
using namespace std;
#include "DLinkedList.h"

// DNode 객체를 생성해서 DLinkedList의 양 끝이 될 header와 trailer를 정의한다. 
DLinkedList::DLinkedList() {
	header = new DNode;
	trailer = new DNode;
	header->next = trailer;
	trailer->prev = header;
}

// 소멸자에서는 동적할당한 DNode 두 포인터 변수를 해제
// 만약 DLinkedList가 비어있는 상태가 아니라면 앞의 노드부터 remove한다. 
DLinkedList::~DLinkedList() {
	while (!empty()) removeFront();
	delete header;
	delete trailer;
}

// 임의로 정한 u 노드를 v와 v의 앞의 노드 사이에 끼워 넣는다. 
void DLinkedList::add(DNode* v, const Elem1& e) {
	DNode* u = new DNode;
	u->elem = e;
	u->next = v;
	u->prev = v->prev;
	// 새로 정의한 u 노드의 next, prev를 v노드와 v의 앞쪽 노드와 연결시킨다. 
	v->prev->next = u;
	v->prev = u;
	// v의 앞의 노드는 다시 u노드를 가리키고, v의 노드 역시 u 노드를 가리킨다.
}

void DLinkedList::addFront(const Elem1& e) {
	add(header->next, e);
} // header-> next 노드에 노드를 추가함으로써, header 다음의 위치에 노드를 삽입

void DLinkedList::addBack(const Elem1& e) {
	add(trailer, e);
} // trailer 노드의 앞에 노드를 추가한다. 

// v 노드를 삭제하는 remove 함수 
void DLinkedList::remove(DNode* v) {
	DNode* u = v->prev;
	DNode* w = v->next;
	// 삭제하려는 노드의 앞, 뒤 노드에 대한 노드 포인터를 임시로 정의
	u->next = w;
	w->prev = u;
	// u와 w노드의 앞, 뒤를 각각 w와 u노드로 지정하여 v의 앞, 뒤 노드의 연관관계를 없애줌.
	delete v;
	// v의 메모리를 해제해 최종적으로 v를 삭제한다. 
}

// 제일 앞의 노드 (header의 다음 노드)를 삭제하는 함수
void DLinkedList::removeFront() {
	remove(header->next);
}

// 제일 뒤의 노드 (trailer의 앞의 노드)를 삭제하는 함수
void DLinkedList::removeBack() {
	remove(trailer->prev);
}

// DLinkedList가 비어있는 지 확인하는 함수 
bool DLinkedList::empty() const {
	return (header->next == trailer);
} // header의 next 포인터가 trailer를 가리키고 있으면 header와 trailer를 제외한 노드는 없는 것으로 판단.

// 제일 앞의 노드의 값을 출력하는 함수
const Elem1& DLinkedList::front() const {
	return (header->next->elem);
}

// 제일 뒤의 노드의 값을 출력하는 함수
const Elem1& DLinkedList::back() const {
	return trailer->prev->elem;
}
