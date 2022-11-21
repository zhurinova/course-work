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
	cout << "8. Delete pipe" << endl;
	cout << "9. Delete KC" << endl;
	cout << "10. Search object" << endl;
	cout << "11. Package pipe's editing " << endl;
	cout << "Choose action" << endl << endl;
}

Pipe& choose_pipe(unordered_map<int, Pipe>& p)
{
	cout << "Enter pipe id: ";
	int id = check_the_number(1, Pipe::max_id_pipe);
	if (p.count(id) == 0)
		cout << "There is no pipe with this id\n";
	else
		return p[id];
}

KC& choose_KC(unordered_map<int, KC>& k)
{
	cout << "Enter KC id: ";
	int id = check_the_number(1, KC::max_id_KC);
	if (k.count(id) == 0)
		cout << "There is no KC with this id\n";
	else
		return k[id];
}

void delete_pipe(unordered_map<int, Pipe>& p)
{
	cout << "Enter Pipe id: ";
	int id = check_the_number(1, Pipe::max_id_pipe);
	if (p.count(id) == 0)
		cout << "There is no Pipe with this id\n";
	else
		p.erase(id);
}

void delete_KC(unordered_map<int, KC>& k)
{
	cout << "Enter KC id: ";
	int id = check_the_number(1, KC::max_id_KC);
	if (k.count(id) == 0)
		cout << "There is no KC with this id\n";
	else
		k.erase(id);
}

void save(unordered_map<int, Pipe>& pipe_map, unordered_map<int, KC>& KC_map)
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
		fout << "Pipe" << endl;
		fout << pipe_map.size() << endl;
		for (const auto& [id_pipe, p] : pipe_map)
			fout << p;
		fout << "KC" << endl;
		fout << KC_map.size() << endl;
		for (const auto& [id_KC, k] : KC_map)
			fout << k;
		fout.close();
	}
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

void load(unordered_map<int, Pipe>& pipe_map, unordered_map<int, KC>& KC_map)
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
		cerr << "File open error" << endl;
	}
	else
	{
		while (!fin.eof())
		{
			string object;
			fin >> ws;
			getline(fin, object);
			int amount_of_pipe;
			int amout_of_KC;
			if (object == "Pipe")
			{
				fin >> amount_of_pipe;
				if (amount_of_pipe > 0)
				{
					Pipe p;
					p.load(fin);
					pipe_map.emplace(p.max_id_pipe, p);
				}
				if (object == "KC")
				{
					KC k;
					load_KC(fin, k);
				}
			}
			cout << "Information is uploaded!" << endl;
			fin.close();
		}
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
		switch (check_the_number(0, 11))
		{
		case 0:
		{
			cout << "Goodbye!\n" << endl;
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
		case 4:
		{
			if (pipe_map.size() > 0)
			{
				choose_pipe(pipe_map).edit_pipe();
			}
			else cout << "" << endl;
			break;
		}
		case 5:
		{
			if (KC_map.size() > 0)
			{
				choose_KC(KC_map).edit_KC();
			}
			else cout << "" << endl;
			break;
		}
		case 6:
			save(pipe_map, KC_map);
			break;
		case 7:
			load(pipe_map, KC_map);
			system("pause");
			break;
		case 8:
		{
			if (pipe_map.size() > 0)
			{
				delete_pipe(pipe_map);
			}
			else cout << "There is no Pipe!" << endl;
			break;
		}
		case 9:
		{
			if (KC_map.size() > 0)
			{
				delete_KC(KC_map);
			}
			else cout << "There is no KC!" << endl;
			break;
		}
		case 10:
		{

		}
		case 11:
		{

		}
		default:
			cout << "Program error";
		}
	}
	return 0;
}