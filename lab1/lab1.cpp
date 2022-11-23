﻿#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <set>
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
		cout << "There is no pipe with this id" << endl;
	else
		return p[id];
}

KC& choose_KC(unordered_map<int, KC>& k)
{
	cout << "Enter KC id: ";
	int id = check_the_number(1, KC::max_id_KC);
	if (k.count(id) == 0)
		cout << "There is no KC with this id" << endl;
	else
		return k[id];
}

void delete_pipe(unordered_map<int, Pipe>& pipe_map)
{
	Pipe p = choose_pipe(pipe_map);
	pipe_map.erase(p.get_id());
}

void delete_KC(unordered_map<int, KC>& KC_map)
{
	KC k = choose_KC(KC_map);
	KC_map.erase(k.get_id());
}

void see_all(unordered_map<int, Pipe>& pipe_map, unordered_map<int, KC>& KC_map)
{
	if (pipe_map.size() != 0)
	{
		for (const auto& [id_pipe, p] : pipe_map)
		{
			cout << p << endl;
		}
	}
	else
		cout << "Input pipes please!" << endl;
	if (KC_map.size() != 0)
	{
		for (const auto& [id_KC, k] : KC_map)
		{
			cout << k << endl;
		}
	}
	else
		cout << "Input KC please!" << endl;
}

void save(unordered_map<int, Pipe>& pipe_map, unordered_map<int, KC>& KC_map)
{
	cout << "Enter the file name: " << endl;
	string file_name;
	cin >> ws;
	getline(cin, file_name);
	file_name += ".txt";
	ofstream fout;
	fout.open(file_name, ofstream::app);   // будем дозаписывать в файл
	if (!fout.is_open())
	{
		cerr << "File open error" << endl;
	}
	else
	{
		if (pipe_map.size() != 0) {
			fout << pipe_map.size() << endl;
			for (const auto& [id_pipe, p] : pipe_map)
				fout << p;
		}
		if (KC_map.size() != 0) {
			fout << KC_map.size() << endl;
			for (const auto& [id_KC, k] : KC_map)
				fout << k;
		}
	fout.close();
	}
}

void load(unordered_map<int, Pipe>& pipe_map, unordered_map<int, KC>& KC_map)
{
	pipe_map.clear();
	KC_map.clear();
	int amount_of_pipe = 0;
	int amount_of_KC = 0;

	cout << "Enter the file name: " << endl;
	string file_name;
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
		fin >> amount_of_pipe;
		for (int i = 0; i < amount_of_pipe; i++)
		{
			Pipe p;
			fin >> p;
			pipe_map[p.get_id()] = p;
		}
		fin >> amount_of_KC;
		for (int i = 0; i < amount_of_KC; i++) {
			KC k;
			fin >> k;
			KC_map[k.get_id()] = k;
		}
		cout << "Information is uploaded!" << endl;
		fin.close();
	}
}

///////////filters

template<typename T>
using filter_for_pipe = bool(*)(const Pipe& p, T param);

bool check_name(const Pipe& p, string param)
{
	return p.name_pipe.find(param) != string::npos;
}

bool check_repair(const Pipe& p, int param)
{
	return p.repair_pipe == param;
}

template<typename T>
set <int> find_pipe_by_filter(const unordered_map<int, Pipe>& pipe_map, filter_for_pipe <T> f, T param)
{
	set <int> res;    
	for (auto& [id_pipe, p] : pipe_map)
	{
		if (f(p, param))
			res.insert(p.get_id());
	}

	if (res.empty())
		cout << "There is no Pipe with this parameter" << endl;

	return res;
}

template<typename T>
using filter_for_KC = bool(*)(const KC& k, T param);

bool check_name(const KC& k, string param)
{
	return k.name_KC.find(param) != string::npos;
}

bool check_percentage(const KC& k, double param)
{
	double not_working = ((double)k.guilds_KC - (double)k.work_guilds_KC)/(double)k.guilds_KC * 100;  //- (double)k.work_guilds_KC) / k.guilds_KC;
	return not_working >= param;
}

template<typename T>
set<int> find_KC_by_filter(const unordered_map<int, KC>& KC_map, filter_for_KC <T> f, T param)
{
	set <int> res;
	for (auto& [id_KC, k] : KC_map)
	{
		if (f(k, param))
			res.insert(k.get_id());
	}

	if (res.empty())
		cout << "There is no KC with this parameter" << endl;

	return res;
}

