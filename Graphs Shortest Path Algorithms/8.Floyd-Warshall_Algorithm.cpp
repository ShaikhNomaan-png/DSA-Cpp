/*  🔹 Problem: Floyd-Warshall Algorithm

Floyd-Warshall is an all-pairs shortest path algorithm.

You are given:

n vertices

A weighted directed graph (can have negative edges, but no negative cycles)

Goal: Find shortest distance between all pairs of vertices.

🔹 Key Points

Handles negative weights.

Detects negative cycles if dist[i][i] < 0.

Time Complexity: O(n^3)

🔹 Algorithm Idea

Initialize dist[i][j] = weight of edge i→j (INF if no edge)

For every vertex k (intermediate node):

for i in 0..n-1:
    for j in 0..n-1:
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])


After all iterations, dist[i][j] = shortest distance from i to j.

🔹 Example Graph
Vertices = 4
Edges:
0 → 1 (5)
0 → 3 (10)
1 → 2 (3)
2 → 3 (1)

🔹 Explanation

dist[0][2] = 8 → Path: 0→1→2 = 5 + 3 = 8

dist[0][3] = 9 → Path: 0→1→2→3 = 5+3+1=9 (better than direct 0→3=10)

dist[1][3] = 4 → Path: 1→2→3 = 3+1=4

INF = No path exists between those vertices

✅ This output gives shortest distances between all pairs.
*/ 

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX;

void floydWarshall(int V, vector<vector<int>>& graph) {
    vector<vector<int>> dist = graph;

    // Main loop
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // Print all-pairs shortest distances
    cout << "All-Pairs Shortest Distances:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF" << "\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int V = 4;
    vector<vector<int>> graph(V, vector<int>(V, INF));

    // Distance to itself = 0
    for (int i = 0; i < V; i++) graph[i][i] = 0;

    // Add edges
    graph[0][1] = 5;
    graph[0][3] = 10;
    graph[1][2] = 3;
    graph[2][3] = 1;

    floydWarshall(V, graph);
    return 0;
}


/* Sure! Let’s **explain the output of Floyd-Warshall step by step** so you clearly see how each value is computed.

---

## 🔹 Graph Recap

Vertices = 4 (0,1,2,3)
Edges:

```
0 → 1 = 5
0 → 3 = 10
1 → 2 = 3
2 → 3 = 1
```

Initial distance matrix (INF = no edge, 0 = self distance):

|   | 0   | 1   | 2   | 3   |
| - | --- | --- | --- | --- |
| 0 | 0   | 5   | INF | 10  |
| 1 | INF | 0   | 3   | INF |
| 2 | INF | INF | 0   | 1   |
| 3 | INF | INF | INF | 0   |

---

## 🔹 Step 1: Using vertex `k = 0` as intermediate

For all pairs `(i,j)`, check if `dist[i][0] + dist[0][j] < dist[i][j]`:

* `dist[0][1]`: min(5, 0+5)=5 → no change
* `dist[0][2]`: min(INF, 0+INF)=INF → no change
* `dist[0][3]`: min(10, 0+10)=10 → no change
* Other rows: no updates because `dist[1][0] = INF`, `dist[2][0] = INF`, etc.

**Matrix after k=0:**

|   | 0   | 1   | 2   | 3   |
| - | --- | --- | --- | --- |
| 0 | 0   | 5   | INF | 10  |
| 1 | INF | 0   | 3   | INF |
| 2 | INF | INF | 0   | 1   |
| 3 | INF | INF | INF | 0   |

---

## 🔹 Step 2: Using vertex `k = 1` as intermediate

Check `dist[i][j] > dist[i][1] + dist[1][j]`:

* `dist[0][2]`: min(INF, dist[0][1]+dist[1][2]=5+3=8) → updated to 8
* `dist[0][3]`: min(10, dist[0][1]+dist[1][3]=5+INF=INF) → stays 10
* `dist[1][3]`: min(INF, dist[1][1]+dist[1][3]=0+INF=INF) → stays INF

**Matrix after k=1:**

|   | 0   | 1   | 2   | 3   |
| - | --- | --- | --- | --- |
| 0 | 0   | 5   | 8   | 10  |
| 1 | INF | 0   | 3   | INF |
| 2 | INF | INF | 0   | 1   |
| 3 | INF | INF | INF | 0   |

---

## 🔹 Step 3: Using vertex `k = 2` as intermediate

* `dist[0][3]`: min(10, dist[0][2]+dist[2][3]=8+1=9) → updated to 9
* `dist[1][3]`: min(INF, dist[1][2]+dist[2][3]=3+1=4) → updated to 4

**Matrix after k=2:**

|   | 0   | 1   | 2   | 3 |
| - | --- | --- | --- | - |
| 0 | 0   | 5   | 8   | 9 |
| 1 | INF | 0   | 3   | 4 |
| 2 | INF | INF | 0   | 1 |
| 3 | INF | INF | INF | 0 |

---

## 🔹 Step 4: Using vertex `k = 3` as intermediate

* No updates, since `3` has no outgoing edges except self-loop.

**Final matrix:**

|   | 0   | 1   | 2   | 3 |
| - | --- | --- | --- | - |
| 0 | 0   | 5   | 8   | 9 |
| 1 | INF | 0   | 3   | 4 |
| 2 | INF | INF | 0   | 1 |
| 3 | INF | INF | INF | 0 |

---

## 🔹 How Output Comes

* `dist[0][2] = 8` → shortest path 0→1→2 = 5+3=8
* `dist[0][3] = 9` → shortest path 0→1→2→3 = 5+3+1=9
* `dist[1][3] = 4` → shortest path 1→2→3 = 3+1=4
* `INF` = no path exists between those vertices

---

✅ **Output Explanation Complete**
This is how Floyd-Warshall iteratively **improves distances using each vertex as intermediate**.

---

If you want, I can **draw the graph and highlight all shortest paths** visually—it makes understanding much easier.

Do you want me to do that?

*/ 