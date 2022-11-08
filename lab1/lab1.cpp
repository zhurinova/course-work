﻿#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void menu()
{
	cout << "0.Exit" << endl;
	cout << "1.Create pipe" << endl;
	cout << "2.Create KC" << endl;
	cout << "3.See all objects" << endl;
	cout << "4.Edit pipe" << endl;
	cout << "5.Edit KC" << endl;
	cout << "6.Save" << endl;
	cout << "7.Download" << endl << endl;
}

template <typename T>

T check(T min, T max)
{
	T n;
	while (((cin >> n).fail()) || (n < min) || (n > max) || (cin.get() != '\n')) {
		cin.clear();
		cin.ignore(1000000, '\n');
		cout << "Enter correct number: ";
	}
	return n;
}

struct Pipe
{
	double length{}, diametr{};
	int repair{};
};
//поток по ссылке
istream& operator >> (istream& in, Pipe& p)   // пользовательский опeратор на вход, который будет принимать тип труба
{
	cout << "Enter options of pipe" << endl;
	cout << "Length (0 - 100 000)" << endl;
	p.length = check(1.0, 100000.0);
	cout << "Diameter (0 - 200)" << endl;
	p.diametr = check(1.0, 200.0);
	cout << "Under repair (yes = 1 / no = 0)" << endl;
	p.repair = check(0, 1);
	return in;
}

struct KC
{
	string name;
	int guilds{}, work_guilds{};
	double efficiency{};
};

istream& operator >> (istream& in, KC& k)
{
	cout << "Enter options of KC" << endl;
	cout << "The name of KC" << endl;
	getline(in, k.name);
	cout << "Amount of guilds (0 - 100)" << endl;
	k.guilds = check(0, 100);
	cout << "Amount of guilds in work (0 - 100)" << endl;
	k.work_guilds = check(0, k.guilds);
	cout << "Efficiency in percent (0 - 100)" << endl;
	k.efficiency = check(0.0, 100.0);
	return in;
}

ostream& operator >> (ostream& out, Pipe& p)
{
	out << "Length: " << p.length
		<< "\t           Diameter: " << p.diametr
		<< "\t           Under repair: " << p.repair << "  (0 - no, 1 - yes)" << endl;
	return out;
}

ostream& operator >> (ostream& out, KC& k)
{
	out << "The name of KC: " << k.name
		<< "\t   Amount of guilds: " << k.guilds
		<< "\t   Amount of guilds in work: " << k.work_guilds
		<< "\t   Efficiency: " << k.efficiency << " %" << endl;
	return out;
}

void edit_pipe(Pipe& p)
{
	cout << "Is pipe under repair?" << endl;
	cout << "0 - no" << endl << "1 - yes" << endl;
	p.repair = check(0, 1);
}

void edit_KC(KC& k)
{
	cout << "Amount of guilds in work" << endl;
	k.work_guilds = check(0, k.guilds);
}

void save(Pipe p, KC k)
{
	ofstream fout;
	fout.open("File.txt", ofstream::out);
	if (!fout.is_open())
	{
		cout << "file open error" << endl;
	}
	else
	{
		fout << k.name << endl << p.length << endl << p.diametr << endl << p.repair << endl;
		fout << k.guilds << endl << k.work_guilds << endl << k.efficiency;
	}
	fout.close();
}

void download(Pipe& p, KC& k)                    // https://www.youtube.com/watch?v=aUP0eAEIxog
{
	ifstream fin;
	fin.open("File.txt", ofstream::in);
	if (!fin.is_open())
	{
		cout << "file open error" << endl;
	}
	else
	{
		getline(fin, k.name);
		fin >> p.length >> p.diametr >> p.repair;
		fin >> k.guilds >> k.work_guilds >> k.efficiency;
	}
	fin.close();

	cout << "Length: " << p.length
		<< "\t        Diameter: " << p.diametr
		<< "\t                Under repair: " << p.repair << "  (0 - no, 1 - yes)" << endl;

	cout << "The name of KC: " << k.name
		<< "\tAmount of guilds: " << k.guilds
		<< "\tAmount of guilds in work: " << k.work_guilds
		<< "\tEfficiency: " << k.efficiency << " %" << endl << endl;
}

int main()
{
	Pipe first = { 0, 0, 0 };
	KC second = { "--",0,0,0 };
	while (true) {
		system("cls");
		menu();
		switch (check(0, 7))
		{
		case 0:
			cout << "Goodbye!\n" << endl;
			return 0;
			break;
		case 1:
			cin >> first;
			break;
		case 2:
			cin >> second;
			break;
		case 3:
			cout >> first;
			cout >> second;
			system("pause");
			break;
		case 4:
			edit_pipe(first);
			break;
		case 5:
			edit_KC(second);
			break;
		case 6:
			save(first, second);
			break;
		case 7:
			download(first, second);
			system("pause");
			break;
		default:
			cout << "Program error";
		}
	}
}
