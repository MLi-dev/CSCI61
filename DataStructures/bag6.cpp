//
// Created by Matthew Li on 4/21/22.
//

// FILE: bag6.template
// -------------------------------------------------------------------------
// This is a partial implementation of the bag template class from Section
// 10.5 of "Data Structures and Other Objects Using C++". The parts marked
// with ***STUDENT WORK*** are left as a project for data structures
// students. Some additional discussion of this project is available at
// http://www.cs.colorado.edu/~main/projects/chap10a.html
// -------------------------------------------------------------------------
// TEMPLATE CLASS IMPLEMENTED: bag<Item> (see bag6.h for documentation)
// INVARIANT of the ADT:
//   root_ptr is the root pointer of a binary search tree that contains the
//   bag's items.

#include <cassert>
#include <cstdlib>
#include "bintree.h"
#include "bag6.h"
namespace main_savitch_10
{
    template <class Item>
    void bst_remove_max(binary_tree_node<Item>*& root_ptr, Item& removed)
    // Precondition: root_ptr is a root pointer of a non-empty binary
    // search tree.
    // Postcondition: The largest item in the binary search tree has been
    // removed, and root_ptr now points to the root of the new (smaller)
    // binary search tree. The reference parameter, removed, has been set
    // to a copy of the removed item.
    {
        binary_tree_node<Item>* old_ptr;
        if(root_ptr->right() == NULL) {
            old_ptr = root_ptr;
            root_ptr = root_ptr->left();
            removed = old_ptr->data();
            delete old_ptr;
        } else {
            root_ptr = root_ptr->right();
            bst_remove_max(root_ptr, removed);
        }
        /***STUDENT WORK***
         ** This recursive function should be implemented by the student, as
         ** discussed on page 507 of the second edition of the textbook.
         ** The base case occurs when there is no right child of the
         ** root_ptr node. In this case, the root_ptr should be moved down
         ** to its left child and then the original root node must be
         ** deleted. There is also a recursive case, when the root does
         ** have a right child. In this case, a recursive call can be made
         ** using root_ptr->right( ) as the first parameter. Please notice
         ** in bintree.h, the return value from root_ptr->right( ) has been
         ** changed from the first printing of the book. The new version of
         ** the right() function has the prototype:
         **    binary_tree_node<Item>*&
         ** The & symbol in the return type means that the return value is
         ** a reference to the actual right pointer in the node. Any changes
         ** made to this pointer in the recursive call will directly change
         ** the right pointer in the root_ptr's node.
         */
    }

    template <class Item>
    bool bst_remove(binary_tree_node<Item>*& root_ptr, const Item& target)
    // Precondition: root_ptr is a root pointer of a binary search tree
    // or may be NULL for an empty tree).
    // Postcondition: If target was in the tree, then one copy of target
    // has been removed, and root_ptr now points to the root of the new
    // (smaller) binary search tree. In this case the function returns true.
    // If target was not in the tree, then the tree is unchanged (and the
    // function returns false).
    {
        binary_tree_node<Item> *oldroot_ptr;

        if (root_ptr == NULL)
        {   // Empty tree
            return false;
        }

        if (target < root_ptr->data( ))
        {   // Continue looking in the left subtree
            // Note: Any change made to root_ptr->left by this recursive
            // call will change the actual left pointer (because the return
            // value from the left() member function is a reference to the
            // actual left pointer.
            binary_tree_node<double>* b = root_ptr->left();
            return bst_remove(b, target);
        }

        if (target > root_ptr->data( ))
        {   // Continue looking in the right subtree
            // Note: Any change made to root_ptr->right by this recursive
            // call will change the actual right pointer (because the return
            // value from the right() member function is a reference to the
            // actual right pointer.
            binary_tree_node<double>* b = root_ptr->right();
            return bst_remove(b, target);
        }

        if (root_ptr->left( ) == NULL)
        {   // Target was found and there is no left subtree, so we can
            // remove this node, making the right child be the new root.
            oldroot_ptr = root_ptr;
            root_ptr = root_ptr->right( );
            delete oldroot_ptr;
            return true;
        }

        // If code reaches this point, then we must remove the target from
        // the current node. We'll actually replace this target with the
        // maximum item in our left subtree.
        // Note: Any change made to root_ptr->left by bst_remove_max
        // will change the actual left pointer (because the return
        // value from the left() member function is a reference to the
        // actual left pointer.
        binary_tree_node<double>* b = root_ptr->left();
        bst_remove_max(b, root_ptr->data( ));
        return true;
    }

