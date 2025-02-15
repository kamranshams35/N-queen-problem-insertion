#include <iostream>
#include <vector>

using namespace std;

// Function to check if a queen can be placed at a given position
bool isSafe(vector<vector<bool>>& board, int row, int col) {
    int n = board.size();

    // Check the column
    for (int i = 0; i < row; i++) {
        if (board[i][col]) {
            return false;
        }
    }

    // Check the main diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check the other diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

// Function to solve the N-Queens problem using backtracking
bool solveNQueens(vector<vector<bool>>& board, int row) {
    int n = board.size();

    // Base case: If all queens are placed, return true
    if (row == n) {
        return true;
    }

    // Try to place a queen in each column of the current row
    for (int col = 0; col < n; col++) {
        // Check if it's safe to place a queen at the current position
        if (isSafe(board, row, col)) {
            // Place a queen at the current position
            board[row][col] = true;

            // Recur for the next row
            if (solveNQueens(board, row + 1)) {
                return true;
            }

            // Backtrack: Remove the queen from the current position
            board[row][col] = false;
        }
    }

    return false;
}

// Function to print the board
void printBoard(vector<vector<bool>>& board) {
    int n = board.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j]) {
                cout << " [Q] ";
            } else {
                cout << " [ ] ";
            }
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;

    vector<vector<bool>> board(n, vector<bool>(n, false));

    if (solveNQueens(board, 0)) {
        cout << "Solution found!" << endl;
        printBoard(board);
    } else {
        cout << "No solution found!" << endl;
    }

    return 0;
}
