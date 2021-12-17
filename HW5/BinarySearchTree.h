#include <iostream>
#include <cmath>
using namespace std;

// template class인 Entry를 가져옴. 
template <typename Key, typename Value>
class Entry;

// Binary Search Tree 클래스 구현
template <typename Object>
class BinarySearchTree {
public:
	// 클래스 객체의 자료형인 Object의 범주에 있는 두 자료형 Key, Value를 선언
	typedef typename Object::K Key;
	typedef typename Object::V Value;

protected:
	// BinarySearchTree의 내부에 protected 접근자로 Node 클래스를 사용
	class Node { // a node in the Binary Search tree 
	private: 
		Object element; // the element 
	public:
		Node* parent = NULL; // parent
		Node* left = NULL; // left child 
		Node* right = NULL; // right child
		Node() { } // 생성자
		~Node() {} // 소멸자
		// 노도의 형제 (부모의 자식)을 반환하는 sibling 함수
		Node* sibling() const { return (this == parent->left ? parent->right : parent->left); }
		void print()  { cout << "(" << element.key() << ", " << element.value() << ")";} // 노드의 element의 key와 value를 출력하는 함수
		const Key& key() const { return element.key(); } // Node의 Key를 반환하는 함수 
		const Key& value() const { return element.value(); } // Node의 value를 반환하는 함수 
		Node* leftChild() const { return left; } // Node의 left Child를 반환하는 함수 
		Node* rightChild() const { return right; }  // Node의 right Child를 반환하는 함수
		void setKey(const Key& key) { element.setKey(key); } // 매개변수로 들어온 key를 현재 노드의 key로 세팅하는 함수  
		void setValue(const Value& value) { element.setValue(value); }// 매개변수로 들어온 value를 현재 노드의 value로 세팅하는 함수  
		Key getKey() const { return element.key(); } // 현재 노드의 key를 반환하는 함수 
		Value getValue() const { return element.value(); } // 현재 노드의 Value를 반환하는 함수
	};
	typedef Node* NodePtr;

private:
	NodePtr ROOT = NULL; // BST의 ROOT 노드를 가리키는 멤버 변수
	int size; // BST의 노드의 개수를 의미
public:
	BinarySearchTree() { // 생성자 
		ROOT = new Node;
		expandExternal(ROOT);  // ROOT에 대해 외부노드를 확장하기 위해 expandExternal 호출
		size = 0; // 노드의 개수는 0으로 초기화
	}
	~BinarySearchTree() { delete ROOT; } // 소멸자

	int findDepth(Node* p) {
		if (p->parent == NULL) return 0; // root 노드라면 Depth는 0
		else return findDepth(p->parent) + 1; // root노드가 아닐 경우, parent 노드의 Depth를 찾아가며 1을 더한다. 
	}

	// BST의 Root 노드를 반환하는 함수
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
	// 노드가 Tree 내에서 사용되었을 경우, 외부 노드인지 출력하는 함수
	bool isExternal(NodePtr n) const {
		return (n->left == NULL && n->right == NULL);
	}
	// 내부 노드인지 출력하는 함수
	bool isInternal(NodePtr n) const {
		return !isExternal(n);
	}
	/*
	*	find Node in BST
	*/  
	// find 함수 : 트리 내에서 노드 객체를 찾아서 반환
	NodePtr find(const Key &key) {
		NodePtr p = finder(key, root());
		// finder 함수에서, key값과 현재 트리의 root노드를 비교한다. 
		if (isInternal(p)) { return p; } // 노드를 찾았을 경우 찾은 노드 객체를 반환
		else {
			cout << "입력한 key를 찾지 못하였습니다. " << endl;
			return NULL;
		} // 노드를 찾지 못했을 경우 경고문을 띄우고 NULL을 반환
	}
	// finder 함수 : 트리 내부에서 찾을 노드에 대하여 비교를 수행하는 함수
	NodePtr finder(const Key &key, NodePtr node) {
		// 트리 내부의 key를 기준으로 node와의 대소를 비교
		if (isExternal(node)) return node;
		// node가 외부 노드가 될 경우의 중단점을 설정한다. 
		if (key < node->key())	return finder(key, node->left);
		else if (key > node->key()) return finder(key, node->right);
		else return node;
	}
	

