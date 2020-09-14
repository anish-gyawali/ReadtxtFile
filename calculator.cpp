#include<iostream>
#include<iomanip>
#include<string>
#include <windows.h>
using namespace std;
int main()
{
	int number;
	char X ='A';
	double total;
	double Rent;
	double grocery;
	double Fperson;
	double Sperson;
	double Tperson;
	double ect,grc,ele,rm;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
	cout << "\c" << "\c" << "\c" << "\c";
	cout << setw(40) << "      ************  wecome to our room calculator  **********      " << endl << endl << endl << endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	cout << "enter the number of people: ";
	cin >> number;
	if (number == 3)
	{
		cout << "enter the price of room rent: ";
		cin >> Rent;
		cout << "enter the total price spend by First person: ";
		cin >> Fperson;
		cout << "enter the total price spend by second person: ";
		cin >> Sperson;
		cout << "enter the total price spend by Third person: ";
		cin >> Tperson;
		cout << "enter the total price of grocery:";
		cin >> grocery;
		cout << "enter the total price of electricity and internet: ";
		cin >> ect;

		total = (Rent + ect + grocery) / number;
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << setw(40) << "first person need to pay = " << total - Fperson << endl;
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
		cout << setw(40) << "second person need to pay = " << total - Sperson << endl;
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
		cout << setw(40) << "third person need to pay = " << total - Tperson << endl;


		cout << "you want to know individual price (Y/N) ?";
		cin >> X;
		if (X == 'Y' || X == 'y')
		{
			grc = (grocery / number);
			ele = (ect / number);
			rm = (Rent / number);
			cout << "Per person grocery is : " << grc << endl;
			cout << "Per person electricity and internet is : " << ele << endl;
			cout << "Per person room rent is : " << rm << endl;
		}
		else
			cout << "It's okey!";

	}
	else

		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << "Thank you!!" << endl;
	system("pause");
	return 0;
}
