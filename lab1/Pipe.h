#pragma once
#include <iostream>
#include <string>
#include <fstream>

class Pipe
{
	int id_pipe{};

public:
	static int max_id_pipe;
	std::string name_pipe;
	double length_pipe{};
	double diametr_pipe{};
	int repair_pipe{};

	void set_id_pipe();
	int get_id_pipe() const;
	void edit_pipe();

	friend std::istream& operator >> (std::istream& in, Pipe& p);
	friend std::ostream& operator << (std::ostream& out, const Pipe& p);
	friend std::ifstream& operator >> (std::ifstream& in, Pipe& p);
	friend std::ofstream& operator << (std::ofstream& out, const Pipe& p);
};