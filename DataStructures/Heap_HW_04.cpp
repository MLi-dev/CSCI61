//
// Created by Matthew Li on 4/14/22.
//

#include "bintree.h"
#include "bintree.cpp"
#include <iostream>
#include <vector>
#include <queue>

using namespace main_savitch_10;
using namespace std;

class TreeBuilder {
public:
    binary_tree_node<string> *createTree(vector<string> &prefix) {
        int begin = 0;
        return buildTree(prefix, begin, prefix.size());
    }

private:
    binary_tree_node<string> *buildTree(vector<string> &prefix) {
        binary_tree_node<string> *root = NULL;
        binary_tree_node<string> *cur = root;
        queue<int> que;
        if (prefix.size() == 0) {
            return root;
        }
        que.push(0);
        while (!que.empty()) {
            int qSize = que.size();
            for (int i = 0; i < qSize; i++) {
                int curIndex = que.front();
                que.pop();
                binary_tree_node<string> *node = new binary_tree_node<string>(prefix[0]);
                if (cur == NULL) {
                    cur = node;
                    root = node;
                } else {
                    if (curIndex % 2 != 0) {
                        cur->set_left(node);
                    } else {
                        cur->set_right(node);
                    }
                }
                if()
                que.push()
            }
        }
    }
};

vector<string> sep_by_space(string input);


int main() {
    string inputPrefix;
    cout << "Please enter an operation with spaces between numbers and operators" << endl;
    //- / + 8 10 2 * 3 2
    //+ / * 99 44 32 - 81 5
    // 42 27 49 39 25
    getline(cin, inputPrefix);
    vector<string> v = sep_by_space(inputPrefix);
    TreeBuilder c;
    binary_tree_node<string> *built = c.createTree(v);
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