//
// Created by Matthew Li on 4/14/22.
//


#include "Office_Hours_Simulator.h"
#include <queue>
#include <iostream>
using namespace std;
using namespace main_savitch_8A;

void office_hour_simulate(double studentArrival, unsigned int totalTime, averager& waitTime);

int main() {
    srand(time(NULL));
    double studentArrivalRate = rand()%100 + 1;
    cout<<studentArrivalRate<<endl;
    averager wT;
    int officeHourTimes = 1;
    for(int i = 1; i<=officeHourTimes; i++) {
        office_hour_simulate(studentArrivalRate, 60, wT);
    }
    cout<<"Number of students served: "<<wT.how_many_numbers()<<endl;
    cout<<"The average waiting time is: "<<wT.averageWait()<<" minutes"<<endl;
    cout<<"Average time student spent working with professor is: "<<wT.averageSpend()<<" minutes"<<endl;
    cout<<"Average time professor spent overtime each OH hosted is: "<<wT.averageOver(officeHourTimes)<<" minutes"<<endl;
}

void office_hour_simulate(double studentArrival, unsigned int totalTime, averager& waitTime) {
    queue<unsigned int> waitLine;
    unsigned int next;
    bool_source arrival(studentArrival);
    education teach;
    int curSec=0;
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
