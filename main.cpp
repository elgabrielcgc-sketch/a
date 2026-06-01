#include "Matrix.h"

int main() {
	
	unsigned int rows;
	unsigned int columns;
	
	std::cout << "Ingrese numero de filas: ";
	std::cin >> rows;
	
	std::cout << "Ingrese numero de columnas: ";
	std::cin >> columns;
	
	Matrix matrix(rows, columns);
	
	matrix.inputData();
	
	std::cout << std::endl;
	std::cout << "MATRIZ INGRESADA" << std::endl;
	std::cout << "----------------" << std::endl;
	
	matrix.showData();
	
	return 0;
}
