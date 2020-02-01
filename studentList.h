/* studentList.h */
#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include <string>
#include <iostream>
#include <iomanip>
#include "student.h"

using namespace std;

class studentList {
private:
    student** pStudent;
    int size;
    int currentIndex;
    void resizePStudent(int n);     //no use of these functions in main
    int gradeCount(char grade);     //hence private functions.
    void outputFor(string sub, ostream& out);
public:
    studentList();
    ~studentList();
    bool importFromFile(string fileName);// bool for filename validity check
    bool exportToFile(string fileName);
    void printBrief() const;
};


#endif //STUDENTLIST_H
