//
// Created by Matthew Li on 4/14/22.
//



#include <queue>
#include <iostream>
using namespace std;

struct Student {
    int id;
    int priority;
};
struct myCompPriority {
    bool operator()(Student a, Student b) {
        return (a.priority < b.priority);
    }
};
struct myCompID {
    bool  operator()(Student a, Student b) {
        return (a.id < b.id);
    }
};
struct myCompCombo {
    bool operator()(Student a, Student b) {
        if(a.priority == b.priority) {
            return (a.id < b.id);
        } else {
            return (a.priority > b.priority);
        }
    }
};

int main() {
    priority_queue<Student, vector<Student>, myCompPriority> p;
    priority_queue<Student, vector<Student>, myCompID> pId;
    priority_queue<Student, vector<Student>, myCompCombo> pCombo;
    for(int i = 0; i< 10; i++) {
        Student s;
        s.id = rand()%20 + 1;
        s.priority = rand()%5 + 1;
        p.push(s);
        pId.push(s);
        pCombo.push(s);
    }
    while(!pCombo.empty()) {
        Student cur = pCombo.top();
        pCombo.pop();
        cout<<"The priority is: "<<cur.priority<<". The id is: "<<cur.id<<endl;
    }
}