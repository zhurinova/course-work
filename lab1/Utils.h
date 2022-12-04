#pragma once
#include <iostream>
#include <unordered_map>

int get_correct_diametr();

template <typename T>

T check_the_number(T min, T max)
{
	T n = 0;
	while (((std::cin >> n).fail()) || (n < min) || (n > max) || (std::cin.get() != '\n')) {
		std::cin.clear();
		std::cin.ignore(1000000, '\n');
		std::cout << "Enter correct number: ";
	}
	return n;
}

template <typename T>

int check_the_id(std::unordered_map<int, T>& map, int min, int max, int x)
{
	int n;
	while ((std::cin >> n).fail() || n < min || n > max || n == x)
	{
		std::cin.clear();
		std::cin.ignore(1000000, '\n');
		std::cout << "Try again please" << std::endl;
		if (map.count(n) == 0)
			std::cout << "There is no object with this id" << std:: endl;
	}
	return n;
};
