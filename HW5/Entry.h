#pragma once
#include <iostream>
using namespace std;

// Tree ������ ��带 Entry ��ü�� �޾�, Key - Value �Ӽ��� �����. 

// Key, Value
template <typename Key, typename Value>
class Entry {
private:
	Key _key; // Ű
	Value _value; // ��
public:
	typedef Key K; // key�� �ڷ����� Key�� ����
	typedef Value V; // value�� �ڷ����� Value�� ����
public:
	Entry(const Key& k = Key(), const Value& v = Value())
		: _key(k), _value(v) {} // ������
	~Entry() {} // �Ҹ���
	const Key& key() const { return _key; }  // Get key 
	const Value& value() const { return _value; } // Get Value
	void setKey(const Key& k) { _key = k; } // Set Key 
	void setValue(const Value& v) { _value = v; } // Set Value 
};
