/* student.cpp */

#include "student.h"
#include <iomanip>

student::student(string firstName, string lastName, string subject)
        : firstName(firstName), lastName(lastName), subject(subject) {}

string student::getFirstName() { return firstName; }

string student::getLastName() { return lastName; }

string student::getSubject() { return subject; }

char student::calculateGrade() {
    float finalAvg = calculateFinalAverage();
    char grade;
    if ( finalAvg < 60 )
        grade = 'F';
    else if ( finalAvg >= 60 && finalAvg < 70 )
        grade = 'D';
    else if ( finalAvg >= 70 && finalAvg < 80 )
        grade = 'C';
    else if ( finalAvg >= 80 && finalAvg < 90 )
        grade = 'B';
    else if ( finalAvg >= 90 )
        grade = 'A';
    return grade;
}

istream& operator>>(istream& in, student* s) {
    //each type of student inputs data differently, hence the function call for readData();
    s->readData(in);
    return in;
}

ostream& operator<<(ostream& out, student* s) {
    string name;
    name = s->getLastName() + ' ' + s->getFirstName();
    out << fixed << setprecision(2);
    out << setw(40) << left << name
        << setw(7) << left << s->getFinalIntegerPart()
        << setw(7) << left << s->calculateFinalAverage()
        << setw(7) << left << s->calculateGrade() << endl;
    return out;
}
