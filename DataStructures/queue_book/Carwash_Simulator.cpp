//
// Created by Matthew Li on 4/14/22.
//

#include "Carwash_Simulator.h"
#include <cassert>
namespace main_savitch_8A {
    bool_source::bool_source(double p) { //Records probability of a car going in carwash
        assert(p >= 0);
        assert(p <= 1);
        probability = p;
    }

    bool bool_source::query() {
        return (rand() < probability * RAND_MAX);
    }

    averager::averager() {
        sum = 0;
        count = 0;
    }

    void averager::next_number(double waitTime) {
        ++count;
        sum += waitTime;
    }

    double averager::average() const {
        assert(how_many_numbers() > 0);
        return sum / count;
    }

    washer::washer(unsigned int s) {
        wash_time = s;
        wash_time_left = 0;
    }

    void washer::one_second() {
        if(!is_busy()) {
            --wash_time_left;
        }
    }

    void washer::start_washing() {
        assert(is_busy());
        wash_time_left = wash_time;

    }
}