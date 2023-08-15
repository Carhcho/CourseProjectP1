#include <iostream>
#include <iomanip>
#include <fstream>							
#include <string>
#include <stdlib.h>
#include <math.h>

using namespace std;

char firstClass[5][4];
char coachClass[10][6];

void initialiseSeats();
void seatMap();
void reserveSeats();
void displaySoldSeats();
void displayEmpty();
void totalSales(double[], int);

int main() {
    int choice;
    double table[3];
    initialiseSeats(); //creating the rows and columns

    while (true) {
        cout << "Enter 1 to reserve seat." << endl;
        cout << "Enter 2 to display total number of seats sold." << endl;
        cout << "Enter 3 to display total number of empty seats in the plane." << endl;
        cout << "Enter 4 to display the sales." << endl;
        cout << "Enter 5 to exit." << endl;
        cout << "\nPlease enter the choice: ";
        cin >> choice;

        if (choice == 1) {
            reserveSeats();
        }
        else if (choice == 2) {
            displaySoldSeats();
        }
        else if (choice == 3) {
            displayEmpty();
        }
        else if (choice == 4) {
            totalSales(table, 3);
        }
        else if (choice == 5) {
            break;
        }
    }
}
//this function creates the seats using #s and *s
void initialiseSeats() {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 4; j++) {
            firstClass[i][j] = '#';
        }
    }
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 6; j++) {
            coachClass[i][j] = '#';
        }
    }
}
//this function display the seats
void seatMap() {
    cout << "First class: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Row " << i + 1 << " ";
        for (int j = 0; j < 2; j++)
        {
            cout << firstClass[i][j] << " ";
        }
        cout << "   "; //this space is here to represent the isle
        for (int j = 2; j < 4; j++)
        {
            cout << firstClass[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Coach class: " << endl;
    for (int i = 0; i < 10; i++) {
        cout << "Row " << i + 1 << " ";
        for (int j = 0; j < 6; j++)
        {
            cout << coachClass[i][j] << " ";
        }
        cout << endl;
    }
}
//this function changes #s for *s wherever the user points
void reserveSeats() {
    int row, seat;
    string type;
    cout << "Section type: \nfirst \ncoach \nPlease enter type: ";
    cin >> type;
    if (type == "first") {
        cout << "Enter row number: ";
        cin >> row;
        cout << "Enter seat number: ";
        cin >> seat;
        if (row < 1 || row > 5 || seat < 1 || seat > 4) {
            cout << "Invalid seat location." << endl;
        }
        if (firstClass[row - 1][seat - 1] == '*') {
            cout << "This seat is already taken, try another" << endl;
        }
        else {
            firstClass[row - 1][seat - 1] = '*';
        }
    }
    else if (type == "coach") {
        cout << "Enter row number: ";
        cin >> row;
        cout << "Enter seat number: ";
        cin >> seat;
        if (row < 1 || row > 10 || seat < 1 || seat > 6) {
            cout << "Invalid seat location." << endl;
        }
        if (coachClass[row - 1][seat - 1] == '*') {
            cout << "This seat is already taken, try another" << endl;
        }
        else {
            coachClass[row - 1][seat - 1] = '*';
        }
    }
    else {
        cout << "Section type doesn't exist, try again.";
    }
}
//this function displays the total number of sold seats and the new seat map
void displaySoldSeats() {
    int i, j;
    int total = 0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 4; j++) {
            if (firstClass[i][j] == '*') {
                total++;
            }
        }
    }
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 6; j++) {
            if (coachClass[i][j] == '*') {
                total++;
            }
        }
    }
    cout << "Total number of seats sold: " << total << endl;
    seatMap();
}
//this function displays the total number of empty seats and the seat map
void displayEmpty() {
    int totalSeats = 0;
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 4; j++) {
            if (firstClass[i][j] == '#') {
                totalSeats++;
            }
        }
        cout << endl;
    }
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 6; j++) {
            if (coachClass[i][j] == '#') {
                totalSeats++;
            }
        }
        cout << endl;
    }
    cout << "Total number of empty seats in the plane: " << totalSeats << endl;
    seatMap();
}
//this function reads from a file puts the values in a table and assign those values to 3 prices then according to the * in each section calculates the total price
void totalSales(double table[], int size) {
    ifstream iFile;
    iFile.open("SeatPrices.txt");

    if (!iFile) {
        cout << "File failed to load, please try again." << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        iFile >> table[i];
    }
    iFile.close();
    
    double price1 = table[0], price2 = table[1], price3 = table[2];
    double total = 0;
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 4; j++) {
            if (firstClass[i][j] == '*')
                total += price1;
        }
    }
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 6; j++) {
            if (coachClass[i][j] == '*')
                total += price2;
        }
    }
    for (i = 5; i < 10; i++) {
        for (j = 0; j < 6; j++) {
            if (coachClass[i][j] == '*')
                total += price3;
        }
    }
    cout << "\nTotal sales: " << total << endl;
}

