#include <iostream>
using namespace std;
#include <vector>
#include <bits/stdc++.h>
#include <set>

int maxCard(vector<int> cardDeck);

int main() {
   int numCards;
   cin>>numCards;
   vector<int> cardDeck;
   int sereja = 0;
   int dima = 0;
   int cardVal;
   for(int i = 0; i<numCards; i++) {
       cin>>cardVal;
       cardDeck.push_back(cardVal);
   }

}
int maxCard(vector<int> cardDeck) {
    int max;
    int begin = 0;
    int end = cardDeck.size()-1;
    int greaterVal;
    for(int i = 0; i<cardDeck.size(); i++) {
        if(cardDeck[begin] > cardDeck[end]) {
            max = cardDeck[begin];
            begin++;
        } else {
            max = cardDeck[end];
            end--;
        }
    }
}



