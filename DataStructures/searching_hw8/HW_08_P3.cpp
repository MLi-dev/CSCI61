#include <iostream>
#include <fstream>

using namespace std;

#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>

struct crossWord {
    string word;
    int x1;
    int y1;
    int x2;
    int y2;
};

bool search(vector<vector<char>> puzzle, string word, crossWord &cw, int row, int col);

int main() {
    ifstream fin;
    fin.open("puzzle.txt");
    if (fin.fail()) {
        cout << "FILE OPENING FAILED" << endl;
    }

    vector<vector<char>> puzzle;
    int numRows;
    int numCol;
    char letter;
    fin >> numRows >> numCol;
    for (int i = 0; i < numRows; i++) {
        vector<char> column;
        for (int j = 0; j < numCol; j++) {
            fin >> letter;
            column.push_back(letter);
        }
        puzzle.push_back(column);
    }
    fin.close();
    ifstream instream;
    instream.open("words.txt");
    if (instream.fail()) {
        cout << "DICTIONARY OPENING FAILED" << endl;
    }
    string word;
    unordered_set<string> wordSet;
    while (!instream.eof()) {
        instream >> word;
        if (word.size() >= 6) {
            wordSet.insert(word);
        }
    }
    vector<crossWord> result;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCol; j++) {
            for (auto e: wordSet) {
                crossWord cw;
                bool found = search(puzzle, e, cw, i, j);
                if (found) {
                    result.push_back(cw);
                    found = false;
                }
            }
        }
    }
    //   sort(result.begin(), result.end());
    for (auto e: result) {
        cout << e.word << endl;
        cout << "(" << e.x1 << "," << e.y1 << ")" << endl;
        cout << "(" << e.x2 << "," << e.y2 << ")" << endl;
    }
}

bool search(vector<vector<char>> puzzle, string word, crossWord &cw, int row, int col) {
    if (puzzle[row][col] != word[0]) {
        return false;
    }
    int xArray[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int yArray[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    for (int i = 0; i < 8; i++) {
        int x = row + xArray[i];
        int y = col + yArray[i];
        int j;
        for (j = 1; j < word.size(); ++j) {
            if (x - 1 < 0 || y - 1 < 0 || x + 1 > puzzle.size() || y + 1 > puzzle[0].size()) {
                break;
            }
            if (word[j] != puzzle[x][y]) {
                break;
            }
            x += xArray[i];
            y += yArray[i];
        }
        if (j + 1 == word.size()) {
            cw.word = word;
            cw.x1 = row;
            cw.y1 = col;
            cw.x2 = x;
            cw.y2 = y;
            return true;
        }
        x = row;
        y = col;
    }
    return false;
}



