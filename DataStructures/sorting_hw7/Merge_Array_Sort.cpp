#include <iostream>
using namespace std;
#include <vector>


int main() {
 int a[11] = {1, 3, 5, 7, 9, 11};
 int b[5] = {2, 4, 6, 8, 10};
 for(int i = 6; i<11; i++) {
     a[i] = b[i-6];
 }
    for(int i = 10; i>=0; --i) {
        int largest_index = 0;
        int largest_data = a[0];
        for(int j = 1; j<= i; j++) {
            if(a[j] > largest_data) {
                largest_index = j;
                largest_data = a[j];
            }
        }
        swap(a[i], a[largest_index]);
    }
    for(auto d: a) {
        cout<<d<<", ";
    }
}



