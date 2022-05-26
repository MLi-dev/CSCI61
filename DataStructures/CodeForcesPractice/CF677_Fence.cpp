#include <iostream>
using namespace std;
#include <vector>

int main() {
    int minWidth = 0;
    int fenceHeight;
    int friends;
    int fHeight;
    cin>>friends>>fenceHeight;
    for(int i = 0; i<friends; i++) {
        cin>>fHeight;
        if(fHeight<=fenceHeight) {
            minWidth++;
        } else {
            minWidth+=2;
        }
    }
    cout<<minWidth<<endl;
}



