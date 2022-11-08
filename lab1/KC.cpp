#include "KC.h"
#include "Utils.h"
#include <iostream>

using namespace std;

istream& operator >> (istream& in, KC& k)
{
	cout << "Enter options of KC, please" << endl;
	cout << "The name of KC" << endl;
	getline(in, k.name_KC);
	cout << "Amount of guilds (0 - 100)" << endl;
	k.guilds_KC = check_the_number(0, 100);
	cout << "Amount of guilds in work (0 - 100)" << endl;
	k.work_guilds_KC = check_the_number(0, k.guilds_KC);
	cout << "Efficiency in percent (0 - 100)" << endl;
	k.efficiency_KC = check_the_number(0.0, 100.0);
	return in;
}

ostream& operator << (ostream& out, const KC& k)
{
	out << "The name of KC: " << k.name_KC
		<< "\t   Amount of guilds: " << k.guilds_KC
		<< "\t   Amount of guilds in work: " << k.work_guilds_KC
		<< "\t   Efficiency: " << k.efficiency_KC << " %" << endl;
	return out;
}
