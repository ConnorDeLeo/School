#include <iostream>
#include <iomanip>

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
double pi = asin(1.0);

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
	cout << "Length of nosecone/bay shoulder: ";
	cin >> sLen;
	cout << "Mass of nosecone/bay: ";
	cin >> mass;
	cout << "Resulting mass multiplier: ";
	cin >> mult;
	cout << "Friction coefficient: ";
	cin >> friction;
}

double calcMass() {
	double multConst = powderConst * (mult / 100.0);
	double sArea = sLen * pi * dia;
	double vol = height * pi * pow((dia / 2), 2.0);
	double force = (sArea * friction * sLen) + (mass * sLen * grav * 1.5);
	double pArea = pi * pow((dia / 2), 2.0);
	double psi = force / pArea;
	double charge = psi * vol * multConst;

	return charge;
}

int main() {
	getInputs();
	cout << endl << "Mass of your charge: " << fixed << setprecision(3) << calcMass() << "g";
}