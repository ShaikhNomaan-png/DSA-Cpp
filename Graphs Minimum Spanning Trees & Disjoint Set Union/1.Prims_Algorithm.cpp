/*  🔹 Problem: Prim’s Algorithm
Prim’s Algorithm is used to find the Minimum Spanning Tree (MST) of a connected weighted undirected graph.
MST = subset of edges that connects all vertices with minimum total weight and no cycles.
Prim’s algorithm builds MST starting from a single vertex and repeatedly adds the minimum weight edge that connects a vertex inside MST to a vertex outside MST.
🔹 Key Points

Graph must be connected.

Works with positive weighted edges.

Can be implemented using:

Adjacency matrix

Adjacency list + priority queue (efficient)

Time Complexity:

Simple: O(V^2) (matrix)

Using min-heap: O(E log V)

🔹 Example Graph
Vertices = 5
Edges (Undirected, weight):
0 - 1 = 2
0 - 3 = 6
1 - 2 = 3
1 - 3 = 8
1 - 4 = 5
2 - 4 = 7
3 - 4 = 9


Graph diagram (for visualization):

      2
  0 ------- 1
  | \       |
 6|  \8     |5
  |   \     |
  3-------4
       9


🔹 Output Explanation

Start from vertex 0: choose minimum edge 0–1 (weight 2) → add 1 to MST

Next, choose minimum edge connecting MST to outside: 1–2 (weight 3) → add 2

Next: 1–4 (weight 5) → add 4

Next: 0–3 (weight 6) → add 3

All vertices included → MST complete

Total weight = 2+3+5+6 = 16 ✅
       */


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> pii; // {weight, vertex}

void primMST(int V, vector<vector<pii>>& adj) {
    vector<int> key(V, INT_MAX);  // Minimum weight edge to vertex
    vector<int> parent(V, -1);    // Parent vertex in MST
    vector<bool> inMST(V, false); // Track vertices in MST

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    key[0] = 0;
    pq.push({0,0}); // {weight, vertex}

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;

        for (auto &[v, w] : adj[u]) {
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    // Print MST edges and total weight
    int totalWeight = 0;
    cout << "Edges in MST:\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " (weight " << key[i] << ")\n";
        totalWeight += key[i];
    }
    cout << "Total weight of MST = " << totalWeight << endl;
}

int main() {
    int V = 5;
    vector<vector<pii>> adj(V);

    // Add undirected edges
    adj[0].push_back({1,2}); adj[1].push_back({0,2});
    adj[0].push_back({3,6}); adj[3].push_back({0,6});
    adj[1].push_back({2,3}); adj[2].push_back({1,3});
    adj[1].push_back({3,8}); adj[3].push_back({1,8});
    adj[1].push_back({4,5}); adj[4].push_back({1,5});
    adj[2].push_back({4,7}); adj[4].push_back({2,7});
    adj[3].push_back({4,9}); adj[4].push_back({3,9});

    primMST(V, adj);
    return 0;
}
