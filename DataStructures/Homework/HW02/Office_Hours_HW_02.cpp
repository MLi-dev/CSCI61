//
// Created by Matthew Li on 4/14/22.
//


#include "Office_Hours_Simulator.h"
#include <queue>
#include <iostream>
using namespace std;
using namespace main_savitch_8A;

void office_hour_simulate(double studentArrival, unsigned int totalTime);
int main() {
    office_hour_simulate( 1.0/5, 60);
}

void office_hour_simulate(double studentArrival, unsigned int totalTime) {
    queue<unsigned int> waitLine;
    unsigned int next;
    bool_source arrival(studentArrival);
    education teach;
    averager waitTime;
    cout<<"Rate of student arrival is: "<<studentArrival<<endl;
    cout<<"Total number of office hours hosted is "<<100<<" times"<<endl;
    cout<<"1 office hour is "<<totalTime<<" minutes"<<endl;
    int curSec=0;
    for(int i = 0; i<100; i++) {
        for (curSec = 1; curSec <= totalTime; curSec++) {
            if (arrival.query()) {
                waitLine.push(curSec);
            }
            if (!teach.is_busy() && !waitLine.empty()) {
                next = waitLine.front();
                waitLine.pop();
                waitTime.next_number(curSec - next);
                int duration = teach.start_teaching();
                waitTime.student_session_time(duration);
                //cout << "Student spent " << duration << " with the professor" << endl;
            }
            teach.one_second();
        }
        while (!waitLine.empty()) {
            if (!teach.is_busy() && !waitLine.empty()) {
                next = waitLine.front();
                waitLine.pop();
                waitTime.next_number(curSec - next);
                int duration = teach.start_teaching();
               // cout << "Student spent " << duration << " with the professor" << endl;
                waitTime.student_session_time(duration);
                curSec += duration;
            }
            teach.one_second();
        }
        int overtime = curSec - totalTime;
        waitTime.teacher_finished(overtime);
    }
    cout<<"Number of students served: "<<waitTime.how_many_numbers()<<endl;
    cout<<"The average waiting time is: "<<waitTime.averageWait()<<" minutes"<<endl;
    cout<<"Average time student spent working with professor is: "<<waitTime.averageSpend()<<" minutes"<<endl;
    cout<<"Average time professor spent overtime each OH hosted is: "<<waitTime.averageOver(100)<<" minutes"<<endl;
}