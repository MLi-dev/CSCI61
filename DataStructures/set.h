//
// Created by Matthew Li on 5/7/22.
//

// FILE: set.h (part of the namespace main_savitch_11)
// TEMPLATE CLASS PROVIDED: set<Item>
//   (a container template class for a set of items)
//
// TYPEDEFS for the set<Item> class:
//   set<Item>::value_type
//     set<Item>::value_type is the data type of the items in the set. It may be
//     any of the C++ built-in types (int, char, etc.), or a class with a
//     default constructor, a copy constructor, an assignment operator, and a
//     less-than operator forming a strict weak ordering.
//
// CONSTRUCTOR for the set<Item> class:
//   set( )
//     Postcondition: The set is empty.
//
// MODIFICATION MEMBER FUNCTIONS for the set<Item> class:
//   void clear( )
//     Postcondition: The set is empty.
//
//   bool insert(const Item& entry)
//     Postcondition: If an equal entry was already in the set, the set is
//     unchanged and the return value is false. Otherwise, entry was added
//     to the set and the return value is true. This is slightly different than
//     the C++ Standard Library set (see Appendix H).
//
//   size_t erase(const Item& target)
//     Postcondition: If target was in the set, then it has been removed from
//     the set and the return value is 1. Otherwise the set is unchanged and the
//     return value is zero.
//
// CONSTANT MEMBER FUNCTIONS for the Set<Item> class:
//   size_t count(const Item& target) const
//     Postcondition: Returns the number of items equal to the target
//     (either 0 or 1 for a set).
//
//  bool empty( ) const
//     Postcondition: Returns true if the set is empty; otherwise returns false.
//
// VALUE SEMANTICS for the set<Item> class:
//   Assignments and the copy constructor may be used with set<Item> objects.
//
// DYNAMIC MEMORY USAGE by the set<Item> class:
//   If there is insufficient dynamic memory, then the following functions throw
//   bad_alloc:
//   The constructors, insert, and the assignment operator.

#ifndef MAIN_SAVITCH_SET_H
#define MAIN_SAVITCH_SET_H

#include <cstdlib>   // Provides size_t
#include <iomanip>
#include "set_array_helper.h"
#include <fstream>
using std::ofstream;

namespace main_savitch_11 {

    template<class Item>
    class set {
    public:
        // TYPEDEFS
        typedef Item value_type;

        // CONSTRUCTORS and DESTRUCTOR
        set();

        set(const set &source);

        ~set() { clear(); }

        // MODIFICATION MEMBER FUNCTIONS
        void operator=(const set &source);

        void clear();

        bool insert(const Item &entry);

        std::size_t erase(const Item &target);

        // CONSTANT MEMBER FUNCTIONS
        std::size_t count(const Item &target) const;

        bool empty() const { return (data_count == 0); }

        // SUGGESTED FUNCTION FOR DEBUGGING
        void print(int indent, std::ostream &outs) const;

        void copy_tree(set<Item> &other);

    private:
        // MEMBER CONSTANTS
        static const std::size_t MINIMUM = 1;
        static const std::size_t MAXIMUM = 2 * MINIMUM;
        // MEMBER VARIABLES
        std::size_t data_count;
        Item data[MAXIMUM + 1];
        std::size_t child_count;
        set *subset[MAXIMUM + 2];

        // HELPER MEMBER FUNCTIONS
        bool is_leaf() const { return (child_count == 0); }

        bool loose_insert(const Item &entry);

        bool loose_erase(const Item &target);

        void remove_biggest(Item &removed_entry);

        void fix_excess(std::size_t i);

        void fix_shortage(std::size_t i);
        // NOTE: The implementor may want to have additional helper functions
    };

    template<class Item>
    set<Item>::set() {
        data_count = 0;
        child_count = 0;
    }

    template<class Item>
    set<Item>::set(const set &source) {
        data_count = 0;
        child_count = 0;
        this->copy_tree(source);
    }

    template<class Item>
    void set<Item>::clear() {
        for (int i = 0; i < child_count; i++) {
            subset[i]->clear();
            delete subset[i];
        }
        for (int i = 0; i < MAXIMUM + 2; i++) {
            subset[i] = NULL;
        }
        data_count = 0;
        child_count = 0;
    }

    template<class Item>
    bool set<Item>::insert(const Item &entry) {
        bool result = loose_insert(entry);
        if (data_count > MAXIMUM) {
            set<Item> *new_child;
            new_child = new set<Item>();
            copy_array(new_child->data, data, new_child->data_count, data_count);
            copy_array(new_child->subset, subset, new_child->child_count, child_count);
            data_count = 0;
            child_count = 1;
            subset[0] = new_child;
            fix_excess(0);
        }
    }

    template<class Item>
    void set<Item>::fix_excess(std::size_t i) {
        Item mid;
        mid = subset[i]->data[(MAXIMUM + 1) / 2];
        set<Item> *new_child;
        new_child = new set<Item>();
        split(subset[i]->data, subset[i]->data_count, new_child->data, new_child->data_count);
        split(subset[i]->subset, subset[i]->child_count, new_child->subset, new_child->child_count);
        insert_item(subset, i + 1, child_count, new_child);
        insert_item(data, i, data_count, mid);
    }

