#ifndef PRODUCT_CPP
#define PRODUCT_CPP

#include <iostream>

#include "Product.h"

void Product::insert() {
	std::cout << "Ingrese el Id del producto: ";
	std::cin >> id;
	std::cin.ignore();
	std::cout << "Ingrese el Nombre del producto: ";
	std::getline(std::cin, productName);
	std::cout << "Ingrese el Stock del producto: ";
	std::cin >> stockQuantity;
	std::cout << "Ingrese el Precio unitario del producto: ";
	std::cin >> price;
}

void Product::show() {
	std::cout << std::endl;
	std::cout << "Id\t\t: " <<  id << std::endl;
	std::cout << "Nombre\t\t: " <<  productName << std::endl;
	std::cout << "Stock\t\t: " <<  stockQuantity << std::endl;
	std::cout << "Precio U.\t: " <<  price << std::endl;
	std::cout << "Precio T.\t: " <<  price * stockQuantity << std::endl;
}

bool Product::isId(int id) {
	return this->id == id;
}

#endif
