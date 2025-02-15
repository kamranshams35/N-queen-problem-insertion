N-Queens Problem Using Backtracking
Introduction
The N-Queens problem is a classic combinatorial problem in which N queens must be placed on an N × N chessboard such that no two queens threaten each other. This means:

No two queens can be in the same row.
No two queens can be in the same column.
No two queens can be on the same diagonal.
This project uses backtracking to efficiently find a solution to the N-Queens problem.

Project Overview
The program takes N as input (the number of queens and the size of the board) and attempts to place N queens on an N × N chessboard following the given constraints. If a solution exists, it prints the board with the queens' positions.

Key Features:
Uses backtracking to explore possible placements.
Checks for valid positions before placing a queen.
Displays the solution in a chessboard-like format.
Handles cases where no solution is possible.
Implementation Details
1. isSafe Function
cpp
Copy
Edit
bool isSafe(vector<vector<bool>>& board, int row, int col)
Checks if a queen can be safely placed at board[row][col].
It verifies three conditions:
Column Check – Ensures no queen is in the same column above the current row.
Main Diagonal Check – Ensures no queen is in the upper-left diagonal.
Other Diagonal Check – Ensures no queen is in the upper-right diagonal.
2. solveNQueens Function
cpp
Copy
Edit
bool solveNQueens(vector<vector<bool>>& board, int row)
Uses recursion and backtracking to solve the problem.
If all queens are placed (row == n), a valid solution is found.
Otherwise, it tries to place a queen in each column of the current row:
If it is safe (isSafe returns true), the queen is placed.
The function recursively calls itself for the next row.
If a placement leads to failure, backtracking removes the queen and tries the next column.
3. printBoard Function
cpp
Copy
Edit
void printBoard(vector<vector<bool>>& board)
Displays the chessboard with:
Q representing a queen.
. representing an empty space.
4. main Function
cpp
Copy
Edit
int main()
Accepts the number of queens (n) from the user.
Initializes an n × n chessboard with false (no queens placed).
Calls solveNQueens() to find a solution.
If successful, prints the solution; otherwise, it informs the user that no solution exists.
Example Output
Input:
typescript
Copy
Edit
Enter the number of queens: 4
Output:
css
Copy
Edit
Solution found!
. Q . . 
. . . Q 
Q . . . 
. . Q . 
(The Q represents the queens, and . represents empty spaces.)

Time Complexity
The worst-case time complexity is O(N!), as the program explores all possible placements recursively.

Conclusion
This project effectively demonstrates how backtracking can be used to solve complex problems like the N-Queens problem. It provides an interactive and visual way to understand recursion and backtracking techniques in C++.
