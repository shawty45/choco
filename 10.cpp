#include<iostream>
#include<vector>
using namespace std;
bool isSafe(const vector<vector<int>>& board, int row, int col, int n) {
    // Check the column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) return false;
    }

    // Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false;
    }

    // Check upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) return false;
    }

    return true;
}

bool nqueen(vector<vector<int>>& board, int row, int n){

    if(row >= n) return true;

    for(int col=0; col<n ;col++){
        if(isSafe(board,row,col,n)){

            board[row][col] = 1;

            if(nqueen(board,row+1,n)){
                return true;
            }

            board[row][col] = 0;
        }
    }
    return false;
}

void printBoard(const vector<vector<int>>& board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
}


int main() {
    int n;
    cout << "Enter the size of the board (N): ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));

    if (nqueen(board, 0, n)) {
        cout << "Solution to " << n << "-Queens problem:" << endl;
        printBoard(board, n);
    } else {
        cout << "No solution exists for " << n << "-Queens problem." << endl;
    }

    return 0;
}