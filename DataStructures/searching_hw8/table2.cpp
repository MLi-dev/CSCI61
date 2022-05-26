//
// Created by Matthew Li on 5/26/22.
//

#include "table2.h"
// FILE: table1.template
// TEMPLATE CLASS IMPLEMENTED: table (see table1.h for documentation)
// INVARIANT for the table ADT:
//   1. The number of records in the table is in the member variable used.
//   2. The actual records of the table are stored in the array data, with
//      a maximum of CAPACITY entries. Each used spot in the array has a
//      non-negative key. Any unused record in the array has a key field of
//      NEVER_USED (if it has never been used) or PREVIOUSLY_USED (if it once
//      was used, but is  now vacant).

#include <cassert>  // Provides assert
#include <cstdlib>  // Provides size_t
#include "table2.h"
using namespace main_savitch_6B;

namespace main_savitch_12B {
    template<class RecordType>
    const std::size_t table<RecordType>::CAPACITY;

    template<class RecordType>
    const int table<RecordType>::NEVER_USED;

    template<class RecordType>
    const int table<RecordType>::PREVIOUSLY_USED;

    template<class RecordType>
    table<RecordType>::table() {
        std::size_t i;

        used = 0;
        for (i = 0; i < CAPACITY; ++i)
            data[i].key = NEVER_USED;  // Indicates a spot that's never been used.
    }

    template<class RecordType>
    void table<RecordType>::insert(const RecordType &entry)
    // Library facilities used: cassert
    {
        bool already_present;   // True if entry.key is already in the table
        std::size_t index;        // data[index] is location for the new entry

        assert(entry.key >= 0);
        index = hash(entry.key);
        main_savitch_6B::node<RecordType> *cur = data[index];
        main_savitch_6B::node<RecordType> *node = new main_savitch_6B::node<RecordType> *(entry, NULL);
        while (cur->link() != NULL) {
            cur = cur->link();
        }
        main_savitch_6B::node<RecordType> *node2 = new main_savitch_6B::node<RecordType> *(entry, NULL);
        cur->set_link(node2);
        used++;
    }

    template<class RecordType>
    void table<RecordType>::remove(int key)
    // Library facilities used: cassert
    {
        bool found;        // True if key occurs somewhere in the table
        std::size_t index;   // Spot where data[index].key == key

        assert(key >= 0);
        index = hash(key);
        if (is_present(key)) {   // The key was found, so remove this record and reduce used by 1.
            node<RecordType> *cur = data[index];
            removeHelper(key, cur);
            if(cur->link() == NULL) {
                data[index] = nullptr;
            }
        }
        used--;

    }
    //Practice more
    template<class T>
    void removeHelper(const T &p, node<T>* head) {
        std::size_t numDeleted = 0;
        node<T> *dummy = new node<T>(-1, head);
        node<T> *cur = dummy;
        while (cur->link() != nullptr) {
            if (cur->link()->data().key == p) {
                node<T> *temp = cur->link();
                cur->setlink(cur->link()->link());
                delete temp;
                numDeleted++;
            } else {
                cur = cur->link();
            }
        }
        head = dummy->link();
        delete dummy;
    }

    template<class RecordType>
    bool table<RecordType>::is_present(int key) const
    // Library facilities used: assert.h
    {
        index = hash(key);
        node<RecordType>* temp = data[index];
        if(temp != NULL) {
            return true;
        }
        return false;
    }

    template<class RecordType>
    void table<RecordType>::find(int key, bool &found, RecordType &result) const
    // Library facilities used: cassert.h
    {
       if(is_present(key)) {
           index = hash(key);
           node<RecordType> *cur = data[index];
           while(cur->data() != result) {
               cur = cur->link();
           }
           if(cur->data() == result) {
               found = true;
               result = cur->data();
           } else {
               found = false;
               result = NULL;
           }
       }
    }
    template<class RecordType>
    inline std::size_t table<RecordType>::hash(int key) const {
        return (key % CAPACITY);
    }
}

