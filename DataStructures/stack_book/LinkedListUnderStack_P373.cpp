//
// Created by Matthew Li on 4/4/22.
//

#include "LinkedListUnderStack_P373.h"
#include <cassert>
namespace main_savitch_7B
{
    template <class Item>
    stack<Item>::stack(const stack<Item>& source){
        main_savitch_6B::node<Item> *tail_ptr;
        main_savitch_6B::list_copy(source.top_ptr, top_ptr, tail_ptr);
    }
    template<class Item>
    void stack<Item>::push(const Item& entry) {
        main_savitch_6B::list_head_insert(top_ptr, entry);
    }
    template<class Item>
    void stack<Item>::pop() {
        assert(!empty());
        main_savitch_6B::list_head_remove(top_ptr);
    }
    template<class Item>
    void stack<Item>::operator=(const stack<Item> &source) {
        if(this == &source) {
            return;
        }
        main_savitch_6B::node<Item> *tail_ptr;
        main_savitch_6B::list_clear(top_ptr);
        main_savitch_6B::list_copy(source.top_ptr, top_ptr, tail_ptr);
    }
    template<class Item>
    Item stack<Item>::top() const {
        assert(!empty());
        return top_ptr->data();
    }

}