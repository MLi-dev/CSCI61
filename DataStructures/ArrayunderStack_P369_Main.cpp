#include <iostream>
using namespace std;
#include "ArrayunderStack_P369.h"
#include "ArrayunderStack_P369.cpp"
using namespace main_savitch_7A;

int main() {
    main_savitch_7A::stack<int> s;
    for(int i = 0; i<5; i++) {
        s.push(i);
    }
    int t = s.top();
    cout<<t<<endl; //Expecting 4.
    s.pop();
    cout<<s.top()<<endl; //Expecting 3.

}
