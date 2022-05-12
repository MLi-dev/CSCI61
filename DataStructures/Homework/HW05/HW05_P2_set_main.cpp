//
// Created by Matthew Li on 4/14/22.
//



#include <iostream>
#include "set.h"
using namespace std;
using std::ofstream;
using namespace main_savitch_11;
int main() {
    ofstream outStream;
    outStream.open("outfile.txt");
    char c[10] = {'S', 'F', 'E', 'V', 'D', 'U', 'J', 'P', 'O', 'T'};
    main_savitch_11::set<char> charSet;
    for(int i = 0; i<10; i++) {
        outStream<<"Adding "<<c[i]<<endl;
        charSet.insert(c[i]);
        charSet.print(4, outStream);
        outStream<<" "<<endl;
    }
    for(int i = 0; i<10; i++) {
        outStream<<"Removing "<<c[i]<<endl;
        charSet.erase(c[i]);
        charSet.print(4, outStream);
        outStream<<" "<<endl;
    }

}
