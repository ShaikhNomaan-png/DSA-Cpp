#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    queue<pair<int, int>> q; // Queue to hold rotten oranges
    int freshCount = 0; // Count of fresh oranges
    int minutes = 0; // Minutes elapsed

    // Initialize the queue and count fresh oranges
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2) {
                q.push({i, j}); // Add rotten oranges to the queue
            }
            if (grid[i][j] == 1) {
                freshCount++; // Count fresh oranges
            }
        }
    }

    // Directions for adjacent cells
    vector<int> directions = {-1, 0, 1, 0, -1, 0};

    // BFS processing
    while (!q.empty()) {
        int size = q.size();
        bool rottenNewOrange = false; // To track if we rot any new orange this minute

        for (int i = 0; i < size; i++) {
            auto [x, y] = q.front();
            q.pop();

            // Check all 4 possible directions
            for (int d = 0; d < 4; d++) {
                int newX = x + directions[d];
                int newY = y + directions[d + 1];

                // If within bounds and fresh
                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == 1) {
                    grid[newX][newY] = 2; // Mark as rotten
                    q.push({newX, newY}); // Add to queue
                    freshCount--; // Decrease fresh count
                    rottenNewOrange = true; // We rotted a new orange
                }
            }
        }
        // Increment minutes if we rotted new oranges
        if (rottenNewOrange) {
            minutes++;
        }
    }

    // If still have fresh oranges, return -1
    return (freshCount == 0) ? minutes : -1;
}

int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    int result = orangesRotting(grid);
    cout << "Minimum minutes to rot all oranges: " << result << endl;

    return 0;
}

/*  Perfect 👌 Let’s break down the **Rotten Oranges problem (G-10)** with the **example we used in code** and explain the output clearly.

---

## 🔹 Problem Again

You have a grid:

* `0` → Empty cell
* `1` → Fresh orange
* `2` → Rotten orange

Each **minute**, all fresh oranges **next to** a rotten orange (up, down, left, right) also become rotten.
You must calculate the **minimum time** needed until no fresh orange is left.
If impossible → return `-1`.

---

## 🔹 Example Input (from code)

```
grid = [
  [2, 1, 1],
  [1, 1, 0],
  [0, 1, 1]
]
```

### Initial State:

```
2 1 1
1 1 0
0 1 1
```

* `2` = rotten at (0,0).
* Rest are fresh `1`.
* We need to check how infection spreads minute by minute.

---

## 🔹 Step-by-step Process (BFS simulation)

### ⏱ Minute 0 (starting state)

```
2 1 1
1 1 0
0 1 1
```

* Rotten orange at (0,0).
* Fresh = 6 oranges.

---

### ⏱ Minute 1

* From (0,0), neighbors (0,1) and (1,0) rot.

```
2 2 1
2 1 0
0 1 1
```

* Fresh left = 4.

---

### ⏱ Minute 2

* From (0,1) → (0,2) rots.
* From (1,0) → (1,1) rots.

```
2 2 2
2 2 0
0 1 1
```

* Fresh left = 2.

---

### ⏱ Minute 3

* From (1,1) → (2,1) rots.

```
2 2 2
2 2 0
0 2 1
```

* Fresh left = 1.

---

### ⏱ Minute 4

* From (2,1) → (2,2) rots.

```
2 2 2
2 2 0
0 2 2
```

* Fresh left = 0 ✅

---

## 🔹 Final Answer

All oranges became rotten in **4 minutes**.
So the output is:

```
Minimum minutes to rot all oranges: 4
```

---

## 🔹 Why BFS Works Here?

* We start with **all rotten oranges at once** (multi-source BFS).
* At each level (minute), all adjacent fresh oranges are infected.
* BFS guarantees the **minimum time** since we process level by level.

---

👉 Would you like me to also cover the **case where the output is -1** (when some oranges can never rot)? That will complete the understanding of this problem.

*/