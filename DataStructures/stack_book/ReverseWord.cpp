#include <iostream>
using namespace std;
#include <stack>

int main() {
    string s = "Anagram";
    stack<char> stk;
    for(int i = 0; i<s.size(); i++) {
        stk.push(s[i]);
    }
    string result = "";
    while(!stk.empty()) {
        result += stk.top();
        stk.pop();
    }
    cout<<result<<endl;
}
