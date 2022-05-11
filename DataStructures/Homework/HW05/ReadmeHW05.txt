*Problem #1:
1. To run HW05_P1_bag_test.cpp, must include bag6.cpp, bag6.h, bintree.cpp, and bintree.h. Need to download my version of bintree, as  binary_tree_node*& left( ) is now call by reference, same for right pointer. Otherwise will give error.
2. Run bag6test.cpp, will display a menu of all key inputs for building tree.
    1. When 'I' or 'i' is pressed, then a number is entered, allows user to insert a node with that number into the tree.
    2. When 'O' or 'o' is pressed, then a number is entered, a single node with this number is removed from the tree.
    3. When 'E' or 'e' is pressed, then a number is entered, all nodes with this number are removed from the tree.
    4. When 'D' is pressed, displays a counter of numbers 0-9 in b1 and b2.
3. In the display menu function, I have added more key inputs to help test.
    1. When 'f' is pressed, will fill the tree with 10 character values.
    2. When 'T' or 't' is pressed, will display the full tree in bag b1 or b2.
    3. When 'r' is pressed, will remove the elements of the tree. Will print out each step as each element is deleted.
    4.  Note the tree structure in the console is sideways, the leftmost node is the root node. Left node is below, right node above the root.

*Problem #2:
1.To run HW05_P2_set_main.cpp, must include set.h, set_array_helper.h.
2. Will print out each step of adding/removing from the tree.

*Problem #3:
  1. Run Office_Hours_Map_HW_05_P3.cpp
  2. Depends on implementation code from the files Student.h and Office_Hours_Simulator.h and Office_Hours_Simulator.cpp
  3. There is no console input, the code runs office_hour_simulate 3 times, and the student arrival rate is set to a random rate each time.
  4. Every office hour is 60 minutes.
  5. Output is number of students served, average waiting time, average time professor spends with student, and average time professor spends overtime.
  6. Unlike HW_02, now using a priority queue and it takes in a pair where pair's first is a randomly generated priority, second is arrival time.
  7. I implemented a comparator which compares the pair's first values. The lower the value, the higher the priority.
  8. Every time a student enters the office, Will print out a list of the student's name plus the topic they are working on.

  **I have also done it so that now every time the code is executed, will print out onto automatically generated files, hence why no screenshots.