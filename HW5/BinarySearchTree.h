#include <iostream>
#include <cmath>
using namespace std;

// template class�� Entry�� ������. 
template <typename Key, typename Value>
class Entry;

// Binary Search Tree Ŭ���� ����
template <typename Object>
class BinarySearchTree {
public:
	// Ŭ���� ��ü�� �ڷ����� Object�� ���ֿ� �ִ� �� �ڷ��� Key, Value�� ����
	typedef typename Object::K Key;
	typedef typename Object::V Value;

protected:
	// BinarySearchTree�� ���ο� protected �����ڷ� Node Ŭ������ ���
	class Node { // a node in the Binary Search tree 
	private: 
		Object element; // the element 
	public:
		Node* parent = NULL; // parent
		Node* left = NULL; // left child 
		Node* right = NULL; // right child
		Node() { } // ������
		~Node() {} // �Ҹ���
		// �뵵�� ���� (�θ��� �ڽ�)�� ��ȯ�ϴ� sibling �Լ�
		Node* sibling() const { return (this == parent->left ? parent->right : parent->left); }
		void print()  { cout << "(" << element.key() << ", " << element.value() << ")";} // ����� element�� key�� value�� ����ϴ� �Լ�
		const Key& key() const { return element.key(); } // Node�� Key�� ��ȯ�ϴ� �Լ� 
		const Key& value() const { return element.value(); } // Node�� value�� ��ȯ�ϴ� �Լ� 
		Node* leftChild() const { return left; } // Node�� left Child�� ��ȯ�ϴ� �Լ� 
		Node* rightChild() const { return right; }  // Node�� right Child�� ��ȯ�ϴ� �Լ�
		void setKey(const Key& key) { element.setKey(key); } // �Ű������� ���� key�� ���� ����� key�� �����ϴ� �Լ�  
		void setValue(const Value& value) { element.setValue(value); }// �Ű������� ���� value�� ���� ����� value�� �����ϴ� �Լ�  
		Key getKey() const { return element.key(); } // ���� ����� key�� ��ȯ�ϴ� �Լ� 
		Value getValue() const { return element.value(); } // ���� ����� Value�� ��ȯ�ϴ� �Լ�
	};
	typedef Node* NodePtr;

private:
	NodePtr ROOT = NULL; // BST�� ROOT ��带 ����Ű�� ��� ����
	int size; // BST�� ����� ������ �ǹ�
public:
	BinarySearchTree() { // ������ 
		ROOT = new Node;
		expandExternal(ROOT);  // ROOT�� ���� �ܺγ�带 Ȯ���ϱ� ���� expandExternal ȣ��
		size = 0; // ����� ������ 0���� �ʱ�ȭ
	}
	~BinarySearchTree() { delete ROOT; } // �Ҹ���

	int findDepth(Node* p) {
		if (p->parent == NULL) return 0; // root ����� Depth�� 0
		else return findDepth(p->parent) + 1; // root��尡 �ƴ� ���, parent ����� Depth�� ã�ư��� 1�� ���Ѵ�. 
	}

	// BST�� Root ��带 ��ȯ�ϴ� �Լ�
	NodePtr root() const {
		return ROOT->left;
	}
	void setRoot(NodePtr n) {
		ROOT = n;
		n->parent = NULL;
	}
	bool isRoot(NodePtr n) const {
		return (n == ROOT);
	}
	// ��尡 Tree ������ ���Ǿ��� ���, �ܺ� ������� ����ϴ� �Լ�
	bool isExternal(NodePtr n) const {
		return (n->left == NULL && n->right == NULL);
	}
	// ���� ������� ����ϴ� �Լ�
	bool isInternal(NodePtr n) const {
		return !isExternal(n);
	}
	/*
	*	find Node in BST
	*/  
	// find �Լ� : Ʈ�� ������ ��� ��ü�� ã�Ƽ� ��ȯ
	NodePtr find(const Key &key) {
		NodePtr p = finder(key, root());
		// finder �Լ�����, key���� ���� Ʈ���� root��带 ���Ѵ�. 
		if (isInternal(p)) { return p; } // ��带 ã���� ��� ã�� ��� ��ü�� ��ȯ
		else {
			cout << "�Է��� key�� ã�� ���Ͽ����ϴ�. " << endl;
			return NULL;
		} // ��带 ã�� ������ ��� ����� ���� NULL�� ��ȯ
	}
	// finder �Լ� : Ʈ�� ���ο��� ã�� ��忡 ���Ͽ� �񱳸� �����ϴ� �Լ�
	NodePtr finder(const Key &key, NodePtr node) {
		// Ʈ�� ������ key�� �������� node���� ��Ҹ� ��
		if (isExternal(node)) return node;
		// node�� �ܺ� ��尡 �� ����� �ߴ����� �����Ѵ�. 
		if (key < node->key())	return finder(key, node->left);
		else if (key > node->key()) return finder(key, node->right);
		else return node;
	}
	

