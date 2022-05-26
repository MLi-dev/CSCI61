#include <iostream>
using namespace std;
#include <vector>

int main() {
    int numMoves;
    int oneRow;
    int oneCol;
    int matrix[5][5];
    for(int i = 0; i<5; i++) {
        for(int j = 0; j<5; j++) {
            cin>>matrix[i][j];
            if(matrix[i][j] == 1) {
                oneRow = i;
                oneCol = j;
            }
        }
    }
    numMoves = abs(2-oneRow) + abs(2-oneCol);
    cout<<numMoves<<endl;
}



