#include <iostream>
using namespace std;
#include <stack>
#include <queue>


int main() {
    queue<char> even;
    queue<char> odd;
    char c;
    cout<<"Please enter a phrase"<<endl;
    int i = 0;
    while(cin.peek() != '\n') {
        cin>>c;
        if(i % 2 == 0) {
            even.push(c);
        } else {
            odd.push(c);
        }
        i++;
    }
    cout<<"Evens:"<<endl;
    while(!even.empty()) {
        cout<<even.front()<<", ";
        even.pop();
    }
    cout<<endl;
    cout<<"Odds:"<<endl;
    while(!odd.empty()) {
        cout<<odd.front()<<", ";
        odd.pop();
    }
}
//Test line: Able was I ere I saw Elba


