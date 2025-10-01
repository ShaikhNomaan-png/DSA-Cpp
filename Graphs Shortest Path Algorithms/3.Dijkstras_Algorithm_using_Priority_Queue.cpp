/*  Great question 👍
This is an **important interview topic**:
---
# 🔹 Why is a **Priority Queue** used in Dijkstra’s Algorithm?
### ✅ 1. Dijkstra’s Algorithm in Short
* Dijkstra finds the **shortest path** from a source node to all other nodes in a weighted graph (non-negative weights).
* The key idea:
  * Always pick the **next node with the smallesttentative distance**.
  * Update (relax) the distances of its neighbors.
---
### ✅ 2. Problem Without Priority Queue
If we use a **normal array or queue**:
* Each time we must **search through all vertices** to find the node with the minimum distance.
* That takes **O(V)** time for each selection.
* Total complexity: **O(V² + E)** (not efficient for large graphs).
---
### ✅ 3. Role of Priority Queue (Min-Heap)
* A **priority queue (min-heap)** always gives us the node with the **smallest distance** in **O(log V)** time.
* When we relax an edge and update a neighbor’s distance, we just **push it into the heap**.
* Even if duplicates exist, the queue ensures the **smallest distance version comes out first**, and outdated entries are ignored.
---
### ✅ 4. Time Complexity Improvement
* Using **priority queue**:
  * Extract-min: **O(log V)**
  * For all `E` edges → total complexity: **O((V + E) log V)**
* Much faster than **O(V²)** for dense graphs.
---
### ✅ 5. Analogy
Imagine you’re exploring cities (nodes) with roads (edges).
* Without a PQ: You check **all cities manually** to see which is closest → slow.
* With a PQ: You have a **to-do list sorted by distance**. The nearest city always comes first → fast and efficient.
---
### ✅ 6. Interview-Style Answer
👉 **“Priority Queue is used in Dijkstra’s Algorithm because it allows us to efficiently select the next node with the smallest tentative distance in O(log V) time. This reduces the overall time complexity from O(V²) to O((V+E) log V), making Dijkstra practical for large graphs.”**
---
⚡ Do you want me to also show you **a comparison example with and without a priority queue (step-by-step trace)** so you see the speed difference?
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> P; // (dist, node)

void dijkstra(int V, vector<vector<P>>& adj, int src) {
    vector<int> dist(V, 1e9); // initialize distances as infinity
    dist[src] = 0;

    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (d > dist[node]) continue; // Skip outdated entry

        for (auto it : adj[node]) {
            int neighbor = it.first;
            int weight = it.second;

            if (dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    // Print shortest distances
    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " → " << dist[i] << endl;
    }
}

int main() {
    int V = 5;
    vector<vector<P>> adj(V);

    // Graph edges
    adj[0].push_back({1,4});
    adj[0].push_back({2,8});
    adj[1].push_back({0,4});
    adj[1].push_back({2,2});
    adj[1].push_back({4,2});
    adj[2].push_back({0,8});
    adj[2].push_back({1,2});
    adj[2].push_back({3,7});
    adj[2].push_back({4,3});
    adj[3].push_back({2,7});
    adj[3].push_back({4,9});
    adj[4].push_back({1,2});
    adj[4].push_back({2,3});
    adj[4].push_back({3,9});

    dijkstra(V, adj, 0); // Source = 0

    return 0;
}
/*   (0)
    /   \
   4     8
  /       \
(1)---(2)--(3)
  \    |     \
   2   3      9
    \  |       \
     (4)--------               *//*
     
     Explanation

From 0 → 1 directly = 4

From 0 → 2: 0→1→2 = 4+2 = 6 (better than 8 direct)

From 0 → 4: 0→1→4 = 4+2 = 6

From 0 → 3: 0→1→2→3 = 4+2+7 = 13

So final shortest distances are {0, 4, 6, 13, 6}.
     */
