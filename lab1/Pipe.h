#pragma once
#include <iostream>
#include <string>

class Pipe
{
public:
	std::string name;
	double length, diametr;
	int repair;

	friend std::istream& operator >> (std::istream& in, Pipe& p);
	friend std::ostream& operator << (std::ostream& out, const Pipe& p);
};

