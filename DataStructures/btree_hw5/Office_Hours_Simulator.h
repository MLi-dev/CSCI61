//
// Created by Matthew Li on 4/14/22.
//

#ifndef DATASTRUCTURES_OFFICE_HOURS_SIMULATOR_H
#define DATASTRUCTURES_OFFICE_HOURS_SIMULATOR_H
#include <cstdlib>
namespace main_savitch_8A {
    class bool_source {
    public:
        bool_source(double p);
        bool query() const;
    private:
        double arrivalRate;
    };
    class averager {
    public:
        averager();
        void next_number(int value);
        void student_session_time(int timeSpent);
        void teacher_finished(int timeSpent);
        std::size_t how_many_numbers() const {return count; }
        double averageWait() const;
        double averageSpend() const;
        double averageOver(int officeCount) const;

    private:
        std::size_t count;
        double totalWait;
        double totalSpend;
        double totalOver;
    };
    class education
    {
     public:
        education();
        void one_second();
        int start_teaching();
        bool is_busy () { return (teach_time_left > 0); }
    private:
        unsigned int seconds_to_teach;
        unsigned int teach_time_left;
    };
}


#endif //DATASTRUCTURES_OFFICE_HOURS_SIMULATOR_H
