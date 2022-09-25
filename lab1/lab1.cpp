#include <iostream>
#include <string>
#include <fstream>
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
	cout << "7.Download" << endl;
	cout << "" << endl;
}

int exit()
{
	cout << "Goodbye!\n" << endl;
	return 0;
}

struct Pipe
{
	double length, diametr;
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
	bool repair;
	cin >> p.repair;
	while (true) {
		if (p.repair == "yes"){
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
	return p;
}

struct KC
{	
	string name;
	int guilds;
	double efficiency;
};

KC create_KC() {
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

void see_pipe(Pipe p) {
	cout << "Length: " << p.length
		<< "\t        Diameter: " << p.diametr
		<< "\t        Under repair: " << p.repair << endl;
}

void see_KC (KC k){
	cout << "The name of KC: " << k.name
		<< "\tAmount of guilds: " << k.guilds
		<< "\tEfficiency: " << k.efficiency << " %" << endl;
}

void edit_pipe(Pipe p)
{
	cout << "What do you want to edit: 1. Length   2. Diametr   3. Under repair" << endl;
	int number;
	cin >> number;
	switch (number)
	{
	case 1:
		cout << "Length" << endl;
		cin >> p.length;
		break;
	case 2:
		cout << "Diameter" << endl;
		cin >> p.diametr;
		break;
	case 3:
		cout << "Under repair (yes/no)" << endl;
		cin >> p.repair;
		break;
	}
}

void edit_KC(KC k)
{

}

void save(Pipe p, KC k)
{
	ofstream fout;
	fout.open("File.txt",ofstream::out);
	if (!fout.is_open())
	{
		cout << "file open error" << endl;
	}
	else
	{
		fout << p.length << endl << p.diametr << endl <<p.repair;
		fout << k.name <<endl << k.guilds << endl<< k.efficiency;
	}
	fout.close();
}

void download(Pipe p, KC k)
{
	ifstream fin;
	fin.open("File.txt", ofstream::in);
	if (!fin.is_open())
	{
		cout << "file open error" << endl;
	}
	else
	{
		fin >> p.length >> p.diametr >> p.repair;
		fin >> k.name >> k.guilds >> k.efficiency;
	}
	cout << "Length: " << p.length
		<< "\t        Diameter: " << p.diametr
		<< "\t                Under repair: " << p.repair << endl;

	cout << "The name of KC: " << k.name
		<< "\tAmount of guilds: " << k.guilds
		<< "\tEfficiency: " << k.efficiency << " %" << endl << endl;
	fin.close();
}

//void skip_to_int()
//{
//	if (cin.fail())
//	{
//		cin.clear(); // Возвращаем поток в состояние good () ; 
//		for (char ch; cin >> ch;) { // Отбра сываем не цифры 
//			if (isdigit(ch) || ch == '-') {
//				cin.unget(); //Возвращаем цифру в поток, чтобы можно было считать число
//				return;
//			}
//		}
//	}
//	cout<< ("Ввода нет");
}

int main()
{
	while (true) {
		menu();
		int number;
		while (true) {
			cin >> number;
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				for (char ch; cin >> ch;) { // Отбра сываем не цифры 
					if (isdigit(ch) || ch == '-') {
						cin.unget(); //Возвращаем цифру в поток, чтобы можно было считать число
						return;
					}
				}
				cout << "Enter number again, please" << endl;
			}
			if (number <= 0 && number >= 7)      //+ проверка на ввод только целого числа
			{
				cout << "Enter number again, please" << endl;
			}
			else {
				cout << "Enter number again, please" << endl;
				break;
			}
		}
		Pipe first;
		KC second;
		switch (number)
		{
		case 0:
			exit();
			break;
		case 1:
			first = create_pipe();
			system("cls");
			break;
		case 2:
			second = create_KC();
			system("cls");
			break;
		case 3:
			see_pipe(first);
			see_KC(second);
			break;
		case 4:
			edit_pipe(first);
			system("cls");
			break;
		case 5:
			edit_KC;
			system("cls");
			break;
		case 6: 
			save(first,second);
			break;
		case 7:
			download(first, second);
			break;
		default:
			return 1;
		}
	}
}
