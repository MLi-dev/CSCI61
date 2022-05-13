#include <iostream>

using namespace std;

#include <stack>
#include <cmath>

void calculation(stack<double> &nums, char op) {
    double right = nums.top();
    nums.pop();
    double left = nums.top();
    nums.pop();
    switch (op) {
        case '+':
            nums.push(left + right);
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
        default:
            break;
    }
}

double read_and_evaluate(istream &ins) {
    stack<double> nums;
    double num;
    char op;
    while (ins.peek() != '\n') {
        if (isdigit(ins.peek())) {
            ins >> num;
            nums.push(num);
        } else if (strchr("+-*/", ins.peek()) != NULL) {
            ins >> op;
            calculation(nums, op);
        } else {
            ins.ignore();
        }
    }
    return nums.top();
}

//I will test on (((60+40)/50) * (16-4)) //Expecting 24.)
int main() {
    double ans;
    cout << "Please input a valid formula: " << endl;
    ans = read_and_evaluate(cin);
    cout << ans << endl;
}



