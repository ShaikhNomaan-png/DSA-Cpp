/*  🔹 Problem: Kruskal’s Algorithm

Kruskal’s Algorithm finds the Minimum Spanning Tree (MST) of a connected, weighted, undirected graph.

MST = subset of edges that:

Connect all vertices

No cycles

Minimum total weight

Idea:

Sort all edges by weight

Pick edges in increasing weight

Include edge only if it does not form a cycle (use Union-Find / Disjoint Set)

Stop when V-1 edges are included (V = number of vertices)

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


Graph diagram:

      2
  0 ------- 1
  | \       |
 6|  \8     |5
  |   \     |
  3-------4
       9

🔹 Step-by-Step Explanation

Sort edges by weight: 0–1(2), 1–2(3), 1–4(5), 0–3(6), 2–4(7), 1–3(8), 3–4(9)

Pick edge 0–1 (2) → no cycle → include

Pick edge 1–2 (3) → no cycle → include

Pick edge 1–4 (5) → no cycle → include

Pick edge 0–3 (6) → no cycle → include

MST now has V-1 = 4 edges, stop

✅ Total weight = 2+3+5+6 = 16

🔹 Key Points

Uses Union-Find to detect cycles efficiently

Works better for sparse graphs

Time Complexity: O(E log E + E α(V)) ≈ O(E log E)

Result is an MST (may not be unique if multiple edges have same weight)
       🔹 C++ Code (Kruskal’s Algorithm)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

// Union-Find functions
int findParent(int u, vector<int>& parent) {
    if (parent[u] != u) parent[u] = findParent(parent[u], parent);
    return parent[u];
}

void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);
    if (rank[u] < rank[v]) parent[u] = v;
    else if (rank[v] < rank[u]) parent[v] = u;
    else { parent[v] = u; rank[u]++; }
}

bool compare(Edge a, Edge b) {
    return a.w < b.w;
}

void kruskalMST(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compare); // Sort edges by weight

    vector<int> parent(V), rank(V, 0);
    for (int i = 0; i < V; i++) parent[i] = i;

    vector<Edge> mst;
    int totalWeight = 0;

    for (auto e : edges) {
        if (findParent(e.u, parent) != findParent(e.v, parent)) {
            mst.push_back(e);
            totalWeight += e.w;
            unionSet(e.u, e.v, parent, rank);
        }
    }

    // Print MST
    cout << "Edges in MST (Kruskal's Algorithm):\n";
    for (auto e : mst)
        cout << e.u << " - " << e.v << " (weight " << e.w << ")\n";
    cout << "Total weight of MST = " << totalWeight << endl;
}

int main() {
    int V = 5;
    vector<Edge> edges = {
        {0,1,2}, {0,3,6}, {1,2,3}, {1,3,8},
        {1,4,5}, {2,4,7}, {3,4,9}
    };

    kruskalMST(V, edges);
    return 0;
}
