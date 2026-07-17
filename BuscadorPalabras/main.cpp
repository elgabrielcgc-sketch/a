#include <iostream>
#include <string>

#include "Trie.h"

int main() {
	Trie trie;
	
	trie.loadFile("vocabulary.txt");
	
	std::string word;
	
	std::cout << "Corrector de palabras" << std::endl<< std::endl;
	std::cout << "Buscar: ";
	
	std::cin >> word;
	std::cout << std::endl;
	
	trie.search(word);
	
	return 0;
}
