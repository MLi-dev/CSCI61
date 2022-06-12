//
// Created by Matthew Li on 4/4/22.
//

#ifndef DATASTRUCTURES_LINKEDLISTUNDERSTACK_P373_H
#define DATASTRUCTURES_LINKEDLISTUNDERSTACK_P373_H
#include <cstdlib>
#include "node2.h"

namespace main_savitch_7B {
    template<class Item>
    class stack {
    public:
        typedef std::size_t size_type;
        typedef Item value_type;
        stack() {top_ptr = NULL; }
        stack(const stack& source);
        ~stack() {main_savitch_6B::list_clear(top_ptr); }
        void push(const Item& entry);
        void pop();
        void operator = (const stack& source);
        size_type size() const { return main_savitch_6B::list_length(top_ptr); }
        bool empty() const {return(top_ptr == NULL); }
        Item top() const;
    private:
        main_savitch_6B::node<Item>* top_ptr;
    };
}


#endif //DATASTRUCTURES_LINKEDLISTUNDERSTACK_P373_H
