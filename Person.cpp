#ifndef PERSON_CPP
#define PERSON_CPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include <windows.h>

#include "Helper.h"
#include "Person.h"
#include "Phone.h"

bool Person::insert() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	system("cls");
	
	Helper helper;
	
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	helper.gotoxy(helper.columnWidth * 0, 0);
	std::cout << "INGRESE DNI: ";
	
	helper.gotoxy(helper.columnWidth * 1, 0);
	std::cout << "INGRESE NOMBRE: ";
	
	helper.gotoxy(helper.columnWidth * 2, 0);
	std::cout << "INGRESE APELLIDO: ";
	
	SetConsoleTextAttribute(hConsole, 7);
	
	helper.gotoxy(helper.columnWidth * 0, 1);
	std::getline(std::cin, this->dni);
	
	if(existsByDni(this->dni)) {
		
		system("cls");
		
		std::cout << "El DNI ya existe.";
		
		return false;
	}
	
	this->idPerson = this->dni;
	
	helper.gotoxy(helper.columnWidth * 1, 1);
	std::getline(std::cin, this->firstName);
	
	helper.gotoxy(helper.columnWidth * 2, 1);
	std::getline(std::cin, this->surName);
	
	std::ofstream myFile("person.txt", std::ios::app);
	
	myFile << this->idPerson << "|" << this->dni << "|" << this->firstName << "|" << this->surName << std::endl;
	
	myFile.close();
	
	return true;
}

bool Person::existsByDni(std::string dni) {
	std::ifstream myFile("person.txt");
	
	std::string line, word;
	bool continueLine = false;
	
	while(std::getline(myFile, line)) {
		std::stringstream stream(line);
		
		continueLine = true;
		
		while(std::getline(stream, word, '|')) {
			if(continueLine) {
				continueLine = false;
				continue; 
			}
			
			if(word == dni) {
				return true;
			}
			
			break;
		}
	}
	
	return false;
}

void Person::showData() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	Phone phone;
	
	system("cls");
	
	Helper helper;
	
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	helper.gotoxy(helper.columnWidth * 0, 0);
	std::cout << "DNI ";
	
	helper.gotoxy(helper.columnWidth * 1, 0);
	std::cout << "NOMBRE ";
	
	helper.gotoxy(helper.columnWidth * 2, 0);
	std::cout << "APELLIDO: ";
	
	SetConsoleTextAttribute(hConsole, 7);
	
	std::ifstream myFile("person.txt");
	
	std::string line, word;
	
	unsigned int row = 1, column = 0;
	bool continueLine = false;
	std::string tempDni = "";
	
	while(std::getline(myFile, line)) {
		std::stringstream stream(line);
		
		continueLine = true;
		tempDni = "";
		
		while(std::getline(stream, word, '|')) {
			if(continueLine) {
				continueLine = false;
				continue; 
			}
			
			helper.gotoxy(column, row);
			std::cout << word << std::endl;
			
			if(tempDni == "") {
				tempDni = word;
			}
			
			column += helper.columnWidth;
		}
		
		row += 1;
		column = 0;
		
		helper.gotoxy(column, row);
		
		row += phone.showData(tempDni);
	}
}

void Person::searchByDni() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	system("cls");
	
	Helper helper;
	Phone phone;
	
	std::string searchDni; 
	
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	helper.gotoxy(helper.columnWidth * 0, 0);
	std::cout << "INGRESE DNI: ";
	
	SetConsoleTextAttribute(hConsole, 7);
	
	helper.gotoxy(helper.columnWidth * 0, 1);
	std::getline(std::cin, searchDni);
	
	std::ifstream myFile("person.txt");
	
	std::string id;
	std::string dni;
	std::string name;
	std::string surname;
	
	while (
		   std::getline(myFile, id, '|') &&
		   std::getline(myFile, dni, '|') &&
		   std::getline(myFile, name, '|') &&
		   std::getline(myFile, surname)
	)	{   
		if( dni == searchDni) {
		   
			system("cls");
			
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			
			helper.gotoxy(helper.columnWidth * 0, 0);
			std::cout << "DNI ";
			
			helper.gotoxy(helper.columnWidth * 1, 0);
			std::cout << "NOMBRE ";
			
			helper.gotoxy(helper.columnWidth * 2, 0);
			std::cout << "APELLIDO: ";
			
			SetConsoleTextAttribute(hConsole, 7);
			
			helper.gotoxy(helper.columnWidth * 0, 1);
			std::cout << dni;
			
			helper.gotoxy(helper.columnWidth * 1, 1);
			std::cout << name;
			
			helper.gotoxy(helper.columnWidth * 2, 1);
			std::cout << surname;
			
		   
		    return;
		}
	}
	std::cout<<"No se encontro DNI";
}

#endif