    template <class Item>
    typename bag<Item>::size_type bst_remove_all
            (binary_tree_node<Item>*& root_ptr, const Item& target)
    // Precondition: root_ptr is a root pointer of a binary search tree
    // or may be NULL for an empty tree).
    // Postcondition: All copies of target have been removed from the tree
    // has been removed, and root_ptr now points to the root of the new
    // (smaller) binary search tree. The return value tells how many copies
    // of the target were removed.
    {
        /** STUDENT WORK
         ** Note: This implementation is similar to bst_remove, except that
         ** all occurrences of the target must be removed, and the return
         ** value is the number of copies that were removed.
         */

        binary_tree_node<Item> *oldroot_ptr;

        if (root_ptr == NULL)
        {   // Empty tree
            /* STUDENT WORK */
        }

        if (target < root_ptr->data( ))
        {   // Continue looking in the left subtree
            /* STUDENT WORK */
        }

        if (target > root_ptr->data( ))
        {   // Continue looking in the right subtree
            /* STUDENT WORK */
        }

        if (root_ptr->left( ) == NULL)
        {   // Target was found and there is no left subtree, so we can
            // remove this node, making the right child be the new root.
            oldroot_ptr = root_ptr;
            root_ptr = root_ptr->right( );
            delete oldroot_ptr;
            return 1;
        }
        int count;
        while(root_ptr->left() != NULL) {
            if(target == root_ptr->data()) {
                bst_remove(root_ptr, target);
                count++;
            } else {
                root_ptr = root_ptr->left();
            }

        }

        // If code reaches this point, then we must remove the target from
        // the current node. We'll actually replace this target with the
        // maximum item in our left subtree. We then continue
        // searching for more copies of the target to remove.
        // This continued search must start at the current root (since
        // the maximum element that we moved up from our left subtree
        // might also be a copy of the target).
        /* STUDENT WORK */
        return count;

    }

    template <class Item>
    bag<Item>::bag()
    // Library facilities used: bintree.h
    {
        root_ptr = NULL;
    }
    template <class Item>
    void bag<Item>::printBag() const {
        print(root_ptr, 5);
    }

    template <class Item>
    bag<Item>::bag(const bag<Item>& source)
    // Library facilities used: bintree.h
    {
        root_ptr = tree_copy(source.root_ptr);
    }

    template <class Item>
    bag<Item>::~bag( )
    // Header file used: bintree.h
    {
        tree_clear(root_ptr);
    }

    template <class Item>
    typename bag<Item>::size_type bag<Item>::size( ) const
    // Header file used: bintree.h
    {
        return tree_size(root_ptr);
    }

    template <class Item>
    void bag<Item>::insert(const Item& entry)
    // Header file used: bintree.h
    {
        binary_tree_node<Item> *cursor;

        if (root_ptr == NULL)
        {   // Add the first node of the binary search tree:
            root_ptr = new binary_tree_node<Item>(entry);
            return;
        }
        else {   // Move down the tree and add a new leaf:
            cursor = root_ptr;
            bool done = false;
            while (!done) {
                if (entry <= root_ptr->data()) {
                    if (root_ptr->left() != NULL) {
                        root_ptr = root_ptr->left();
                    } else {
                        root_ptr->set_left(new binary_tree_node<Item>(entry));
                        done = true;
                    }
                } else {
                    if (root_ptr->right() != NULL) {
                        root_ptr = root_ptr->right();
                    } else {
                        root_ptr->set_right(new binary_tree_node<Item>(entry));
                        done = true;
                    }
                }
            }
        }
        return;
    }


    template <class Item>
    typename bag<Item>::size_type bag<Item>::count(const Item& target) const
    {
        size_type answer = 0;
        binary_tree_node<Item> *cursor;
        cursor = root_ptr;
        while(cursor != NULL) {
            if(target < cursor->data()) {
                cursor = cursor->left();
            } else if(target > cursor->data()){
                cursor = cursor->right();
            } else {
                answer++;
                cursor = cursor->left();
            }
        }
        return answer;
    }

    template <class Item>
    typename bag<Item>::size_type bag<Item>::erase(const Item& target)
    {
        return bst_remove_all(root_ptr, target);
    }

    template <class Item>
    bool bag<Item>::erase_one(const Item& target)
    {
        return bst_remove(root_ptr, target);
    }

    template <class Item>
    void bag<Item>::operator =(const bag<Item>& source)
    // Header file used: bintree.h
    {
        if (root_ptr == source.root_ptr)
            return;
        tree_clear(root_ptr);
        root_ptr = tree_copy(source.root_ptr);
    }


    //Must learn more about += operator in future.
    template <class Item>
    void bag<Item>::operator +=(const bag<Item>& addend)
    {
        if (root_ptr == addend.root_ptr)
        {
            bag<Item> copy = addend;
            insert_all(copy.root_ptr);
        }
        else
            insert_all(addend.root_ptr);
    }

    template <class Item>
    bag<Item> operator +(const bag<Item>& b1, const bag<Item>& b2)
    {
        bag<Item> answer = b1;
        answer += b2;
        return answer;
    }

    template <class Item>
    void bag<Item>::insert_all(binary_tree_node<Item>* addroot_ptr)
    // Precondition: addroot_ptr is the root pointer of a binary search tree that
    // is separate for the binary search tree of the bag that activated this
    // method.
    // Postcondition: All the items from the addroot_ptr's binary search tree
    // have been added to the binary search tree of the bag that activated this
    // method.
    {
        if (addroot_ptr != NULL)
        {
            insert(addroot_ptr->data( ));
            insert_all(addroot_ptr->left( ));
            insert_all(addroot_ptr->right( ));
        }
    }
}

