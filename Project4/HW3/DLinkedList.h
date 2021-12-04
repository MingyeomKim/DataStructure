#pragma once
#include "DNode.h"

// DLinkedList Ŭ������ �������
class DLinkedList {
public:
	DLinkedList();	
	~DLinkedList(); 
	bool empty() const;
	const Elem1& front() const;
	const Elem1& back() const;
	void addFront(const Elem1& e);
	void addBack(const Elem1& e);
	void removeFront();
	void removeBack();
private:
	DNode* header;
	DNode* trailer;	
protected: 
	// add�� remove �Լ��� �ܺο��� ���� �̿����� �ʰ�, addFront �� ���� ��� �Լ����� ����ϰ� �����Ƿ� protected ���� �����ڸ� ����Ѵ�. 
	void add(DNode* v, const Elem1& e);
	void remove(DNode* v);
};