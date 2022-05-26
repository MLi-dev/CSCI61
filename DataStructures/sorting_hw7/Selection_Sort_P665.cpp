#include <iostream>
using namespace std;
#include <vector>


int main() {
  vector<int> v = {1, 7, 8, 5, 3, 6, 4, 2};
  for(int i = v.size()-1; i>0; --i) {
      int largest_index = 0;
      int largest_data = v[0];
      for(int j = 1; j<= i; j++) {
          if(v[j] > largest_data) {
              largest_index = j;
              largest_data = v[j];
          }
      }
      swap(v[i], v[largest_index]);
  }
  for(auto d: v) {
      cout<<d<<", ";
  }
}



