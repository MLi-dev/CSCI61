#include <iostream>

using namespace std;

#include <vector>


int main() {
    vector<string> pets;
    pets.push_back("cat");
    pets.push_back("dog");
    pets.push_back("dog");
    pets.push_back("fish");
    pets.push_back("snake");
    pets.push_back("turtle");
    vector<string>::iterator i;
    cout << binary_search(pets.begin(), pets.end(), "cat") << endl;
    vector<string>::iterator first_low = lower_bound(pets.begin(), pets.end(), "fish");
    vector<string>::iterator first_high = upper_bound(pets.begin(), pets.end(), "fish");
    //Iterate leading up to fish
    for (i = pets.begin(); i != first_low; ++i) {
        cout << *i;
        cout << endl;
    }
    for (i = first_low; i != pets.end(); ++i) {
        cout << *i;
        cout << endl;
    }
    if (first_low != pets.end()) {
        cout << "FOUND AT: " << *first_low << endl;
    } else {
        cout << "NOT FOUND" << endl;
    }
    if (first_high != pets.end()) {
        cout << "FOUND AT: " << *first_high << endl;
    } else {
        cout << "NOT FOUND" << endl;
    }
    //Using STL search function to find a sub-vector.
    vector<string> pets2;
    pets2.push_back("dog");
    pets2.push_back("dog");
    pets2.push_back("fish");
    vector<string>::iterator containSub = search(pets.begin(), pets.end(), pets2.begin(), pets2.end());
    if (containSub != pets.end()) {
        cout << "FOUND AT: " << *containSub << endl;
    } else {
        cout << "SubVector NOT FOUND "<<endl;
    }

    return 0;
}



