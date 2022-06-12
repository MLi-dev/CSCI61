#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int main() {
    string s1;
    string s2;
    cin>>s1;
    cin>>s2;
    int equality;
    for(int i = 0; i<s1.size(); i++) {
        s1[i] = tolower(s1[i]);
        s2[i] = tolower(s2[i]);
        if(tolower(s1[i]) <tolower(s2[i])) {
            equality = -1;
            break;
        } else if(tolower(s1[i]) > tolower(s2[i])) {
           equality = 1;
           break;
        } else if(toupper(s1[i]) == tolower(s2[i])){
            equality = 0;
        }
    }
    cout<<equality<<endl;
}



