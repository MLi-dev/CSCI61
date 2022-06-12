#include <iostream>
using namespace std;
#include <vector>
#include <bits/stdc++.h>

int main() {
    int size;
    int val;
    cin>>size;
    int arr[size];
    for(int i = 0; i<size; i++) {
        cin>>val;
        arr[i] = val;
    }
    sort(arr, arr+size);
    for(int i = 0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
}



