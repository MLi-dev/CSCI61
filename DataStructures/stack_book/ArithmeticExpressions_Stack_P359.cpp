#include <iostream>
using namespace std;
#include <stack>
#include <cmath>

void calculation(stack<double>& nums, stack<char>& ops) {
    double right = nums.top();
    nums.pop();
    double left = nums.top();
    nums.pop();
    char opers = ops.top();
    ops.pop();
    switch (opers) {
        case '+':
            nums.push(left+right);
        break;
        case '-':
            nums.push(left-right);
        break;
        case '*':
            nums.push(left*right);
        break;
        case '/':
            nums.push(left/right);
        break;
        case '^':
            nums.push(pow(left, right));
        break;
    }
}

double read_and_evaluate(istream& ins) {
    stack<double> nums;
    stack<char> ops;
    double num;
    char op;
    while(ins.peek() != '\n') {
        if(isdigit(ins.peek())) {
            cin>>num;
            nums.push(num);
        } else if(strchr("+-*^", ins.peek()) != NULL) {
            cin>>op;
            ops.push(op);
        } else if(ins.peek() == '/') {
            cin>>op;
            if(ins.peek() == '/') {
                while(ins.peek() != '\n') {
                    ins.ignore();
                }
            } else {
                ops.push(op);
            }
        }
        else if(ins.peek() == ')') {
            ins.ignore();
            calculation(nums, ops);
        }
        else {
            ins.ignore();
        }
    }
    return nums.top();
}
//I will test on (((60+40)/50) * (16-4)) //Expecting 24.)
int main() {
        double ans;
       cout<<"Please input a valid formula: "<<endl;
       ans = read_and_evaluate(cin);
       cout<<ans<<endl;
}



