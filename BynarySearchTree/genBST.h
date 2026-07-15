#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <iostream>

using namespace std;

template<class T>
class Deque {
public:
	enum { blockSize = 4 };
	
	Deque();
	~Deque();
	
	bool empty() const;
	int length() const;
	
	void push_back(const T& el);
	void push_front(const T& el);
	
	T pop_back();
	T pop_front();
	
	T& operator[](int n);
	
private:
	T** blocks;
	T** headBlock;
	T** tailBlock;
	T* head;
	T* tail;
	
	int blocksSize;
	int startIndex;
	int numberOfElements;
	
	void resizeBlocks();
	void ensureBlock(int blockIndex);
	void updatePointers();
};

template<class T>
class Stack {
public:
	bool empty() const;
	void push(const T& el);
	T pop();
	
private:
	Deque<T> deque;
};

template<class T>
class Queue {
public:
	bool empty() const;
	T dequeue();
	void enqueue(const T& el);
	
private:
	Deque<T> deque;
};

template<class T>
class BSTNode {
public:
	BSTNode();
	BSTNode(const T& e, BSTNode<T>* l = 0, BSTNode<T>* r = 0);
	
	T el;
	BSTNode<T>* left;
	BSTNode<T>* right;
};

template<class T>
class BST {
public:
	BST();
	~BST();
	
	void clear();
	bool isEmpty() const;
	
	void preorder();
	void inorder();
	void postorder();
	
	T* search(const T& el) const;
	
	void breadthFirst();
	void iterativePreorder();
	void iterativeInorder();
	void iterativePostorder();
	void MorrisInorder();
	
	void insert(const T&);
	
	void deleteByMerging(BSTNode<T>*&);
	void findAndDeleteByMerging(const T&);
	
	void deleteByCopying(BSTNode<T>*&);
	void findAndDeleteByCopying(const T&);
	
	void balance(T*, int, int);
	
protected:
	BSTNode<T>* root;
	
	void clear(BSTNode<T>*);
	T* search(BSTNode<T>*, const T&) const;
	
	void preorder(BSTNode<T>*);
	void inorder(BSTNode<T>*);
	void postorder(BSTNode<T>*);
	
	virtual void visit(BSTNode<T>* p);
};

#endif