set <int> find(unordered_map<int, Pipe>& pipe_map)
{
	set <int> result;
	cout << "Find pipes by the: 1 - name, 2 - repair:  " << endl;
	switch (check_the_number(1, 2))
	{
	case 1:
	{
		string name;
		cout << "Find pipe by the name:  " << endl;
		getline(cin, name);
		for (int i : find_pipe_by_filter(pipe_map, check_name, name))
		{
			cout << pipe_map[i];
		}
		result = find_pipe_by_filter(pipe_map, check_name, name);
		system("pause");
		break;
	}
	case 2:
	{
		cout << "Find pipes which: 1 - is working, 0 - under repair " << endl;
		int repair = check_the_number(0, 1);
		for (int i : find_pipe_by_filter(pipe_map, check_repair, repair))
			cout << pipe_map[i];
		result = find_pipe_by_filter(pipe_map, check_repair, repair);
		system("pause");
		break;
	}
	}
	return result;
}

void find_by_filter(unordered_map<int, Pipe>& pipe_map, unordered_map<int, KC>& KC_map)
{
	cout << "Find pipes or KC by filter: 1 - pipes, 2 - KC:  " << endl;
	if (check_the_number(1, 2) == 1)
	{
		find(pipe_map);
	}
	if (check_the_number(1, 2) == 2)
	{
		cout << "Find KS by filter: 1 - name, 2 - percentage of non-working guilds:  " << endl;
		switch (check_the_number(1, 2))
		{
		case 1:
		{
			string name;
			cout << "Find KC by the name:  " << endl;
			getline(cin, name);
			for (int i : find_KC_by_filter(KC_map, check_name, name))
				cout << KC_map[i];
			system("pause");
			break;
		}
		case 2:
		{
			cout << "Find KC by percentage of non-working guilds: " << endl;
			double not_working = check_the_number(0.0, 100.0);
			for (int i : find_KC_by_filter(KC_map, check_percentage, not_working))
				cout << KC_map[i];
			system("pause");
			break;
		}
		}
	}
}

//////////////

void package_pipe_editing(unordered_map<int, Pipe>& pipe_map)
{
	set <int> by_filter = find(pipe_map);
	cout << "Do you want to edit: 1 - all pipes, 2 - several pipes: ";
	if (check_the_number(1, 2) == 1)
	{
		cout << "Enter 1 - to make all pipes work, 2 - to make it under repair";
		if (check_the_number(1, 2) == 1)
		{
			for (auto& id : by_filter)
				pipe_map[id].repair_pipe = 1;
		}
		else
		{
			for (auto& id : by_filter)
				pipe_map[id].repair_pipe = 0;
		}
	}
	else
	{
		set <int> id_vector;
		while (true)
		{
			cout << "Enter id of pipe to edit it or 0 to complete the editing: ";
			int number = check_the_number(0, Pipe::max_id_pipe);
			if (number)
			{
				if (by_filter.count(number) == 0)
					cout << "There is no pipe with this id" << endl;
				else
				{
					int i = 0;
					for (auto& id : id_vector)
					{
						if (number == id)
						{
							i++;
						}
					}
					if (i == 0)
					{
						id_vector.insert(number);
					}
					else
					{
						cout << "You have already edit this pipe" << endl;;
					}
				}
			}
			else
				break;
		}
		for (int i : id_vector)
		{
			if (pipe_map[i].repair_pipe == 1) {
				pipe_map[i].repair_pipe = 0;
			}
			else if (pipe_map[i].repair_pipe == 0){
				pipe_map[i].repair_pipe = 1;
			}
		}
	}
}

int main()
{
	unordered_map <int, Pipe> pipe_map = {};
	unordered_map <int, KC> KC_map = {};
	
	while (true) {
		//system("cls");
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
			pipe_map.insert({p.get_id(), p});
			break;
		}
		case 2:
		{
			KC k;
			cin >> k;
			//KC_map[k.get_id()] = k;
			KC_map.insert({ k.get_id(), k });
			break;
		}
		case 3:
		{
			see_all(pipe_map,KC_map);
			system("pause");
			break;
		}
		case 4:
		{
			if (pipe_map.size() > 0)
			{
				choose_pipe(pipe_map).edit_pipe();
			}
			else cout << "Input Pipe please" << endl;
			system("pause");
			break;
		}
		case 5:
		{
			if (KC_map.size() > 0)
			{
				choose_KC(KC_map).edit_KC();
			}
			else cout << "Input KC please" << endl;
			system("pause");
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
			system("pause");
			break;
		}
		case 9:
		{
			if (KC_map.size() > 0)
			{
				delete_KC(KC_map);
			}
			else cout << "There is no KC!" << endl;
			system("pause");
			break;
		}
		case 10:
		{
			find_by_filter(pipe_map,KC_map);
			break;
		}
		case 11:
		{
			package_pipe_editing(pipe_map);
			system("pause");
			break;
		}
		default:
			cout << "Program error";
		}
	}
	return 0;
}