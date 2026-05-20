#include<iostream>

#include "Helper.h"
#include "Person.h"
#include "Phone.h"

int main (int argc, char *argv[]) {
	Helper helper;
	Person person;
	Phone phone;
	
	unsigned int option;
	
	do {
		option = helper.showMenu();
		
		switch(option) {
		case 1:
			if(person.insert()) {
				std::cout << std::endl << "Registro realizado correctamente.";
				
				break;
			}
			
			std::cout << std::endl << "El registro no pudo realizarse, verifique los datos.";
			
			break;
			
		case 2:
			phone.insert();
			
			break;
			
		case 3:
			person.showData();
			
			break;
			
		case 4:
			person.searchByDni();
			
			break;
			
		case 5:
			
			phone.removePhone();
			
			break;
			
		case 0: return 0;
		}
		
		std::cout << std::endl << std::endl;
		system("pause");
	} while(option != 0);
	
	return 0;
}
