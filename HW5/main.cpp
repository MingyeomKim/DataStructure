#include <iostream>
#include "Entry.h"
#include "BinarySearchTree.h"
using namespace std;

template <typename Key,typename Value>
class Entry;

template <typename Object>
class BinarySearchTree;

int main() {
	BinarySearchTree <Entry<int, char>> bst;
	// 삽입 연산이 정상 동작하는 것을 보일 것

	bst.insert(1, 'a');
	bst.insert(2, 'b');
	bst.insert(6, 'f');
	bst.insert(5, 'c');
	bst.insert(7, 'e');
	bst.insert(4, 'd');
	bst.insert(3, 'k');
	bst.insert(8, 'h');

	// 트리 형태로 출력	
	bst.print_BT();
	cout << endl; 

	// preorder, inorder, postorder로 방문 순서를 출력할 것
	cout << "preorder : ";
	bst.print_preorder();

	cout << endl << "inorder : ";
	bst.print_inorder();

	cout << endl << "postorder : ";
	bst.print_postorder();

	// 삭제 연산이 정상 동작하는 것을 보일 것
	bst.remove(3);
	cout << endl << endl;
	cout << "노드 3을 삭제하였습니다. " << endl << endl;
	cout << "preorder : ";
	bst.print_preorder();
	cout << endl << "inorder : ";
	bst.print_inorder();

	cout << endl << "postorder : ";
	bst.print_postorder();
	cout << endl;
	return 0;
}	
