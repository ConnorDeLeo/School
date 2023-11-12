#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <algorithm>

using namespace std;

void dispHeader() {
    cout << "*------------------------------------------------------------------------*" << endl;
    cout << "Connor De Leo" << endl;
    cout << "https://github.com/ConnorDeLeo/School/blob/main/CS11/Project%208/Project%208/Project%208.cpp" << endl;
    cout << "11/11/2023" << endl;
    cout << "Long Beach City College: CS11 Introduction to Computer Science - C++" << endl;
    cout << "*------------------------------------------------------------------------*" << endl << endl;
}

struct menuItem
{
    string name; double price;
};

menuItem menu[8];
menuItem loweredMenu[8];

void setMenu() {
    menu[0].name = "Plain Egg";
    menu[0].price = 1.45;
    menu[1].name = "Bacon and Egg";
    menu[1].price = 2.45;
    menu[2].name = "Muffin";
    menu[2].price = 0.99;
    menu[3].name = "French Toast";
    menu[3].price = 1.99;
    menu[4].name = "Fruit Basket";
    menu[4].price = 2.49;
    menu[5].name = "Cereal";
    menu[5].price = 0.69;
    menu[6].name = "Coffee";
    menu[6].price = 0.50;
    menu[7].name = "Tea";
    menu[7].price = 0.75;

    string lowMenuItem;

    for (int i = 0; i < 8; i++) {

        lowMenuItem = menu[i].name;

        for (char& c : lowMenuItem) {
            c = tolower(c);
        }

        loweredMenu[i].name = lowMenuItem;
        loweredMenu[i].price = menu[i].price;
    }
}

void dispMenu() {

    cout << endl << setw(25) << left << "Menu" << right << "Price" << endl;

    cout << fixed;

    for (int m = 0; m < 8; m++) {
        cout << setw(25) << left << menu[m].name << right << setprecision(2) << menu[m].price << endl;
    }

    cout << endl;
}

void printCheck(int item, string* items, double* prices) {

    cout << "Welcome to Johnny's Restaurant!" << endl;
    cout << fixed;

    double preTax = 0.00;
    double tax;
    double total;

    for (int c = 0; c < item; c++) {
        cout << setw(25) << left << items[c] << right << setprecision(2) << prices[c] << endl;
        preTax += prices[c];
    }

    tax = preTax * 0.05;
    total = preTax + tax;

    cout << setw(25) << left << "Tax" << right << setprecision(2) << tax << endl;
    cout << setw(25) << left << "Total Due" << right << setprecision(2) << total << endl;
}

void collectInputs() {
    cout << "Which items would you like to order?" << endl << "When done ordering, type N" << endl << endl;

    int item = 0;
    int size = 16;

    string* items = nullptr;
    items = new string[size];

    double* prices = nullptr;
    prices = new double[size];

    string order;
    string lowered;

    while (true) {
        getline(cin, order);

        lowered = order;
        for (char& c : lowered) {
            c = tolower(c);
        }

        if (lowered == "n") {
            break;
        }
        else {
            for (int i = 0; i < 8; i++) {
                if (lowered == loweredMenu[i].name) {
                    items[item] = menu[i].name;
                    prices[item] = menu[i].price;

                    item++;

                    break;
                }
            }
        }
    }

    printCheck(item, items, prices);

    delete[] items;
    delete[] prices;
}

int main() {
    dispHeader();

    setMenu();
    dispMenu();

    collectInputs();
}