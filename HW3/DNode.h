#pragma once
#include <iostream>
#include <string>
using namespace std;

typedef string Elem1;
// Elem1�� string ������ Ÿ���� ��Ī���� ����, ���� ������ Ÿ�� ���� �� ���� ����
class DNode{
public:
	Elem1 elem;
	DNode* prev;
	DNode* next;
	friend class DLinkedList;
};
