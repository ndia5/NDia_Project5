/*
 * Class: CMSC140 CRN 40020
 * Instructor: Professor Tsai
 * Project 5
 * Description: Check if a 3x3 grid forms a Lo Shu Magic Square using three parallel 1-D arrays.
 * Due Date:08/09/2025
 * I pledge that I have completed the programming assignment independently.
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Ndeye Dia 
 */

#include <iostream>
#include <limits>
#include <cctype>
using namespace std;

// Global constants 
const int ROWS = 3;  // The number of rows in the array
const int COLS = 3;  // The number of columns in the array
const int MIN = 1;  // The value of the smallest number
const int MAX = 9;  // The value of the largest number

// Function prototypes
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max);
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRowSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
bool checkColSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
bool checkDiagSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
void showArray(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);

int main()
{
    int magicArrayRow1[COLS], magicArrayRow2[COLS], magicArrayRow3[COLS];
    char again = 'y';

    do {
        fillArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);

        cout << "\n";
        showArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);

        if (isMagicSquare(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS))
            cout << "This is a Lo Shu magic square." << endl;
        else
            cout << "This is not a Lo Shu magic square." << endl;

        cout << "\nDo you want to try again?";
        cin >> again;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (tolower(static_cast<unsigned char>(again)) == 'y');

    // First pause
    cout << "\nPress any key to continue . . . ";
    cin.get();

    // Footer section
    cout << "\n\nName: Ndeye Dia\n";
    cout << "Project #: 5\n";
    cout << "Due Date: 8/9\n";
    cout << "Press any key to continue . . . ";
    cin.get();

    return 0;
}

// ---- Function definitions ----
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
    for (int c = 0; c < size; ++c) {
        cout << "Enter the number for row 0 and column " << c << " :";
        cin >> arrayRow1[c];
    }
    for (int c = 0; c < size; ++c) {
        cout << "Enter the number for row 1 and column " << c << " :";
        cin >> arrayRow2[c];
    }
    for (int c = 0; c < size; ++c) {
        cout << "Enter the number for row 2 and column " << c << " :";
        cin >> arrayRow3[c];
    }
}

void showArray(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size) {
    for (int i = 0; i < size; ++i) cout << arrayrow1[i] << " ";
    cout << "\n";
    for (int i = 0; i < size; ++i) cout << arrayrow2[i] << " ";
    cout << "\n";
    for (int i = 0; i < size; ++i) cout << arrayrow3[i] << " ";
    cout << "\n";
}

bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max) {
    for (int i = 0; i < size; ++i) {
        if (arrayRow1[i] < min || arrayRow1[i] > max) return false;
        if (arrayRow2[i] < min || arrayRow2[i] > max) return false;
        if (arrayRow3[i] < min || arrayRow3[i] > max) return false;
    }
    return true;
}

bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
    bool seen[MAX + 1] = { false };
    int vals[ROWS * COLS], k = 0;

    for (int i = 0; i < size; ++i) vals[k++] = arrayRow1[i];
    for (int i = 0; i < size; ++i) vals[k++] = arrayRow2[i];
    for (int i = 0; i < size; ++i) vals[k++] = arrayRow3[i];

    for (int i = 0; i < ROWS * COLS; ++i) {
        if (seen[vals[i]]) return false;
        seen[vals[i]] = true;
    }
    return true;
}

bool checkRowSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size) {
    int s1 = 0, s2 = 0, s3 = 0;
    for (int i = 0; i < size; ++i) { s1 += arrayrow1[i]; s2 += arrayrow2[i]; s3 += arrayrow3[i]; }
    return (s1 == s2 && s2 == s3);
}

bool checkColSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size) {
    int c0 = arrayrow1[0] + arrayrow2[0] + arrayrow3[0];
    int c1 = arrayrow1[1] + arrayrow2[1] + arrayrow3[1];
    int c2 = arrayrow1[2] + arrayrow2[2] + arrayrow3[2];
    return (c0 == c1 && c1 == c2);
}

bool checkDiagSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size) {
    int d1 = arrayrow1[0] + arrayrow2[1] + arrayrow3[2];
    int d2 = arrayrow1[2] + arrayrow2[1] + arrayrow3[0];
    return (d1 == d2);
}

bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
    if (!checkRange(arrayRow1, arrayRow2, arrayRow3, size, MIN, MAX)) return false;
    if (!checkUnique(arrayRow1, arrayRow2, arrayRow3, size)) return false;
    if (!checkRowSum(arrayRow1, arrayRow2, arrayRow3, size)) return false;
    if (!checkColSum(arrayRow1, arrayRow2, arrayRow3, size)) return false;
    if (!checkDiagSum(arrayRow1, arrayRow2, arrayRow3, size)) return false;

    int target = arrayRow1[0] + arrayRow1[1] + arrayRow1[2];
    int firstCol = arrayRow1[0] + arrayRow2[0] + arrayRow3[0];
    int mainDiag = arrayRow1[0] + arrayRow2[1] + arrayRow3[2];

    return (target == firstCol && target == mainDiag);
}
