#ifndef SIMPLELIST_H
#define SIMPLELIST_H

#include <iostream>
#include "Node.h"

template <class T>
class SimpleList {
public:
	SimpleList() : head(nullptr) {}
	
	Node<T>* head;
	
	void insert(T data) {
		Node<T>* node = new Node<T>(data);
		
		if(head == nullptr) {
			head = node;
			return;
		}
		
		Node<T>* current = head;
		
		while(current->next != nullptr)
			current = current->next;
		
		current->next = node;
	}
	
	void show(void (*callback)(T&)) {
		if(head == nullptr) {
			std::cout << "No hay datos\n";
			return;
		}
		
		Node<T>* current = head;
		
		while(current != nullptr) {
			callback(current->data);
			current = current->next;
		}
	}
	
	bool exists(bool (*cmp)(T&, int), int id) {
		Node<T>* current = head;
		
		while(current != nullptr) {
			if(cmp(current->data, id))
				return true;
			
			current = current->next;
		}
		return false;
	}
	
	void showById(bool (*cmp)(T&, int),
						void (*callback)(T&),
							  int id) {
		
		Node<T>* current = head;
		
		while(current != nullptr) {
			if(cmp(current->data, id)) {
				callback(current->data);
				return;
			}
			current = current->next;
		}
		
		std::cout << "No encontrado\n";
	}
};

#endif
