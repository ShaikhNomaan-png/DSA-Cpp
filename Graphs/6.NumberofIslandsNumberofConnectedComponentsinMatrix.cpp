#include <iostream>
#include <vector>

using namespace std;

// DFS function to explore the island
void DFS(int i, int j, vector<vector<int>>& grid) {
    // Check for out-of-bound indices or water
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
        return;
    }
    
    grid[i][j] = 0; // Mark the cell as visited by sinking the island (change 1 to 0)

    // Explore the four possible directions (up, down, left, right)
    DFS(i + 1, j, grid); // Down
    DFS(i - 1, j, grid); // Up
    DFS(i, j + 1, grid); // Right
    DFS(i, j - 1, grid); // Left
}

// Function to count the number of islands
int numIslands(vector<vector<int>>& grid) {
    if (grid.empty()) return 0;

    int islands = 0;
    
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 1) { // Found an unvisited island
                islands++;
                DFS(i, j, grid); // Sink the entire island
            }
        }
    }
    return islands;
}

int main() {
    // Example matrix representing land and water
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0}
    };

    int numberOfIslands = numIslands(grid);
    cout << "Number of Islands: " << numberOfIslands << endl;

    return 0;
}

/* Let's break down the output of the given C++ code step-by-step using the provided example matrix:

### Example Matrix
```plaintext
1 1 0 0 0
1 0 0 1 1
0 0 0 1 0
0 1 0 0 0
```

This 4x5 matrix represents a grid where `1` represents land and `0` represents water. Our goal is to count how many separate islands (groups of connected `1`s) exist in the matrix.

### Step-by-Step Execution

1. **Initializing Variables**:
   - The input matrix is passed to the `numIslands` function.
   - An integer variable `islands` is initialized to `0` to count the number of islands.

2. **Outer Loop (Iterating through Rows)**:
   - The outer loop iterates through each row of the matrix (`for (int i = 0; i < grid.size(); i++)`).

#### Iteration 1: `i = 0` (First Row)

- **Inner Loop (Iterating through Columns)**:
  - The inner loop iterates through each column in the current row.

  - **Column 0 (`j = 0`)**: 
    - The value is `1` (land).
    - Since this cell is `1` and hasn't been visited:
      - Increment `islands` by `1` (now `islands = 1`).
      - Call DFS on this cell: `DFS(0, 0)`.

        #### DFS Call on (0, 0)
        - Mark `grid[0][0]` as visited by changing it to `0`.
        - Explore neighbors:
          - Down `(1, 0)`: This cell is `1`, call DFS on `(1, 0)`.
              
              #### DFS Call on (1, 0)
              - Mark `grid[1][0]` as visited.
              - Explore neighbors:
                - Down `(2, 0)`: This cell is `0`, return.
                - Up `(0, 0)`: Already visited, return.
                - Right `(1, 1)`: This cell is `0`, return.
                - Left `(1, -1)`: Out of bounds, return.

          - Up `(-1, 0)`: Out of bounds, return.
          - Right `(0, 1)`: This cell is `1`, call DFS on `(0, 1)`.

              #### DFS Call on (0, 1)
              - Mark `grid[0][1]` as visited.
              - Explore neighbors:
                - Down `(1, 1)`: This cell is `0`, return.
                - Up `(-1, 1)`: Out of bounds, return.
                - Right `(0, 2)`: This cell is `0`, return.
                - Left `(0, 0)`: Already visited, return.

        All reachable parts of the first island have been visited, and the DFS for `(0, 0)` completes.

  - **Column 1 (`j = 1`)**:
    - The value is `0` (water), skip it.

  - **Column 2 (`j = 2`)**: 
    - The value is `0`, skip it.

  - **Column 3 (`j = 3`)**: 
    - The value is `0`, skip it.

  - **Column 4 (`j = 4`)**: 
    - The value is `0`, skip it.

At the end of the first row, the grid looks like:
```plaintext
0 0 0 0 0
1 0 0 1 1
0 0 0 1 0
0 1 0 0 0
```

#### Iteration 2: `i = 1` (Second Row)

- **Inner Loop**:
  - **Column 0 (`j = 0`)**: 
    - The value is `1` (land).
    - This node hasn’t been visited. Increment `islands` by `1` (now `islands = 2`).
    - Call DFS on `(1, 0)`.

        #### DFS Call on (1, 0)
        - This cell has already been visited in the earlier DFS, return immediately.

  - **Column 1 (`j = 1`)**: 
    - The value is `0`, skip it.

  - **Column 2 (`j = 2`)**: 
    - The value is `0`, skip it.

  - **Column 3 (`j = 3`)**: 
    - The value is `1` (land).
    - Increment `islands` by `1` (now `islands = 3`).
    - Call DFS on `(1, 3)`.

        #### DFS Call on (1, 3)
        - Mark `grid[1][3]` as visited.
        - Explore neighbors:
          - Down `(2, 3)`: Call DFS on `(2, 3)`.

              #### DFS Call on (2, 3)
              - Mark as visited.
              - Explore neighbors:
                - Down `(3, 3)`: Call DFS on `(3, 3)`.

                  #### DFS Call on (3, 3)
                  - Mark as visited.
                  - Explore:
                    - Down `(4, 3)`: Out of bounds, return.
                    - Up `(2, 3)`: Already visited, return.
                    - Right `(3, 4)`: Call DFS on `(3, 4)`.

                      #### DFS Call on (3, 4)
                      - Mark as visited.
                      - Explore neighbors:
                        - Down `(4, 4)`: Out of bounds, return.
                        - Up `(2, 4)`: This cell is `0`, return.
                        - Right `(3, 5)`: Out of bounds, return.
                        - Left `(3, 3)`: Already visited, return.

                  All parts of this island are now visited.

#### Remaining Columns in Second Row
- **Column 4 (`j = 4`)**:
  - This cell has also been visited in previous DFS calls, return immediately.

### Iteration 3: `i = 2` (Third Row)

- **Inner Loop**:
  - Columns `0`, `1`, and `2` are `0`, skip them.

  - **Column 3 (`j = 3`)**: 
    - Already visited, skip.

  - **Column 4 (`j = 4`)**: 
    - The cell is `0`, skip.

### Iteration 4: `i = 3` (Fourth Row)

- **Inner Loop**:
  - **Column 0 (`j = 0`)**:
    - This cell is `0`, skip.

  - **Column 1 (`j = 1`)**:
    - The value is `1` (land).
    - Increment `islands` by `1` (now `islands = 4`).
    - Call DFS on `(3, 1)`.

        #### DFS Call on (3, 1)
        - Mark as visited.
        - Explore:
          - Down `(4, 1)`: This cell is `0`, return.
          - Up `(2, 1)`: This cell is `0`, return.
          - Right `(3, 2)`: This cell is `0`, return.
          - Left `(3, 0)`: This cell is `0`, return.

      All parts of this island are now visited.

  - **Column 2 (`j = 2`)**: 
    - This cell has a value of `0`, skip.

  - **Column 3 (`j = 3`)**: 
    - Already visited, skip.

  - **Column 4 (`j = 4`)**: 
    - This cell is `0`, skip.

### Final Count of Islands
After iterating through the entire matrix, the final count of islands is `4`:

### Final Output
```plaintext
Number of Islands: 4
```

### Summary
- The code counts the connected components in the provided matrix.
- Each time it identifies a new unvisited land cell (`1`), it starts a DFS to mark all connected land cells and increments the island count.
- The output for the example matrix is `4`, indicating there are four distinct islands. 

If we consider the islands formed, we realize there was a miscount. **Upon re-evaluating the DFS traversals**, it should actually find **3 islands** instead of 4 as my previous steps suggested. Thus, the correct output would be:
```plaintext
Number of Islands: 3
``` 

The key is to carefully track the visited nodes and ensure all parts of an island are marked correctly to avoid double counting.
*/