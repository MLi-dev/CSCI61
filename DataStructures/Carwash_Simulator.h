//
// Created by Matthew Li on 4/14/22.
//

#ifndef DATASTRUCTURES_CARWASH_SIMULATOR_H
#define DATASTRUCTURES_CARWASH_SIMULATOR_H

#include <queue>

namespace main_savitch_8A {
    class bool_source {
    public:
        bool_source(double p = 0.5);

        bool query();

    private:
        double probability;
    };

    class averager {
    public:
        averager();

        void next_number(double waitTime);

        std::size_t how_many_numbers() const { return count; }

        double average() const;

    private:
        std::size_t count;
        double sum;
    };

    class washer {
    public:
        washer(unsigned int s = 60);

        void one_second();

        void start_washing();

        bool is_busy() const { return (wash_time_left > 0); }

    private:
        unsigned int wash_time_left;
        unsigned int wash_time;
    };

}


#endif //DATASTRUCTURES_CARWASH_SIMULATOR_H
