#ifndef TRIE_H
#define TRIE_H

#include <string>

class Trie {
private:
	struct Node {
		char letter;
		bool endWord;
		Node* child;
		Node* sibling;
		
		Node(char value = '\0') {
			letter = value;
			endWord = false;
			child = nullptr;
			sibling = nullptr;
		}
	};
	
	Node* root;
	Node* findChild(Node* node, char letter);
	void showWords(Node* node, std::string word);
	
public:
	Trie();
	
	void insert(std::string word);
	void loadFile(std::string fileName);
	void search(std::string word);
};

#endif
