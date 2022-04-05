//
// Created by Matthew Li on 4/4/22.
//

#ifndef DATASTRUCTURES_ARRAYUNDERSTACK_P369_H
#define DATASTRUCTURES_ARRAYUNDERSTACK_P369_H
#include <cstdlib>

namespace main_savitch_7A {
    template<class Item>
    class stack {
    public:
        typedef std::size_t  size_type;
        typedef Item value_type;
        static const size_type CAPACITY = 30;
        stack() {used = 0;}
        void push(const Item& entry);
        void pop();
        bool empty() const { return (used == 0); }
        size_type size() const {return used; }
        Item top() const;
    private:
        Item data[CAPACITY];
        size_type used;
    };
}


#endif //DATASTRUCTURES_ARRAYUNDERSTACK_P369_H
