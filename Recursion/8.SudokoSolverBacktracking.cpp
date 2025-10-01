#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
private:
    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') { // Find an empty cell
                    for (char num = '1'; num <= '9'; num++) {
                        if (isValid(board, row, col, num)) { // Check if placement is valid
                            board[row][col] = num; // Place the number
                            if (solve(board)) { // Recur to continue solving
                                return true; // All cells filled correctly
                            }
                            board[row][col] = '.'; // Reset on backtrack
                        }
                    }
                    return false; // No valid number found, trigger backtrack
                }
            }
        }
        return true; // All cells filled correctly
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char num) {
        // Check row
        for (int x = 0; x < 9; x++) {
            if (board[row][x] == num) return false;
        }
        
        // Check column
        for (int x = 0; x < 9; x++) {
            if (board[x][col] == num) return false;
        }
        
        // Check 3x3 sub-box
        int startRow = row - row % 3, startCol = col - col % 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i + startRow][j + startCol] == num) return false;
            }
        }
        
        return true; // No conflicts found
    }
};

int main() {
    Solution solution;
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','2','8','.','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    solution.solveSudoku(board);

    // Print the solved board
    for (const auto& row : board) {
        for (const auto& num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}

/*   The Sudoku Solver is another classic backtracking problem where the objective is to fill a 9x9 grid with numbers so that each column, each row, and each of the nine 3x3 subgrids contains all of the digits from 1 to 9 without repeating.

### Problem Statement

Given a partially filled 9x9 Sudoku grid, write a program to solve the puzzle. The digits 1-9 must appear in each row, column, and 3x3 subgrid.

### Approach

1. **Backtracking**:
   - Start with the first empty cell and try placing each number from 1 to 9.
   - Check if the number is valid according to Sudoku rules: it must not already be in the same row, column, or 3x3 subgrid.
   - If the number is valid, place it and recursively attempt to fill in the next empty cell.
   - If you reach a contradiction (no valid numbers can be placed), backtrack by removing the last placed number and trying the next one.
  
2. **Geometric Checks**: For each placement, you need to ensure:
   - The number is not already in the same row, column, or 3x3 box.

### C++ Implementation

Here is a C++ implementation of the Sudoku Solver using backtracking.

```cpp
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
private:
    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') { // Find an empty cell
                    for (char num = '1'; num <= '9'; num++) {
                        if (isValid(board, row, col, num)) { // Check if placement is valid
                            board[row][col] = num; // Place the number
                            if (solve(board)) { // Recur to continue solving
                                return true; // All cells filled correctly
                            }
                            board[row][col] = '.'; // Reset on backtrack
                        }
                    }
                    return false; // No valid number found, trigger backtrack
                }
            }
        }
        return true; // All cells filled correctly
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char num) {
        // Check row
        for (int x = 0; x < 9; x++) {
            if (board[row][x] == num) return false;
        }
        
        // Check column
        for (int x = 0; x < 9; x++) {
            if (board[x][col] == num) return false;
        }
        
        // Check 3x3 sub-box
        int startRow = row - row % 3, startCol = col - col % 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i + startRow][j + startCol] == num) return false;
            }
        }
        
        return true; // No conflicts found
    }
};

int main() {
    Solution solution;
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','2','8','.','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    solution.solveSudoku(board);

    // Print the solved board
    for (const auto& row : board) {
        for (const auto& num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
```

### Explanation of the Code

1. **Class Definition**: The `Solution` class encapsulates the method to solve the Sudoku.

2. **Main Method**:
   - The `solveSudoku` method initiates the backtracking process.
   - The `solve` method attempts to fill in the Sudoku board.

3. **Backtracking Method**:
   - For each cell in the grid, if an empty cell (denoted by '.') is found, it attempts to place numbers 1 through 9.
   - The `isValid` method checks whether placing a specific number is valid according to Sudoku rules.
   - If a number placement leads to a complete grid, it returns true; otherwise, it resets and backtracks.

4. **Validation Method**:
   - The `isValid` function checks the row, column, and the corresponding 3x3 subgrid to ensure that no duplicates exist.

### Complexity

- **Time Complexity**: O(9^(N×N)) in the worst case, where N is the size of the grid (9). This is because for each empty spot, there are at most 9 possibilities.
- **Space Complexity**: O(N^2) for the board storage, however, the recursion stack could be as deep as N^2 in worst cases, adding to memory usage.

### Output

The program will print the solved Sudoku board as follows:

```
5 3 4 6 7 8 9 1 2 
6 7 2 1 9 5 3 4 8 
1 9 8 3 4 2 5 6 7 
8 5 9 7 6 1 2 4 3 
4 2 6 8 5 3 7 9 1 
7 1 3 9 2 4 8 5 6 
9 6 1 5 3 7 2 8 4 
2 8 7 4 1 9 6 3 5 
3 4 5 2 8 6 1 7 9 
```

This indicates that the Sudoku puzzle has been successfully solved. If you have further questions or need additional explanations, feel free to ask!
*/