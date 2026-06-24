#include <iostream>

#include "Menu.h"
#include "SimpleList.h"
#include "Product.h"

// ?? CALLBACK: comparar por ID
bool compareProductId(Product& product, int id) {
	return product.id == id;
}

// ?? CALLBACK: mostrar producto
void showProduct(Product& product) {
	product.show();
}

int main(int argc, char *argv[]) {
	
	Menu menu;
	SimpleList<Product> simpleList;
	Product product;
	
	int selectedOption = -1;
	int idTemp = -1;
	
	do {
		selectedOption = menu.show();
		
		switch(selectedOption) {
			
		case 0:
			return 0;
			
		case 1:
			product.insert();
			
			if(simpleList.exists(compareProductId, product.id)) {
				std::cout << "El Id ingresado ya se encuentra registrado.\n\n";
				system("pause");
			} else {
				simpleList.insert(product);
			}
			break;
			
		case 2:
			simpleList.show(showProduct);
			system("pause");
			break;
			
		case 3:
			std::cout << "Ingrese el Id buscado: ";
			std::cin >> idTemp;
			
			simpleList.showById(compareProductId, showProduct, idTemp);
			system("pause");
			break;
			
		case 4:
			std::cout << "Actualizacion de stock no implementada.\n";
			system("pause");
			break;
			
		case 5:
			std::cout << "Eliminacion no implementada.\n";
			system("pause");
			break;
			
		case 6:
			std::cout << "Opcion no implementada.\n";
			system("pause");
			break;
		}
		
	} while(selectedOption != 0);
	
	return 0;
}
