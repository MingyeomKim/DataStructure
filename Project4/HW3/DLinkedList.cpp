#include <iostream>
using namespace std;
#include "DLinkedList.h"

// DNode ��ü�� �����ؼ� DLinkedList�� �� ���� �� header�� trailer�� �����Ѵ�. 
DLinkedList::DLinkedList() {
	header = new DNode;
	trailer = new DNode;
	header->next = trailer;
	trailer->prev = header;
}

// �Ҹ��ڿ����� �����Ҵ��� DNode �� ������ ������ ����
// ���� DLinkedList�� ����ִ� ���°� �ƴ϶�� ���� ������ remove�Ѵ�. 
DLinkedList::~DLinkedList() {
	while (!empty()) removeFront();
	delete header;
	delete trailer;
}

// ���Ƿ� ���� u ��带 v�� v�� ���� ��� ���̿� ���� �ִ´�. 
void DLinkedList::add(DNode* v, const Elem1& e) {
	DNode* u = new DNode;
	u->elem = e;
	u->next = v;
	u->prev = v->prev;
	// ���� ������ u ����� next, prev�� v���� v�� ���� ���� �����Ų��. 
	v->prev->next = u;
	v->prev = u;
	// v�� ���� ���� �ٽ� u��带 ����Ű��, v�� ��� ���� u ��带 ����Ų��.
}

void DLinkedList::addFront(const Elem1& e) {
	add(header->next, e);
} // header-> next ��忡 ��带 �߰������ν�, header ������ ��ġ�� ��带 ����

void DLinkedList::addBack(const Elem1& e) {
	add(trailer, e);
} // trailer ����� �տ� ��带 �߰��Ѵ�. 

// v ��带 �����ϴ� remove �Լ� 
void DLinkedList::remove(DNode* v) {
	DNode* u = v->prev;
	DNode* w = v->next;
	// �����Ϸ��� ����� ��, �� ��忡 ���� ��� �����͸� �ӽ÷� ����
	u->next = w;
	w->prev = u;
	// u�� w����� ��, �ڸ� ���� w�� u���� �����Ͽ� v�� ��, �� ����� �������踦 ������.
	delete v;
	// v�� �޸𸮸� ������ ���������� v�� �����Ѵ�. 
}

// ���� ���� ��� (header�� ���� ���)�� �����ϴ� �Լ�
void DLinkedList::removeFront() {
	remove(header->next);
}

// ���� ���� ��� (trailer�� ���� ���)�� �����ϴ� �Լ�
void DLinkedList::removeBack() {
	remove(trailer->prev);
}

// DLinkedList�� ����ִ� �� Ȯ���ϴ� �Լ� 
bool DLinkedList::empty() const {
	return (header->next == trailer);
} // header�� next �����Ͱ� trailer�� ����Ű�� ������ header�� trailer�� ������ ���� ���� ������ �Ǵ�.

// ���� ���� ����� ���� ����ϴ� �Լ�
const Elem1& DLinkedList::front() const {
	return (header->next->elem);
}

// ���� ���� ����� ���� ����ϴ� �Լ�
const Elem1& DLinkedList::back() const {
	return trailer->prev->elem;
}
