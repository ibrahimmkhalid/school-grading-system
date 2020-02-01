/* englishStudent.h */
#ifndef ENGLISHSTUDENT_H
#define ENGLISHSTUDENT_H

#include "student.h"

template<typename T>
class englishStudent : public student {
private:
    T attendance;
    T project;
    T midterm;
    T final;
public:
    englishStudent(string firstName, string lastName)
            : student(firstName, lastName, "English") {}

    float calculateFinalAverage() {
        return 0.1 * attendance + 0.3 * (project + midterm + final);
    }

    void readData(istream& in) {
        in >> attendance >> project >> midterm >> final;
    }

    int getFinalIntegerPart() { return static_cast<int>(final); }

};


#endif //ENGLISHSTUDENT_H
