#pragma once
#include <iostream>
#include <string>
#include <fstream>

class KC
{
	int id_KC;

public:
	KC();
	void edit_KC();
	int get_id() const;

	static int max_id_KC;
	std:: string name_KC;
	int guilds_KC{};
	int work_guilds_KC{};
	double efficiency_KC{};
	int degree_of_income = 0;
	int degree_of_outcome = 0;

	friend std::istream& operator >> (std::istream& in, KC& k);
	friend std::ostream& operator << (std::ostream& out, const KC& k);
	friend std::ifstream& operator >> (std::ifstream& in, KC& k);
	friend std::ofstream& operator << (std::ofstream& out, const KC& k);
};

