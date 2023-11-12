#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void dispHeader() {
    cout << "*------------------------------------------------------------------------*" << endl;
    cout << "Connor De Leo" << endl;
    cout << "https://github.com/ConnorDeLeo/School/blob/main/CS11/Project%207/Project%207/Project%207.cpp" << endl;
    cout << "11/4/2023" << endl;
    cout << "Long Beach City College: CS11 Introduction to Computer Science - C++" << endl;
    cout << "*------------------------------------------------------------------------*" << endl << endl;
}

struct record
{
    string name; int votes;
};

void readFile() {

    ifstream inputFile("records.txt");
    record records[5];

    for (int i = 0; i < 5; i++) {
        inputFile >> records[i].name >> records[i].votes;
    }

    inputFile.close();

    int total = 0;

    for (int t = 0; t < 5; t++) {
        total += records[t].votes;
    }

    double percents[5];

    for (int p = 0; p < 5; p++) {
        percents[p] = 100.0 * static_cast<double>(records[p].votes) / static_cast<double>(total);
    }

    string test;
    string prevTest = "";
    int longest;

    for (int l = 0; l < 5; l++) {

        test = records[l].name + to_string(records[l].votes);

        if (prevTest != "") {
            if (test > prevTest) {
                prevTest = test;
                longest = l;
            }
            else {
                prevTest = test;
            }
        }
        else {
            prevTest = records[l].name + to_string(records[l].votes);
        }
    }

    int winner;
    int largest = records[0].votes;

    for (int w = 1; w < 5; w++) {
        if (largest < records[w].votes) {
            winner = w;
        }
        else if (largest > records[w].votes && w == 1) {
            winner = 0;
        }
    }

    int spaceCand = 5 + string("Candidate").size();
    int spaceVot = 5 + string("Votes Recieved").size();
    int spacePer = 5 + string("% of Total Votes").size();

    cout << setw(spaceCand) << left << "Candidate" << setw(spaceVot) << left << "Votes Recieved" << setw(spacePer) << left << "% of Total Votes" << endl;

    for (int r = 0; r < 5; r++) {
        if (percents[r] > 10.0) {
            cout << setw(spaceCand) << left << records[r].name << setw(spaceVot) << left << records[r].votes << setw(spacePer) << left << setprecision(3) << percents[r] << endl;
        }
        else {
            cout << setw(spaceCand) << left << records[r].name << setw(spaceVot) << left << records[r].votes << setw(spacePer) << left << setprecision(2) << percents[r] << endl;
        }
    }

    cout << setw(spaceCand) << left << "Total" << setw(spaceVot) << left << total << endl << endl;
    cout << "The winner of the election is " << records[winner].name << ".";
}

int main() {
    dispHeader();
    readFile();
}