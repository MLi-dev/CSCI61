//
// Created by Matthew Li on 4/14/22.
//


#include <queue>
#include <iostream>
#include "Office_Hours_Simulator.h"
using namespace std;
using namespace main_savitch_8A;

struct myComp {
    bool operator()(pair<int, int>& a, pair<int, int>& b)
    {
        return a.first > b.first;
    }
};

void office_hour_simulate(double studentArrival, unsigned int totalTime, averager& waitTime);

int main() {
//    priority_queue<pair<int,int>, vector<pair<int, int>>, myComp> waitLine;
//    for(int i = 0; i<10; i++) {
//        int priority = rand() % 100 + 1;
//        pair<int, int> p(priority, 1);
//        waitLine.push(p);
//    }
//    for(int i = 0; i<10; i++) {
//        cout<<waitLine.top().first<<endl;
//        waitLine.pop();
//    }

    srand(time(NULL));
    averager wT;
    int officeHourTimes = 3;
    for(int i = 1; i<=officeHourTimes; i++) {
        double studentArrivalRate = rand()%20+1;
        office_hour_simulate(studentArrivalRate, 60, wT);
    }
    cout<<"Number of students served: "<<wT.how_many_numbers()<<endl;
    cout<<"The average waiting time is: "<<wT.averageWait()<<" minutes"<<endl;
    cout<<"Average time student spent working with professor is: "<<wT.averageSpend()<<" minutes"<<endl;
    cout<<"Average time professor spent overtime each OH hosted is: "<<wT.averageOver(officeHourTimes)<<" minutes"<<endl;
}

void office_hour_simulate(double studentArrival, unsigned int totalTime, averager& waitTime) {
    priority_queue<pair<int,int>, vector<pair<int, int>>, myComp> waitLine;
    unsigned int next;
    bool_source arrival(studentArrival);
    education teach;
    int curSec=0;
        for (curSec = 1; curSec <= totalTime; curSec++) {
            int priority = rand()%100+1;
            pair<int, int> p(priority, curSec);
            if (arrival.query()) {
                waitLine.push(p);
            }
            if (!teach.is_busy() && !waitLine.empty()) {
                next = waitLine.top().second;
                cout<<"Student priority is: "<<waitLine.top().first<<endl;
                waitLine.pop();
                if(!waitLine.empty()) {
                    cout<<"The next student priority is: "<<waitLine.top().first<<endl;
                } else {
                    cout<<"There is nobody else in the line waiting"<<endl;
                }
                waitTime.next_number(curSec - next);
                int duration = teach.start_teaching();
                waitTime.student_session_time(duration);
                //cout << "Student spent " << duration << " with the professor" << endl;
            }
            teach.one_second();
        }
        while (!waitLine.empty()) {
            if (!teach.is_busy() && !waitLine.empty()) {
                next = waitLine.top().second;
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
