//  Time Complexity: O(V + E)
//Space Complexity: O(V) for visited + recursion stack
#include <iostream>
#include <vector>
using namespace std;

bool dfsCycle(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack) {
    visited[node] = true;
    recStack[node] = true; // add to recursion stack

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfsCycle(neighbor, adj, visited, recStack))
                return true;
        }
        else if (recStack[neighbor]) {
            // Node is in current recursion stack → cycle detected
            return true;
        }
    }

    recStack[node] = false; // remove from recursion stack
    return false;
}

bool hasCycleDirected(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfsCycle(i, adj, visited, recStack))
                return true;
        }
    }
    return false;
}

int main() {
    int V = 4;
    vector<vector<int>> adj(V);

    // Example Directed Graph
    // 0 → 1 → 2 → 3
    //      ↑      |
    //      └──────┘
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1); // back edge creates cycle

    if (hasCycleDirected(V, adj))
        cout << "Graph contains a cycle" << endl;
    else
        cout << "Graph does not contain a cycle" << endl;

    return 0;
}

/* Absolutely! Let’s carefully explain the **output of the DFS-based cycle detection in a directed graph** (G-19).

---

## 🔹 Problem Recap

We are detecting **cycles in a directed graph**.

* A **cycle exists** if you can start from a node and follow directed edges to eventually return to the same node.
* We use **DFS** with a **recursion stack** to detect cycles.

---

## 🔹 Graph Used in Code

Edges:

```
0 → 1 → 2 → 3
      ↑     |
      └─────
```

Adjacency list in code:

| Node | Neighbors |
| ---- | --------- |
| 0    | 1         |
| 1    | 2         |
| 2    | 3         |
| 3    | 1         |

* Node `3 → 1` is a **back edge**, forming a **cycle**: `1 → 2 → 3 → 1`.

---

## 🔹 DFS Traversal Step-by-Step

1. Start DFS at **node 0**

   * Mark `0` visited, add to recursion stack

2. Visit neighbor **1**

   * Mark `1` visited, add to recursion stack

3. Visit neighbor **2**

   * Mark `2` visited, add to recursion stack

4. Visit neighbor **3**

   * Mark `3` visited, add to recursion stack

5. Visit neighbor **1**

   * `1` is already in the **recursion stack** → **cycle detected**

---

## 🔹 Recursion Stack Status (Before detecting cycle)

| Node | In Recursion Stack? |
| ---- | ------------------- |
| 0    | yes                 |
| 1    | yes                 |
| 2    | yes                 |
| 3    | yes                 |

* Encountering `1` again in the **recursion stack** signals a cycle.

---

## 🔹 Output

```
Graph contains a cycle
```

---

## 🔹 Why the Output is Correct

* The graph contains a **directed cycle**: `1 → 2 → 3 → 1`
* DFS with recursion stack successfully detected it

---

## 🔹 Key Points

* **Directed graph cycles** require **recursion stack**, not just visited array.
* **Back edge to a node in recursion stack** → cycle
* **Time Complexity:** `O(V + E)`
* **Space Complexity:** `O(V)`

---

If you want, I can also draw a **graph with no cycle** and show **how DFS traversal proceeds and confirms no cycle**, which helps for interviews.

Do you want me to do that?

*/