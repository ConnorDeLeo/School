#include <iostream>

using namespace std;

int main()
{
    // Input vars
    int eid;
    double hours;
    double rate;

    // Output vars
    double gross;

    // Get input
    std::cout << "Please enter your employee ID number: ";
    cin >> eid;
    cout << "Please enter your hours worked: ";
    cin >> hours;
    cout << "Please enter your hourly rate: $";
    cin >> rate;

    // Math
    gross = hours * rate;

    // Output
    cout << "Employee ID: " << eid << endl;
    cout << "Hours worked: " << hours << " At a rate of: $" << rate << endl;
    cout << "Your gross pay is: $" << gross << endl;
}