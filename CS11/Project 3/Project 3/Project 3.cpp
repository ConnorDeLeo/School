#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

float truncate(float x)
{
	return trunc(x * 100.0f) / 100.0f;
}

int main()
{
	string name = "";
	float gross = 0.0f;

	float fed = 0.0f;
	float state = 0.0f;
	float sec = 0.0f;
	float med = 0.0f;
	float pen = 0.0f;
	float ins = 0.0f;

	float net = 0.0f;

	ofstream out;

	// header
	cout << "*------------------------------------------------------------------------*" << endl;
	cout << "Connor De Leo" << endl;
	cout << "https://github.com/ConnorDeLeo/School/blob/main/CS11/Project%202/Project%202/Project%202.cpp" << endl;
	cout << "9/2/2023" << endl;
	cout << "Long Beach City College: CS11 Introduction to Computer Science - C++" << endl;
	cout << "*------------------------------------------------------------------------*" << endl;

	// inputs
	cout << "Please input employee name: ";
	cin >> name;
	cout << "Please input gross pay: ";
	cin >> gross;

	gross = (float)gross;

	// calcs
	net = gross;
	fed = truncate((15.0f / 100.0f) * net);
	net = net - fed;
	state = truncate((3.5f / 100.0f) * net);
	net = net - state;
	sec = truncate((5.75f / 100.0f) * net);
	net = net - sec;
	med = truncate((2.75f / 100.0f) * net);
	net = net - med;
	pen = truncate((5.0f / 100.0f) * net);
	net = net - pen;
	ins = truncate(75.0f);
	net = truncate(net - ins);

	// file saving
	out.open("netPay.txt");

	out << "Employee Name:               " << left << setw(100) << name << endl;
	out << "Gross Pay ($):               " << left << setw(10) << gross << endl;
	out << "Federal Tax ($):             " << left << setw(10) << fed << endl;
	out << "State Tax ($):               " << left << setw(10) << state << endl;
	out << "Social Security Tax ($):     " << left << setw(10) << sec << endl;
	out << "Medicare/Medicaid Tax ($):   " << left << setw(10) << med << endl;
	out << "Pension Plan ($):            " << left << setw(10) << pen << endl;
	out << "Health Insurance ($):        " << left << setw(10) << ins << endl;
	out << "Net Pay ($):                 " << left << setw(10) << net << endl;

	out.close();

	return 0;
}