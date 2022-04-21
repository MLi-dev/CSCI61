#include <iostream>
using namespace std;
#include <stack>
#include "bintree.h"
#include "useful.h"
using namespace main_savitch_10;

void instruct() {
    cout<<"Think of an animal and I will try to guess it. Answer yes or no"<<endl;
}

binary_tree_node<string>* beginning_tree() {
    binary_tree_node<string> *root_ptr;
    binary_tree_node<string> *child_ptr;
    const string root_question("Are you a mammal?");
    const string left_question("Are you bigger than a cat?");
    const string right_question("Do you live underwater?");
    const string animal1("Kangaroo");
    const string animal2("Mouse");
    const string animal3("Trout");
    const string animal4("Robin");
    root_ptr = new binary_tree_node<string>(root_question);
    child_ptr = new binary_tree_node<string>(left_question);
    child_ptr->set_left(new binary_tree_node<string>(animal1));
    child_ptr->set_right(new binary_tree_node<string>(animal2));
    root_ptr->set_left((child_ptr));
    child_ptr = new binary_tree_node<string>(right_question);
    child_ptr->set_left(new binary_tree_node<string>(animal3));
    child_ptr->set_right(new binary_tree_node<string>(animal4));
    root_ptr->set_right(child_ptr);
    return root_ptr;
}

void ask_and_move(binary_tree_node<string>*& current_ptr) {
    string reply;
    cout<<current_ptr->data()<<endl;
    cin>>reply;
    if(reply == "Yes") {
        current_ptr = current_ptr->left();
    } else {
        current_ptr = current_ptr->right();
    }
}

void learn(binary_tree_node<string>* leaf_ptr) {
    string guess_animal;    // The animal that was just guessed
    string correct_animal;  // The animal that the user was thinking of
    string new_question;    // A question to distinguish the two animals
    // Set strings for the guessed animal, correct animal and a new question.
    guess_animal = leaf_ptr->data( );
    cout << "I give up. What are you? " << endl;
    getline(cin, correct_animal);
    cout << "Please type a yes/no question that will distinguish a" << endl;
    cout << correct_animal << " from a " << guess_animal << "." << endl;
    cout << "Your question: " << endl;
    getline(cin, new_question);
    leaf_ptr->set_data(new_question);
    cout<<"Does the new animal qualify, Yes or No?"<<endl;
    string reply;
    cin>>reply;
    if(reply == "Yes") {
        leaf_ptr->set_left(new binary_tree_node<string>(correct_animal));
        leaf_ptr->set_right(new binary_tree_node<string>(guess_animal));
    } else {
        leaf_ptr->set_left(new binary_tree_node<string>(guess_animal));
        leaf_ptr->set_right(new binary_tree_node<string>(correct_animal));
    }
}

void play(binary_tree_node<string>* current_ptr) {
    cout<<"Think of an animal, then press the return key"<<endl;
    eat_line();
    while(!current_ptr->is_leaf()) {
        ask_and_move(current_ptr);
    }
    cout<<"My answer is... "<<current_ptr->data()<<endl;
    if(!inquire("Am I correct?")) {
        learn(current_ptr);
    } else {
        cout<<"I know your animal!"<<endl;
    }
}

int main() {
    binary_tree_node<string> *animals_root_ptr;
    instruct();
    animals_root_ptr = beginning_tree();
    do
        play(animals_root_ptr);
        while(inquire("Shall we play again?"));
    cout<<"Thanks for teaching me a thing or two."<<endl;
    return EXIT_SUCCESS;
}
