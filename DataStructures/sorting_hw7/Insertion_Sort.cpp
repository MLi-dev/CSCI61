#include <iostream>
using namespace std;
#include <vector>


int main() {
  vector<int> v = {1, 7, 8, 5, 3, 6, 4, 2};
  for(int i = 1; i<v.size(); i++) {
     int curVal = v[i];
     int sortIndex = i-1;
     while(sortIndex > -1 && v[sortIndex] > curVal) {
         v[sortIndex+1] = v[sortIndex];
         sortIndex--;
     }
     v[sortIndex+1] = curVal;
  }
  for(auto d: v) {
      cout<<d<<", ";
  }
}



