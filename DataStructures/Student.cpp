//
// Created by Matthew Li on 5/8/22.
//

#include "Student.h"
#include <cstdlib>

Student::Student(double curSec) {
    string nameChar = "1234567890";
    string topicChar = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i = 0; i<1; i++) {
        name_+=nameChar[rand()%10];
    }
    for(int i = 0; i<15; i++) {
        topic_ +=topicChar[rand()%25];
    }
    arrivalTime_ = curSec;
    priority_ = (rand() % 10) + 1; //1 - 10 (inclusive).
}

bool operator<(const Student& s1, const Student& s2) {
    if (s1.getPriority() < s2.getPriority()) {
        return true;
    }
    return false;
}