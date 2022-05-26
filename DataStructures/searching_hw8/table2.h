//
// Created by Matthew Li on 5/26/22.
//



#ifndef TABLE2_H
#define TABLE2_H
#include <cstdlib>    // Provides size_t
#include "node2.h"    // Provides the node type, from Figure 6.5 on page 306

namespace main_savitch_12B
{
    template <class RecordType>
    class table
    {
    public:
        // MEMBER CONSTANT -- See Appendix E if this fails to compile.
        static const std::size_t CAPACITY = 811;
        // CONSTRUCTORS AND DESTRUCTOR
        table( );
        table(const table& source);
        ~table( );
        // MODIFICATION MEMBER FUNCTIONS
        void insert(const RecordType& entry);
        void remove(int key);
        void operator =(const table& source);
        // CONSTANT MEMBER FUNCTIONS
        void find(int key, bool& found, RecordType& result) const;
        bool is_present(int key) const;
        std::size_t size( ) const { return total_records; }
    private:
        static const int NEVER_USED = -1;
        static const int PREVIOUSLY_USED = -2;
        main_savitch_6B::node<RecordType> *data[CAPACITY];
        std::size_t used;
        std::size_t total_records;
        // HELPER MEMBER FUNCTION
        std::size_t hash(int key) const;
    };
}



#endif //DATASTRUCTURES_TABLE2_H
