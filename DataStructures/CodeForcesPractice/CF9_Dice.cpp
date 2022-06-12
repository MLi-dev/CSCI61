#include <iostream>

using namespace std;

#include <vector>
#include <bits/stdc++.h>

int main() {
    int numFaces = 6;
    int rows[6] = {1, 2, 3, 4, 5, 6};
    int yakkoRoll;
    int wakkoRoll;
    int validRolls = 0;
    cin >> yakkoRoll >> wakkoRoll;
    for (int i = 0; i < 6; i++) {
        if (rows[i] >= max(yakkoRoll, wakkoRoll)) {
            validRolls++;
        }
    }
    switch (validRolls) {
        case 0:
            cout<<"0/6"<<endl;
            break;
        case 1:
            cout << "1/6" << endl;
            break;
        case 2:
            cout << "1/3" << endl;
            break;
        case 3:
            cout << "1/2" << endl;
            break;
        case 4:
            cout << "2/3" << endl;
            break;
        case 5:
            cout << "5/6" << endl;
            break;
        case 6:
            cout << "1/1" << endl;
            break;
        default:
            break;
    }
}



