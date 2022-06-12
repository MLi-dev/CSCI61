#include <iostream>
using namespace std;
#include <vector>

int main() {
    int numberGames;
    cin>>numberGames;
    char winner;
    int aCounter = 0;
    int dCounter = 0;
    for(int i = 0; i<numberGames; i++) {
        cin>>winner;
        if(winner == 'A') {
            aCounter++;
        } else {
            dCounter++;
        }
    }
    if(aCounter > dCounter) {
        cout<<"Anton"<<endl;
    }  else if(dCounter > aCounter) {
        cout<< "Danik"<<endl;
    } else {
        cout<<"Friendship"<<endl;
    }
}



