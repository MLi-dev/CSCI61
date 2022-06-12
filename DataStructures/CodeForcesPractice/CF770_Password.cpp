#include <iostream>
using namespace std;
#include <vector>
#include <bits/stdc++.h>

int main() {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int length;
    int distinct;
    cin>>length>>distinct;
    char c;
    string pwd;
    for(int i = 0; i<length; i++) {
        pwd += alphabet[i%distinct];
    }
    cout<<pwd<<endl;
}



