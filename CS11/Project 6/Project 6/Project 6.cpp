#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

void dispHeader() {
    cout << "*------------------------------------------------------------------------*" << endl;
    cout << "Connor De Leo" << endl;
    cout << "https://github.com/ConnorDeLeo/School/blob/main/CS11/Project%206/Project%206/Project%206.cpp" << endl;
    cout << "10/22/2023" << endl;
    cout << "Long Beach City College: CS11 Introduction to Computer Science - C++" << endl;
    cout << "*------------------------------------------------------------------------*" << endl << endl;
}

// Assemble string barcode from binary digits
void assembleStr(string binDigits[], string binCorDigs[]) {

    string digitsBar[] = {"", "", "", "", ""};
    string corBar[] = { "", ""};
    string bar = "|";

    for (int d = 0; d < 5; d++) {
        string strDig = binDigits[d];
        replace(strDig.begin(), strDig.end(), '0', ':');
        replace(strDig.begin(), strDig.end(), '1', '|');
        digitsBar[d] = strDig;
    }

    for (int c = 0; c < 2; c++) {
        string strDig = binCorDigs[c];
        replace(strDig.begin(), strDig.end(), '0', ':');
        replace(strDig.begin(), strDig.end(), '1', '|');
        corBar[c] = strDig;
    }

    // Combine digitsBar and corBar arrays into bar string
    for (int l = 0; l < 5; l++) {
        bar += digitsBar[l];
    }

    for (int l = 0; l < 2; l++) {
        bar += corBar[l];
    }

    bar += "|";

    cout << bar;
}

// Return correction digit
int correctZip(int digits[]) {

    int corDig = 0;

    for (int d = 0; d < 5; d++) {
        corDig += digits[d];
    }

    // Find correction digit using ceiling predefined function
    corDig = 10 * (ceil(corDig / 10.0));
    return corDig;
}

// Convert to bin digits based on table 1
string convBin(int val) {
    
    switch (val) {
        case 0:
            return "11000";
        case 1:
            return "00011";
        case 2:
            return "00101";
        case 3:
            return "00110";
        case 4:
            return "01001";
        case 5:
            return "01010";
        case 6:
            return "01100";
        case 7:
            return "10001";
        case 8:
            return "10010";
        case 9:
            return "10100";
        default:
            return "0";
    }
}

// Encode the zipcode and correction digit into bin
void encodeZip(int zip) {

    int zip2 = zip;
    int digits[5];
    string binDigits[5];

    int corDig = 0;
    int corDigs[2];
    string binCorDigs[2];

    // Split digits using zip2 and convert to bin
    for (int d = 0; d < 5; d++) {
        int digit = zip2 % 10;
        digits[d] = digit;
        zip2 /= 10;

        binDigits[d] = convBin(digits[d]);
        corDig += digits[d];
    }

    for (int d = 0; d < 2; d++) {
        int digit = corDig%10;
        corDigs[d] = digit;
        corDig /= 10;

        binCorDigs[d] = convBin(corDigs[d]);
    }

    assembleStr(binDigits, binCorDigs);
}

int main()
{
    // Input vars
    int zip;

    // Header
    dispHeader();

    // Get inputs
    cout << "Please input your zipcode for encoding: ";
    cin >> zip;

    encodeZip(zip);
}