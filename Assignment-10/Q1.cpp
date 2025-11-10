#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    // Check column
    for (int i = 0; i < row; i++)
        if (board[i][col]) return false;

    // Check upper left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    // Check upper right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j]) return false;

    return true;
}

void printSolution(vector<vector<int>>& board, int n) {
    static int count = 1;
    cout << "Solution " << count++ << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << (board[i][j] ? "Q " : ". ");
        cout << endl;
    }
    cout << endl;
}

void solveNQueen(vector<vector<int>>& board, int row, int n) {
    if (row == n) {
        printSolution(board, n);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;
            solveNQueen(board, row + 1, n);
            board[row][col] = 0; // backtrack
        }
    }
}

int main() {
    int n = 8;  // 8x8 chessboard
    vector<vector<int>> board(n, vector<int>(n, 0));

    cout << "All possible solutions for " << n << "-Queens problem:\n\n";
    solveNQueen(board, 0, n);
    return 0;
}
