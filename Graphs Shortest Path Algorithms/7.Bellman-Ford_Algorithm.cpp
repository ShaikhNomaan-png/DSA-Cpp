/*🔹 Problem: Bellman-Ford Algorithm
Bellman-Ford is used to find the shortest path from a source vertex to all other vertices in a graph.
Works for graphs with negative weights.
Detects negative weight cycles.
Slower than Dijkstra: O(V · E).
🔹 Algorithm Steps
Initialize distances: dist[src] = 0, others = ∞.
Repeat V-1 times:

For each edge (u, v, w), relax it:

if dist[u] + w < dist[v]:
    dist[v] = dist[u] + w


Do one more pass to check for negative cycles.

If dist[u] + w < dist[v] again → negative cycle exists.

🔹 Example Graph
Vertices = 5
Edges:
0 → 1 (weight -1)
0 → 2 (weight 4)
1 → 2 (weight 3)
1 → 3 (weight 2)
1 → 4 (weight 2)
3 → 2 (weight 5)
3 → 1 (weight 1)
4 → 3 (weight -3)

*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int u, v, w;
};

void bellmanFord(int V, int E, int src, vector<Edge>& edges) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Step 1: Relax edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Step 2: Check for negative cycles
    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            cout << "Graph contains negative weight cycle!" << endl;
            return;
        }
    }

    // Print shortest distances
    cout << "Vertex Distance from Source " << src << ":\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            cout << i << " : INF" << endl;
        else
            cout << i << " : " << dist[i] << endl;
    }
}

int main() {
    int V = 5; // number of vertices
    int E = 8; // number of edges
    vector<Edge> edges = {
        {0,1,-1}, {0,2,4}, {1,2,3}, {1,3,2},
        {1,4,2}, {3,2,5}, {3,1,1}, {4,3,-3}
    };

    bellmanFord(V, E, 0, edges);
    return 0;
}

/*  Got it 👍 Let’s **explain the output** of **Bellman-Ford (Example 1)** step by step.

---

## 🔹 Graph Used

```
Edges:
0 → 1 (-1)
0 → 2 (4)
1 → 2 (3)
1 → 3 (2)
1 → 4 (2)
3 → 2 (5)
3 → 1 (1)
4 → 3 (-3)
```

---

## 🔹 Initial Setup

* Source = **0**
* Distance array initialized:

```
dist = [0, INF, INF, INF, INF]
```

---

## 🔹 Iteration 1 (Relax all edges)

Relax each edge one by one:

* `0→1 (-1)` → dist[1] = 0 + (-1) = **-1**
* `0→2 (4)` → dist[2] = 0 + 4 = **4**
* `1→2 (3)` → dist[2] = -1 + 3 = **2** (better than 4)
* `1→3 (2)` → dist[3] = -1 + 2 = **1**
* `1→4 (2)` → dist[4] = -1 + 2 = **1**
* `3→2 (5)` → dist[2] = min(2, 1+5=6) = **2** (no change)
* `3→1 (1)` → dist[1] = min(-1, 1+1=2) = **-1** (no change)
* `4→3 (-3)` → dist[3] = min(1, 1+(-3)=-2) = **-2**

👉 After Iteration 1:

```
dist = [0, -1, 2, -2, 1]
```

---

## 🔹 Iteration 2, 3, 4

Relaxing again won’t improve distances further, so the array stays the same.

---

## ✅ Final Distances

```
0 : 0
1 : -1
2 : 2
3 : -2
4 : 1
```

---

## 🔎 Meaning of Output

* **Shortest path from 0 → 1 = -1** (direct edge)
* **Shortest path from 0 → 2 = 2** (via 0→1→2)
* **Shortest path from 0 → 3 = -2** (via 0→1→4→3)
* **Shortest path from 0 → 4 = 1** (via 0→1→4)

👉 No negative cycle detected, so these are correct shortest paths.

---

Do you want me to also draw the **graph diagram with highlighted shortest paths** for better visualization of this output?

*/
