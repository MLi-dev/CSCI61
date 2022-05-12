*Problem #1:
1. Console will ask user to input a number of nodes.
2. Prints out how many different trees that can be made with the inputted number of nodes.
3. Improved performance by introducing map as cache. Will cache the subtree count so it won't do redundant recursion for counting subtrees.
*Problem #2:
1. Prompts the user to input a string representing a prefix expression. Note there must be spaces in between each operator/operand.
2. Must include bintree.cpp and bintree.h files.
3. Prints out the tree of operators and operands. Note the tree structure in the console is sideways, leftmost node is root, left subtree node below, right subtree node above root.
4. Sample input: - / + 8 10 2 * 3 2
*Problem #3:
1. To run bag6test.cpp, must include bag6.cpp, bag6.h, bintree.cpp, and bintree.h. Need to download my version of bintree, as  binary_tree_node*& left( ) is now call by reference, same for right pointer. Otherwise will give error.
2. Run bag6test.cpp, will display a menu of all key inputs for building tree.
    1. When 'I' or 'i' is pressed, then a number is entered, allows user to insert a node with that number into the tree.
    2. When 'O' or 'o' is pressed, then a number is entered, a single node with this number is removed from the tree.
    3. When 'E' or 'e' is pressed, then a number is entered, all nodes with this number are removed from the tree.
    4. When 'D' is pressed, displays a counter of numbers 0-9 in b1 and b2.
3. In the display menu function, I have added more key inputs to help test.
    1. When 'B' or 'b' is pressed, will fill the tree with 10 random values.
    2. When 'T' or 't' is pressed, will display the full tree in bag b1 or b2.
    3. Note the tree structure in the console is sideways, the leftmost node is the root node. Left node is below, right node above the root.