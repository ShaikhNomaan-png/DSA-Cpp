//Time Complexity: O(V + E) (each node & edge visited once)
//✅ Space Complexity: O(V) (visited + queue)


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int vertex;
    int parent;
};

bool isCycleBFS(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<Node> q;

    visited[start] = true;
    // Push the start node with no parent
    q.push({start, -1});

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        // Iterate through all the neighbors of the current vertex
        for (int neighbor : adj[cur.vertex]) {
            // If the neighbor hasn't been visited, mark it and enqueue
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, cur.vertex});  // Set parent to current vertex
            }
            // If the neighbor is visited and is not the parent of the current node, there is a cycle
            else if (neighbor != cur.parent) {
                return true; // Cycle detected
            }
        }
    }
    return false; // No cycle found
}

bool hasCycle(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);

    // Check for cycles in disconnected components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) { // Only start a BFS from unvisited nodes
            if (isCycleBFS(i, adj, visited)) {
                return true; // Cycle found
            }
        }
    }
    return false; // No cycles in any components
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<int>> adj(V); // Graph representation as an adjacency list

    // Example graph with a cycle
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(4);
    adj[4].push_back(3);

    adj[4].push_back(1); // Back edge creates cycle
    adj[1].push_back(4); // Add this line for undirected graph completeness

    if (hasCycle(V, adj))
        cout << "Graph contains a cycle" << endl;
    else
        cout << "Graph does not contain a cycle" << endl;

    return 0;
}

/* Alright 👍 let’s make it super clear with **problem + example graph + BFS steps + final output**.

---

## 🔹 Problem (G-11: Detect a Cycle in an Undirected Graph using BFS)

We are given an **undirected graph**.
We need to check **if it contains a cycle**.

👉 A **cycle** exists if we can start at a node, move along edges, and come back to the same node **without repeating an edge**.

---

## 🔹 Graph Used in Code

The code builds this graph:

```
0 -- 1 -- 2 -- 3 -- 4
      \____________/
```

### Edges:

* `0 – 1`
* `1 – 2`
* `2 – 3`
* `3 – 4`
* `4 – 1`  (extra edge that creates a cycle)

---

## 🔹 BFS Cycle Detection Process

We start BFS from each unvisited node, and for each node, we store its **parent** (the node that discovered it).

1. Start BFS at **node 0**

   * Visit neighbor `1` (parent = 0).

2. From **node 1**

   * Visit neighbor `2` (parent = 1).
   * Visit neighbor `4` (parent = 1).

3. From **node 2**

   * Visit neighbor `3` (parent = 2).

4. From **node 3**

   * Try to visit neighbor `4`.
   * But `4` is **already visited** and `4` is \*\*not parent of 3\`.
   * 🔴 This means we found a **back edge → cycle exists**.

---

## 🔹 Output

```
Graph contains a cycle
```

---

## 🔹 Why This Output?

* Because of the edge **1–4**, there is a path:

```
1 → 2 → 3 → 4 → 1
```

This forms a **cycle**.

If we remove the edge `(1–4)`, the graph would look like a straight line `0–1–2–3–4` → and then the output would be:

```
Graph does not contain a cycle
```

---

✅ So, the program correctly identifies cycles using BFS + parent tracking.

---

Do you want me to also show the **DFS version (G-12)** of detecting cycle, so you can compare BFS vs DFS approaches side by side?
 */