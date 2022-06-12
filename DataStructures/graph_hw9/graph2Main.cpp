// FILE: testtab2.cxx
// An interactive test program for the second table ADT.

#include <bits/stdc++.h>
#include "graph2.h"
using namespace std;

bool compare(string &x1, string &x2);

void createGraph(graph& dicG, vector<string>& dicV);

void findPath(graph& dicG, vector<string>& dicV);

int main() {
    graph dicG;
    vector<string> dicV;
    createGraph(dicG, dicV);
    cout<<"The graph has been created"<<endl;
    findPath(dicG, dicV);
}

void createGraph(graph& dicG, vector<string>& dicV) {
    ifstream fin;
    fin.open("dictionary.txt");
    if (fin.fail()) {
        cout << "FILE OPENING FAILED" << endl;
        return;
    }
    while (!fin.eof()) {
        string word;
        fin >> word;
        dicV.push_back(word);
        dicG.add_vertex();
    }
    for (int i = 0; i < dicG.n(); ++i) {
        for (int j = i; j < dicG.n(); ++j) {
            string first = dicV[i];
            string second = dicV[j];
            if (compare(first, second)) {
                dicG.add_edge(i, j);
            }
        }
    }
}
bool compare(string &x1, string &x2) {
    int counter = 0;
    for (int i = 0; i < 5; ++i) {
        if(x1[i] == x2[i]) {
            counter++;
        }
    }
    return (counter>=4);
}
void findPath(graph& dicG, vector<string>& dicV) {
    ifstream fin;
    fin.open("words.txt");
    string source;
    string target;
    ofstream fout;
    fout.open("output.txt");
    while(!fin.eof()) {
        fin>>source>>target;
        std::size_t sourceIndex;
        std::size_t targetIndex;
        for (std::size_t i = 0; i < dicV.size(); ++i) {
            if(dicV[i] == source) {
                sourceIndex = i;
                break;
            }
        }
        for (std::size_t i = 0; i < dicV.size(); ++i) {
            if(dicV[i] == target) {
                targetIndex = i;
                break;
            }
        }
        vector<int> path = dicG.shortest_path(sourceIndex, targetIndex);
        if(path.size() == 0) {
            fout<<"Sorry, could not find path from "<<source<<" to "<<target<<endl;
        }
        std::reverse(path.begin(), path.end());
        for (int i = 0; i < path.size(); ++i) {
            fout<<dicV[path[i]]<<" ";
        }
        fout<<endl;
    }
}