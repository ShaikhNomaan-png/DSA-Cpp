/* 🔹 Problem

Input:

A Directed Acyclic Graph (DAG) with weighted edges.

N nodes labeled 0 to N-1

edges → list of [u, v, weight]

Goal: Find the shortest path from a source node to all other nodes.

Key Idea:

Because the graph is a DAG, we can use Topological Sorting to process nodes in dependency order.

Once in topological order, relax each edge only once, giving O(V + E) shortest path computation.

🔹 Approach

Topological Sort of the DAG (DFS-based or BFS-based).

Initialize dist[] array with INF (except source = 0).

Process nodes in topological order:

For each node u, update distances of all neighbors v using dist[v] = min(dist[v], dist[u] + weight(u,v))

Why it works:

In DAG, there are no cycles, so topological order ensures all predecessors are processed before a node.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

// DFS for Topological Sort
void topoDFS(int node, vector<vector<pair<int,int>>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;
    for (auto &neighbor : adj[node]) {
        int v = neighbor.first;
        if (!visited[v])
            topoDFS(v, adj, visited, st);
    }
    st.push(node);
}

// Shortest Path in DAG
vector<int> shortestPathDAG(int N, int src, vector<vector<pair<int,int>>>& adj) {
    vector<bool> visited(N, false);
    stack<int> st;

    // Step 1: Topological Sort
    for (int i = 0; i < N; i++)
        if (!visited[i])
            topoDFS(i, adj, visited, st);

    // Step 2: Initialize distances
    vector<int> dist(N, INT_MAX);
    dist[src] = 0;

    // Step 3: Process nodes in topological order
    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (dist[u] != INT_MAX) {
            for (auto &neighbor : adj[u]) {
                int v = neighbor.first;
                int w = neighbor.second;
                if (dist[u] + w < dist[v])
                    dist[v] = dist[u] + w;
            }
        }
    }
    return dist;
}

int main() {
    int N = 6; // number of nodes
    vector<vector<pair<int,int>>> adj(N);

    // Example weighted DAG
    adj[0].push_back({1,5});
    adj[0].push_back({2,3});
    adj[1].push_back({3,6});
    adj[1].push_back({2,2});
    adj[2].push_back({4,4});
    adj[2].push_back({5,2});
    adj[2].push_back({3,7});
    adj[3].push_back({4,-1});
    adj[4].push_back({5,-2});

    int src = 1;
    vector<int> dist = shortestPathDAG(N, src, adj);

    cout << "Shortest distances from node " << src << ": ";
    for (int d : dist) {
        if (d == INT_MAX) cout << "INF ";
        else cout << d << " ";
    }
    cout << endl;

    return 0;
}


/*  Sure! Let’s explain the **output of Shortest Path in a DAG using Topological Sort** in simple terms.

---

## 🔹 Problem Recap

* **Graph:** Weighted DAG with nodes `0` to `5`
* **Edges:**

```
0 → 1 (5)
0 → 2 (3)
1 → 3 (6)
1 → 2 (2)
2 → 4 (4)
2 → 5 (2)
2 → 3 (7)
3 → 4 (-1)
4 → 5 (-2)
```

* **Source node:** `1`
* **Goal:** Find shortest distance from node `1` to all other nodes.

---

## 🔹 Step-by-Step Explanation

1. **Topological Sort:**

   * Process nodes in order such that all predecessors are visited before a node.
   * Example topological order could be: `0,1,2,3,4,5` (only relative order matters).

2. **Initialize distances:**

| Node | Distance from 1 |
| ---- | --------------- |
| 0    | INF             |
| 1    | 0               |
| 2    | INF             |
| 3    | INF             |
| 4    | INF             |
| 5    | INF             |

3. **Relax edges in topological order:**

* Node `1`:

  * 1 → 2: `dist[2] = min(INF, 0+2) = 2`
  * 1 → 3: `dist[3] = min(INF, 0+6) = 6`

* Node `2`:

  * 2 → 4: `dist[4] = min(INF, 2+4) = 6`
  * 2 → 5: `dist[5] = min(INF, 2+2) = 4`
  * 2 → 3: `dist[3] = min(6, 2+7) = 6` (no change)

* Node `3`:

  * 3 → 4: `dist[4] = min(6, 6-1) = 5`

* Node `4`:

  * 4 → 5: `dist[5] = min(4, 5-2) = 3`

* Node `0`: no outgoing edges (source not reachable from node 0)

---

## 🔹 Final Distances

| Node | Distance from 1     |
| ---- | ------------------- |
| 0    | INF (not reachable) |
| 1    | 0                   |
| 2    | 2                   |
| 3    | 6                   |
| 4    | 5                   |
| 5    | 3                   |

**Output:**

```
Shortest distances from node 1: INF 0 2 6 5 3
```

---

## 🔹 Explanation of INF

* Node `0` has **no path from source node 1** → distance = INF.
* Other nodes are reachable through directed edges and distances are **shortest path sum of weights**.

---

✅ **Key Takeaways:**

* DAG + Topological sort → **linear time shortest path computation**
* Negative weights are fine in DAG (no cycles)
* Order of processing ensures **all predecessors are relaxed before a node**

---

If you want, I can **draw a visual DAG showing the shortest paths from source node 1**, which makes it very easy to understand.

Do you want me to do that?

*/