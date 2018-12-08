#include "HList.h"
#include <iostream>

void f(){

	std::cout << "Nu imi place la Litrughie" << std::endl;

	HList Varabila;

	std::cout << "Diriga e o pocaita nebuna(not even joking)" << std::endl;


}

int main() {

	std::cout << "Nu imi place la Litrughie" << std::endl;

	HList Variabla;
	std::string item1;
	std::string item2;

	while(std::getline(std::cin, item1)) {
		std::getline(std::cin, item2);
		Variabla.addElement(std::stoi(item1), std::stoi(item2));
		Variabla.print_list();
	}
	

	std::cout << "Diriga e o pocaita nebuna(not even joking)" << std::endl;


	return 0;
}

// Nu imi place la Litrughie
// HList created.
// Nu imi place la Litrughie
// HList created.
// Diriga e o pocaita nebuna(not even joking)
// HList destroyed.
// Diriga e o pocaita nebuna(not even joking)
// HList destroyed.
