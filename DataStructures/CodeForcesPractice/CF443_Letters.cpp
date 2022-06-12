#include <iostream>

using namespace std;

#include <vector>
#include <bits/stdc++.h>

int main() {
    set<char> distinctChars;
    string s;
    getline(cin, s);
    for(int i = 0; i<s.size(); i++) {
        if(s[i] <= 'z' && s[i] >= 'a') {
            distinctChars.insert(s[i]);
        }
    }
    cout<<distinctChars.size()<<endl;
}


