#include <iostream>

#include <queue>

using namespace std;

int main(){

    queue<int> q;

    for (int i = 1; i <= 7; ++i){

        q.push(i);

    }

    int n(0);

    while (q.size() != 1){

        int front = q.front();

        q.pop();

        if (n++ % 3 != 0){

            q.push(front);

        }

    }

    cout << q.front() << endl;

    return 0;

}