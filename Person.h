#ifndef PERSON_H
#define PERSON_H

#include <string>

#include "Phone.h"

class Person {
public:
	std::string idPerson;
	std::string firstName;
	std::string surName;
	std::string dni;
	
	Phone phone[100];
	
	bool insert();
	bool existsByDni(std::string dni);
	
	void showData();
	
	void searchByDni();
	
};

#endif