    template<class Item>
    bool set<Item>::loose_insert(const Item &entry) {
        int i = first_ge(data, data_count, entry);
        if (data[i] == entry) {
            return false;
        } else if (this->is_leaf()) {
            insert_item(data, i, data_count, entry);
            return true;
        } else {
            subset[i]->loose_insert(entry);
            if (subset[i]->data_count > MAXIMUM) {
                this->fix_excess(i);
            }
            return true;
        }
    }

    template<class Item>
    void set<Item>::copy_tree(set<Item> &other) {
        this->clear();
        copy_array(this->data, other.data, this->data_count, other.data_count);
        this->child_count = other.child_count;
        for (int i = 0; i < other.child_count; i++) {
            subset[i]->copy_tree(*other.subset[i]);
        }
    }

    template<class Item>
    void set<Item>::print(int indent, std::ostream &outs) const {
        if (!is_leaf()) {
            for (int i = 1; i <= data_count; i++) {
                subset[child_count - i]->print(indent + 1, outs);
                outs << std::setw(indent * 4) << "" << data[data_count - i] << std::endl;
            }
            subset[0]->print(indent + 1, outs);
        } else {
            for (int i = data_count - 1; i >= 0; i--) {
                outs << std::setw(indent * 4) << "" << data[i] << std::endl;
            }
        }

    }

    template<class Item>
    bool set<Item>::loose_erase(const Item &target) {
        Item hold;
        int index;
        bool found;
        index = first_ge(data, data_count, target);
        if ((child_count == 0 && data[index] != target) || (child_count == 0 && index >= data_count)) {
            return false;
        } else if (child_count == 0 && data[index] == target) {
            delete_item(data, index, data_count, hold);
            return true;
        } else if (child_count > 0 && data[index] != target) {
            found = subset[index]->loose_erase(target);
            if (subset[index]->data_count < MINIMUM) {
                fix_shortage(index);
            }
            return found;
        } else if (child_count > 0 && data[index] == target) {
            subset[index]->remove_biggest(data[index]);
            if (subset[index]->data_count < MINIMUM) {
                fix_shortage(index);
            }
            return true;
        }
    }

    template<class Item>
    void set<Item>::remove_biggest(Item &removed_entry) {
        if (child_count == 0) {
            removed_entry = data[data_count - 1];
            data_count--;
        } else {
            subset[child_count - 1]->remove_biggest(removed_entry);
            if (subset[child_count - 1]->data_count < MINIMUM) {
                fix_shortage(child_count - 1);
            }
        }
    }

    template<class Item>
    void set<Item>::fix_shortage(std::size_t i) {
        Item hold;
        set *child_hold;

        if ((i >= 1) && subset[i - 1]->data_count > MINIMUM) {
            insert_item(subset[i]->data, 0, subset[i]->data_count, data[i - 1]);
            data[i - 1] = subset[i - 1]->data[subset[i - 1]->data_count - 1];
            subset[i - 1]->data_count--;
            if (subset[i - 1]->child_count > 0) {
                insert_item(subset[i]->subset, 0, subset[i]->child_count,
                            subset[i - 1]->subset[subset[i - 1]->child_count - 1]);
                subset[i - 1]->child_count--;
            }
        }

        if (i + 1 < child_count && subset[i + 1]->data_count > MINIMUM) {
            insert_item(subset[i]->data, 0, subset[i]->data_count, data[i]);
            data[i] = subset[i + 1]->data[0];
            delete_item(subset[i + 1]->data, 0, subset[i + 1]->data_count, hold);
            if (subset[i + 1]->child_count > 0) {
                insert_item(subset[i]->subset, subset[i]->child_count, subset[i]->child_count,
                            subset[i - 1]->subset[0]);
                delete_item(subset[i + 1]->subset, 0, subset[i + 1]->child_count, child_hold);
            }
        } else if (i>= 1 && subset[i - 1]->data_count == MINIMUM) {
            delete_item(data, i - 1, data_count, hold);
            subset[i - 1]->data[subset[i - 1]->data_count] = hold;
            subset[i - 1]->data_count++;
            merge(subset[i - 1]->data, subset[i - 1]->data_count, subset[i]->data, subset[i]->data_count);
            merge(subset[i - 1]->subset, subset[i - 1]->child_count, subset[i]->subset, subset[i]->child_count);
            delete_item(subset, i, child_count, child_hold);
            delete child_hold;
        } else if (i + 1 < child_count && subset[i + 1]->data_count == MINIMUM) {
            delete_item(data, i, data_count, hold);
            subset[i]->data[subset[i]->data_count] = hold;
            subset[i]->data_count++;
            merge(subset[i]->data, subset[i]->data_count, subset[i + 1]->data, subset[i + 1]->data_count);
            merge(subset[i]->subset, subset[i]->child_count, subset[i + 1]->subset, subset[i + 1]->child_count);
            delete_item(subset, i + 1, child_count, child_hold);
            delete child_hold;
        }
    }

    template<class Item>
    std::size_t set<Item>::erase(const Item &target) {
        if (!loose_erase(target)) {
            return false;
        }
        if (this->data_count == 0 && this->child_count == 1) {
            set<Item> *temp = this->subset[0];
            copy_array(this->data, temp->data, this->data_count, temp->data_count);
            copy_array(this->subset, temp->subset, this->child_count, temp->child_count);
            for (int i = 0; i < temp->child_count; i++) {
                temp->subset[i] = NULL;
            }
            temp->child_count = temp->data_count = 0;
            delete temp;
        }
        return true;
    }
}
#endif
