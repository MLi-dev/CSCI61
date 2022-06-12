//
// Created by Matthew Li on 5/8/22.
//

#include "Student.h"
#include <cstdlib>

Student::Student(double curSec, int officeHour) {
    string nameChar = "1234567890";
    string topicArr[4] = {"Math", "English", "Science", "History"};
    for(int i = 0; i<1; i++) {
        name_+=nameChar[rand()%10];
    }
        topic_ =topicArr[rand()%4];
    arrivalTime_ = curSec;
    priority_ = (rand() % 10) + 1; //1 - 10 (inclusive).
    officeHourNum_ = officeHour;
}

bool operator<(const Student& s1, const Student& s2) {
    if (s1.getPriority() < s2.getPriority()) {
        return true;
    }
    return false;
}