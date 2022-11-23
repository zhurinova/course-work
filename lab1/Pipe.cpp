#include "Pipe.h"
#include "Utils.h"

using namespace std;

int Pipe::max_id_pipe = 0;

Pipe::Pipe()
{
	id_pipe = ++Pipe::max_id_pipe;
}

int Pipe::get_id() const
{
	return id_pipe;
}

void Pipe:: edit_pipe()
{
	cout << "Is pipe under repair?" << endl;
	cout << "0 - no" << endl << "1 - yes" << endl;
	repair_pipe = check_the_number(0, 1);
}

istream& operator >> (istream& in, Pipe& p)   // пользовательский опeратор на вход, который будет принимать тип труба
{
	cout << "Enter the options of Pipe, please" << endl;
	cout << "The name of Pipe" << endl;
	getline(in, p.name_pipe);
	cout << "Length (0 - 100 000)" << endl;
	p.length_pipe = check_the_number(1.0, 100000.0);
	cout << "Diameter (0 - 200)" << endl;
	p.diametr_pipe = check_the_number(1.0, 200.0);
	cout << "Under repair (yes = 1 / no = 0)" << endl;
	p.repair_pipe = check_the_number(0, 1);
	return in;
}

ostream& operator << (ostream& out, const Pipe& p)
{
	out << "The ID of Pipe: " << p.id_pipe
	    << "\t           The name of Pipe: " << p.name_pipe
		<< "\t           Length: " << p.length_pipe
		<< "\t           Diameter: " << p.diametr_pipe
		<< "\t           Under repair: " << p.repair_pipe << "  (0 - no, 1 - yes)" << endl;
	return out;
}

ifstream& operator >> (ifstream& in, Pipe& p)
{
	in >> p.id_pipe;
	in >> p.name_pipe;
	in >> p.length_pipe;
	in >> p.diametr_pipe;
	in >> p.repair_pipe;
	return in;
}

ofstream& operator << (ofstream& out, const Pipe& p)
{
	out << p.id_pipe << endl
		<< p.name_pipe << endl
		<< p.length_pipe << endl
		<< p.diametr_pipe << endl
		<< p.repair_pipe << endl;
	return out;
}
