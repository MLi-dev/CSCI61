#include <iostream>
using namespace std;
#include <vector>
#include <bits/stdc++.h>

int main() {
    string word;
    cin>>word;
    int capCount = 0;
    int lowCount = 0;
    for(int i = 0; i<word.size(); i++) {
        if(word[i] >= 65 && word[i] <= 90) {
            capCount++;
        } else if(word[i] >= 97 && word[i] <= 122) {
            lowCount++;
        }
    }
    if(capCount > lowCount) {
        for(int i = 0; i<word.size(); i++) {
           word[i] = toupper(word[i]);
        }
        cout<<word;
    } else {
        for(int i = 0; i<word.size(); i++) {
            word[i] = tolower(word[i]);
        }
        cout<<word<<endl;
    }
}



