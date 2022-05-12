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
    binary_tree_node<int> *createTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, postorder);
    }

private:
    binary_tree_node<int> *buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size() == 0) {
            return NULL;
        }
        int rootVal = postorder[postorder.size()-1];
        binary_tree_node<int>* root = new binary_tree_node<int>(rootVal);
        if(postorder.size() == 1) {
            return root;
        }
        int index = 0;
        for(index = 0; index<inorder.size(); index++) {
            if(inorder[index] == rootVal) {
                break;
            }
        }
        vector<int> linorder(inorder.begin(), inorder.begin()+index);
        vector<int> rinorder(inorder.begin()+index+1, inorder.end());
        postorder.resize(postorder.size()-1);
        vector<int> lpostorder(postorder.begin(), postorder.begin()+linorder.size());
        vector<int> rpostorder(postorder.begin()+linorder.size(), postorder.end());
        root->set_left(buildTree(linorder, lpostorder));
        root->set_right(buildTree(rinorder, rpostorder));
        return root;
    }
};

vector<string> sep_by_space(string input);


int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    TreeBuilder c;
    binary_tree_node<int> *built = c.createTree(inorder, postorder);
    cout<<"Original tree:"<<endl;
    print(built, 0);
    reheapify(built);
    cout<<"Reheapified tree:"<<endl;
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