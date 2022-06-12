Problem 1:
    1. Implements chained hashing by modding key by CAPACITY. Anytime multiple records have same hash value, will group together as nodes in a linked list.
    2. When starting the main function, will give you instructions for what keys to press. S will print result, I inserts a new record, R removes a record that you will input, F searches for record, and Q exits.

Problem 2:
    1. Main function when run, will ask you whether you want to search based on Student or Topic (enter in that format).
    2. If the user entered Student, they must enter something such as "Student1", as it is structured so that name is student + a number. If topic, enter Math, Science, English, or History.
    3. Will print out in an output file three columns: Topic, Name, and Office Hour number.
Problem 3:
    1. Opens a puzzle file that I have now also modified to include the number of rows + number columns of puzzle.
    2. I created two arrays representing the combinations of number of steps for the x and y axes of the puzzle. I loop through the size of both arrays and add them to each row and column of puzzle.
    3. Keep adding as long as it matches with a word in the dictionary file.
    4. Also I have special cases when not to traverse fully across puzzle, such as when the row and column index I am looking at is in the corner.