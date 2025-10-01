#include <iostream>
#include <vector>
#include <queue>
#include <utility> // For std::pair
using namespace std;

int shortestPathBinaryMaze(vector<vector<int>>& maze, pair<int,int> src, pair<int,int> dest) {
    int n = maze.size();
    int m = maze[0].size();

    if (maze[src.first][src.second] == 0 || maze[dest.first][dest.second] == 0)
        return -1; // start or end blocked

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    queue<pair<int,int>> q;

    dist[src.first][src.second] = 0;
    q.push(src);

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        // Reached destination
        if (x == dest.first && y == dest.second)
            return dist[x][y] + 1; // include starting cell

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m && maze[nx][ny] == 1 && dist[nx][ny] == INT_MAX) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return -1; // no path exists
}

int main() {
    vector<vector<int>> maze = {
        {1,0,1,1},
        {1,1,1,0},
        {0,1,0,1},
        {1,1,1,1}
    };

    pair<int,int> src = {0,0};
    pair<int,int> dest = {3,3};

    int shortest = shortestPathBinaryMaze(maze, src, dest);
    cout << "Shortest path length = " << shortest << endl;

    return 0;
}

/*  Sure! Let’s go **step by step** and explain **Shortest Path in a Binary Maze** in full detail, including BFS traversal, path, and output.

---

## 🔹 Problem Recap

* **Input:** 2D binary matrix (maze)

  * `1` → open cell
  * `0` → blocked cell
* **Goal:** Find the **shortest path** from source `(0,0)` to destination `(3,3)`
* **Moves allowed:** Up, Down, Left, Right (4 directions)
* **Output:** Minimum number of steps (including starting cell) or `-1` if no path exists.

**Maze:**

```
1 0 1 1
1 1 1 0
0 1 0 1
1 1 1 1
```

---

## 🔹 BFS Approach

1. Treat each **cell as a graph node**.
2. Use **BFS** for shortest path (all moves have cost = 1).
3. Maintain a **distance matrix** `dist[][]` to track shortest distance to each cell.
4. Use a **queue** to traverse nodes level by level.
5. Stop BFS when we reach **destination cell**.

---

## 🔹 BFS Step-by-Step

### **Step 1:** Start at `(0,0)`

* Distance = 0
* Queue = `[(0,0)]`

---

### **Step 2:** Explore neighbors

* `(0,0)` neighbors: `(1,0)` (open), `(0,1)` blocked
* Push `(1,0)` → distance = 1
* Queue = `[(1,0)]`

---

### **Step 3:** Explore `(1,0)`

* Neighbors: `(0,0)` (visited), `(2,0)` blocked, `(1,1)` open
* Push `(1,1)` → distance = 2
* Queue = `[(1,1)]`

---

### **Step 4:** Explore `(1,1)`

* Neighbors: `(0,1)` blocked, `(2,1)` open, `(1,0)` visited, `(1,2)` open
* Push `(2,1)` → distance = 3
* Push `(1,2)` → distance = 3
* Queue = `[(2,1),(1,2)]`

---

### **Step 5:** Explore `(2,1)`

* Neighbors: `(3,1)` open, `(2,0)` blocked, `(2,2)` blocked, `(1,1)` visited
* Push `(3,1)` → distance = 4
* Queue = `[(1,2),(3,1)]`

---

### **Step 6:** Explore `(1,2)`

* Neighbors: `(0,2)` open, `(2,2)` blocked, `(1,1)` visited, `(1,3)` blocked
* Push `(0,2)` → distance = 4
* Queue = `[(3,1),(0,2)]`

---

### **Step 7:** Explore `(3,1)`

* Neighbors: `(2,1)` visited, `(3,0)` open, `(3,2)` open
* Push `(3,0)` → distance = 5
* Push `(3,2)` → distance = 5
* Queue = `[(0,2),(3,0),(3,2)]`

---

### **Step 8:** Explore `(0,2)`

* Neighbors: `(0,3)` open, `(1,2)` visited, `(0,1)` blocked
* Push `(0,3)` → distance = 5
* Queue = `[(3,0),(3,2),(0,3)]`

---

### **Step 9:** Explore `(3,2)`

* Neighbors: `(3,3)` open, `(3,1)` visited, `(2,2)` blocked
* Push `(3,3)` → distance = 6 (destination reached)

---

## 🔹 Shortest Path Found

* **Length = 7** (including starting cell)
* **Path (one example):**

```
(0,0) → (1,0) → (1,1) → (2,1) → (3,1) → (3,2) → (3,3)
```

---

## 🔹 Distance Matrix after BFS

```
0  - 6 7  8
1 2  3  - 
- 3  - 4
5 4 5 6
```

(`-` = blocked or unreachable)

---

## 🔹 Output

```
Shortest path length = 7
```

---

## 🔹 Key Takeaways

1. BFS works because **all moves have equal weight (unit cost)**.
2. **Distance matrix** ensures we don’t revisit cells.
3. **Queue** maintains BFS traversal order → finds shortest path level by level.
4. **Time Complexity:** `O(n*m)`
5. **Space Complexity:** `O(n*m)`

---
If you want, I can **draw the binary maze visually and highlight the BFS traversal with path**, which makes it very easy to understand the algorithm in action.
Do you want me to do that?
*/