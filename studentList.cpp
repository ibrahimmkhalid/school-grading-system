/* studentList.cpp */
#include "studentList.h"
#include "englishStudent.h"
#include "historyStudent.h"
#include "mathStudent.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//function used to remove unwanted characters from the start and end of the passed string.
void cleanString(string& str) {
    bool checkStartStr = false;
    bool checkEndStr = false;
    int len = str.length();

    while ( !checkStartStr ) {
        if ( str[0] == '\r' || str[0] == '\n' || str[0] == ' ' ) {
            for ( int j = 0; j < len - 1; j++ ) {
                str[j] = str[j + 1];
            }
            str[len - 1] = '\0';
        } else
            checkStartStr = true;
    }
    int i = len - 1;
    while ( !checkEndStr ) {
        if ( str[i] == '\r' || str[i] == '\n' || str[i] == ' ' || str[i] == '\0' ) {
            str.resize(i);
            --i;
        } else
            checkEndStr = true;
    }
}

studentList::studentList() {
    size = 0;
    pStudent = nullptr;
    currentIndex = 0;
}

studentList::~studentList() {
    for (int i = 0; i < size; i++)
        delete pStudent[i];
    delete[]pStudent;
}

//resize the list of students
void studentList::resizePStudent(int n) {
    student** tmp = new student* [size + n];
    for ( int i = 0; i < size; i++ ) {
        tmp[i] = pStudent[i];
    }
    for ( int i = size; i < size + n; i++ )
        tmp[i] = nullptr;
    delete[] pStudent;
    pStudent = tmp;
}

int studentList::gradeCount(char grade) {
    int count = 0;
    for ( int i = 0; i < size; i++ )
        if ( pStudent[i]->calculateGrade() == grade )
            count++;
    return count;
}

void studentList::outputFor(string sub, ostream& out) {

    //output formatting
    out << "---" << sub << " Class---" << endl;
    out << setw(40) << left << "Student" << setw(7) << left
        << "Final" << setw(7) << left << "Final" << setw(7) << left
        << "Letter\n" << setw(40) << left << "Name   " << setw(7) << left
        << "Exam " << setw(7) << left << "Avg  " << setw(7) << left
        << "Grade \n";
    out << setw(60) << setfill('-') << '-' << endl << setfill(' ');
    for ( int i = 0; i < size; i++ ) {
        if ( pStudent[i]->getSubject() == sub )
            out << pStudent[i];
    }
    out << "\n\n";
}

bool studentList::importFromFile(string fileName) {

    int numberOfEntries;
    string tmpFirstName;
    string tmpLastName;
    string tmpSubject;
    string tmpType;
    bool isFloat;
    streamoff streamPos;

    ifstream fin;
    fin.open(fileName);
    if ( !fin.is_open())
        return false;
    fin >> numberOfEntries;

    resizePStudent(numberOfEntries);
    size = size + numberOfEntries;

    for ( int i = currentIndex; i < size; i++ ) {

        getline(fin, tmpFirstName, ',');
        getline(fin, tmpLastName, '\n');
        getline(fin, tmpSubject, ' ');
        cleanString(tmpFirstName);
        cleanString(tmpLastName);
        cleanString(tmpSubject);

        //method to check whether the entry is in float or int
        isFloat = false;
        streamPos = fin.tellg();
        getline(fin, tmpType);
        fin.seekg(streamPos);
        for ( int j = 0; j < tmpType.length(); j++ ) {
            if ( tmpType[j] == '.' ) {
                isFloat = true;
                break;
            }
        }

        if ( isFloat ) {
            if ( tmpSubject == "English" )
                pStudent[currentIndex] = new englishStudent<float>(tmpFirstName, tmpLastName);
            else if ( tmpSubject == "History" )
                pStudent[currentIndex] = new historyStudent<float>(tmpFirstName, tmpLastName);
            else if ( tmpSubject == "Math" )
                pStudent[currentIndex] = new mathStudent<float>(tmpFirstName, tmpLastName);
        } else {
            if ( tmpSubject == "English" )
                pStudent[currentIndex] = new englishStudent<int>(tmpFirstName, tmpLastName);
            else if ( tmpSubject == "History" )
                pStudent[currentIndex] = new historyStudent<int>(tmpFirstName, tmpLastName);
            else if ( tmpSubject == "Math" )
                pStudent[currentIndex] = new mathStudent<int>(tmpFirstName, tmpLastName);
        }
        fin >> pStudent[currentIndex];
        currentIndex++;
    }
    fin.close();
    return true;
}

bool studentList::exportToFile(string fileName) {
    ofstream fout;
    fout.open(fileName);
    if ( !fout.is_open())
        return false;
    fout << "Student Grade Report" << endl;
    fout << "--------------------" << endl;
    outputFor("English", fout);     //output the subsection in the grade report
    outputFor("History", fout);     //for specific types of students
    outputFor("Math", fout);
    fout << "Overall Grade Distribution\n";
    fout << "A:\t" << gradeCount('A') << endl;
    fout << "B:\t" << gradeCount('B') << endl;
    fout << "C:\t" << gradeCount('C') << endl;
    fout << "D:\t" << gradeCount('D') << endl;
    fout << "F:\t" << gradeCount('F') << endl;
    return true;
}

//used for the console brief display
void studentList::printBrief() const {
    if ( size > 0 ) {
        cout << setw(20) << left << "First" << setw(20)
             << left << "Last" << setw(20) << left << "Course\n" << endl;
        for ( int i = 0; i < size; i++ ) {
            cout << setw(20) << left << pStudent[i]->getFirstName()
                 << setw(20) << left << pStudent[i]->getLastName()
                 << setw(20) << left << pStudent[i]->getSubject() << "\n";
        }
        cout << endl;
    } else
        cout << "No data saved yet.\n";
}