	/*
	*	insert Node in BST
	*/
	// <key, value> 로 이루어진 노드를 Insert 
	NodePtr insert(const Key& key, const Value& value) {
		NodePtr p = finder(key, root());
		while (isInternal(p)) p = p->right; // Node가 내부 노드일 경우 오른쪽으로 이동한다
		expandExternal(p);  // 외부 노드에 도착한 상태에서, expandExternal을 호출해 확장한다. 
		p->setKey(key); 
		p->setValue(value); 
		// p 노드의 key와 value를 매개변수에 들어온 값으로 설정해준다. 
		size++; // 노드의 개수를 1 증가시켜준다. 
		return p;
	}
	// BST에서 외부 노드를 확장하는 함수
	void expandExternal(NodePtr p) {
		p->left = new Node;
		p->right = new Node;
		// 노드 p를 기준으로 왼쪽, 오른쪽 노드를 추가
		p->left->parent = p->right->parent = p; // 왼쪽, 오른쪽 노드의 부모 노드를 p로 지정
		size += 2; // left, right 노드가 추가되었으므로 노드의 개수를 2 증가
	}

	/*
	*	remove Node in BST
	*/
	class NonexistentElementException {
	private:
		string errMsg; // errorMsg 멤버 변수
	public:
		NonexistentElementException(string err) {
			errMsg = err;
		}
		string getMessage() {
			return errMsg;
		}
	}; // 예외 처리 클래스 NonexistentElementException
	// Key를 기준으로 찾은 노드를 삭제하는 함수
	void remove(const Key& key) throw(NonexistentElementException){
		NodePtr p = finder(key, root());
		if (p == NULL)  throw NonexistentElementException("Remove nonexistent element");
		remover(p); // 찾은 노드를 remover함수의 인자에 넣어 호출. 
	}
	NodePtr remover(const NodePtr& r) {
		NodePtr p;
		if (isExternal(r->leftChild()))	p = r->leftChild(); // 왼쪽 자식이 외부 노드일 경우 왼쪽 자식 대입
		else if (isExternal(r->rightChild())) p = r->rightChild(); // 오른쪽 자식이 외부 노드일 경우 오른쪽 자식 대입
		else { // 내부 노드일 경우 
			p = r->rightChild(); // 오른쪽 자식을 대입한다.  
			do {
				p = p->leftChild();  // 왼쪽으로 이동한다. 
			} while (isInternal(p)); // 외부노드가 될 때까지 
			r->setKey(p->parent->key());
			r->setValue(p->parent->value()); }
		// r 노드에 p->parent의 key, value를 대입한다.  
		size--; // 노드의 개수를 하나 감소시킨다. 
		return removeAboveExternal(p); // 외부노드를 삭제하는 removeAboveExternal함수를 호출한다. 
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

	// 트리 형태를 좌측으로 정렬해서 출력한다. 
	void print_BT(const string& prefix, const NodePtr node, bool isLeft) {
		if (node != nullptr) { // node가 null pointer가 아닌 경우
			cout << prefix; // key 출력 이전에 출력될 공백
			cout << (isLeft ? "├──" : "└──"); 
			
			cout << "  " << node->getKey() << endl;  // node의 key를 출력한다. 
			print_BT(prefix + (isLeft ? "│   " : "    "), node->leftChild() , true);
			// leftChild를 출력하는 경우 오른쪽 노드를 마저 출력해야 하므로 isLeft = true
			print_BT(prefix + (isLeft ? "│   " : "    "), node->rightChild(), false);
			// rightChild를 출력하는 경우, 노드를 더 출력할 필요가 없으므로 isLeft = false;
		}
	}
	// root()노드의 인자를 받아 print_BT의 함수를 출력하는 오버로딩된 함수
	void print_BT(const NodePtr node) {
		print_BT("", node, false); 
	}
	// main 함수에서 Node를 만들어 매개변수에 넣을 수 없기 때문에 , 함수 오버로딩을 이용해 root()를 매개변수로 하여 print_BT함수를 호출한다. 
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

