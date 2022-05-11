//
// Created by Matthew Li on 5/7/22.
//

#ifndef DATASTRUCTURES_ARRAY_FUNCTIONS_H
#define DATASTRUCTURES_ARRAY_FUNCTIONS_H
#include <cassert>
#include <cstdlib>
namespace main_savitch_11 {
    template<class Item>
    int first_ge(const Item data[], int size, const Item &target) {
        int index = 0;
        while (index < size) {
            if (data[index] >= target) {
                return index;
            }
            index++;
        }
        return index;
    }

    template<class Item>
    void copy_array(Item dest[], Item source[], std::size_t &destSize, int sourceSize) {
        for (int i = 0; i < sourceSize; i++) {
            dest[i] = source[i];
        }
        destSize = sourceSize;
    }

    template<class Item>
    void insert_item(Item data[], int index, std::size_t &dataCount, Item entry) {
        assert(index <= dataCount);

        for (int i = dataCount; i > index; i--) {
            data[i] = data[i - 1]; //For inserting an element in array, need to shift elements after i.
        }
        data[index] = entry;
        dataCount++;
    }
    template<class Item>
    void delete_item(Item data[], int index, std::size_t &dataCount, Item& entry) {
        assert(index <= dataCount);
        entry = data[index];
        for(int i = index; i<dataCount-1; i++) {
            data[i] = data[i+1];
        }
        dataCount--;
    }

    template<class Item>
    void split(Item data[], std::size_t &n1, Item data2[], std::size_t &n2) {
        //Function will split out the second half of array into a new data2 array. For example, if you have array of tree elements
        //{13, 16, 19, 22, 25} Will copy 22 and 25 into data2, and resize data into {13, 16}.
        //Note: B-tree elements can never be even, as according to B-tree rules, MAXIMUM+1 means excess and MAXIMUM = 2*MINIMUM.
        //But the B-Tree's children it is possible to have even number, since split function needs to also be able to handle splitting the children nodes. So here we introduce
        // Odd and even split. For example if I have children {0, 1, 2, 3, 4, 5, 6} in this case {4, 5, 6} will split into data 2, data becomes {0, 1, 2}
        int mid = n1 / 2;
        if (n1 % 2 != 0) {
            for (int i = 0; i < mid; i++) {
                data2[i] = data[mid + i + 1];
            }
        } else {
            for (int i = 0; i < mid; i++) {
                data2[i] = data[mid + i];
            }
        }
        n1 = mid;
        n2 = mid;
    }

    template <class Item>
    void merge(Item data[], std::size_t &n1, Item data2[], std::size_t &n2) {
        for(int i = 0; i<n2; i++) {
            data[n1++] = data2[i];
        }
        n2 = 0;
    }
}
#endif //DATASTRUCTURES_ARRAY_FUNCTIONS_H
