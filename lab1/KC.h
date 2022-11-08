#pragma once
#include <iostream>
#include <string>

class KC
{
public:
		std:: string name;
		int guilds{}, work_guilds{};
		double efficiency{};

		friend std::istream& operator >> (std::istream& in, KC& k);
		friend std::ostream& operator << (std::ostream& out, const KC& k);

};

