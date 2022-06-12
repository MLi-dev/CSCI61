//
// Created by Matthew Li on 4/21/22.
//

#include "bintree.h"
// FILE: bintree.template
// IMPLEMENTS: The binary_tree node class (see bintree.h for documentation).
#include <cassert>    // Provides assert
#include <cstdlib>   // Provides NULL, std::size_t
#include <iomanip>    // Provides std::setw
#include <iostream>   // Provides std::cout

namespace main_savitch_10
{
    template <class Process, class BTNode>
    void inorder(Process f, BTNode* node_ptr)
    // Library facilities used: cstdlib
    {
        if (node_ptr != NULL)
        {
            inorder(f, node_ptr->left( ));
            f( node_ptr->data( ) );
            inorder(f, node_ptr->right( ));
        }
    }

    template <class Process, class BTNode>
    void postorder(Process f, BTNode* node_ptr)
    // Library facilities used: cstdlib
    {
        if (node_ptr != NULL)
        {
            postorder(f, node_ptr->left( ));
            postorder(f, node_ptr->right( ));
            f(node_ptr->data( ));
        }
    }

    template <class Process, class BTNode>
    void preorder(Process f, BTNode* node_ptr)
    // Library facilities used: cstdlib
    {
        if (node_ptr != NULL)
        {
            f( node_ptr->data( ) );
            preorder(f, node_ptr->left( ));
            preorder(f, node_ptr->right( ));
        }
    }

    template <class Item, class SizeType>
    void print(binary_tree_node<Item>* node_ptr, SizeType depth, std::ostream& out)
    // Library facilities used: iomanip, iostream, stdlib
    {
        if (node_ptr != NULL)
        {
            print(node_ptr->right( ), depth+1, out);
            out << std::setw(4*depth) << ""; // Indent 4*depth spaces.
            out << node_ptr->data( ) << std::endl;
            print(node_ptr->left( ),  depth+1, out);
        }
    }

    template <class Item>
    void tree_clear(binary_tree_node<Item>*& root_ptr)
    // Library facilities used: cstdlib
    {
        binary_tree_node<Item>* child;
        if (root_ptr != NULL)
        {
            child = root_ptr->left( );
            tree_clear( child );
            child = root_ptr->right( );
            tree_clear( child );
            delete root_ptr;
            root_ptr = NULL;
        }
    }

    template <class Item>
    binary_tree_node<Item>* tree_copy(const binary_tree_node<Item>* root_ptr)
    // Library facilities used: cstdlib
    {
        binary_tree_node<Item> *l_ptr;
        binary_tree_node<Item> *r_ptr;

        if (root_ptr == NULL)
            return NULL;
        else
        {
            l_ptr = tree_copy( root_ptr->left( ) );
            r_ptr = tree_copy( root_ptr->right( ) );
            return
                    new binary_tree_node<Item>( root_ptr->data( ), l_ptr, r_ptr);
        }
    }

    template <class Item>
    size_t tree_size(const binary_tree_node<Item>* node_ptr)
    // Library facilities used: cstdlib
    {
        if (node_ptr == NULL)
            return 0;
        else
            return
                    1 + tree_size(node_ptr->left( )) + tree_size(node_ptr->right( ));
    }

    template <class Item>
    void reheapify(binary_tree_node<Item>*& root_ptr) {
        if (root_ptr->left() == nullptr && root_ptr->right() == nullptr) {
            return;
        }
        else {
            Item tempData;
            if (root_ptr->left() != nullptr) {
                if (root_ptr->data() < root_ptr->left()->data()) {
                    reheapify(root_ptr->left());
                    tempData = root_ptr->data();
                    root_ptr->set_data(root_ptr->left()->data());
                    root_ptr->left()->set_data(tempData);
                    reheapify(root_ptr->left());
                }
            }

            if (root_ptr->right() != nullptr) {
                if (root_ptr->data() < root_ptr->right()->data()) {
                    reheapify(root_ptr->right());
                    tempData = root_ptr->data();
                    root_ptr->set_data(root_ptr->right()->data());
                    root_ptr->right()->set_data(tempData);
                    reheapify(root_ptr->right());
                }

            }
        }
    }

    template <class Item>
    void reheapify1(binary_tree_node<Item>*& root_ptr) {
       if(root_ptr == NULL) {
           return;
       }
       int curVal = root_ptr->data();
       int leftVal = 0;
       int rightVal = 0;
       if(root_ptr->left() != NULL) {
            leftVal = root_ptr->left()->data();
       }
       if(root_ptr->right() != NULL) {
           rightVal = root_ptr->right()->data();
       }
       int larger = std::max(leftVal, rightVal);
       if(curVal < larger) {
           root_ptr->set_data(larger);
           if(larger == leftVal) {
               root_ptr->left()->set_data(curVal);
           } else {
               root_ptr->right()->set_data(curVal);
           }
       }
        reheapify(root_ptr->left());
        reheapify(root_ptr->right());

    }
}
