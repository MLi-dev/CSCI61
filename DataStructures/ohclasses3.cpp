#include <iostream>
#include <cassert>
#include <cstdlib>
#include "ohclasses3.h"
using namespace std;

bts::bts(double p){
    assert(p >= 0 && p <= 1);   //probability must be between 0 and 1
    probability = p;
}

bool bts::query() const{
    //say 0.2 is the proportion that comes to OH
    return (rand() < probability * RAND_MAX);
}

int bts::generate_time(){
    return (rand() % 10 + 1);   //a student q can take anywhere from 1-10 min
}

int bts::generate_topic(int size){
    return (rand() % size);   //topic can be from index 0-size of topic array
}

int bts::generate_number(){
    return (rand() % 40 + 1);  //40 students to choose from
}

math::math(){   //math class default constructor
    count = 0;
    sum = 0;
}

void math::add_value(int value){
    sum += value;
    ++count;
}

double math::calc_average(){
    assert(count != 0);   //don't want divide by 0 error
    return (sum/count);
}

professor::professor(){
    length_of_q = 0;
    q_time_left = 0;
}

void professor::set_time(int s){
    assert(s > 0);    //just in case a nonpositive value is entered
    length_of_q = s;
    q_time_left = 0;
}

void professor::one_second(){
    if(is_busy()){
        --q_time_left;
    }
}

void professor::start_teaching(){
    assert(!is_busy());
    q_time_left = length_of_q;
}
