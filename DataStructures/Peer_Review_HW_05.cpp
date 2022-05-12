#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <queue>
#include <map>
#include <ctime>
#include "ohclasses3.h"
#include <fstream>
using namespace std;

struct Point{         //each data value in the queue will contain a Point
    int arrival_time;
    int time_for_q;
};

void simulate(double p_arrival, string arr[], int size, math & overtime, math & wait, math & length);

int main(){

    srand(time(0));
    math overtimes, waits, lengths;
    string topics[] = {"Stacks", "Queues", "Binary Search Trees", "Heaps", "B-Trees", "Maps", "Sorting", "Searching", "Other"};

    ofstream out_stream;
    out_stream.open("HW05output.txt");
    if(out_stream.fail()){
        cout << "File opening failed." << endl;
        exit(1);
    }

//test loop:
/*
for(int x=1; x <= 4; ++x){
  simulate(0.2, topics, 9, overtimes, waits, lengths);
  cout << "Total overtime spent so far:" << overtimes.get_sum() << endl;
  cout << overtimes.get_count() << endl;
}*/

    for(int x=1; x <= 100; ++x){
        simulate(0.2, topics, 9, overtimes, waits, lengths);
    }

    cout << "Average wait time: " << waits.calc_average() << endl;
    cout << "Average length of question: " << lengths.calc_average() << endl;
    cout << "Average time spent overtime: " << overtimes.calc_average() << endl;

    out_stream.close();

    return 0;
}

void simulate(double p_arrival, string arr[], int size, math & overtime, math & wait, math & length){
    queue <Point> students;   //put students into queue as they arrive
    Point s;    //each point will contain the arrival time AND the length of q for each student
    int student_count, num;  //use to name each student that comes in
    string name;
    bts arrival(p_arrival);
    professor prof;    //will insert time per question based on student data point

    //make multimap where keys are "student1", "student2", etc. Do this with string concatenation using the student_count
    //variable: i.e. "student" + to_string(student_count) will create the name "student1"
    multimap <string, string> m;
    //keys will be strings: student names
    //values will be strings also: topics of OH visit

    for(int i=1; i <= 60; ++i){   //OH runs for 60 minutes
        //Step 1: check if student has arrived
        if(arrival.query()){
            s.arrival_time = i;   //set arrival time component
            s.time_for_q = arrival.generate_time();   //set length of question
            length.add_value(s.time_for_q);    //add to length of ?
            students.push(s);   //push point into queue of students
            student_count = arrival.generate_number();    //generate student #
            name = "student" + to_string(student_count);  //create student name
            m.insert(pair <string, string> (name, arr[bts::generate_number()])); //create multimap key with topic value
        }

        //Step 2: check if professor can begin helping student
        if(!prof.is_busy() && !students.empty()){
            prof.set_time(students.front().time_for_q);   //initialize professor's job
            wait.add_value(i-students.front().arrival_time);  //add to wait times
            students.pop();   //remove student from queue
            prof.start_teaching();
        }

        //Step 3: progress
        prof.one_second();
    }

    //Step 4: calculate overtime once 60 min are over and continue adding wait times
    int j=61;
    for(j=61; !students.empty(); ++j){
        //if prof was in middle of helping a student when the loop ended
        //first finish helping that student
        if(!prof.is_busy()){   //don't need !empty condition since it is in the for loop
            prof.set_time(students.front().time_for_q); //give prof next student
            wait.add_value(j-students.front().arrival_time);  //add to wait times
            students.pop();
            prof.start_teaching();
        }
        prof.one_second();
    }
    overtime.add_value(j-60);   //adds total overtime
}
