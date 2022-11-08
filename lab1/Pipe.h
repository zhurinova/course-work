#pragma once
#include <iostream>
#include <string>

class Pipe
{
public:
	std::string name_pipe;
	double length_pipe, diametr_pipe;
	int repair_pipe;

	friend std::istream& operator >> (std::istream& in, Pipe& p);
	friend std::ostream& operator << (std::ostream& out, const Pipe& p);
};

