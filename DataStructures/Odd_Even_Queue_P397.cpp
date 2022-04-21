#include <iostream>
using namespace std;
#include <stack>
#include <queue>


int main() {
    queue<char> que;
    stack<char> stk;
    char c;
    cout<<"Please enter a phrase"<<endl;
    while(cin.peek() != '\n') {
        cin>>c;
        if(isalpha(c)) {
            que.push(c);
            stk.push(c);
        }
    }
    int mismatch = 0;
    while(!que.empty() && !stk.empty()) {
        if(tolower(que.front()) != tolower(stk.top())) {
            mismatch++;
        }
        que.pop();
        stk.pop();
    }
    if(mismatch > 0) {
        cout<<"Not a palindrome!"<<endl;
    } else {
        cout<<"Is palindrome"<<endl;
    }
}
//Test line: Able was I ere I saw Elba


