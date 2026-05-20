#ifndef HELPER_CPP
#define HELPER_CPP

#include <iostream>
#include <string>

#include <windows.h>

#include "Helper.h"

void Helper::gotoxy(int x, int y) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { (SHORT)x, (SHORT)y };
	
	SetConsoleCursorPosition(hConsole, pos);
}

int Helper::showMenu() {
	system("cls");
	
	std::string tempOption;
	
	std::cout << "--------------MENU--------------" << std::endl;
	std::cout << "1. Registrar persona" << std::endl;
	std::cout << "2. Registrar nro de celular" << std::endl;
	std::cout << "3. Mostrar datos" << std::endl;
	std::cout << "4. Buscar persona por DNI" << std::endl;
	std::cout << "5. Eliminar nro de celuar de una persona" << std::endl;
	std::cout << "0. Salir" << std::endl << std::endl;
	
	std::cout << "Ingrese opcion: ";
	std::getline(std::cin, tempOption);
	
	return std::stoi(tempOption);
}

#endif
