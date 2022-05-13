//
// Created by Matthew Li on 4/4/22.
//

#include <stack>
#include <iostream>
#include <istream>
#include <vector>

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


//Post and prefix logic are siimlar except prefix reverses string, so look to right bracket.
//Pushes right bracket to stack, use left bracket to match and pop.
string infixtoPrefix(string infix) {
    stack<char> cStack;
    string result = " ";
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
            result += " ";
        } else if (c == '(') {
            while (cStack.top() != ')') {
                result += " ";
                result += cStack.top();
                cStack.pop();
            }
            cStack.pop();
        }
    }
    while (!cStack.empty()) {
        result += " ";
        result += cStack.top();
        result += " ";
        cStack.pop();
    }
    return result;
}

vector<string> sep_by_space(string input) {
    vector<string> out;
    string term = "";
    for (auto c: input) {
        if (c != ' ') {
            term += c;
        } else {
            out.push_back(term);
            term = "";
        }
    }
    //At the end when there is no space, push in any remaining characters.
    out.push_back(term);
    return out;
}

string prefixToInfix(string str) {
    stack<string> sStack;
    vector<string> prefix = sep_by_space(str);
    reverse(prefix.begin(), prefix.end());
    for (int i = 0; i < prefix.size(); i++) {
        string s = prefix[i];
        char c;
        if (s.size() == 1) {
            c = s[0];
        } else {
            c = ' ';
        }
        if (isalpha(c)) {
            string result = "";
            result += c;
            sStack.push(result);
        } else if (!sStack.empty() && strchr("+-*/", c) != NULL) {
            string s1 = sStack.top();
            sStack.pop();
            string s2 = sStack.top();
            sStack.pop();
            sStack.push("(" + s1 + c + s2 + ")");
        } else if(s.size()>0) {
            sStack.push(s);
        }
    }
    return sStack.top();
}


int main() {
    char c;
    string s = "";
    cout<<"Please input a valid prefix expression"<<endl;
    while (cin.peek() != '\n') {
        cin >> c;
        s += c;
    }
    reverse(s.begin(), s.end());
    string prefix = infixtoPrefix(s);
    reverse(prefix.begin(), prefix.end());
    cout<<"Here is the prefix function: "<<prefix<<endl;
    cout << "Here is the infix function: " << prefixToInfix(prefix) << endl;
}
//3*X+(Y-12)-Z
//(100/(4/2))/((18/9)+((7*(9/3))*(5+(6-1))))
//(A+B)+C-(D-E)^F