//
// Created by Matthew Li on 4/14/22.
//

#include "Carwash_Simulator.h"
#include <queue>
#include <iostream>
using namespace std;
using namespace main_savitch_8A;

void car_wash_simulate(unsigned int washTime, double carProb, unsigned int totalTime);
int main() {
    car_wash_simulate(240, 1.0/100, 6000);
}

void car_wash_simulate(unsigned int washTime, double carProb, unsigned int totalTime) {
    queue<unsigned int> cars;
    unsigned int next;
    bool_source arrival(carProb);
    washer machine (washTime);
    averager waitTime;
    cout<<"Seconds to wash one car is "<<washTime<<endl;
    cout<<"Probability of a customer arrival during each second is "<<carProb<<endl;
    cout<<"Total time is "<<totalTime<<endl;
    for(int curSec = 1; curSec<=totalTime; curSec++) {
        if(arrival.query()) {
            cars.push(curSec);
        }
        if(!machine.is_busy() && !cars.empty()) {
            next = cars.front();
            cars.pop();
            waitTime.next_number(curSec - next);
            machine.start_washing();
        }
        machine.one_second();
    }
    cout<<"Number of cars serviced: "<<waitTime.how_many_numbers()<<endl;
    cout<<"The average waiting time is: "<<waitTime.average()<<endl;
}