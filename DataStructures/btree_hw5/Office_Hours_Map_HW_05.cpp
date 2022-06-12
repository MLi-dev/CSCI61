//
// Created by Matthew Li on 4/14/22.
//


#include <queue>
#include <iostream>
#include "Office_Hours_Simulator.h"
#include "map"
#include "Student.h"
#include "set"
#include "fstream"

using namespace std;
using namespace main_savitch_8A;

struct myComp {
    bool operator()(pair<int, int> &a, pair<int, int> &b) {
        return a.first > b.first;
    }
};

void office_hour_simulate(double studentArrival, unsigned int totalTime, averager &waitTime, multimap<string, string>& mp);
void office1();
void office2();

int main() {
    //Office1 prints out the simulation report.
    office1();
    //Office2 prints out the report as an input of a sorting function.
    office2();

}

void office_hour_simulate(double studentArrival, unsigned int totalTime, averager &waitTime, multimap<string, string>& mp) {
    priority_queue<Student> waitLine;
    unsigned int next;
    bool_source arrival(studentArrival);
    education teach;
    int curSec = 0;

    for (curSec = 1; curSec <= totalTime; curSec++) {
//        int priority = rand() % 100 + 1;
//        pair<int, int> p(priority, curSec);
        Student s(curSec);
        mp.insert(make_pair(s.getName(), s.getTopic()));
        if (arrival.query()) {
            waitLine.push(s);
        }
        if (!teach.is_busy() && !waitLine.empty()) {
            next = waitLine.top().getArrivalTime();
//            outStream << "Student priority is: " << waitLine.top().getPriority() << endl;
            waitLine.pop();
            if (!waitLine.empty()) {
//                outStream << "The next student priority is: " << waitLine.top().getPriority() << endl;
            } else {
//                outStream << "There is nobody else in the line waiting" << endl;
            }
            waitTime.next_number(curSec - next);
            int duration = teach.start_teaching();
            waitTime.student_session_time(duration);
            //outStream << "Student spent " << duration << " with the professor" << endl;
        }
        teach.one_second();
    }
    while (!waitLine.empty()) {
        if (!teach.is_busy() && !waitLine.empty()) {
            next = waitLine.top().getArrivalTime();
            waitLine.pop();
            waitTime.next_number(curSec - next);
            int duration = teach.start_teaching();
            // outStream << "Student spent " << duration << " with the professor" << endl;
            waitTime.student_session_time(duration);
            curSec += duration;
        }
        teach.one_second();
    }
    int overtime = curSec - totalTime;
    waitTime.teacher_finished(overtime);
}
void office1() {
    ofstream outStream;
    outStream.open("Officeoursout.txt");
    srand(time(NULL));
    averager wT;
    int officeHourTimes = 3;
    multimap<string, string> mp;

    for(int i = 1; i<=officeHourTimes; i++) {
        double studentArrivalRate = rand()%20+1;
        office_hour_simulate(studentArrivalRate, 60, wT, mp);
    }
    outStream << "Number of students served: " << wT.how_many_numbers() << endl;
    outStream << "The average waiting time is: " << wT.averageWait() << " minutes" << endl;
    outStream << "Average time student spent working with professor is: " << wT.averageSpend() << " minutes" << endl;
    outStream << "Average time professor spent overtime each OH hosted is: " << wT.averageOver(officeHourTimes) << " minutes"
              << endl;
    multimap<string, string>::const_iterator i;
    set<string> keySet;
    for(i = mp.begin(); i!= mp.end(); i++) {
        keySet.insert(i->first);
    }
    for(auto e: keySet) {
        outStream<<"*********************************************************"<<endl;
        outStream<<"Report for "<<e<<": "<<endl;
        outStream<<"*********************************************************"<<endl;
        int count = 0;
        for(auto itr = mp.find(e); itr != mp.end(); itr++) {
            outStream<<"Topic taken: "<<itr->second<<endl;
            count++;
        }
        outStream<<"Total office hour time: "<<count<<endl;

    }
}
void office2() {
    ofstream outStream;
    outStream.open("Officeoursout2.txt");
    srand(time(NULL));
    averager wT;
    int officeHourTimes = 3;
    multimap<string, string> mp;

    for(int i = 1; i<=officeHourTimes; i++) {
        double studentArrivalRate = rand()%20+1;
        office_hour_simulate(studentArrivalRate, 60, wT, mp);
    }
    multimap<string, string>::const_iterator i;
    set<string> keySet;
    for(i = mp.begin(); i!= mp.end(); i++) {
       outStream<<i->first<<" "<<i->second<<endl;
    }

}
