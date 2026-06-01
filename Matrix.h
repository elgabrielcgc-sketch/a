#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {
private:
	int **matrix;
	unsigned int rows;
	unsigned int columns;
	
public:
	Matrix(unsigned int tempRows, unsigned int tempColumns);
	
	void inputData();
	void showData();
	
	~Matrix();
};

#endif
