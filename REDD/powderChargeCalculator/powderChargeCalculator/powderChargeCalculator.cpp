#include <iostream>

using namespace std;

// Vars
// Usr
double height;
double dia;
double sLen;
double mass;
int mult;
double friction;
// Const
double grav = 9.8;
double powderConst = 0.000516262589984;

void dispHeader() {
	cout << "Amateur Rocketry Powder Charge Calculator" << endl;
	cout << "Connor De Leo" << endl;
	cout << "12/14/2023" << endl << endl;
}

void getInputs() {
	cout << "Input Units:" << endl << "Mass (lb)" << endl << "Distance (in)" << endl << "Multiplier (%)" << endl;

	cout << "Height of body tube chamber: ";
	cin >> height;
	cout << "Inner diameter of the body tube chamber: ";
	cin >> dia;
	cout << "";
}

int main() {
	getInputs();
}