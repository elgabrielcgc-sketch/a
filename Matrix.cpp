#ifndef MATRIX_CPP
#define MATRIX_CPP

#include "Matrix.h"

Matrix::Matrix(unsigned int tempRows, unsigned int tempColumns) {
	
	rows = tempRows;
	columns = tempColumns;
	
	matrix = new int*[rows];
	
	for(unsigned int i = 0; i < rows; i++) {
		
		*(matrix + i) = new int[columns];
	}
}

void Matrix::inputData() {
	
	for(unsigned int i = 0; i < rows; i++) {
		
		for(unsigned int j = 0; j < columns; j++) {
			
			std::cout << "Ingrese valor [" << i << "][" << j << "]: ";
			
			std::cin >> *(*(matrix + i) + j);
		}
	}
}

void Matrix::showData() {
	
	std::cout << std::endl;
	
	for(unsigned int i = 0; i < rows; i++) {
		
		for(unsigned int j = 0; j < columns; j++) {
			
			std::cout << *(*(matrix + i) + j) << "\t";
		}
		
		std::cout << std::endl;
	}
}

Matrix::~Matrix() {
	
	for(unsigned int i = 0; i < rows; i++) {
		
		delete[] *(matrix + i);
	}
	
	delete[] matrix;
}

#endif
