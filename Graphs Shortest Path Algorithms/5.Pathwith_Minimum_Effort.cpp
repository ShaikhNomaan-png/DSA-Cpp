/*🔹 Problem Recap: Path with Minimum Effort

We are given a grid of heights, and we want to move from top-left (0,0) to bottom-right (n-1, m-1).

Moving between adjacent cells has an "effort" = abs(height[current] - height[next]).

The effort of a path = maximum difference along that path.

Our goal = find a path that minimizes this maximum effort.

🔹 Input Grid (heights matrix)
1 2 2
3 8 2
5 3 5


Start: (0,0) → value = 1

End: (2,2) → value = 5

🔹 Possible Paths & Their Efforts

We check some paths:

Path A:
(0,0)=1 → (0,1)=2 → (0,2)=2 → (1,2)=2 → (2,2)=5


Efforts along edges:

|1-2| = 1

|2-2| = 0

|2-2| = 0

|2-5| = 3

Maximum = 3

Path B:
(0,0)=1 → (1,0)=3 → (2,0)=5 → (2,1)=3 → (2,2)=5


Efforts:

|1-3| = 2

|3-5| = 2

|5-3| = 2

|3-5| = 2

Maximum = 2

🔹 Best Path = Path B

Path A’s max effort = 3

Path B’s max effort = 2 ✅

So, the minimum effort path has effort 2.

🔹 Program Output
Minimum Effort Path = 2
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>   // For INT_MAX
#include <utility>   // For std::pair

using namespace std;

typedef pair<int, pair<int, int>> P; // {effort, {x, y}}

int minimumEffortPath(vector<vector<int>>& heights) {
    int n = heights.size();
    int m = heights[0].size();

    // Distance matrix (stores minimum effort to reach each cell)
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    dist[0][0] = 0;

    // Min-heap priority queue
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, {0, 0}});

    // Directions: up, down, left, right
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int effort = top.first;
        int x = top.second.first;
        int y = top.second.second;

        // If we reached bottom-right cell, return effort
        if (x == n - 1 && y == m - 1) {
            return effort;
        }

        // Explore neighbors
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                int newEffort = max(effort, abs(heights[x][y] - heights[nx][ny]));
                if (newEffort < dist[nx][ny]) {
                    dist[nx][ny] = newEffort;
                    pq.push({newEffort, {nx, ny}});
                }
            }
        }
    }
    return 0;
}

int main() {
    vector<vector<int>> heights = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };

    cout << "Minimum Effort Path = " << minimumEffortPath(heights) << endl;
    return 0;
}

/*   Got it 👍 Let’s carefully explain the **output** of the code:

---

### 🔹 Problem Recap: *Path with Minimum Effort*

We are given a **grid of heights**, and we want to move from **top-left (0,0)** to **bottom-right (n-1, m-1)**.

* Moving between adjacent cells has an "effort" = `abs(height[current] - height[next])`.
* The effort of a path = **maximum difference** along that path.
* Our goal = find a path that minimizes this maximum effort.

---

### 🔹 Input Grid (heights matrix)

```
1 2 2
3 8 2
5 3 5
```

* Start: `(0,0)` → value = 1
* End: `(2,2)` → value = 5

---

### 🔹 Possible Paths & Their Efforts

We check some paths:

#### Path A:

```
(0,0)=1 → (0,1)=2 → (0,2)=2 → (1,2)=2 → (2,2)=5
```

Efforts along edges:

* |1-2| = 1
* |2-2| = 0
* |2-2| = 0
* |2-5| = 3

**Maximum = 3**

---

#### Path B:

```
(0,0)=1 → (1,0)=3 → (2,0)=5 → (2,1)=3 → (2,2)=5
```

Efforts:

* |1-3| = 2
* |3-5| = 2
* |5-3| = 2
* |3-5| = 2

**Maximum = 2**

---

### 🔹 Best Path = Path B

* Path A’s max effort = 3
* Path B’s max effort = 2 ✅

So, the **minimum effort path** has effort **2**.

---

### 🔹 Program Output

```
Minimum Effort Path = 2
```

---

⚡ In short:
The algorithm (Dijkstra with priority queue) finds that the safest way to travel across the grid is through `(0,0) → (1,0) → (2,0) → (2,1) → (2,2)`, where the largest jump is only **2**.

---

👉 Do you want me to **modify the code to also print this actual path (cells visited)** along with the effort?

*/