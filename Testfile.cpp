#include "HList.h"
#include <iostream>

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
	return 0;
}