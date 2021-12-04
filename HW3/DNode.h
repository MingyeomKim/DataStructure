#pragma once
#include <iostream>
#include <string>
using namespace std;

typedef string Elem1;
// Elem1를 string 데이터 타입의 별칭으로 지정, 추후 데이터 타입 변경 시 편리함 제공
class DNode{
public:
	Elem1 elem;
	DNode* prev;
	DNode* next;
	friend class DLinkedList;
};
