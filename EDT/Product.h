#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
public:
	Product() {}
	
	int id;
	std::string productName;
	int stockQuantity;
	float price;
	
	void insert();
	void show();
	bool isId(int id);
};

#endif
