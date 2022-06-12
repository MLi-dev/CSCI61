#include <iostream>

using namespace std;

#include <vector>
#include <bits/stdc++.h>

int main() {
    int numTeams;
    cin>>numTeams;
    vector<int> home, guest;
    int counter = 0;
    for(int i = 0; i<numTeams; i++) {
        int a, b;
        cin>>a>>b;
        home.push_back(a);
        guest.push_back(b);
    }
    for(int i = 0; i<numTeams; i++) {
        for(int j = 0; j<numTeams; j++) {
            if(home[i] == guest[j]) {
                counter++;
            }
        }
    }
    cout<<counter<<endl;
}



