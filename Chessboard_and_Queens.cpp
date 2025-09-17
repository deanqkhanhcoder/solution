#include <iostream>
#include <string>
using namespace std;
char board[8][8];
bool colUsed[8] = {false};
bool diag1Used[15] = {false};
bool diag2Used[15] = {false};
int way = 0;

void backtrack(int row){
    if (row == 8){
        way++;
        return;
    }
    for (int col = 0; col < 8; ++col){
        if (board[row][col] == '*') continue;
        if (colUsed[col]) continue;
        if (diag1Used[row - col + 7]) continue;
        if (diag2Used[row + col]) continue;

        colUsed[col] = true;
        diag1Used[row - col + 7] = true;
        diag2Used[row + col] = true;

        backtrack(row + 1);
        colUsed[col] = false;
        diag1Used[row - col + 7] = false;
        diag2Used[row + col] = false;
    }
}

void FastIO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    FastIO();
    for (int i = 0; i < 8; ++i){
        string z; cin >> z;
        for (int j = 0; j < 8; ++j){
            board[i][j] = z[j];
        }
    }
    backtrack(0);
    cout << way;
    return 0;
}