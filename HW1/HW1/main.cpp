/*	Program No. : HW1.CPP
	Programmer : Neville Li
	Course / Section : ELET 4309 - 01 / 19260
	Instructor : Dr.F.Attarzadeh
	Date Assigned : 01/29/2019
	Date Modified : 02/03/2019
	Due Date : 02/12/2019
	Compiler : Microsoft Visual Studio 2017 Community Edition
	Environment : Console Applications
	Operating System : Windows 10
*/

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

void generateMenu() {
	cout << "Select: \n"
		<< "H for Help\n"
		<< "C for Cars\n"
		<< "M for Motorcycles\n"
		<< "S for Senior Citizens\n"
		<< "Q for Quit\n" << endl;
}

char selectOption() {
	char option;
	cout << "Choose an option: \n";
	cin >> option;

	return tolower(option);
}

void showHelp() {
	cout << "This software is to show and calculate prices for UH parking\n"
		<< "Cars:             First 1 hour:   Free\n"
		<< "                  Next 2 hours:   $3.00 per hour\n"
		<< "                  Thereafter:     $1.50 per hour(for more than three 3 hours)\n"
		<< "Motorcycles:      First 1 hour:   $2.00\n"
		<< "                  Next 5 hours:   $1.50 per hour\n"
		<< "                  Thereafter:     $1.00 per hour\n"
		<< "Senior Citizens:                  Free\n" << endl;
	system("pause");
}

// this function prompt the user for a number in minutes and calculating the coresponding price

int getCharge(char type) {
	double  minutes, charge, hours, rate0, rate1, rate2, interval;

	cout << "Please enter the number of minutes you have parked in the lot: ";

	cin >> minutes;
	if (minutes < 0) {
		cout << "Invalid input\n";
		system("pause");
		return -1;
	}

	hours = round(minutes / 60);

	switch (type) {
		case 'c':
			rate0 = 0.00;
			rate1 = 3.00;
			rate2 = 1.50;
			interval = 2.0;
			break;
		case 'm':
			rate0 = 2.00;
			rate1 = 1.50;
			rate2 = 1.00;
			interval = 5.0;
			break;
		case 's':
			cout << "Parking is free for senior citizens";
			return 0;
			break;
		default:
			cout << "An error has occured";
	}

	if (hours <= 1 ) {
		charge = rate0;
	}
	else if (hours <= interval){
		charge = (hours - 1.00) * rate1;
	}
	else {
		charge = (interval - 1) * rate1 + (hours - interval) * rate2;
	}
	cout << cout.precision(2) << fixed;
	cout << "Your total is: $" << charge << endl;
	system("pause");
	return 0;
}

int main() {
	bool isOn = true;
	
	while (isOn) {

		int option;
		system("cls");
		generateMenu();
		option = selectOption();
		switch (option) {
			case 'h':
				system("cls");
				showHelp();
				break;
			case 'c':
				system("cls");
				getCharge(option);
				break;
			case 'm':
				system("cls");
				getCharge(option);
				break;
			case 's':
				system("cls");
				getCharge(option);
				system("pause");
				break;
			case 'q':
				isOn = !isOn;
				break;
			default:
				cout << "Not a valid option";
		}
	}
	system("PAUSE");
	return 0;
}