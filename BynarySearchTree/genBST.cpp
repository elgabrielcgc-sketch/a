#include "genBST.h"

template<class T>
Deque<T>::Deque() {
	blocksSize = 4;
	blocks = new T*[blocksSize];
	
	for(int i = 0; i < blocksSize; i++) {
		blocks[i] = 0;
	}
	
	startIndex = (blocksSize / 2) * blockSize;
	numberOfElements = 0;
	
	headBlock = &blocks[startIndex / blockSize];
	tailBlock = headBlock;
	
	head = 0;
	tail = 0;
}

template<class T>
Deque<T>::~Deque() {
	for(int i = 0; i < blocksSize; i++) {
		if(blocks[i] != 0) {
			delete[] blocks[i];
		}
	}
	
	delete[] blocks;
}

template<class T>
	bool Deque<T>::empty() const {
	return numberOfElements == 0;
}

template<class T>
	int Deque<T>::length() const {
	return numberOfElements;
}

template<class T>
	void Deque<T>::ensureBlock(int blockIndex) {
	if(blocks[blockIndex] == 0) {
		blocks[blockIndex] = new T[blockSize];
	}
}

template<class T>
	void Deque<T>::updatePointers() {
	if(numberOfElements == 0) {
		headBlock = &blocks[startIndex / blockSize];
		tailBlock = headBlock;
		head = 0;
		tail = 0;
		return;
	}
	
	int firstIndex = startIndex;
	int lastIndex = startIndex + numberOfElements - 1;
	
	headBlock = &blocks[firstIndex / blockSize];
	tailBlock = &blocks[lastIndex / blockSize];
	
	head = *headBlock + (firstIndex % blockSize);
	tail = *tailBlock + (lastIndex % blockSize);
}

template<class T>
	void Deque<T>::resizeBlocks() {
	int newBlocksSize = blocksSize * 2;
	T** newBlocks = new T*[newBlocksSize];
	
	for(int i = 0; i < newBlocksSize; i++) {
		newBlocks[i] = 0;
	}
	
	if(numberOfElements == 0) {
		for(int i = 0; i < blocksSize; i++) {
			if(blocks[i] != 0) {
				delete[] blocks[i];
			}
		}
		
		delete[] blocks;
		
		blocks = newBlocks;
		blocksSize = newBlocksSize;
		startIndex = (blocksSize / 2) * blockSize;
		
		updatePointers();
		return;
	}
	
	int oldFirstBlock = startIndex / blockSize;
	int oldLastBlock = (startIndex + numberOfElements - 1) / blockSize;
	int usedBlocks = oldLastBlock - oldFirstBlock + 1;
	
	int newFirstBlock = (newBlocksSize - usedBlocks) / 2;
	int offset = startIndex % blockSize;
	
	for(int i = 0; i < usedBlocks; i++) {
		newBlocks[newFirstBlock + i] = blocks[oldFirstBlock + i];
		blocks[oldFirstBlock + i] = 0;
	}
	
	for(int i = 0; i < blocksSize; i++) {
		if(blocks[i] != 0) {
			delete[] blocks[i];
		}
	}
	
	delete[] blocks;
	
	blocks = newBlocks;
	blocksSize = newBlocksSize;
	startIndex = newFirstBlock * blockSize + offset;
	
	updatePointers();
}

template<class T>
	void Deque<T>::push_back(const T& el) {
	if(startIndex + numberOfElements >= blocksSize * blockSize) {
		resizeBlocks();
	}
	
	int position = startIndex + numberOfElements;
	int blockIndex = position / blockSize;
	int cellIndex = position % blockSize;
	
	ensureBlock(blockIndex);
	
	*(*(blocks + blockIndex) + cellIndex) = el;
	
	numberOfElements++;
	
	updatePointers();
}

template<class T>
	void Deque<T>::push_front(const T& el) {
	if(startIndex == 0) {
		resizeBlocks();
	}
	
	startIndex--;
	
	int blockIndex = startIndex / blockSize;
	int cellIndex = startIndex % blockSize;
	
	ensureBlock(blockIndex);
	
	*(*(blocks + blockIndex) + cellIndex) = el;
	
	numberOfElements++;
	
	updatePointers();
}

template<class T>
	T Deque<T>::pop_back() {
	if(numberOfElements == 0) {
		return T();
	}
	
	int position = startIndex + numberOfElements - 1;
	int blockIndex = position / blockSize;
	int cellIndex = position % blockSize;
	
	T tmp = *(*(blocks + blockIndex) + cellIndex);
	
	numberOfElements--;
	
	updatePointers();
	
	return tmp;
}

template<class T>
	T Deque<T>::pop_front() {
	if(numberOfElements == 0) {
		return T();
	}
	
	int position = startIndex;
	int blockIndex = position / blockSize;
	int cellIndex = position % blockSize;
	
	T tmp = *(*(blocks + blockIndex) + cellIndex);
	
	startIndex++;
	numberOfElements--;
	
	updatePointers();
	
	return tmp;
}

