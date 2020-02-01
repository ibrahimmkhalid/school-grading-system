/* mathStudent.h */
#ifndef MATHSTUDENT_H
#define MATHSTUDENT_H

#include "student.h"

template<typename T>
class mathStudent : public student {
private:
    T quiz[3];
    T test1;
    T test2;
    T final;
public:
    mathStudent(string firstName, string lastName)
            : student(firstName, lastName, "Math") {}

    float calculateFinalAverage() {
        T quizSum = quiz[0] + quiz[1] + quiz[2];
        float quizAvg = static_cast<float>(quizSum) / 3;
        return 0.1 * quizAvg + 0.25 * (test1 + test2) + 0.4 * final;
    }

    void readData(istream& in) {
        for ( int i = 0; i < 3; i++ )
            in >> quiz[i];
        in >> test1 >> test2 >> final;
    }

    int getFinalIntegerPart() { return static_cast<int>(final); }

};

#endif //MATHSTUDENT_H
