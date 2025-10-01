// Time Complexity: O(V + E)
// Space Complexity: O(V) (color array + recursion stack)
#include <iostream>
#include <vector>
using namespace std;

// DFS function to check bipartite from a node
bool isBipartiteDFS(int node, vector<vector<int>>& adj, vector<int>& color, int c) {
    color[node] = c; // Assign color to current node

    for (int neighbor : adj[node]) {
        if (color[neighbor] == -1) {
            // Color neighbor with opposite color
            if (!isBipartiteDFS(neighbor, adj, color, 1 - c))
                return false;
        }
        else if (color[neighbor] == color[node]) {
            // Same color as neighbor → not bipartite
            return false;
        }
    }
    return true;
}

// Function to check bipartite for entire graph
bool checkBipartite(int V, vector<vector<int>>& adj) {
    vector<int> color(V, -1); // -1 means uncolored

    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {
            if (!isBipartiteDFS(i, adj, color, 0))
                return false;
        }
    }
    return true;
}

int main() {
    int V = 4; // number of vertices
    vector<vector<int>> adj(V);

    // Example Graph (same as previous BFS example)
    // Graph: 0--1
    //        |  |
    //        3--2
    adj[0].push_back(1); adj[1].push_back(0);
    adj[1].push_back(2); adj[2].push_back(1);
    adj[2].push_back(3); adj[3].push_back(2);
    adj[3].push_back(0); adj[0].push_back(3);

    if (checkBipartite(V, adj))
        cout << "Graph is Bipartite using DFS" << endl;
    else
        cout << "Graph is Not Bipartite" << endl;

    return 0;
}

/*Absolutely! Let’s carefully explain **G-18: Bipartite Graph using DFS** with **problem, graph, DFS steps, coloring, and output**.

---

## 🔹 Problem (Bipartite Graph using DFS)

We are given an **undirected graph**, and we need to **check whether it is bipartite**.

### Definition:

* A graph is **bipartite** if we can divide its vertices into **two sets** such that **no two vertices in the same set are connected by an edge**.
* Equivalently: **the graph is 2-colorable** (nodes can be colored with 0 or 1 such that adjacent nodes have different colors).

**Goal:**

* Use **DFS traversal** to color the nodes and detect conflicts.
* If conflict exists (two adjacent nodes have the same color) → Not bipartite.
* If all nodes colored without conflict → Bipartite.

---

## 🔹 Graph Used in Code

Edges added in code:

| Node | Neighbors |
| ---- | --------- |
| 0    | 1, 3      |
| 1    | 0, 2      |
| 2    | 1, 3      |
| 3    | 2, 0      |

### Visual Representation:

```
     0
    / \
   1   3
    \ /
     2
```

* 4-node cycle (even-length)
* This is a classic **bipartite graph**.

---

## 🔹 DFS Coloring Step-by-Step

We maintain a **color array** initialized with `-1` (uncolored).

1. **Start DFS at node 0**, assign color `0`

   * Neighbor `1` → assign color `1`
   * Neighbor `3` → assign color `1`

2. **DFS from node 1**

   * Neighbor `0` → already colored `0` ✅ OK
   * Neighbor `2` → assign color `0`

3. **DFS from node 3**

   * Neighbor `0` → already colored `0` ✅ OK
   * Neighbor `2` → already colored `0` ✅ OK

4. **DFS from node 2**

   * Neighbor `1` → already colored `1` ✅ OK
   * Neighbor `3` → already colored `1` ✅ OK

✅ All nodes colored successfully without conflict → **Graph is Bipartite**

---

## 🔹 Final Coloring Table

| Node | Color |
| ---- | ----- |
| 0    | 0     |
| 1    | 1     |
| 2    | 0     |
| 3    | 1     |

* Adjacent nodes always have **different colors**, confirming bipartite property.

---

## 🔹 Output

```
Graph is Bipartite
```

---

## 🔹 Why This Output?

* The graph is a **4-node even cycle** → bipartite
* DFS successfully colors nodes alternately
* **No conflicts** detected → satisfies bipartite condition

> Note: If the cycle were **odd-length** (e.g., 3 nodes), DFS would detect a conflict and output **“Graph is Not Bipartite”**.

---

## 🔹 Key Notes

* DFS works recursively by coloring nodes and checking neighbors.
* Handles **disconnected graphs** by running DFS on all unvisited nodes.
* **Time Complexity:** `O(V + E)`
* **Space Complexity:** `O(V)` (color array + recursion stack)

---

If you want, I can also make a **graph with an odd cycle** and show **why DFS outputs “Not Bipartite”**, which is perfect for interviews.

Do you want me to do that?

*/