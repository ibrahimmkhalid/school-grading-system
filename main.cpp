/* main.cpp */
#include <cctype>
#include <string>
#include <iostream>
#include "studentList.h"

using namespace std;

void menu() {
    cout << "I\tImport student data from file\n"
         << "S\tShow student data(brief)\n"
         << "E\tExport student data to file\n"
         << "M\tShow this menu\n"
         << "Q\tQuit the program\n";
}

int main() {
    studentList list;
    string fileName;
    bool quit = false;
    char choice;
    menu();

    while ( !quit ) {
        cout << '>';
        cin >> choice;
        choice = toupper(choice);
        cin.ignore();
        switch ( choice ) {
            case 'I':
                cout << "Enter filename:";
                getline(cin, fileName, '\n');
                if ( !list.importFromFile(fileName))
                    cout << "File not found! Data not imported!\n";
                break;
            case 'S':
                list.printBrief();
                break;
            case 'E':
                cout << "Enter filename:";
                getline(cin, fileName, '\n');
                if ( !list.exportToFile(fileName))
                    cout << "Bad filename! Data not exported!\n";
                break;
            case 'M':
                menu();
                break;
            case 'Q':
                quit = true;
                break;
            default:
                cout << "Invalid option! try again.\n";
        }
    }
    cout << "Goodbye!\n";
    return 0;
}
