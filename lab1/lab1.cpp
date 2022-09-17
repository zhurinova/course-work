#include <iostream>
#include <fstream>
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
	return 0;
}

void add_pipe()
{
	double length, diametr;
	string answer;
	bool repair;
	cout << "Enter options of pipe" << endl;
	cout << "Length" << endl; 
	cin >> length;
	cout << "Diameter" << endl;
	cin >> diametr;
	cout << "Under repair (yes/no)" << endl;
	cin >> answer;
	if (answer == "yes") {
		repair = true;
	}
	else if (answer == "no") {
        repair = false;
	}
	else{
		cout << "Enter yes or no, please" << endl;
	}
}

void add_KC() {
	char name;
	int guilds, efficiency;
	cout << "Enter options of KC" << endl;
	cout << "The name of KC" << endl;
	cin >> name;
	cout << "Amount of guilds" << endl;
	cin >> guilds;
	cout << "Efficiency in percent" << endl;
	cin >> efficiency;
}

void see_all() {
}

int main()
{
	menu();
	long double n;
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
		add_pipe();
		break;
	case 2:
		add_KC();
	}
}

