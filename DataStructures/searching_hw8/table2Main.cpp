// FILE: testtab2.cxx
// An interactive test program for the second table ADT.

#include <cctype>      // Provides toupper
#include <cstdlib>     // Provides EXIT_SUCCESS and size_t
#include <iostream>    // Provides cin, cout
#include "table2.h"    // Provides the table class
#include "table2.cpp"    // Provides the table class
using namespace std;
using namespace main_savitch_12B;

// Struct definition for the test_record_type, which has a key and a double.
struct test_record_type
{
    int key;
    double data;
};

// PROTOTYPES for functions used by this test program:
void print_menu( );
// Postcondition: A menu of choices for this program has been written to cout.

char get_user_command( );
// Postcondition: The user has been prompted to enter a one character command.
// The next character has been read (skipping blanks and newline characters), 
// and this character has been returned.

test_record_type get_record( );
// Postcondition: The user has been prompted to enter data for a record. The
// key has been read, echoed to the screen, and returned by the function.

int get_key( );
// Postcondition: The user has been prompted to enter a key for a record. The
// items have been read, echoed to the screen, and returned by the function.


int main( )
{
    table<test_record_type> test;    // A table that we'll perform tests on
    char choice;                     // A command character entered by the user
    bool found;                      // Value returned by find function
    test_record_type result;         // Value returned by find function

    cout << "I have initialized an empty table. Each record in the table\n";
    cout << "has an integer key and a real number as data." << endl;

    do
    {
        print_menu( );
        choice = toupper(get_user_command( ));
        switch (choice)
        {
            case 'S': cout << "The table size is " << test.size( ) << endl;
                break;
            case 'I': test.insert(get_record( ));
                cout << "The record has been inserted." << endl;
                break;
            case 'R': test.remove(get_key( ));
                cout << "Remove has been called with that key." << endl;
                break;
            case '?': if (test.is_present(get_key( )))
                    cout << "That key is present." << endl;
                else
                    cout << "That key is not present." << endl;
                break;
            case 'F': test.find(get_key( ), found, result);
                if (found)
                    cout << "The key's data is: " << result.data << endl;
                else
                    cout << "That key is not present." << endl;
                break;
            case 'Q': cout << "Ridicule is the best test of truth." << endl;
                break;
            default:  cout << choice << " is invalid. Sorry." << endl;
        }
    }
    while ((choice != 'Q'));

    return EXIT_SUCCESS;
}

void print_menu( )
// Library facilities used: iostream.h
{
    cout << endl; // Print blank line before the menu
    cout << "The following choices are available: " << endl;
    cout << " S   Print the result from the size( ) function" << endl;
    cout << " I   Insert a new record with the insert(...) function" << endl;
    cout << " R   Remove a record with the remove(...) function" << endl;
    cout << " ?   Check whether a particular key is present" << endl;
    cout << " F   Find the data associated with a specified key" << endl;
    cout << " Q   Quit this test program" << endl;
}

char get_user_command( )
// Library facilities used: iostream.h
{
    char command;

    cout << "Enter choice: ";
    cin >> command; // Input of characters skips blanks and newline character

    return command;
}

test_record_type get_record( )
// Library facilities used: iostream.h
{
    test_record_type result;

    cout << "Please enter a real number for a record's data: ";
    cin  >> result.data;
    cout << result.data << " has been read." << endl;
    result.key = get_key( );
    return result;
}

int get_key( )
// Library facilities used: iostream.h
{
    int key;

    do
    {
        cout << "Please enter a non-negative integer for a key: ";
        cin  >> key;
    }
    while (key < 0);
    cout << key << " has been read." << endl;
    return key;
}