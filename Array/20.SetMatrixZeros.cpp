#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return;

    int m = matrix.size();
    int n = matrix[0].size();
    bool firstRowZero = false;
    bool firstColZero = false;

    // Check if first row has zeros
    for (int j = 0; j < n; j++) {
        if (matrix[0][j] == 0) {
            firstRowZero = true;
            break;
        }
    }

    // Check if first column has zeros
    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) {
            firstColZero = true;
            break;
        }
    }

    // Use first row and first column to mark zeros
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;  // Mark column
                matrix[0][j] = 0;  // Mark row
            }
        }
    }

    // Set matrix cells to zero using marks
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Set first row to zero if needed
    if (firstRowZero) {
        for (int j = 0; j < n; j++) {
            matrix[0][j] = 0;
        }
    }

    // Set first column to zero if needed
    if (firstColZero) {
        for (int i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    setZeroes(matrix);

    // Print the updated matrix
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

/*   Certainly! Let’s break down the output of the C++ program step by step and explain what the output represents in the context of the problem of setting matrix zeros.

### Code Overview
Here’s a brief recap of what the code does:
- It scans a given matrix to find any zeroes.
- If a zero is found, it marks the respective row and column for future zeroing.
- Finally, it modifies the matrix to set the identified rows and columns to zero.

### Input Matrix
The input matrix provided in the code is:
```
1 1 1
1 0 1
1 1 1
```

### Process Breakdown
1. **Identify Zeroes**:
   - First, the code checks if any elements in the first row or first column are zero.
   - In this case, the element at position (1, 1) is **0**, so:
     - `firstRowZero` remains **false** since no zero is present in the first row.
     - `firstColZero` also remains **false** since no zero is present in the first column.

2. **Marking Rows and Columns**:
   - The code uses the first row and first column to mark which rows and columns need to be zeroed.
   - Upon scanning the matrix, it finds the **0** at (1, 1):
     - It marks the first element of the second column (`matrix[0][1]`) and the first element of the second row (`matrix[1][0]`) as **0**.
   - After this marking step, the matrix looks like this:
   ```
   1 0 1
   0 0 1
   1 1 1
   ```
   Here, any non-zero position that corresponds to a zero has been marked.

3. **Setting Rows and Columns to Zero**:
   - Next, the code goes through the marked rows and columns to set the appropriate elements to **0**.
   - It sets:
     - The entire second row (index 1) to zero because of the marked row.
     - The entire second column (index 1) to zero because of the marked column.
   - The matrix after this change looks like:
   ```
   1 0 1
   0 0 0
   1 0 1
   ```
   
4. **Handling the First Row and First Column**:
   - Finally, the code checks if it needs to zero out the first row and the first column based on initial checks.
   - Since neither `firstRowZero` nor `firstColZero` are true in this case, the first row and first column remain unchanged.

### Final Output
The final updated matrix is:
```
1 0 1
0 0 0
1 0 1
```

### Explanation of the Output:
- **First Row**: The first row remains unchanged, retaining the value `1 0 1`. The zero in column 1 indicates that any value in that column across rows should be zeroed, which has been done in all relevant rows.
- **Second Row**: This row is completely zeroed out since it contained a zero at position (1, 1). Hence the matrix reflects the zeros as `0 0 0`.
- **Third Row**: The third row shows `1 0 1`, with zeros in the second column due to the zero in row 1.

### Summary
The final output matrix correctly represents the requirements of the "Set Matrix Zeros" problem:
- Each element that lies in the same row or column as a zero has been set to zero.
- The first row and first column have retained original values since they didn’t contain any initial zeros.

This approach efficiently modifies the matrix in place, ensuring the desired outcome with minimal space usage. The program clearly reflects this logic, leading to the expected final output.
*/