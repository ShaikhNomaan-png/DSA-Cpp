#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> results;
        vector<string> board(n, string(n, '.')); // Initialize the board
        vector<bool> columns(n, false); // Track occupied columns
        vector<bool> diag1(2 * n, false); // Major diagonal
        vector<bool> diag2(2 * n, false); // Minor diagonal
        
        backtrack(results, board, columns, diag1, diag2, n, 0);
        return results;
    }
    
    void backtrack(vector<vector<string>>& results, vector<string>& board, 
                   vector<bool>& columns, vector<bool>& diag1, vector<bool>& diag2, 
                   int n, int row) {
        if (row == n) { // All queens are placed
            results.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (columns[col] || diag1[row - col + n] || diag2[row + col]) {
                continue; // If it's not safe, skip this column
            }
            // Place the queen
            board[row][col] = 'Q';
            columns[col] = true;
            diag1[row - col + n] = true;
            diag2[row + col] = true;

            // Recur to place the next queen
            backtrack(results, board, columns, diag1, diag2, n, row + 1);

            // Backtrack
            board[row][col] = '.'; // Remove the queen
            columns[col] = false;
            diag1[row - col + n] = false;
            diag2[row + col] = false;
        }
    }
};

int main() {
    int n = 4; // Example for 4-Queens
    Solution solution;
    vector<vector<string>> results = solution.solveNQueens(n);
    
    // Print the results
    for (const auto& board : results) {
        for (const auto& row : board) {
            cout << row << endl;
        }
        cout << endl;
    }
    return 0;
}

/*  The N-Queens problem is a classic backtracking problem where the challenge is to place N queens on an N×N chessboard so that no two queens threaten each other. This means no two queens can be in the same row, same column, or same diagonal.

### Problem Statement

Given an integer N, return all distinct solutions to the N-Queens puzzle. Each solution contains a distinct board configuration of the N-Queens' placements, where 'Q' and '.' indicate a queen and an empty space, respectively.

### Approach

1. **Backtracking**:
   - We will place queens one row at a time.
   - For each row, we will try placing a queen in each column and check if it is safe to do so.
   - If it is safe, we place the queen and move to the next row.
   - If placing the queen leads to a solution, we store the solution. If not, we backtrack and try the next column.

2. **Safety Check**:
   - Maintain three arrays (or sets):
     - `columns`: to keep track of which columns are occupied.
     - `diag1`: to track the major diagonal (row - col).
     - `diag2`: to track the minor diagonal (row + col).

### C++ Implementation

Here’s a C++ solution for the N-Queens problem using backtracking:

```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> results;
        vector<string> board(n, string(n, '.')); // Initialize the board
        vector<bool> columns(n, false); // Track occupied columns
        vector<bool> diag1(2 * n, false); // Major diagonal
        vector<bool> diag2(2 * n, false); // Minor diagonal
        
        backtrack(results, board, columns, diag1, diag2, n, 0);
        return results;
    }
    
    void backtrack(vector<vector<string>>& results, vector<string>& board, 
                   vector<bool>& columns, vector<bool>& diag1, vector<bool>& diag2, 
                   int n, int row) {
        if (row == n) { // All queens are placed
            results.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (columns[col] || diag1[row - col + n] || diag2[row + col]) {
                continue; // If it's not safe, skip this column
            }
            // Place the queen
            board[row][col] = 'Q';
            columns[col] = true;
            diag1[row - col + n] = true;
            diag2[row + col] = true;

            // Recur to place the next queen
            backtrack(results, board, columns, diag1, diag2, n, row + 1);

            // Backtrack
            board[row][col] = '.'; // Remove the queen
            columns[col] = false;
            diag1[row - col + n] = false;
            diag2[row + col] = false;
        }
    }
};

int main() {
    int n = 4; // Example for 4-Queens
    Solution solution;
    vector<vector<string>> results = solution.solveNQueens(n);
    
    // Print the results
    for (const auto& board : results) {
        for (const auto& row : board) {
            cout << row << endl;
        }
        cout << endl;
    }
    return 0;
}
```

### Explanation of the Code

1. **Class Definition**: The `Solution` class contains the main function `solveNQueens()` that initializes the board and the backtracking process.
  
2. **Initialization**:
   - A 2D vector `results` to store the valid board configurations.
   - A `board` initialized with '.' representing empty spaces.
   - Three boolean vectors (`columns`, `diag1`, `diag2`) to track occupied positions.

3. **Backtracking Method**:
   - The `backtrack()` function attempts to place queens row by row.
   - It checks if the current column and diagonals are already under attack (occupied).
   - If it's safe to place a queen, it updates the board and the tracking arrays.
   - After placing a queen and moving to the next row, if a solution is found, it's added to results.
   - If not, it backtracks by removing the queen and marking the positions as unoccupied.

4. **Main Function**: Initializes a 4-Queens problem and prints all found configurations.

### Complexity

- **Time Complexity**: O(N!), as there can be N! configurations across N rows.
- **Space Complexity**: O(N) for the storage of the board and other tracking structures. The output space is also O(N²) for the final results.

### Output

For N = 4, the output will be:
```
. Q . . 
. . . Q
Q . . . 
. . Q . 

. . Q . 
Q . . . 
. . . Q 
. Q . . 
```

This shows all distinct arrangements of 4 queens on a 4x4 chessboard where they do not threaten each other. 

If you have further questions or need more information, feel free to ask!
*/