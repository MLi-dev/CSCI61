//
// Created by Matthew Li on 4/10/22.
//

#ifndef DATASTRUCTURES_STACK3_H
#define DATASTRUCTURES_STACK3_H

#include <cstdlib> // Provides size_t
namespace main_savitch_7A
{
    template <class Item>
    class stack
    {
    public:
        // TYPEDEFS AND MEMBER CONSTANT -- See Appendix E if this fails to compile.
        typedef std::size_t size_type;
        typedef Item value_type;
        static const size_type CAPACITY = 30;
        // CONSTRUCTOR
        stack( ) { used = 0; }
        // MODIFICATION MEMBER FUNCTIONS
        void push(const Item& entry);
        void pop( );
        Item& top( );
        // CONSTANT MEMBER FUNCTIONS
        bool empty( ) const { return (used == 0); }
        size_type size( ) const { return used; }
        const Item& top( ) const;
        int peek(int index) const;
    private:
        Item data[CAPACITY];        // Partially filled array
        size_type used;             // How much of array is being used
    };
}

#endif //DATASTRUCTURES_STACK3_H
