#include <bits/stdc++.h>
using namespace std;


int main() {
    int numStones;
    string stones;
    cin>>numStones;
    cin>>stones;
    int counter = 0;
    for(int i = 0; i<numStones-1; i++) {
        if(stones[i] == stones[i+1]) {
                counter++;
        }
    }
    cout<<counter;
}



