#pragma once
#include <iostream>

template <typename T>

T check_the_number(T min, T max)
{
	T n;
	while (((std::cin >> n).fail()) || (n < min) || (n > max) || (std::cin.get() != '\n')) {
		std::cin.clear();
		std::cin.ignore(1000000, '\n');
		std::cout << "Enter correct number: ";
	}
	return n;
}