	/*
	*	insert Node in BST
	*/
	// <key, value> �� �̷���� ��带 Insert 
	NodePtr insert(const Key& key, const Value& value) {
		NodePtr p = finder(key, root());
		while (isInternal(p)) p = p->right; // Node�� ���� ����� ��� ���������� �̵��Ѵ�
		expandExternal(p);  // �ܺ� ��忡 ������ ���¿���, expandExternal�� ȣ���� Ȯ���Ѵ�. 
		p->setKey(key); 
		p->setValue(value); 
		// p ����� key�� value�� �Ű������� ���� ������ �������ش�. 
		size++; // ����� ������ 1 ���������ش�. 
		return p;
	}
	// BST���� �ܺ� ��带 Ȯ���ϴ� �Լ�
	void expandExternal(NodePtr p) {
		p->left = new Node;
		p->right = new Node;
		// ��� p�� �������� ����, ������ ��带 �߰�
		p->left->parent = p->right->parent = p; // ����, ������ ����� �θ� ��带 p�� ����
		size += 2; // left, right ��尡 �߰��Ǿ����Ƿ� ����� ������ 2 ����
	}

	/*
	*	remove Node in BST
	*/
	class NonexistentElementException {
	private:
		string errMsg; // errorMsg ��� ����
	public:
		NonexistentElementException(string err) {
			errMsg = err;
		}
		string getMessage() {
			return errMsg;
		}
	}; // ���� ó�� Ŭ���� NonexistentElementException
	// Key�� �������� ã�� ��带 �����ϴ� �Լ�
	void remove(const Key& key) throw(NonexistentElementException){
		NodePtr p = finder(key, root());
		if (p == NULL)  throw NonexistentElementException("Remove nonexistent element");
		remover(p); // ã�� ��带 remover�Լ��� ���ڿ� �־� ȣ��. 
	}
	NodePtr remover(const NodePtr& r) {
		NodePtr p;
		if (isExternal(r->leftChild()))	p = r->leftChild(); // ���� �ڽ��� �ܺ� ����� ��� ���� �ڽ� ����
		else if (isExternal(r->rightChild())) p = r->rightChild(); // ������ �ڽ��� �ܺ� ����� ��� ������ �ڽ� ����
		else { // ���� ����� ��� 
			p = r->rightChild(); // ������ �ڽ��� �����Ѵ�.  
			do {
				p = p->leftChild();  // �������� �̵��Ѵ�. 
			} while (isInternal(p)); // �ܺγ�尡 �� ������ 
			r->setKey(p->parent->key());
			r->setValue(p->parent->value()); }
		// r ��忡 p->parent�� key, value�� �����Ѵ�.  
		size--; // ����� ������ �ϳ� ���ҽ�Ų��. 
		return removeAboveExternal(p); // �ܺγ�带 �����ϴ� removeAboveExternal�Լ��� ȣ���Ѵ�. 
	}

	NodePtr removeAboveExternal(NodePtr n) {
		NodePtr p = n->parent;
		NodePtr s = n->sibling();
		if (isRoot(p)) setRoot(s);
		else {
			NodePtr g = p->parent;
			if (p == g->left) g->left = s;
			else g->right = s;
			s->parent = g;
		}
		delete n; delete p;
		size -= 2;
		return s;
	}

	// Ʈ�� ���¸� �������� �����ؼ� ����Ѵ�. 
	void print_BT(const string& prefix, const NodePtr node, bool isLeft) {
		if (node != nullptr) { // node�� null pointer�� �ƴ� ���
			cout << prefix; // key ��� ������ ��µ� ����
			cout << (isLeft ? "������" : "������"); 
			
			cout << "  " << node->getKey() << endl;  // node�� key�� ����Ѵ�. 
			print_BT(prefix + (isLeft ? "��   " : "    "), node->leftChild() , true);
			// leftChild�� ����ϴ� ��� ������ ��带 ���� ����ؾ� �ϹǷ� isLeft = true
			print_BT(prefix + (isLeft ? "��   " : "    "), node->rightChild(), false);
			// rightChild�� ����ϴ� ���, ��带 �� ����� �ʿ䰡 �����Ƿ� isLeft = false;
		}
	}
	// root()����� ���ڸ� �޾� print_BT�� �Լ��� ����ϴ� �����ε��� �Լ�
	void print_BT(const NodePtr node) {
		print_BT("", node, false); 
	}
	// main �Լ����� Node�� ����� �Ű������� ���� �� ���� ������ , �Լ� �����ε��� �̿��� root()�� �Ű������� �Ͽ� print_BT�Լ��� ȣ���Ѵ�. 
	void print_BT() {
		print_BT(root());
	}
	

	void print_preorder() { preorder(root()); }
	void preorder(Node * p) { // DLR
		p->print();  cout << " ";
		if (isInternal(p->leftChild())) preorder(p->leftChild());
		if(isInternal(p->rightChild())) preorder(p->rightChild());
	}
	void print_postorder() { postorder(root()); }
	void postorder(Node * p) { // DLR
		if (isInternal(p->leftChild()))
			postorder(p->leftChild());
		if(isInternal(p->rightChild()))
			postorder(p->rightChild());
		p->print();
		cout << " ";
	}
	void print_inorder() { inorder(root()); }
	void inorder(Node *p) { // DLR
		if (isInternal(p->leftChild())) inorder(p->leftChild());
		p->print(); cout << " ";
		if (isInternal(p->rightChild())) inorder(p->rightChild());
	}

};

