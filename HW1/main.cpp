// File Name ��������.. H1NevilleLi.cpp
// Course ���������... ELET 4309 Object-Oriented Application Programming
// Programmer �������.. Neville Li
// Compiler �������..�.. Microsoft Visual Studio 2017
// Operating System ���..�.. Windows 10
// Environment ����..��.... Console Applications
// Date �����������. 02/12/2019

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

/*	Program Description
	___________________

	Develop a C++ program for calculating parking fee. It prompts the user for vehicle type and how long the vehicle has been parked in minutes.
	Based on the inputs the program would calculate and displays the appropriate fee. The primary purpose of the main function is to act as a selection system
	and call the appropriate functions based on user's input
*/



#include <iostream>
#include <cmath>
#include <iomanip>
#include<string>
using namespace std;


void pause();
void showHelp();
char selectOption();
void generateMenu();
int getCharge(char);

int main() {
	bool isOn = true;
	
	while (isOn) {

		int option;
		system("cls");
		generateMenu();
		option = selectOption();
		system("cls");
		switch (option) {
			case 'h':
				showHelp();
				pause();
				break;
			case 'c':
				getCharge(option);
				pause();
				break;
			case 'm':
				getCharge(option);
				pause();
				break;
			case 's':
				getCharge(option);
				pause();
				break;
			case 'q':
				isOn = !isOn;
				break;
			default:
				cout << "Not a valid option" << endl;
				pause();
		}
	}
	pause();
	return 0;
}

void pause() {
	cout << "Press enter to continue";
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getchar();
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
}

char selectOption() {
	char option;
	cout << "Choose an option: \n";
	cin >> option;

	return tolower(option);
}


void generateMenu() {
	cout << "Select: \n"
		<< "H for Help\n"
		<< "C for Cars\n"
		<< "M for Motorcycles\n"
		<< "S for Senior Citizens\n"
		<< "Q for Quit\n" << endl;
}

// this function prompt the user for a number in minutes and calculating the coresponding price

int getCharge(char type) {
	double  minutes, charge, hours, rate0, rate1, rate2, interval;

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
		cout << "Parking is free for senior citizens\n";
		return 0;
		break;
	default:
		cout << "An error has occured";
	}

	cout << "Please enter the number of minutes you have parked in the lot: ";

	cin >> minutes;
	if (minutes < 0) {
		cout << "Invalid input\n";
		pause();
		return -1;
	}

	hours = ceil((minutes / 60.0));

	if (hours <= 1.0) {
		charge = rate0;
	}
	else if (hours <= interval) {
		charge = (hours - 1.00) * rate1 + rate0;
	}
	else {
		charge = (rate0)+(interval * rate1) + ((hours - interval - 1.00) * rate2);
	}
	cout << setprecision(2) << fixed;
	cout << "Your total is: $" << charge << endl;
	return 0;
}




