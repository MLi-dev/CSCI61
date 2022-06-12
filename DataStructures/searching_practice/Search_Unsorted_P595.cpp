#include <iostream>

using namespace std;

#include <vector>

int main() {
    vector<string> pets;
    pets.push_back("cat");
    pets.push_back("bear");
    pets.push_back("dog");
    pets.push_back("dog");
    pets.push_back("fish");
    pets.push_back("snake");
    pets.push_back("dog");
    pets.push_back("turtle");
    //Lower_bound won't work because collection is UNSORTED.
    vector<string>::iterator first_low = lower_bound(pets.begin(), pets.end(), "cat");
    if (first_low != pets.end()) {
        cout << "FOUND AT: " << *first_low << endl;
    } else {
        cout << "NOT FOUND" << endl;
    }
    //Use "find" instead
    vector<string>::iterator find_result = find(pets.begin(), pets.end(), "cat");
    if (find_result != pets.end()) {
        cout << "FOUND AT: " << *find_result << endl;
    } else {
        cout << "NOT FOUND" << endl;
    }
    vector<string>::difference_type occurCounts = count(pets.begin(), pets.end(), "dog");
    cout<<"Occurs "<<occurCounts<<endl;
    return 0;
}



