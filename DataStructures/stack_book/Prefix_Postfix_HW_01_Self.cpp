//
// Created by Matthew Li on 4/4/22.
//

#include <stack>
#include <iostream>
#include <istream>

using namespace std;

//Since string is reversed for prefix, for same operator, right (input operator) takes precedence.
bool inLowPrecForPre(char c, char t) {
    bool val = false;
    switch (c) {
        case '+':
        case '-':
            if (strchr("*/", t) != NULL) {
                val = true;
            }
            break;
        default:
            break;
    }
    return val;
}

//For post, same operator,left(operator in stack)take precedence

bool inLowPrecForPost(char input, char stackTop) {
    bool val = true;
    switch(input) {
        case '*':
        case '/':
            if(strchr("+-", stackTop) != NULL) {
                val = false;
            }
        break;
        default:
            break;
    }
    return val;
}

//Post and prefix logic are siimlar except prefix reverses string, so look to right bracket.
//Pushes right bracket to stack, use left bracket to match and pop.
string infixtoPrefix(string infix) {
    stack<char> cStack;
    string result = "";
    for (int i = 0; i < infix.size(); i++) {
        char c = infix[i];
        if (isdigit(c) || isalpha(c)) {
            result += c;
        } else if (c == ')') {
            cStack.push(c);
        } else if (strchr("+-*/", c) != NULL) {
            while (!cStack.empty() && inLowPrecForPre(c, cStack.top()) && cStack.top() != ')') {
                result += cStack.top();
                cStack.pop();
            }
            cStack.push(c);
        } else if (c == '(') {
            while (cStack.top() != ')') {
                result += cStack.top();
                cStack.pop();
            }
            cStack.pop();
        }
    }
    while (!cStack.empty()) {
        result += cStack.top();
        cStack.pop();
    }
    return result;
}

string prefixToInfix(string prefix) {
    stack<string> sStack;
    reverse(prefix.begin(), prefix.end());
    for(int i = 0; i<prefix.size(); i++) {
        char c = prefix[i];
        if(isdigit(c) || isalpha(c)) {
            string result = "";
            result += c;
            sStack.push(result);
        } else if(!sStack.empty() && strchr("+-*/", c) != NULL) {
            string s1 = sStack.top();
            sStack.pop();
            string s2 = sStack.top();
            sStack.pop();
            sStack.push("(" + s1 + c + s2 + ")");
        }
    }
    return sStack.top();
}

string infixtoPostFix(string infix) {
    stack<char> cStack;
    string output = "";
    for(int i = 0; i<infix.size(); i++) {
        char c = infix[i];
        if(isdigit(c) || isalpha(c)) {
            output+=c;
        } else if(strchr("+-*/", c) != NULL) {
            while(!cStack.empty() && inLowPrecForPost(c, cStack.top()) && cStack.top() != '(') {
                output += cStack.top();
                cStack.pop();
            }
            cStack.push(c);
        } else if(c == ')') {
            while(cStack.top() != '(') {
                output+=cStack.top();
                cStack.pop();
            }
            cStack.pop();
        } else if(c == '(') {
            cStack.push(c);
        }
    }
    while(!cStack.empty()) {
        output+=cStack.top();
        cStack.pop();
    }
    return output;
}

int main() {
    char c;
    string s = "";
    while (cin.peek() != '\n') {
        cin >> c;
        s += c;
    }
    string post = infixtoPostFix(s);
    cout << post << endl;
    reverse(s.begin(), s.end());
    string prefix = infixtoPrefix(s);
    reverse(prefix.begin(), prefix.end());
    cout << prefix << endl;
    cout<<prefixToInfix(prefix)<<endl;
}
//3*X+(Y-12)-Z
//(100/(4/2))/((18/9)+((7*(9/3))*(5+(6-1))))