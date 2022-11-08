#pragma once
#include <iostream>
#include <string>

class KC
{
public:
		std:: string name_KC;
		int guilds_KC{}, work_guilds_KC{};
		double efficiency_KC{};

		friend std::istream& operator >> (std::istream& in, KC& k);
		friend std::ostream& operator << (std::ostream& out, const KC& k);

};

