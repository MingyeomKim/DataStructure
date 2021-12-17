#pragma once
#include <iostream>
using namespace std;

// Tree 내부의 노드를 Entry 객체로 받아, Key - Value 속성을 만든다. 

// Key, Value
template <typename Key, typename Value>
class Entry {
private:
	Key _key; // 키
	Value _value; // 값
public:
	typedef Key K; // key의 자료형을 Key로 선언
	typedef Value V; // value의 자료형을 Value로 선언
public:
	Entry(const Key& k = Key(), const Value& v = Value())
		: _key(k), _value(v) {} // 생성자
	~Entry() {} // 소멸자
	const Key& key() const { return _key; }  // Get key 
	const Value& value() const { return _value; } // Get Value
	void setKey(const Key& k) { _key = k; } // Set Key 
	void setValue(const Value& v) { _value = v; } // Set Value 
};
