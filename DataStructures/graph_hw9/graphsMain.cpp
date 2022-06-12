// FILE: testtab2.cxx
// An interactive test program for the second table ADT.

#include <cctype>      // Provides toupper
#include <cstdlib>     // Provides EXIT_SUCCESS and size_t
#include <iostream>    // Provides cin, cout
#include "graph.h"// Provides the table class
#include "graph.cpp"

using namespace std;
using namespace main_savitch_15;


// PROTOTYPES for functions used by this test program:
void print_menu();
// Postcondition: A menu of choices for this program has been written to cout.

char get_user_command();
// Postcondition: The user has been prompted to enter a one character command.
// The next character has been read (skipping blanks and newline characters), 
// and this character has been returned.

int get_vertex_label();
// Postcondition: The user has been prompted to enter data for a record. The
// key has been read, echoed to the screen, and returned by the function.

pair<int, int> get_edge();
// Postcondition: The user has been prompted to enter a key for a record. The
// items have been read, echoed to the screen, and returned by the function.


int main() {

    graph<std::size_t> test;    // A table that we'll perform tests on
    char choice;                     // A command character entered by the user
    bool found;                      // Value returned by find function

    cout << "I have initialized an empty graph." << endl;

    do {
        print_menu();
        choice = toupper(get_user_command());
        switch (choice) {
            case 'S':
                cout << "The graph size is " << test.size() << endl;
                break;
            case 'I':
                test.add_vertex(get_vertex_label());
                cout << "The vertex has been inserted." << endl;
                break;
            case 'E': {
                pair<int, int> p = get_edge();
                test.add_edge(p.first, p.second);
                cout << "Connected edge between " << p.first << " and " << p.second << endl;
                break;
            }
            case 'R': {
                pair<int, int> p = get_edge();
                test.remove_edge(p.first, p.second);
                cout << "Disconnected edge between " << p.first << " and " << p.second << endl;
                break;
            }
            case 'P': {
                if (test.size() > 0) {
                    for (int i = 0; i < test.size(); ++i) {
                        cout << test[i] << endl;
                    }
                } else {
                    cout << "Graph is empty!" << endl;
                }
                break;
            }
            case 'G': {
                test.add_vertex(0);
                test.add_vertex(1);
                test.add_vertex(2);
                test.add_vertex(3);
                test.add_vertex(4);
                test.add_edge(0, 2);
                test.add_edge(0, 3);
                test.add_edge(1, 2);
                test.add_edge(1, 3);
                test.add_edge(3, 2);
                test.add_edge(4, 1);
                test.add_edge(4, 2);
                test.add_edge(4, 0);
                cout << "Created a sample graph" << endl;
                break;
            }
            case 'D': {
                pair<std::size_t , std::size_t> p = get_edge();
                int dist = test.longest_distance(p.first, p.second);
                cout<<"The distance from "<<p.first<<" "<<p.second<<" is " <<dist<<endl;
                break;
            }
            case 'Q':
                cout << "Ridicule is the best test of truth." << endl;
                break;
            default:
                cout << choice << " is invalid. Sorry." << endl;
        }
    } while ((choice != 'Q'));

    return EXIT_SUCCESS;
}

void print_menu()
// Library facilities used: iostream.h
{
    cout << endl; // Print blank line before the menu
    cout << "The following choices are available: " << endl;
    cout << " S   Print the result from the size( ) function" << endl;
    cout << " I   Insert a new vertex with the add_vertex() function" << endl;
    cout << " E   Insert a new edge between pair of vertices" << endl;
    cout << " R   Removes an edge between pair of vertices" << endl;
    cout << " P   Prints labels of all the vertices" << endl;
    cout << " G   Generates a sample graph" << endl;
    cout << " D   Finds distance between vertices of graph"<<endl;
    cout << " Q   Quit this test program" << endl;
}

char get_user_command()
// Library facilities used: iostream.h
{
    char command;

    cout << "Enter choice: ";
    cin >> command; // Input of characters skips blanks and newline character

    return command;
}



int get_vertex_label() {
    int result;
    cout << "Please enter a real number for a vertex label: ";
    cin >> result;
    cout << result << " has been read." << endl;
    return result;
}

pair<int, int> get_edge() {
    pair<int, int> p;
    cout << "Please enter the source vertex: " << endl;
    cin >> p.first;
    cout << "Please enter the target vertex: " << endl;
    cin >> p.second;
    return p;
}