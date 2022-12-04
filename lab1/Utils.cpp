#include "Utils.h"

int get_correct_diametr()
{
	int n;
	while (((std::cin >> n).fail()) || ((n !=500 ) && ( n!= 700) && (n != 1400)) || (std::cin.get() != '\n')) {
		std::cin.clear();
		std::cin.ignore(1000000, '\n');
		std::cout << "Enter correct number: ";
	}
	return n;
}