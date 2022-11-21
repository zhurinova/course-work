#pragma once
#include <iostream>
#include <string>
#include <fstream>

class KC
{
	int id_KC{};

public:
	static int max_id_KC;
	std:: string name_KC;
	int guilds_KC{};
	int work_guilds_KC{};
	double efficiency_KC{};

	void set_id_KC();
	int get_id_KC() const;
	void edit_KC();

	friend std::istream& operator >> (std::istream& in, KC& k);
	friend std::ostream& operator << (std::ostream& out, const KC& k);
	friend std::ifstream& operator >> (std::ifstream& in, KC& k);
	friend std::ofstream& operator << (std::ofstream& out, const KC& k);
};

