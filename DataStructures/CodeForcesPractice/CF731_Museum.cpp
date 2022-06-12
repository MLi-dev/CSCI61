#include <iostream>

using namespace std;

#include <fstream>
#include <bits/stdc++.h>

int main() {
    string name;
    cin>>name;
    int numTurns = 0;
    int now = 0;
    for(int i = 0; i<name.size(); i++) {
        int next = name[i]-'a';
        //How to loop around alphabet?
        numTurns+= min(abs(now-next), min(now+26-next, 26-now+next));
        now = next;
    }
    cout<<numTurns<<endl;
}



