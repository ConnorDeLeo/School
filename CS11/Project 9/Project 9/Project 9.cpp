#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void dispHeader() {
    cout << "*------------------------------------------------------------------------*" << endl;
    cout << "Connor De Leo" << endl;
    cout << "https://github.com/ConnorDeLeo/School/blob/main/CS11/Project%209/Project%209/Project%209.cpp" << endl;
    cout << "11/19/2023" << endl;
    cout << "Long Beach City College: CS11 Introduction to Computer Science - C++" << endl;
    cout << "*------------------------------------------------------------------------*" << endl << endl;
}

class romanType {
public:

    void dispKey() {
        cout << "Roman Numeral Translation Key:" << endl;
        cout << setw(20) << left << "M" << right << "1000" << endl;
        cout << setw(20) << left << "D" << right << "500" << endl;
        cout << setw(20) << left << "C" << right << "100" << endl;
        cout << setw(20) << left << "L" << right << "50" << endl;
        cout << setw(20) << left << "X" << right << "10" << endl;
        cout << setw(20) << left << "V" << right << "5" << endl;
        cout << setw(20) << left << "I" << right << "1" << endl << endl;

        cout << "When entering numerals, use upper or lower case." << endl << endl;
    }

    string input;

    bool setOutput() {
        cout << "Display input as numeral instead? (Y/n): ";
        getline(cin, input);

        for (char& c : input) {
            c = tolower(c);
        }

        if (input == "n") {
            return 0;
        }
        else if (input == "y") {
            return 1;
        }
        else {
            return -1;
        }
    }

    string readInput() {
        cout << "Enter roman numeral: ";
        getline(cin, input);

        for (char& c : input) {
            c = tolower(c);
        }

        return input;
    }

    int solve(string input) {

        vector<int> solved;
        vector<char> numeral;

        int sum = 0;
        string num = "";

        for (int i = 0; i < input.length(); i++) {
            numeral.push_back(input[i]);
        }

        for (int i = 0; i < input.length(); i++) {
            switch (numeral[i]) {
                case 'i':
                    solved.push_back(1);
                    break;
                case 'v':
                    solved.push_back(5);
                    break;
                case 'x':
                    solved.push_back(10);
                    break;
                case 'l':
                    solved.push_back(30);
                    break;
                case 'c':
                    solved.push_back(100);
                    break;
                case 'd':
                    solved.push_back(500);
                    break;
                case 'm':
                    solved.push_back(1000);
                    break;
                default:
                    cout << "Character " << i << " is not a Roman Numeral." << endl;
                    return 0;
            }
        }

        for (int i = 0; i < input.length() - 1; i++) {
            if (solved[i + 1] > solved[i])
                solved[i] = (-1) * solved[i];
        }

        for (int i = 0; i < input.length(); i++) {
            sum += solved[i];
        }

        return sum;
    }
};

int main() {

    dispHeader();

    romanType object;
    string input;
    int outputType;

    object.dispKey();

    outputType = object.setOutput();

    if (outputType == 0) {
        while (true) {

            input = object.readInput();
            if (input.empty()) {
                break;
            }

            cout << object.solve(input) << endl;
        }
    }
    else if (outputType == 1) {
        while (true) {

            input = object.readInput();
            if (input.empty()) {
                break;
            }

            cout << input << endl;
        }
    }
    else if (outputType == -1) {
        cout << "Incorrect selection occured, exiting with code 0." << endl;
        return 0;
    }
    else {
        cout << "Fatal program error occured, exiting with code -1" << endl;
        return -1;
    }
}