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
#include "node2.h"
#include "node2.cpp"
using namespace main_savitch_6B;

namespace main_savitch_12B {
    template<class RecordType>
    const std::size_t table<RecordType>::CAPACITY;

    template<class RecordType>
    table<RecordType>::table() {
        std::size_t i;

        total_records = 0;
        for (i = 0; i < CAPACITY; ++i)
            data[i] = NULL;  // Indicates a spot that's never been used.
    }

    template<class RecordType>
    void table<RecordType>::insert(const RecordType &entry)
    // Library facilities used: cassert
    {
        bool already_present;   // True if entry.key is already in the table
        std::size_t index;        // data[index] is location for the new entry

        assert(entry.key >= 0);
        index = hash(entry.key);
        main_savitch_6B::node<RecordType> *head = data[index];
        main_savitch_6B::node<RecordType> *node = new main_savitch_6B::node<RecordType>(entry, NULL);
        if(head == NULL) {
            head = node;
        } else {
            main_savitch_6B::node<RecordType> *cur = head;
            while (cur->link() != NULL) {
                cur = cur->link();
            }
            cur->set_link(node);
        }
        data[index] = head;
        total_records++;
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
        total_records--;

    }
    //Practice more
    template<class RecordType>
    void table<RecordType>::removeHelper(int p, node<RecordType>* head) {
        std::size_t numDeleted = 0;
        RecordType r;
        node<RecordType> *dummy = new node<RecordType>(r, head);
        node<RecordType> *cur = dummy;
        while (cur->link() != nullptr) {
            if (cur->link()->data().key == p) {
                list_remove(cur);
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
        std::size_t index;
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
           std::size_t index = hash(key);
           node<RecordType> *cur = data[index];
           node<RecordType> *node = list_search(cur, key);
           if(node != NULL) {
               found = true;
               result = node->data();
           } else {
               found = false;
           }
       }
    }
    template<class RecordType>
    table<RecordType>::~table( ) {
        std::size_t i;
        for(i = 0; i<CAPACITY; i++) {
            while(data[i] != NULL) {
                node<RecordType>* pointer = data[i];
                node<RecordType>* temp = pointer;
                pointer = pointer->link();
                delete temp;
            }
            total_records--;
        }
    }
    template<class RecordType>
    inline std::size_t table<RecordType>::hash(int key) const {
        return (key % CAPACITY);
    }
}

