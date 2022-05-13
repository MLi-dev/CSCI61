#include <iostream>
using namespace std;
#include <stack>

int main() {
        string s = "(((X+Y*(Z+7))*(A+B)))";
        stack<char> brackets;
        for (int i = 0; i < s.size(); i++) {
            if (brackets.empty() || s[i] == '(') { //Need to also check if brackets is empty.
                brackets.push(')');
            } else if (s[i] == brackets.top()) {
                brackets.pop();
            }
        }
        cout<<brackets.empty()<<endl;
}
