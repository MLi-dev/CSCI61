#include <iostream>
using namespace std;
#include <vector>
#include <bits/stdc++.h>

int main() {
    int numMagnets;
    int numGroups = 1;
    cin>>numMagnets;
    vector<string> mag;
    string pole;
    for(int i = 0; i<numMagnets; i++) {
        cin>>pole;
        mag.push_back(pole);
    }
    for(int i = 1; i<mag.size(); i++) {
        if(mag[i] != mag[i-1]) {
            numGroups++;
        }
    }
    cout<<numGroups;
}



