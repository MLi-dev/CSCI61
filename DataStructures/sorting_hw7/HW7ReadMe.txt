Problem #3:
1. Takes in a vector, sets the value at current Index as curVal, and compares to the value 1 index back.
2. If the value at the sortIndex, is greater than curVal, switch places and move the sortIndex back.

Problem #4:
1. Quicksort calls partition, which then takes in three arguments: The array, the beginning index of the array, and the end index of the part of array that will be osrted.

Problem #5:
1. The syntax for the sorting function is that it takes a vector of a pair of strings, the column (if 0 is passed in, sorts based on name, if 1, sorts based on topic), and direction (0 means ascending order, 1 means descending order).
2. Calls an additional continueSorting function, which will sort in the direction passed as argument (0, sorts in ascending, 1 sorts descending).
3. Sorts Officeoursout_HW7.txt, and then returns 4 files: Name sorted in ascending order, name sorted in descending order, topic sorted in ascending order, topic sorted in descending order.