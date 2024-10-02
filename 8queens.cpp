#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c){
    for (int i=0; i<c; i++){
        //row do you repeat any values
        if (q[i]==q[c]) return false;
        //diagnol do you repeat any values
        if (abs(q[c]-q[i])==(c-i)) return false;
    }
    return true;
}

void print(int q[], int count){
    cout << count << "." << endl;
    for (int a=0; a<8; a++){
        for (int j=0; j<8; j++){
            if (q[a]==j){
                cout << " * ";
            } else {
                cout << "   ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main (){
    int board[8]={0}, col=0, count=1;
    board[0]=0;
    while (col>=0){
        if (col==8) {
            print(board, count);
            col--;
            count++;
            board[col]++;
            } else if (board[col]==8){
                board[col]=0;
                col--;
                if (col != -1) board[col]++;
            } else if (ok(board, col)==true) {
                col++;
            } else {
                board[col]++;
            }
        }
    return 0;
}
