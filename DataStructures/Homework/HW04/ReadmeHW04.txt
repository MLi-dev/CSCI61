Problem 1:
1. Takes in a vector already written in in-order notation, and a vector already written in post-order notation.
2. Uses in-order and post-order vectors to construct binary tree containing parent node less than the child node.
3. Binary tree is printed sideways, left being root node, right being child nodes.
4. The reheapify function will do upward heapification to make binary tree become a max heap, root node largest, each subsequent node decreasing.
5. Prints out the binary tree as a max heap.

Problem 2:
1. Run Office_Hours_HW_04.cpp
2. Depends on implementation code from the files Office_Hours_Simulator.cpp and Office_Hours_Simulator.h.
3. There is no console input, the code runs office_hour_simulate 3 times, and the student arrival rate is set to a random rate each time.
4. Every office hour is 60 minutes.
5. Output is number of students served, average waiting time, average time professor spends with student, and average time professor spends overtime.
6. Unlike HW_02, now using a priority queue and it takes in a pair where pair's first is a randomly generated priority, second is arrival time.
7. I implemented a comparator which compares the pair's first values. The lower the value, the higher the priority.
8. Every time a student enters the office, Will print out the student's priority and the next student's priority to show it is picking the student of higher priority.
9. If there is no next student, will say there is no students waiting.