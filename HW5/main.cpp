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
	// ���� ������ ���� �����ϴ� ���� ���� ��

	bst.insert(1, 'a');
	bst.insert(2, 'b');
	bst.insert(6, 'f');
	bst.insert(5, 'c');
	bst.insert(7, 'e');
	bst.insert(4, 'd');
	bst.insert(3, 'k');
	bst.insert(8, 'h');

	// Ʈ�� ���·� ���	
	bst.print_BT();
	cout << endl; 

	// preorder, inorder, postorder�� �湮 ������ ����� ��
	cout << "preorder : ";
	bst.print_preorder();

	cout << endl << "inorder : ";
	bst.print_inorder();

	cout << endl << "postorder : ";
	bst.print_postorder();

	// ���� ������ ���� �����ϴ� ���� ���� ��
	bst.remove(3);
	cout << endl << endl;
	cout << "��� 3�� �����Ͽ����ϴ�. " << endl << endl;
	cout << "preorder : ";
	bst.print_preorder();
	cout << endl << "inorder : ";
	bst.print_inorder();

	cout << endl << "postorder : ";
	bst.print_postorder();
	cout << endl;
	return 0;
}	
