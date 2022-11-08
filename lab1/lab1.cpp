#include <iostream>
#include <fstream>
#include <string>
#include "Pipe.h"
#include "KC.h"
#include "Utils.h"

using namespace std;

void menu()
{
	cout << "0. Exit" << endl;
	cout << "1. Create pipe" << endl;
	cout << "2. Create KC" << endl;
	cout << "3. See all objects" << endl;
	cout << "4. Edit pipe" << endl;
	cout << "5. Edit KC" << endl;
	cout << "6. Save" << endl;
	cout << "7. Download" << endl;
	cout << "8. Delete pipe or several pipes" << endl;
	cout << "9. Delete KC or several KCs" << endl;
	cout << "10. Search object" << endl;
	cout << "11. Package pipe's editing " << endl;
	cout << "Choose action" << endl << endl;
}

void edit_pipe(Pipe& p)
{
	cout << "Is pipe under repair?" << endl;
	cout << "0 - no" << endl << "1 - yes" << endl;
	p.repair_pipe = check_the_number(0, 1);
}

void edit_KC(KC& k)
{
	cout << "Amount of guilds in work" << endl;
	k.work_guilds_KC = check_the_number(0, k.guilds_KC);
}

void save(const Pipe& p, const KC& k)
{
	cout << "Enter the file name: " << endl;
	string file_name;
	cin >> ws;
	getline(cin, file_name);
	file_name += ".txt";
	ofstream fout;
	fout.open(file_name, ofstream::out);
	if (!fout.is_open())
	{
		cerr << "File open error" << endl;
	}
	else
	{
		if (!(p.length_pipe == 0))
		{
			fout << "Pipe" << endl << p.name_pipe << endl << p.length_pipe << endl << p.diametr_pipe << endl << p.repair_pipe << endl;
		}
		if (!(k.guilds_KC == 0))
		{
			fout << "KC" << endl << k.name_KC << endl << k.guilds_KC << endl << k.work_guilds_KC << endl << k.efficiency_KC;
		}
	}
	fout.close();
	cout << "Information is saved!" << endl;
}

void load_pipe(ifstream& fin, Pipe& p)
{
	getline(fin, p.name_pipe);
	fin >> p.length_pipe >> p.diametr_pipe >> p.repair_pipe;
}

void load_KC(ifstream& fin, KC& k) 
{
	getline(fin, k.name_KC);
	fin >> k.guilds_KC >> k.work_guilds_KC >> k.efficiency_KC;
}

void load(Pipe& p, KC& k)                    // https://www.youtube.com/watch?v=aUP0eAEIxog
{
	cout << "Enter the file name: " << endl;
	string file_name;
	cin >> ws;
	getline(cin, file_name);
	file_name += ".txt";
	ifstream fin;
	fin.open(file_name, ofstream::in);
	if (!fin.is_open())
	{
		cerr << "file open error" << endl;
	}
	else
	{
		while (!fin.eof())
		{
			string object;
			fin >> ws;
			getline(fin, object);
			if (object == "Pipe")
			{
				load_pipe(fin, p);
			}
			if (object == "KC")
			{
				load_KC(fin, k);
			}
		}
		cout << "Information is uploaded!" << endl;
		fin.close();
	}
}

int main()
{
	Pipe first = { "--", 0, 0, 0 };
	KC second = { "--", 0, 0, 0 };
	while (true) {
		system("cls");
		menu();
		switch (check_the_number(0, 7))
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
			cout << first;
			cout << second;
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
			load(first, second);
			system("pause");
			break;
		default:
			cout << "Program error";
		}
	}
}
