#include <iostream>

using namespace std;

#include <bits/stdc++.h>

using namespace std;

int main() {
    int ncard;
    cin >> ncard;
    int arr[ncard];
    for (int i = 0; i < ncard; ++i) {
        cin >> arr[i];
    }


    int start = 0, end = ncard - 1, p1 = 0, p2 = 0;

    for (int i = 0; i < ncard; ++i) {
        if (arr[start] > arr[end]) {
            if (i % 2 == 0) {
                p1 += arr[start];

            } else {
                p2 += arr[start];

            }
            ++start;
        } else {
            if (i % 2 == 0) {
                p1 += arr[end];

            } else {
                p2 += arr[end];

            }
            --end;

        }


    }

    cout << p1 << " " << p2;


}

