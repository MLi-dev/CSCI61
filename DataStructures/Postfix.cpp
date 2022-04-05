//
// Created by Matthew Li on 4/4/22.
//

#include <stack>
#include <iostream>
#include <istream>
using namespace std;

bool inLowPrec(char c, char t) {
    bool val = true;
    switch (c) {
        case '*':
        case '/':
            if (strchr("+-", t) != NULL) {
                val = false;
            }
            break;
        default: break;
    }
    return val;
}

string infixtoPrefix(string infix) {
    stack<char> nums;
    string result = "";
    for(int i = 0; i<infix.size(); i++) {
        char c = infix[i];
        if (isdigit(c) || isalpha(c)) {
            result += c;
        } else if (c == ')') {
            nums.push(c);
        } else if (strchr("+-*/", c) != NULL) {
            while (!nums.empty() && nums.top() != ')' && inLowPrec(c, nums.top())) {
                result += nums.top();
                nums.pop();
            }
            nums.push(c);
        } else if(c == '(') {
            while (nums.top() != ')') {
                result += nums.top();
                nums.pop();
            }
            nums.pop();
        } else {
            cin.ignore();
        }
    }
    while(!nums.empty()) {
        result += nums.top();
        nums.pop();
    }
    return result;
}


string infixtoPostFix(string infix) {
    stack<char> nums;
    string result = "";
    for(int i = 0; i<infix.size(); i++) {
        char c = infix[i];
        if (isdigit(c) || isalpha(c)) {
            result += c;
        } else if (c == '(' ) {
            nums.push(c);
        } else if (strchr("+-*/", c) != NULL) {
            while (!nums.empty() && nums.top() != '(' && inLowPrec(c, nums.top())) {
                result += nums.top();
                nums.pop();
            }
            nums.push(c);
        } else if(c == ')') {
            while (nums.top() != '(') {
                result += nums.top();
                nums.pop();
            }
            nums.pop();
        } else {
            cin.ignore();
        }
    }
    while(!nums.empty()) {
        result += nums.top();
        nums.pop();
    }
    return result;
}

int main() {
    char c;
    string s = "";
    while (cin.peek() != '\n') {
        cin >> c;
        s+=c;
    }
    reverse(s.begin(), s.end());
    string prefix = infixtoPrefix(s);
    reverse(prefix.begin(), prefix.end());
    cout<<prefix<<endl;
}
//(A+B)+C-(D-E)^F