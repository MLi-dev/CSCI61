//
// Created by Matthew Li on 4/4/22.
//

#include "ArrayunderStack_P369.h"
#include <cassert>
namespace main_savitch_7A {
//   template<class Item>
//   const typename stack<Item>::size_type stack<Item>::CAPACITY;

    template<class Item>
    void stack<Item>::push(const Item& entry) {
            assert(size()<CAPACITY);
            data[used] = entry;
            used++;
    }
    template<class Item>
    void stack<Item>::pop() {
        assert(!empty());
        used--;
    }

    template<class Item>
    Item stack<Item>::top() const {
        assert(!empty());
        return data[used-1];
    }


}