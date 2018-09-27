#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

void PrintAuthor();

int main() {
    PrintAuthor();

    return 0;
}

void PrintAuthor() {
    for( int row = 0; row < 14; row++ ) {
        for( int column = 0; column < 71; column++ ) {
                bool flagVertically = (( row >= 7 && row <= 12) && column == 0 ) ||
            ( ( row == 7 || row == 8 ) && column == 3 ) ||
            ( ( row >= 1 && row <= 8 ) && column == 6 ) ||
            ( ( row >= 1 && row <= 12 ) && ( column == 11 || column == 17 || column == 23 ||
               column == 29 || column == 41 || column == 47 || column == 53 || column == 59 ) ) ||
            ( ( ( row >= 1 && row <= 3 ) || ( row >= 10 && row <= 12 )) && column == 14 ) ||
            ( ( row == 6 || row == 7 ) &&  ( column == 19 || column == 21 ) ) ||
            ( ( row >= 1 && row <= 12 ) && column == 29 ) ||
            ( ( ( row >= 1 && row <= 5) || ( row >= 10 && row <= 12 ) ) && column == 35) ||
            ( ( row >= 1 && row <= 8 ) && column == 64 ) ||
            ( ( row >= 7 && row <= 12 ) && column == 70 ) ||
            ( ( row == 7 || row == 8 ) && column == 67 ) || ( ( row == 11 || row == 12 ) && ( column == 55 || column == 57 ) ) ||
            ( ( row == 3 || row == 4 ) && column == 56 ) || ( ( ( row == 3 ) || ( row >= 10 && row <= 12 ) ) && column == 32 ) ||
            ( row == 7 && column == 33 ) || ( row == 8 && column == 34 ) ||
            ( row == 1 && column == 43 ) || ( ( row == 1 || row == 2 ) && column == 45 ) ||
            ( ( row == 11 || row == 12 ) && column == 43 ) || ( row == 12 && column == 45 );
                bool flagHorizontally = ( ( column == 1 || column == 2 ) && row == 6 ) ||
            ( ( column == 4 || column == 5 ) && row == 9 ) ||
            ( ( ( column >= 1 && column <= 6 ) && row == 13 ) ) ||
            ( ( ( column >= 7 && column <= 10) || ( column >= 12 && column <= 16 ) ||
               (column >= 18 && column <= 22 ) || ( column >= 24 && column <= 28 ) || ( column >= 30 && column <= 34 ) ||
               (column >= 36 && column <= 40 ) || ( column >= 42 && column <= 46 && column != 44 ) || ( column >= 48 && column <= 52 ) ||
               ( column >= 54 && column <= 58 ) || ( column >= 60 && column <= 63 ) ) && ( row == 0 || row == 13 ) ) ||
            ( ( ( column >= 24 && column <= 28 ) || ( column >= 48 && column <= 52 ) ) && row == 3) ||
            ((column >= 64 && column <= 69) && row == 13) || ( ( column >= 19 && column <= 21 ) && ( row == 5 || row == 8 ) ) ||
            ( ( column == 65 || column == 66) && row == 9 ) ||
            ( ( column == 68 || column == 69) && row == 6) || ( ( column == 33 || column == 34 ) && row == 6 ) ||
            ( ( column >= 55 && column <= 57 ) && row == 10 ) ||
            ( ( column >= 38 && column <= 40 ) && ( row == 4 || row == 9 ) );
                bool flagException = ( column == 56 && row == 13 );
                bool flagDivide = ( ( row == 2 || row == 11 ) && column == 44 );
            if (flagVertically) {
                cout << 'I';
            } else if (flagHorizontally && !flagException) {
                cout << '-';
            } else if (flagDivide) {
                cout << '\\';
            } else {
                cout << ' ';
            }


        }
        cout << endl;
    }
}

