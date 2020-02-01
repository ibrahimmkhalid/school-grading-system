/* student.h */
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

using namespace std;

class student {
private:
    string firstName;
    string lastName;
    string subject;
public:
    student(string firstName, string lastName, string subject);
    virtual float calculateFinalAverage() = 0;
    virtual void readData(istream& in) = 0;
    virtual int getFinalIntegerPart() = 0;
    string getFirstName();
    string getLastName();
    string getSubject();
    char calculateGrade();
    friend istream& operator>>(istream& in, student* s);
    friend ostream& operator<<(ostream& out, student* s);
};


#endif //STUDENT_H
