//
// Created by Matthew Li on 4/10/22.
//

#include "stack3.h"
#include <cassert>  // Provides assert

namespace main_savitch_7A
{
    template <class Item>
    const typename stack<Item>::size_type stack<Item>::CAPACITY;

    template <class Item>
    void stack<Item>::push(const Item& entry)
    // Library facilities used: cassert
    {
        assert(size( ) < CAPACITY);
        data[used] = entry;
        ++used;
    }

    template <class Item>
    void stack<Item>::pop( )
    // Library facilities used: cassert
    {
        assert(!empty( ));
        --used;
    }

    template <class Item>
    Item& stack<Item>::top( )
    // Library facilities used: cassert
    {
        assert(!empty( ));
        return data[used-1];
    }

    template <class Item>
    const Item& stack<Item>::top( ) const
    // Library facilities used: cassert
    {
        assert(!empty( ));
        return data[used-1];
    }
    template <class Item>
    int stack<Item>::peek(int index) const {
        assert(!empty());
        return data[used-index];
    }
}
