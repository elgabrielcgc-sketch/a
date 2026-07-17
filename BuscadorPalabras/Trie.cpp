#include <iostream>
#include <fstream>

#include "Trie.h"

Trie::Trie() {
	root = new Node();
}

Trie::Node* Trie::findChild(Node* node, char letter) {
	Node* current = node->child;
	
	while (current != nullptr) {
		if (current->letter == letter) {
			return current;
		}
		
		current = current->sibling;
	}
	
	return nullptr;
}

void Trie::insert(std::string word) {
	Node* current = root;
	Node* found;
	
	for (unsigned int i = 0; i < word.length(); i++) {
		found = findChild(current, word[i]);
		
		if (found == nullptr) {
			found = new Node(word[i]);
			
			found->sibling = current->child;
			current->child = found;
		}
		
		current = found;
	}
	
	current->endWord = true;
}

void Trie::loadFile(std::string fileName) {
	std::ifstream myFile;
	
	myFile.open(fileName);
	
	std::string word;
	
	while (myFile >> word) {
		insert(word);
	}
	
	myFile.close();
}

void Trie::showWords(Node* node, std::string word) {
	if (node->endWord == true) {
		std::cout << word << std::endl;
	}
	
	Node* current = node->child;
	
	while (current != nullptr) {
		showWords(
				  current,
				  word + current->letter
				  );
		
		current = current->sibling;
	}
}

void Trie::search(std::string word) {
	Node* current = root;
	
	for (unsigned int i = 0; i < word.length(); i++) {
		current = findChild(current, word[i]);
		
		if (current == nullptr) {
			return;
		}
	}
	
	showWords(current, word);
}
