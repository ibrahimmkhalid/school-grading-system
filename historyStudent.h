/* historyStudent.cpp */
#ifndef HISTORYSTUDENT_H
#define HISTORYSTUDENT_H

#include "student.h"

template<typename T>
class historyStudent : public student {
private:
    T termPaper;
    T midterm;
    T final;
public:
    historyStudent(string firstName, string lastName)
            : student(firstName, lastName, "History") {}

    float calculateFinalAverage() {
        return 0.25 * termPaper + 0.35 * midterm + 0.4 * final;
    }

    void readData(istream& in) {
        in >> termPaper >> midterm >> final;
    }

    int getFinalIntegerPart() { return static_cast<int>(final); }

};


#endif //HISTORYSTUDENT_H
