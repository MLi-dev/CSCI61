#include <bits/stdc++.h>
using namespace std;


int main() {
    int numEvents;
    cin>>numEvents;
    int val;
    int police = 0;
    int crime = 0;
    for(int i = 0; i<numEvents; i++) {
        cin>>val;
        if(val == -1) {
            if(police > 0) {
                police--;
            } else {
                crime++;
            }
        } else {
            police += val;
        }
    }
    cout<<crime<<endl;
}



