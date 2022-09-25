#include <iostream>
using namespace std;

void menu()
{
	cout << "0.Exit" << endl;
	cout << "1.Add pipe" << endl;
	cout << "2.Add KC" << endl;
	cout << "3.See all objects" << endl;
	cout << "4.Edit pipe" << endl;
	cout << "5.Edit KC" << endl;
	cout << "6.Save" << endl;
	cout << "7.Download" << endl;
	cout << "" << endl;
}

int exit()
{
	cout << "Goodbye" << endl;
	return 0;
}

struct Pipe
{
	double length = 0, diametr = 0;
	string repair;
};

Pipe create_pipe()
{
	Pipe p;
	cout << "Enter options of pipe" << endl;
	cout << "Length" << endl; 
	cin >> p.length;
	cout << "Diameter" << endl;
	cin >> p.diametr;
	cout << "Under repair (yes/no)" << endl;
	repair();
	return p;
}

void repair()
{
	Pipe p;
	bool repair = false;
	cin >> p.repair;
	while (true) {
		if (p.repair == "yes") {
			repair = true;
			break;
		}
		else if (p.repair == "no") {
			repair = false;
			break;
		}
		else {
			cout << "Enter yes or no, please" << endl;
			cin >> p.repair;
		}
	}
}

struct KC
{
	int guilds;
	double efficiency = 0;
	string name;
};

KC create_KC()
{
	KC k;
	cout << "Enter options of KC" << endl;
	cout << "The name of KC" << endl;
	cin >> k.name;
	cout << "Amount of guilds" << endl;
	cin >> k.guilds;
	cout << "Efficiency in percent" << endl;
	cin >> k.efficiency;
	return k;
}

void see_all(Pipe p, KC k)
{
	cout << "Length:" << p.length
		<< "\tDiameter:" << p.diametr
		<< "\tUnder repair:" << p.repair << endl;

	cout << "The name of KC:" << k.name
		<< "\tAmount of guilds" << k.guilds
		<< "\tEfficiency in percent" << k.efficiency << endl;
}

void edit_pipe(Pipe p)
{
	cout << "What do you want to edit: 1. Length   2. Diametr   3. Under repair" << endl;
	int number;
	cin >> number;
	switch (number)
	{
	case 1:
		cin >> p.length;
		break;
	case 2:
		cin >> p.diametr;
		break;
	case 3:
		repair();
		break;
	}
}

int main()
{
	menu();
	int number;
	cin >> number;
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Enter number again, please" << endl;
		cin >> number;
	}
	if (number < 0 || number > 7)      //+ проверка на ввод только целого числа
	{
		cout << "Enter number again, please" << endl;
	}
	switch (number)
	{
	case 0:
		exit();
		break;
	case 1:
		create_pipe();
		break;
	case 2:	
	    create_KC();
		break;
	case 3:
		break;
	default:
		return 1;
	}
}

