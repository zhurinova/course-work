#include "KC.h"
#include "Utils.h"
#include <iostream>

using namespace std;

istream& operator >> (istream& in, KC& k)
{
	cout << "Enter options of KC, please" << endl;
	cout << "The name of KC" << endl;
	getline(in, k.name);
	cout << "Amount of guilds (0 - 100)" << endl;
	k.guilds = check_the_number(0, 100);
	cout << "Amount of guilds in work (0 - 100)" << endl;
	k.work_guilds = check_the_number(0, k.guilds);
	cout << "Efficiency in percent (0 - 100)" << endl;
	k.efficiency = check_the_number(0.0, 100.0);
	return in;
}

ostream& operator << (ostream& out, const KC& k)
{
	out << "The name of KC: " << k.name
		<< "\t   Amount of guilds: " << k.guilds
		<< "\t   Amount of guilds in work: " << k.work_guilds
		<< "\t   Efficiency: " << k.efficiency << " %" << endl;
	return out;
}
