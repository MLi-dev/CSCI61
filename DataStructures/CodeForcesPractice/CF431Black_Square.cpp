#include <iostream>

using namespace std;

#include <fstream>
#include <bits/stdc++.h>

int main() {
    vector<int> seconds;
    int sec1;
    int sec2;
    int sec3;
    int sec4;
    cin>>sec1>>sec2>>sec3>>sec4;
    int totalCal = 0;
    string strips;
    cin >> strips;
    for (int i = 0; i < strips.size(); i++) {
        switch (strips[i]) {
            case '1':
                totalCal += sec1;
                break;
            case '2':
                totalCal += sec2;
                break;
            case '3':
                totalCal += sec3;
                break;
            case '4':
                totalCal += sec4;
                break;
            default:
                totalCal+= 0;
                break;
        }
    }
    cout<<totalCal<<endl;
}



