#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool hasCycleBFS(int V, vector<vector<int>>& adj) {
    vector<int> inDegree(V, 0);

    // Compute in-degree of each node
    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            inDegree[v]++;
        }
    }

    queue<int> q;
    // Add nodes with in-degree 0 to queue
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) q.push(i);
    }

    int count = 0; // Count of nodes processed

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;

        for (int neighbor : adj[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    // If count < V, cycle exists
    return count != V;
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

    if (hasCycleBFS(V, adj))
        cout << "Graph contains a cycle" << endl;
    else
        cout << "Graph does not contain a cycle" << endl;

    return 0;
}
