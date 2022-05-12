//
// Created by Matthew Li on 4/14/22.
//

#include "Office_Hours_Simulator.h"
#include <cassert>
#include <cstdlib>
using namespace std;

namespace main_savitch_8A
{
    bool_source::bool_source(double p) {
        arrivalRate = p/100;
    }
    bool bool_source::query() const {
        return (rand() < arrivalRate*RAND_MAX);
    }

    averager::averager() {
        count = 0;
        totalWait = 0;
        totalSpend = 0;
        totalOver = 0;
    }
    void averager::next_number(int value) {
        ++count;
        totalWait += value;
    }

    void averager::student_session_time(int timeSpent) {
        totalSpend += timeSpent;
    }

    void averager::teacher_finished(int timeSpent) {
        totalOver += timeSpent;
    }


    double averager::averageWait() const {
        assert(how_many_numbers() > 0);
        return totalWait/count;
    }
    double averager::averageSpend() const {
        assert(how_many_numbers() > 0);
        return totalSpend/count;
    }
    double averager::averageOver(int officeCount) const {
        assert(officeCount > 0);
        return totalOver/officeCount;
    }

    education::education() {
        seconds_to_teach = 0;
        teach_time_left = 0;
    }
    void education::one_second() {
        if(is_busy()) {
            --teach_time_left;
        }
    }
    int education::start_teaching() {
        assert(!is_busy());
            int random = 1 + (rand()%10);
            teach_time_left = random;
            return random;
    }
}
