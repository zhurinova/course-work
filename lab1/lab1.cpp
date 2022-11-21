#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
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

Pipe& choose_pipe(unordered_map<int, Pipe>& p)
{
	cout << "Enter pipe id: ";
	int id = check_the_number(1, Pipe::max_id_pipe);
	if (p.count(id) == 0)
		cout << "ERROR! There is no pipe with this id\n";
	else
		return p[id];
}

KC& choose_KC(unordered_map<int, KC>& k)
{
	cout << "Enter compressor station id: ";
	int id = check_the_number(1, KC::max_id_KC);
	if (k.count(id) == 0)
		cout << "ERROR! There is no compressor station with this id\n";
	else
		return k[id];
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
	unordered_map <int, Pipe> pipe_map = {};
	unordered_map <int, KC> KC_map = {};
	
	Pipe first;
	KC second;
	while (true) {
		system("cls");
		menu();
		switch (check_the_number(0, 7))
		{
		case 0:
		{
			cout << "Goodbye!\n" << endl;
			return 0;
			break;
		}
		case 1:
		{
			Pipe p;
			cin >> p;
			pipe_map.emplace(p.max_id_pipe, p);
			break;
		}
		case 2:
		{
			KC k;
			cin >> k;
			KC_map.emplace(k.max_id_KC, k);
			break;
		}
		case 3:
		{
			if ((pipe_map.size() != 0) && (KC_map.size() == 0))
			{
				for (const auto& [id_pipe, p] : pipe_map)
				{
					cout << id_pipe;
					cout << p << endl;
				}
			}
			else if ((pipe_map.size() == 0) && (KC_map.size() != 0))
			{
				for (const auto& [id_KC, k] : KC_map)
				{
					cout << id_KC;
					cout << k << endl;
				}
			}
			else if ((pipe_map.size() != 0) && (KC_map.size() != 0))
			{
				for (const auto& [id_pipe, p] : pipe_map)
				{
					cout << id_pipe;
					cout << p << endl;
				}
				for (const auto& [id_KC, k] : KC_map)
				{
					cout << id_KC;
					cout << k << endl;
				}
			}
			else cout << "Please create objects" << endl;
			system("pause");
			break;
		}
		break;
		case 4:
		{
			if (pipe_map.size() > 0)
			{
				choose_pipe(pipe_map).edit_pipe();
			}
			else cout << "Before editing pipe you should INPUT pipe" << endl;
			break;
		}
			break;
		case 5:
		{
			if (KC_map.size() > 0)
			{
				choose_KC(KC_map).edit_KC();
			}
			else cout << "Before editing compressor station you should INPUT compressor station" << endl;
			break;
		}
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