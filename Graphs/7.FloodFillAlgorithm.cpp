#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &image, int i, int j, int oldColor, int newColor) {
    // boundary check + color check
    if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != oldColor)
        return;

    image[i][j] = newColor; // fill color

    // explore 4 directions
    dfs(image, i + 1, j, oldColor, newColor); // down
    dfs(image, i - 1, j, oldColor, newColor); // up
    dfs(image, i, j + 1, oldColor, newColor); // right
    dfs(image, i, j - 1, oldColor, newColor); // left
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
    int oldColor = image[sr][sc];
    if (oldColor == newColor) return image; // no need to fill

    dfs(image, sr, sc, oldColor, newColor);
    return image;
}

int main() {
    vector<vector<int>> image = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };

    int sr = 1, sc = 1, newColor = 2;

    vector<vector<int>> result = floodFill(image, sr, sc, newColor);

    cout << "Flood Fill Result:\n";
    for (auto row : result) {
        for (auto val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}

/* Let's analyze the provided C++ code step-by-step, explaining the flood fill process and detailing the output. 

### Problem Definition
You are given a 2D grid representing an image where each cell has a color represented by an integer. The goal is to change the color of a specified pixel and all pixels connected (up, down, left, right) to it that share the same initial color to a new color.

### Code Breakdown
1. **Function Definitions**:
   - The `dfs` function performs a depth-first search to fill neighboring pixels.
   - The `floodFill` function includes initial checks for color and initiates the flood-fill process.

2. **Input Parameters**:
   - `image`: A 2D vector representing the pixel grid.
   - `sr`, `sc`: The starting row and column coordinates from where the flood fill should begin.
   - `newColor`: The color to which the connected pixels should be changed.

3. **Matrix Initialization**:
   The input matrix before any changes is:
   ```plaintext
   1 1 1
   1 1 0
   1 0 1
   ```

4. **Starting Point**:
   - Starting coordinates `(sr = 1, sc = 1)` point to the value `1` (color of the pixel being filled).

5. **New Color**: 
   - The new color to fill with is `2`.

### Step-by-Step Execution

1. **Initial State**:
   The initial state of the image:
   ```plaintext
   1 1 1
   1 1 0
   1 0 1
   ```

2. **Perform Flood Fill**:
   - **Check Colors**: 
     - The old color at `(1, 1)` is `1`, and the new color is `2`. Since they differ, we proceed to the flood filling.

3. **Call to DFS**: 
   The function `dfs(image, 1, 1, 1, 2)` is called, which begins the flood fill.

#### DFS Execution Steps:

- **First Call**: `(1, 1)`
  - Color at `(1, 1)` is `1` (matches `oldColor`), so fill with `2`:
  ```plaintext
   1 1 1
   1 2 0
   1 0 1
   ```
  - Explore 4 Directions:
  
  - **Down** to `(2, 1)`:
    - Color is `0` (does not match `oldColor`), return.
  
  - **Up** to `(0, 1)`:
    - Color is `1` (matches `oldColor`), fill with `2`:
    ```plaintext
    1 2 1
    1 2 0
    1 0 1
    ```
    - Explore further:
      - Down `(1, 1)`: already filled, return.
      - Up `(-1, 1)`: out of bounds, return.
      - Left `(0, 0)`:
        - Color is `1`, fill with `2`:
        ```plaintext
        2 2 1
        1 2 0
        1 0 1
        ```
        - Explore:
          - Down `(1, 0)`:
            - Color is `1`, fill with `2`:
            ```plaintext
            2 2 1
            2 2 0
            1 0 1
            ```
            - Explore:
              - Down `(2, 0)`:
                - Color is `1`, fill with `2`:
                ```plaintext
                2 2 1
                2 2 0
                2 0 1
                ```
                - Explore:
                  - Down `(3, 0)`: out of bounds.
                  - Up `(1, 0)`: already filled.
                  - Left `(2, -1)`: out of bounds.
                  - Right `(2, 1)`: Color is `0`, return.
              - Up `(0, 0)`: already filled.
              - Left `(1, -1)`: out of bounds.
              - Right `(1, 1)`: already filled.
          - Up `(0, 0)`: already filled.
          - Left `(0, -1)`: out of bounds.
          - Right `(0, 1)`: already filled.
      - Down `(2, 1)`: already processed.
      - Left `(0, 0)`: already filled.
      - Right `(0, 2)`:
        - Color is `1`, fill with `2`:
        ```plaintext
        2 2 2
        2 2 0
        2 0 1
        ```
        - Explore:
          - Down `(1, 2)`: Color is `0`, return.
          - Up `(-1, 2)`: out of bounds.
          - Left `(0, 1)`: already filled.
          - Right `(0, 3)`: out of bounds.

- **Right** `(1, 2)`: Color is `0`, return.

- All reachable pixels from `(1, 1)` have been processed.

### Final Output State
After executing the Flood Fill, the modified image is:

```plaintext
2 2 2
2 2 0
2 0 1
```

### Complete Output in `main`:

```plaintext
Flood Fill Result:
2 2 2 
2 2 0 
2 0 1 
```

### Summary
- The Flood Fill algorithm successfully changed all connected components of the initial color `1` starting from `(1, 1)` to the new color `2`. It traversed the grid using depth-first search, filling each connected pixel that matched the original color until no more connected pixels remained. 
- Careful boundary and color checks ensured that the filling proceeded correctly without errors like overflow or unnecessary changes, resulting in an accurate flood fill.
*/