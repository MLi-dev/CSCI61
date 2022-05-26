#include <iostream>
using namespace std;
#include <vector>

int main() {
    int limakHeight;
    int bobHeight;
    int numYears = 0;
    cin>>limakHeight>>bobHeight;
    while(limakHeight<=bobHeight) {
        limakHeight *= 3;
        bobHeight *= 2;
        numYears++;
    }
    cout<<numYears<<endl;
}



