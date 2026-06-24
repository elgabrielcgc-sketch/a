#ifndef NODE_H
#define NODE_H

template <class T>
struct Node {
	Node() : next(nullptr) {}
	
	Node(T data) : data(data), next(nullptr) {}
	
	T data;
	Node<T>* next;
};

#endif