template<class T>
	T& Deque<T>::operator[](int n) {
		if(n < blockSize - (head - *headBlock)) {
			return *(head + n);
		}
		else {
			n = n - (blockSize - (head - *headBlock));
			
			int q = n / blockSize + 1;
			int r = n % blockSize;
			
			return *(*(headBlock + q) + r);
		}
	}
	
	template<class T>
							bool Stack<T>::empty() const {
		return deque.empty();
	}
	
	template<class T>
							void Stack<T>::push(const T& el) {
		deque.push_back(el);
	}
	
	template<class T>
							T Stack<T>::pop() {
		return deque.pop_back();
	}
	
	template<class T>
							bool Queue<T>::empty() const {
		return deque.empty();
	}
	
	template<class T>
							T Queue<T>::dequeue() {
		return deque.pop_front();
	}
	
	template<class T>
							void Queue<T>::enqueue(const T& el) {
		deque.push_back(el);
	}
	
	template<class T>
							BSTNode<T>::BSTNode() {
		left = right = 0;
	}
	
	template<class T>
							BSTNode<T>::BSTNode(const T& e, BSTNode<T>* l, BSTNode<T>* r) {
		el = e;
		left = l;
		right = r;
	}
	
	template<class T>
							BST<T>::BST() {
		root = 0;
	}
	
	template<class T>
							BST<T>::~BST() {
		clear();
	}
							
							template<class T>
								void BST<T>::clear() {
								clear(root);
								root = 0;
							}
							
							template<class T>
								bool BST<T>::isEmpty() const {
								return root == 0;
							}
							
							template<class T>
								void BST<T>::preorder() {
								preorder(root);
							}
							
							template<class T>
								void BST<T>::inorder() {
								inorder(root);
							}
							
							template<class T>
								void BST<T>::postorder() {
								postorder(root);
							}
							
							template<class T>
								T* BST<T>::search(const T& el) const {
								return search(root, el);
							}
							
							template<class T>
								void BST<T>::visit(BSTNode<T>* p) {
								cout << p->el << ' ';
							}
							
							template<class T>
								void BST<T>::clear(BSTNode<T>* p) {
								if(p != 0) {
									clear(p->left);
									clear(p->right);
									delete p;
								}
							}
							
							template<class T>
								T* BST<T>::search(BSTNode<T>* p, const T& el) const {
								while(p != 0) {
									if(el == p->el) {
										return &p->el;
									}
									else if(el < p->el) {
										p = p->left;
									}
									else {
										p = p->right;
									}
								}
								
								return 0;
							}
							
							template<class T>
								void BST<T>::inorder(BSTNode<T>* p) {
								if(p != 0) {
									inorder(p->left);
									visit(p);
									inorder(p->right);
								}
							}
							
							template<class T>
								void BST<T>::preorder(BSTNode<T>* p) {
								if(p != 0) {
									visit(p);
									preorder(p->left);
									preorder(p->right);
								}
							}
							
							template<class T>
								void BST<T>::postorder(BSTNode<T>* p) {
								if(p != 0) {
									postorder(p->left);
									postorder(p->right);
									visit(p);
								}
							}
							
							template<class T>
								void BST<T>::breadthFirst() {
								Queue<BSTNode<T>*> queue;
								BSTNode<T>* p = root;
								
								if(p != 0) {
									queue.enqueue(p);
									
									while(!queue.empty()) {
										p = queue.dequeue();
										
										visit(p);
										
										if(p->left != 0) {
											queue.enqueue(p->left);
										}
										
										if(p->right != 0) {
											queue.enqueue(p->right);
										}
									}
								}
							}
							
							template<class T>
								void BST<T>::iterativePreorder() {
								Stack<BSTNode<T>*> travStack;
								BSTNode<T>* p = root;
								
								if(p != 0) {
									travStack.push(p);
									
									while(!travStack.empty()) {
										p = travStack.pop();
										
										visit(p);
										
										if(p->right != 0) {
											travStack.push(p->right);
										}
										
										if(p->left != 0) {
											travStack.push(p->left);
										}
									}
								}
							}
							
							template<class T>
								void BST<T>::iterativeInorder() {
								Stack<BSTNode<T>*> travStack;
								BSTNode<T>* p = root;
								
								while(p != 0) {
									while(p != 0) {
										if(p->right) {
											travStack.push(p->right);
										}
										
										travStack.push(p);
										p = p->left;
									}
									
									p = travStack.pop();
									
									while(!travStack.empty() && p->right == 0) {
										visit(p);
										p = travStack.pop();
									}
									
									visit(p);
									
									if(!travStack.empty()) {
										p = travStack.pop();
									}
									else {
										p = 0;
									}
								}
							}
							
							template<class T>
								void BST<T>::iterativePostorder() {
								Stack<BSTNode<T>*> travStack;
								BSTNode<T>* p = root;
								BSTNode<T>* q = root;
								
								while(p != 0) {
									for( ; p->left != 0; p = p->left) {
										travStack.push(p);
									}
									
									while(p->right == 0 || p->right == q) {
										visit(p);
										q = p;
										
										if(travStack.empty()) {
											return;
										}
										
										p = travStack.pop();
									}
									
									travStack.push(p);
									p = p->right;
								}
							}
							
							template<class T>
								void BST<T>::MorrisInorder() {
								BSTNode<T>* p = root;
								BSTNode<T>* tmp;
								
								while(p != 0) {
									if(p->left == 0) {
										visit(p);
										p = p->right;
									}
									else {
										tmp = p->left;
										
										while(tmp->right != 0 && tmp->right != p) {
											tmp = tmp->right;
										}
										
										if(tmp->right == 0) {
											tmp->right = p;
											p = p->left;
										}
										else {
											visit(p);
											tmp->right = 0;
											p = p->right;
										}
									}
								}
							}
							
							template<class T>
								void BST<T>::insert(const T& el) {
								BSTNode<T>* p = root;
								BSTNode<T>* prev = 0;
								
								while(p != 0) {
									prev = p;
									
									if(el < p->el) {
										p = p->left;
									}
									else {
										p = p->right;
									}
								}
								
								if(root == 0) {
									root = new BSTNode<T>(el);
								}
								else if(el < prev->el) {
									prev->left = new BSTNode<T>(el);
								}
								else {
									prev->right = new BSTNode<T>(el);
								}
							}
							
							template<class T>
								void BST<T>::deleteByMerging(BSTNode<T>*& node) {
								BSTNode<T>* tmp = node;
								
								if(node != 0) {
									if(!node->right) {
										node = node->left;
									}
									else if(node->left == 0) {
										node = node->right;
									}
									else {
										tmp = node->left;
										
										while(tmp->right != 0) {
											tmp = tmp->right;
										}
										
										tmp->right = node->right;
										tmp = node;
										node = node->left;
									}
									
									delete tmp;
								}
							}
							
							template<class T>
								void BST<T>::findAndDeleteByMerging(const T& el) {
								BSTNode<T>* node = root;
								BSTNode<T>* prev = 0;
								
								while(node != 0) {
									if(node->el == el) {
										break;
									}
									
									prev = node;
									
									if(el < node->el) {
										node = node->left;
									}
									else {
										node = node->right;
									}
								}
								
								if(node != 0 && node->el == el) {
									if(node == root) {
										deleteByMerging(root);
									}
									else if(prev->left == node) {
										deleteByMerging(prev->left);
									}
									else {
										deleteByMerging(prev->right);
									}
								}
								else if(root != 0) {
									cout << "element " << el << " is not in the tree\n";
								}
								else {
									cout << "the tree is empty\n";
								}
							}
							
							template<class T>
								void BST<T>::deleteByCopying(BSTNode<T>*& node) {
								BSTNode<T>* previous;
								BSTNode<T>* tmp = node;
								
								if(node == 0) {
									return;
								}
								
								if(node->right == 0) {
									node = node->left;
								}
								else if(node->left == 0) {
									node = node->right;
								}
								else {
									tmp = node->left;
									previous = node;
									
									while(tmp->right != 0) {
										previous = tmp;
										tmp = tmp->right;
									}
									
									node->el = tmp->el;
									
									if(previous == node) {
										previous->left = tmp->left;
									}
									else {
										previous->right = tmp->left;
									}
								}
								
								delete tmp;
							}
							
							template<class T>
								void BST<T>::findAndDeleteByCopying(const T& el) {
								BSTNode<T>* node = root;
								BSTNode<T>* prev = 0;
								
								while(node != 0) {
									if(node->el == el) {
										break;
									}
									
									prev = node;
									
									if(el < node->el) {
										node = node->left;
									}
									else {
										node = node->right;
									}
								}
								
								if(node != 0 && node->el == el) {
									if(node == root) {
										deleteByCopying(root);
									}
									else if(prev->left == node) {
										deleteByCopying(prev->left);
									}
									else {
										deleteByCopying(prev->right);
									}
								}
								else if(root != 0) {
									cout << "element " << el << " is not in the tree\n";
								}
								else {
									cout << "the tree is empty\n";
								}
							}
							
							template<class T>
								void BST<T>::balance(T data[], int first, int last) {
								if(first <= last) {
									int middle = (first + last) / 2;
									
									insert(data[middle]);
									
									balance(data, first, middle - 1);
									balance(data, middle + 1, last);
								}
							}
							
							template class Deque<BSTNode<int>*>;
							template class Stack<BSTNode<int>*>;
							template class Queue<BSTNode<int>*>;
							template class BSTNode<int>;
							template class BST<int>;
