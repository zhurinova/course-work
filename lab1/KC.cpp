#include "KC.h"
#include "Utils.h"

using namespace std;

int KC::max_id_KC = 1;

KC::KC() {
	id_KC = KC::max_id_KC;
}

//int KC::get_id_KC() const
//{
//	return id_KC;
//}

void KC:: edit_KC()
{
	cout << "Amount of guilds in work" << endl;
	work_guilds_KC = check_the_number(0, guilds_KC);
}

void KC::load(std::ifstream& fin)
{
	fin >> name_KC;
	fin >> guilds_KC;
	fin >> work_guilds_KC;
	fin >> efficiency_KC;
}

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
	out << "The ID of KC: " << k.id_KC
		<< "\t   The name of KC: " << k.name_KC
		<< "\t   Amount of guilds: " << k.guilds_KC
		<< "\t   Amount of guilds in work: " << k.work_guilds_KC
		<< "\t   Efficiency: " << k.efficiency_KC << " %" << endl;
	return out;
}

ifstream& operator >> (ifstream& in, KC& k)
{
	in >> k.id_KC;
	in >> k.name_KC;
	in >> k.guilds_KC;
	in >> k.work_guilds_KC;
	in >> k.efficiency_KC;
	return in;
}

ofstream& operator << (ofstream& out, const KC& k)
{
	out << k.name_KC << endl
		<< k.guilds_KC << endl
		<< k.work_guilds_KC << endl
		<< k.efficiency_KC << endl;
	return out;
}

