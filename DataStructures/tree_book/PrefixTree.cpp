//
// Created by Matthew Li on 4/14/22.
//

#include "../bintree.h"
#include "../bintree.cpp"
#include <iostream>
#include <vector>
using namespace main_savitch_10;
using namespace std;

class TreeBuilder {
public:
   binary_tree_node<string>* createTree(vector<string>& prefix) {
       int begin = 0;
       return buildTree(prefix, begin, prefix.size());
   }
private:
    binary_tree_node<string>* buildTree(vector<string>& prefix, int& start, int end) {
        if(start >= end) {
            return nullptr;
        }
        binary_tree_node<string>* newNode = new binary_tree_node<string>(prefix[start]);
        if(!isdigit(prefix[start][0])) {
            start++;
            newNode->set_left(buildTree(prefix, start, end));
            newNode->set_right(buildTree(prefix, start, end));
        } else {
            start++;
        }
        return newNode;
    }
};
vector<string> sep_by_space(string input);


int main() {
    string inputPrefix;
    cout<<"Please enter an operation with spaces between numbers and operators"<<endl;
    //- / + 8 10 2 * 3 2
    //+ / * 99 44 32 - 81 5
    getline(cin, inputPrefix);
    vector<string> v = sep_by_space(inputPrefix);
    TreeBuilder c;
    binary_tree_node<string>* built = c.createTree(v);
    print(built, 0);
}
vector<string> sep_by_space(string input) {
    vector<string> out;
    string term = "";
    for (auto c: input) {
        if (c != ' ') {
            term += c;
        } else {
            out.push_back(term);
            term = "";
        }
    }
    //At the end when there is no space, push in any remaining characters.
    out.push_back(term);
    return out;
}