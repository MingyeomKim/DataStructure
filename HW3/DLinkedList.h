#pragma once
#include "DNode.h"

// DLinkedList 클래스의 헤더파일
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
	// add와 remove 함수를 외부에서 직접 이용하지 않고, addFront 등 내부 멤버 함수에서 사용하고 있으므로 protected 접근 지정자를 사용한다. 
	void add(DNode* v, const Elem1& e);
	void remove(DNode* v);
};