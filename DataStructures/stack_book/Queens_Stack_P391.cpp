    //
// Created by Matthew Li on 4/4/22.
//

#include <cassert>
#include <iostream>
#include "../stack3.h" // Provides the stack class with a peek(i) function.
#include "../stack3.cpp"
    using namespace std;
    using namespace main_savitch_7A;
    void print_solution(stack<int> choices)
    {
        int i;
        cout << "Solution for n = " << choices.size( ) << endl;
        cout << "======================================================" << endl;
        for (i = 1; !choices.empty( ); i++)
        {
            cout << "Queen in row " << i << ", column " << choices.top( ) << endl;
            choices.pop( );
        }
        cout << "======================================================\n" << endl;
    }
    bool is_conflict(const stack<int>& choices)
    {
        int top = choices.top();
        for(int i = 2; i <= choices.size(); i++) {
            int curRowQueen = choices.peek(i);
            if(curRowQueen == top || top + i -1 == curRowQueen || top -(i-1) == curRowQueen) {
                return true;
            }
        }
       return false;
    }

    void queens(int n)
    {
        stack<int> choices;
        int next;
        bool success = false;
        assert (n >= 1);
        choices.push(1);
        success = false;
        while(!success && !choices.empty()) {
            if(is_conflict(choices)) {
                while (!choices.empty() && choices.top() == n) {
                    choices.pop();
                }
                if(!choices.empty()) {
                    next = choices.top() + 1;
                    choices.pop();
                    choices.push(next);
                }
            } else if(choices.size() == n) {
                success = true;
            } else {
                choices.push(1);
            }
        }
        if(success) {
            print_solution(choices);
        } else {
            cout<<"No possible solutions"<<endl;
        }
    }
    int main( )
    {
        int n;

        cout << "Please enter n for the n-queens problem (n >= 1): ";
        cin >> n;
        queens(n);
        return 0;
    }