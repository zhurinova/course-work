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
	Pipe::max_id_pipe = 1;
	KC::max_id_KC = 1;
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
			p.load(fin);
			pipe_map[Pipe::max_id_pipe++] = p;
		}
		fin >> amount_of_KC;
		for (int i = 0; i < amount_of_KC; i++) {
			KC k;
			k.load(fin);
			KC_map[KC::max_id_KC++] = k;
		}
		cout << "Information is uploaded!" << endl;
		fin.close();
	}
}

template<typename T>
using filter_for_pipe = bool(*)(const Pipe& p, T param);

bool check_name(const Pipe& p, string param)
{
	return p.name_pipe == param;
}

bool check_repair(const Pipe& p, int param)
{
	return p.repair_pipe == param;
}

template<typename T>
vector <int> find_pipe_by_filter(const unordered_map<int, Pipe>& pipe_map, filter_for_pipe <T> f, T param)
{
	vector <int> res;
	int i = 0;
	for (auto& p : pipe_map)
	{
		if (f(p.second, param))
			res.push_back(p.first);
		i++;
	}

	if (res.empty())
		cout << "There is no Pipe with this parameter" << endl;

	return res;
}

template<typename T>
using filter_for_KC = bool(*)(const KC& k, T param);

bool check_name(const KC& k, string param)
{
	return k.name_KC == param;
}

bool check_percentage(const KC& k, double param)
{
	double not_working = ((double)k.guilds_KC - (double)k.work_guilds_KC)/(double)k.guilds_KC * 100;  //- (double)k.work_guilds_KC) / k.guilds_KC;
	return not_working >= param;
}

template<typename T>
vector <int> find_KC_by_filter(const unordered_map<int, KC>& KC_map, filter_for_KC <T> f, T param)
{
	vector <int> res;
	int i = 0;
	for (auto& k : KC_map)
	{
		if (f(k.second, param))
			res.push_back(k.first);
		i++;
	}

	if (res.empty())
		cout << "There is no KC with this parameter" << endl;

	return res;
}

void package_pipe_editing(unordered_map<int, Pipe>& pipe_map)
{
	cout << "Do you want to edit: 1 - all pipes, 2 - several pipes: ";
	if (check_the_number(1, 2) == 1)
	{
		cout << "Enter 1 - to make all pipes work, 2 - to make it under repair: ";
		if (check_the_number(1, 2) == 1)
		{
			for (auto& p : pipe_map)
				p.second.repair_pipe = 1;
		}
		else
		{
			for (auto& p : pipe_map)
				p.second.repair_pipe = 0;
		}
	}
	else
	{
		vector <int> id_vector;
		while (true)
		{
			cout << "Enter id of pipe to edit it or 0 to complete: ";
			int number = check_the_number(0, Pipe:: max_id_pipe);
			if (number)
			{
				if (pipe_map.count(number) == 0)
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
						id_vector.push_back(number);
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
			pipe_map[Pipe::max_id_pipe++] = p;
			break;
		}
		case 2:
		{
			KC k;
			cin >> k;
			KC_map[KC::max_id_KC++] = k;
			break;
		}
		case 3:
		{
			if ((pipe_map.size() != 0) && (KC_map.size() == 0))
			{
				for (const auto& [id_pipe, p] : pipe_map)
				{
					cout << p << endl;
				}
			}
			else if ((pipe_map.size() == 0) && (KC_map.size() != 0))
			{
				for (const auto& [id_KC, k] : KC_map)
				{
					cout << k << endl;
				}
			}
			else if ((pipe_map.size() != 0) && (KC_map.size() != 0))
			{
				for (const auto& [id_pipe, p] : pipe_map)
				{
					cout << p << endl;
				}
				for (const auto& [id_KC, k] : KC_map)
				{
					cout << k << endl;
				}
			}
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
			break;
		}
		case 5:
		{
			if (KC_map.size() > 0)
			{
				choose_KC(KC_map).edit_KC();
			}
			else cout << "Input KC please" << endl;
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
			else cout << "There is no KC" << endl;
			break;
		}
		case 10:
		{
			cout << "Find pipes or KC by filter: 1 - pipes, 2 - KC:  " << endl;
			if (check_the_number(1, 2) == 1)
			{
				cout << "Find pipes by the: 1 - name, 2 - repair:  " << endl;
				switch (check_the_number(1, 2))
				{
				case 1:
				{
					string name;
					cout << "Find pipe by the name:  " << endl;
					getline(cin, name);
					for (int i : find_pipe_by_filter(pipe_map, check_name, name))
						cout << pipe_map[i];
					system("pause");
					break;
				}
				case 2:
				{
					cout << "Find pipes which: 1 - is working, 0 - under repair " << endl;
					int repair = check_the_number(0, 1);
					for (int i : find_pipe_by_filter(pipe_map, check_repair, repair))
						cout << pipe_map[i];
					system("pause");
					break;
				}
				}
			}
			else
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