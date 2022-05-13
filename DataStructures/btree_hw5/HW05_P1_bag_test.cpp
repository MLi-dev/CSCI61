#include <cctype>     // Provides toupper
#include <iostream>   // Provides cout, cin
#include <cstdlib>    // Provides EXIT_SUCCESS, size_t
#include "bintree.h"
#include "bag6.h"     // Provides the bag<char> class (with Item as a char)
#include "bag6.cpp"
#include "vector"
#include <fstream>

using namespace std;
using namespace main_savitch_10;


// PROTOTYPES for the functions used in this test program.
void print_menu();
// Postcondition: A menu of choices for this program has been written to cout.

char get_user_command();
// Postcondition: The user has been prompted to enter a one character command.
// A line of input (with at least one character) has been read, and the first
// character of the input line is returned.

void display_bags(const bag<char> &b1, const bag<char> &b2);
// Postcondition: The function has tested whether the numbers 0..9 are in
// the two bags, and printed the results to standard output.

bag<char> copybag(bag<char> b);
// Postcondition: The return value is a copy of b.

char get_char();
// Postcondition: The user has been prompted to enter a char number. The
// number has been read, echoed to the screen, and returned by the function.

void display_bag_tree(bag<char> b, std::ostream& out);

int main() {
    ofstream outStream;
    outStream.open("HW05P1outfile.txt");
    bag<char> b1, b2;  // Bags that we'll perform tests on
    char choice; // A command character entered by the user

    cout << "I have initialized two empty bags of chars." << endl;

    do {
        //print_menu( );
        choice = get_user_command();
        switch (choice) {
            case 'A':
                b1 = b2;
                break;
            case 'a':
                b2 = b1;
                break;
            case 'f': {
                vector<char> v = {'S', 'F', 'E', 'V', 'D', 'U', 'J', 'P', 'O', 'T'};
                for (auto e: v) {
                    outStream<<"Adding "<<e<<endl;
                    b1.insert(e);
                    display_bag_tree(b1, outStream);
                }
                cout<<"The binary search tree has been generated, details shown in HW05P1outfile.txt"<<endl;
            }
                break;
            case 'r':
            {
                vector<char> v = {'S', 'F', 'E', 'V', 'D', 'U', 'J', 'P', 'O', 'T'};
                for (auto e: v) {
                    outStream<<"Removing "<<e<<endl;
                    b1.erase_one(e);
                    display_bag_tree(b1, outStream);
                }
                cout<<"The binary search tree has been erased, details shown in HW05P1outfile.txt"<<endl;
            }
                break;
            case 'C':
                b1 = copybag(b2);
                break;
            case 'c':
                b2 = copybag(b1);
                break;
            case 'S':
            case 's':
                cout << "The bags' sizes are " << b1.size();
                cout << " and " << b2.size() << endl;
                break;
            case 'I':
                b1.insert(get_char());
                break;
            case 'i':
                b2.insert(get_char());
                break;
            case 'O':
                b1.erase_one(get_char());
                break;
            case 'o':
                b2.erase_one(get_char());
                break;
            case 'E':
                b1.erase(get_char());
                break;
            case 'e':
                b2.erase(get_char());
                break;
            case 'D':
            case 'd':
                display_bags(b1, b2);
                break;
            case 'q':
            case 'Q':
                cout << "Ridicule is the best test of truth." << endl;
                break;
            case 'T':
                display_bag_tree(b1, outStream);
                break;
            case 't':
                display_bag_tree(b2, outStream);
                break;
            default:
                cout << choice << " is invalid. Sorry." << endl;

        }
    } while ((toupper(choice) != 'Q'));

    return EXIT_SUCCESS;

}

void display_bag_tree(bag<char> b, std::ostream& out) {
    b.printBag(out);
}

void print_menu()
// Library facilties used: iostream.h
{
    cout << "The following choices are available with 2 bags: " << endl;
    cout << " A  Use the assignment operator to make b1 equal to b2" << endl;
    cout << " a  Use the assignment operator to make b2 equal to b1" << endl;
    cout << " B  Inserts a batch of 10 items into b1. Item's data is randomly generated 1-10." << endl;
    cout << " b  Inserts a batch of 10 items into b2. Item's data is randomly generated 1-10" << endl;
    cout << " C  Use the copy constructor to make b1 equal to b2" << endl;
    cout << " c  Use the copy constructor to make b2 equal to b1" << endl;
    cout << " I  Insert an item into b1" << endl;
    cout << " i  Insert an item into b2" << endl;
    cout << " E  Erase item from b1" << endl;
    cout << " e  Erase item from b2" << endl;
    cout << " O  Erase one item from b1" << endl;
    cout << " o  Erase one item from b2" << endl;
    cout << " D  Display a count of items 0-9 in b1 and b2" << endl;
    cout << " S  Print the result from the size( ) functions" << endl;
    cout << " Q  Quit this test program" << endl;
    cout << " T  Displays all nodes of b1" << endl;
    cout << " t  Displays all nodes of b2" << endl;
}

char get_user_command()
// Library facilties used: iostream.h
{
    char command;

    cout << "Enter choice: ";
    cin >> command;

    return command;
}

void display_bags(const bag<char> &b1, const bag<char> &b2)
// Library facilties used: iostream.h
{
    int i;
    for (i = 0; i < 10; i++) {
        cout << i << " in b1? " << b1.count(i);
        cout << "            " << i << " in b2? " << b2.count(i) << endl;
    }
}

bag<char> copybag(bag<char> b) {
    return b;
}

char get_char()
// Library facilties used: iostream.h
{
    char result;

    cout << "Please enter a char for the bag: ";
    cin >> result;
    cout << result << " has been read." << endl;
    return result;
}
