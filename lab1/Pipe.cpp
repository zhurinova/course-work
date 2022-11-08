#include "Pipe.h"
#include "Utils.h"

using namespace std;

istream& operator >> (istream& in, Pipe& p)   // пользовательский опeратор на вход, который будет принимать тип труба
{
	cout << "Enter the options of Pipe, please" << endl;
	cout << "The name of Pipe" << endl;
	getline(in, p.name);
	cout << "Length (0 - 100 000)" << endl;
	p.length = check_the_number(1.0, 100000.0);
	cout << "Diameter (0 - 200)" << endl;
	p.diametr = check_the_number(1.0, 200.0);
	cout << "Under repair (yes = 1 / no = 0)" << endl;
	p.repair = check_the_number(0, 1);
	return in;
}

ostream& operator << (ostream& out, const Pipe& p)
{
	out <<"The name of Pipe: " << p.name
		<< "\t           Length: " << p.length
		<< "\t           Diameter: " << p.diametr
		<< "\t           Under repair: " << p.repair << "  (0 - no, 1 - yes)" << endl;
	return out;
}