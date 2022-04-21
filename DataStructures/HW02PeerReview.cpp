//
// Created by Matthew Li on 4/20/22.
//
#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
using namespace std;

class Student{
private:
    int arrivalTime;
    int waitTime;
    int spentTime;
    bool currentTime;
public:
    Student(int aT, int wT, int sT){
        waitTime=wT;
        arrivalTime=aT;
        spentTime=sT;
        currentTime=false;
        //currentTime means that professor working with student.
    }
    int getArrivalTime(){return arrivalTime;}
    int getWaitTime(){return waitTime;}
    int getSpentTime(){return spentTime;}
    bool getCurrentTime(){return currentTime;}
    void setArrivalTime(int input){arrivalTime=input;}
    void setWaitTime(int input){waitTime=input;}
    void setSpentTime(int input){spentTime=input;}
    void setCurrentTime(bool input){currentTime=input;}
};

void officeHours(double* averageWait, double* averageSpent, double* averageTime){
    int wait=0;
    int officeHourTime=0;
    int spentTime=0;
    double count=0.0;
    queue<Student> queue;
    srand(time(NULL));

    for(officeHourTime=0; officeHourTime<60; officeHourTime++){
    //Maybe name it currentTime instead of officeHourTime, and then pass in currentTime as arrivalTime when student arrive?
        int temp=rand()%100; //Probability a student will go into the office hours. Could be better? Our original code has it hard coded.
        if(temp<15){
            int temp2=rand()%10+3;
            Student toAdd(0, officeHourTime, temp2);
            //Why is officeHourTime passed in for waitTime?
            //Sets object and immediately pushes into queue.
            //Why is arrivalTime 0? Is that assuming all the students pushed into queue at same time? That seems unrealistic. I think correct way is pass
            //officeHourTime, which is suggest you also rename as currentTime.
            queue.push(toAdd);
            spentTime+=temp2;
            count++;
        }
        //Looks like teacher would be working with student WHILE student is still in the queue, then student gets removed from queue when done.
        //Based on my understanding from car wash, first pop out student from the queue, then work with teacher. In the meantime there's a simulation for START working with professor.
        //Then start tracking time, decrement time.
        if(!queue.empty()){
            if(queue.front().getSpentTime()==0){
                queue.pop();
            }
            if(queue.front().getCurrentTime()==false){
                queue.front().setCurrentTime(true);
                queue.front().setWaitTime(officeHourTime-queue.front().getArrivalTime());
                wait+=queue.front().getWaitTime();
            }
            //Modified so function will always decrement spent time for student at front of queue.
            queue.front().setSpentTime(queue.front().getSpentTime()-1);

        }

    }
    while(!queue.empty()){
        if(queue.front().getSpentTime()==0){
            queue.pop();
            //Should we set a variable to queue's front?
        }
        if(queue.front().getCurrentTime()==false){ //Meaning slot is available(?)
            queue.front().setCurrentTime(true); //Professor now works with student
            queue.front().setWaitTime(officeHourTime-queue.front().getWaitTime());
            wait+=queue.front().getWaitTime();
            queue.front().setSpentTime(queue.front().getSpentTime()-1);
        }
        else{
            queue.front().setSpentTime(queue.front().getSpentTime()-1);
        }
        officeHourTime++;
    }
    *averageWait+=(wait/count);
    *averageSpent+=(spentTime/count);
    *averageTime+=officeHourTime;

}

int main()
{
    double averageWait=0;
    double averageSpent=0;
    double averageTime=0;
    int times = 100;
    for(int k=0; k <= times; k++){
        officeHours(&averageWait,&averageSpent,&averageTime);
    }

    cout<<"Average Student Wait Time: "<< averageWait/times << endl;
    cout << "Average Student Spent Time: "<< averageSpent/times << endl;
    cout << "Average Office Hour Length: "<< averageTime/times << endl;
    cout << "Average Time Professor Goes Over: "<<(averageTime/times)-60;
    return 0;
}

