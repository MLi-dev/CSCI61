#include <iostream>
using namespace std;
#include <vector>
#include <bits/stdc++.h>
#include <set>

int main() {
    string s;
    cin>>s;
    set<char> charSet;
    for(int i = 0; i<s.size(); i++) {
        if(charSet.find(s[i]) == charSet.end()) {
            charSet.insert(s[i]);
        }
    }
    if(charSet.size() % 2 == 0) {
        cout<<"CHAT WITH HER!"<<endl;
    } else {
        cout<<"IGNORE HIM!"<<endl;
    }
}



