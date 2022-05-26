#include <iostream>

using namespace std;

#include <vector>


int main() {
    string text = "Cyclops has just one eye.";
    string::iterator i;
    string::iterator whereE;
    whereE = find(text.begin(), text.end(), 'e');
    cout<<"Before e:"<<endl;
    for(i = text.begin(); i != whereE; ++i) {
        cout<<*i;
    }
    cout<<endl;
    cout<<"After e:"<<endl;
    for(i = whereE; i != text.end(); ++i) {
        cout<<*i;
    }
    cout<<endl;
    return 0;
}



