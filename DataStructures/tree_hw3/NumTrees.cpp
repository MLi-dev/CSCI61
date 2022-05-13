//
// Created by Matthew Li on 4/14/22.
//

#include <queue>
#include <iostream>
#include <map>
using namespace std;

class solution{
public:
    int treeCount(int n) {
        return tree_Count(1, n);
    }
private:
    //Used map because it acts as a cache mechanism, if the number of nodes has already been calculated, then retrieve from map instead of doing recursion. More efficient.
    map<pair<int, int>, int> mp;
    int tree_Count(int start, int end) {
        pair<int, int> p(start, end);
        if(start > end) {
            return 1;
        }
        if(mp[p] != NULL) {
            return mp[p];
        }
        int numTree = 0;
        for(int rIndex = start; rIndex<=end; rIndex++) {
            int left = tree_Count(start, rIndex-1);
            int right = tree_Count(rIndex+1, end);
            numTree += left*right;
            mp[p] = numTree;
        }
        return numTree;
    }


};

int main() {
    int n;
    cout<<"Please enter a number for how many tree nodes you want"<<endl;
    cin>>n;
    solution s;
    int nums = s.treeCount(n);
    cout<<"There are "<<nums<<" possible trees that can be made with "<<n<<" nodes"<<endl;
}

