#include <iostream>
using namespace std;
#include <vector>

int main() {
  int numLines;
  int p1;
  int p2;
  int p3;
  int sure = 0;
  cin>>numLines;
  for(int i = 0; i<numLines; i++) {
      cin>>p1>>p2>>p3;
      if((p1==1 && p2 ==1) || (p1 == 1 && p3 ==1) || (p2 == 1 && p3 == 1)) {
          sure++;
      }
  }
  cout<<sure<<endl;
}



