#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to check bipartite from a starting node using BFS
bool isBipartiteBFS(int start, vector<vector<int>>& adj, vector<int>& color) {
    queue<int> q;
    color[start] = 0; // start coloring with 0
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (color[neighbor] == -1) {
                // Assign opposite color to neighbor
                color[neighbor] = 1 - color[node];
                q.push(neighbor);
            } else if (color[neighbor] == color[node]) {
                // Same color as neighbor → not bipartite
                return false;
            }
        }
    }
    return true;
}

// Function to check bipartite for entire graph (handles disconnected graph)
bool checkBipartite(int V, vector<vector<int>>& adj) {
    vector<int> color(V, -1); // -1 means uncolored

    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {
            if (!isBipartiteBFS(i, adj, color)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int V = 4; // number of vertices
    vector<vector<int>> adj(V); // adjacency list

    // Example Graph
    // Graph: 0--1
    //        |  |
    //        3--2
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(0);
    adj[0].push_back(3);

    if (checkBipartite(V, adj))
        cout << "Graph is Bipartite using BFS" << endl;
    else
        cout << "Graph is Not Bipartite" << endl;

    return 0;
}

/*  Sure! Let’s explain the **output** of the corrected **Bipartite Graph BFS code** with a step-by-step walkthrough.

---

## 🔹 Problem Recap

We want to check if the graph is **Bipartite**, meaning:

* The vertices can be divided into **two sets**,
* No two vertices in the same set are connected by an edge.

Equivalent to: **Can we 2-color the graph?**

* Color 0 → Set A
* Color 1 → Set B
* Adjacent nodes must have **different colors**

---

## 🔹 Graph Used in Code

The edges are:

```
0--1
|  |
3--2
```

Adjacency list in code:

| Node | Neighbors |
| ---- | --------- |
| 0    | 1, 3      |
| 1    | 0, 2      |
| 2    | 1, 3      |
| 3    | 2, 0      |

This is a **4-node cycle** (even cycle).

---

## 🔹 BFS Traversal & Coloring Step by Step

1. **Start BFS at node 0**, color `0`

   * Neighbor 1 → color `1`
   * Neighbor 3 → color `1`

2. **Process node 1**

   * Neighbor 0 → already colored `0` → ok
   * Neighbor 2 → color `0`

3. **Process node 3**

   * Neighbor 0 → already colored `0` → ok
   * Neighbor 2 → already colored `0` → ok

4. **Process node 2**

   * Neighbor 1 → already colored `1` → ok
   * Neighbor 3 → already colored `1` → ok

✅ All nodes colored without conflicts.

---

## 🔹 Final Coloring

| Node | Color |
| ---- | ----- |
| 0    | 0     |
| 1    | 1     |
| 2    | 0     |
| 3    | 1     |

* **Adjacent nodes always have different colors** ✅

---

## 🔹 Output

```
Graph is Bipartite
```

---

### 🔹 Why the Output is Correct

* The graph forms a **4-node cycle**, which is an **even-length cycle**.
* **Even cycles are bipartite**, because we can alternate colors around the cycle.
* BFS coloring detects this correctly.

---

If you want, I can also show a **graph with an odd-length cycle**, where the output will be **“Graph is Not Bipartite”**, and explain why it fails.

Do you want me to show that?

*/