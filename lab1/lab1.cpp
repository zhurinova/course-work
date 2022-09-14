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

int main()
{
	menu();
	int number;
	cin >> number;
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Enter number, please" << endl;
		cin >> number;
	}
	if (number < 0 || number > 7||number%1==0)
	{
		cout << "Enter number, please" << endl;
	}
	return 0;
}

//	
//int number;
//	cin >> number;
//	switch (number)
//	{
//	case 0:
//		return 0;
//	case 1:
//		
//	};
//}

