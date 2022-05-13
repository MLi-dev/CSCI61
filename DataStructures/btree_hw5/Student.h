//
// Created by Matthew Li on 5/8/22.
//

#ifndef DATASTRUCTURES_STUDENT_H
#define DATASTRUCTURES_STUDENT_H
using namespace std;
#include <iostream>

class Student {
public:
    Student(double curSec);
    string getName() const { return name_; }
    string getTopic() const { return topic_; }
    int getArrivalTime() const {return arrivalTime_;}
    int getPriority() const {return priority_;}

private:
    string name_ = "Student";
    string topic_;
    int arrivalTime_;
    int priority_;
};

bool operator<(const Student& s1, const Student& s2);


#endif //DATASTRUCTURES_STUDENT_H
