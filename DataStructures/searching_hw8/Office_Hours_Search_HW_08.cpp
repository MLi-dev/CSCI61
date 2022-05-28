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

void office_hour_simulate(double studentArrival, unsigned int totalTime, averager &waitTime, multimap<string, string>& mp, vector<Student>& studentVec, int officeHourNum);
void office1();
void find(string searchType, string name, vector<Student>& studentVec, vector<Student>& searchResult);

int main() {
    //Office1 prints out the simulation report. Depends if you enter Student or Topic it will generate in output file.
    office1();
}
void find(string searchType, string name, vector<Student>& studentVec, vector<Student>& searchResult) {
    for(auto e: studentVec) {
        if(searchType == "Student") {
            if(e.getName() == name) {
                searchResult.push_back(e);
            }
        } else if(searchType == "Topic") {
            if(e.getTopic() == name) {
                searchResult.push_back(e);
            }
        }
    }
}

void office_hour_simulate(double studentArrival, unsigned int totalTime, averager &waitTime, multimap<string, string>& mp, vector<Student>& studentVec, int officeHourNum) {
    priority_queue<Student> waitLine;
    unsigned int next;
    bool_source arrival(studentArrival);
    education teach;
    int curSec = 0;

    for (curSec = 1; curSec <= totalTime; curSec++) {
//        int priority = rand() % 100 + 1;
//        pair<int, int> p(priority, curSec);
        Student s(curSec, officeHourNum);
        studentVec.push_back(s);
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
    vector<Student> studentVec;

    for(int i = 1; i<=officeHourTimes; i++) {
        double studentArrivalRate = rand()%20+1;
        office_hour_simulate(studentArrivalRate, 60, wT, mp, studentVec, i);
    }
    string SOT;
    string name;
    //Search by topic
    cout<<"Would you like to find a Student or Topic? (Put in Student or Topic in this exact format)"<<endl;
    cin>>SOT;
    cout<<"Enter a name you want to find"<<endl;
    cin>>name;
    vector<Student> result;
    find(SOT, name, studentVec, result);
    for(auto e: result) {
        outStream<<e.getTopic()<<" "<<e.getName()<<" "<<e.getOfficeHourNum()<<endl;
    }
}

}
