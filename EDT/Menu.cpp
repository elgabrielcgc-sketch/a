#ifndef MENU_CPP
#define MENU_CPP

#include <iostream>
#include <windows.h>

#include "Menu.h"

int Menu::show() {
	system("cls");
	
	int option = -1;
	
	std::cout << "-------MENU DE OPCIONES-------" << std::endl;
	std::cout << "1. Registrar un nuevo producto." << std::endl;
	std::cout << "2. Mostrar inventario completo." << std::endl;
	std::cout << "3. Buscar producto por ID." << std::endl;
	std::cout << "4. Actualizar stock." << std::endl;
	std::cout << "5. Eliminar producto." << std::endl;
	std::cout << "0. Salir." << std::endl << std::endl;
	std::cout << "Ingrese opcion: ";
	
	std::cin >> option;
	
	return option;
}

#endif
