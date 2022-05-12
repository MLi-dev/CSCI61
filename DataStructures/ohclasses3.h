//
// Created by Matthew Li on 5/11/22.
//

#ifndef DATASTRUCTURES_OHCLASSES3_H
#define DATASTRUCTURES_OHCLASSES3_H

#include <cstdlib>
#include <iostream>
using namespace std;

class bts {
public:
    bts() { probability = 0.5; }  //default constructor
    bts(double p);    //setting constructor
    bool query() const;
    int generate_time();  //randomly generate how much time a q will take (within reason)
    int generate_topic(int size); //takes in size of array and randomly picks an index to be use to choose topic
    static int generate_number();  //used to generate suffix for student names (i.e. student4)
private:
    double probability; //probability that a student comes into OH at a given second
};

class math{
public:
    math();   //default constructor
    int get_count() { return count; }
    int get_sum() { return sum; }
    void add_value(int value);  //adds number to sum and increments count
    double calc_average();    //calculates average with sum and count
private:
    int count;    //# of values taken in
    int sum;   //sum of all values taken in
};

class professor{
public:
    professor();    //default constructor
    void set_time(int t);   //allows us to set time a particular question will take
    void one_second();  //subtracts 1 second (minute) from q_time_left
    void start_teaching();  //sets q_time_left equal to t, the time student's Q will take to answer
    bool is_busy() { return q_time_left > 0; }  //true if professor is answering a student's Q
private:
    int length_of_q;  //how long a student's Q will take to answer
    int q_time_left;  //time left answering student's question
};


#endif //DATASTRUCTURES_OHCLASSES3_H
