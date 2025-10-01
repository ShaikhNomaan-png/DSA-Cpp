#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool hasCycleTopologicalSort(int V, vector<vector<int>>& adj) {
    vector<int> inDegree(V, 0);

    // Compute in-degree
    for (int u = 0; u < V; u++)
        for (int v : adj[u])
            inDegree[v]++;

    queue<int> q;
    for (int i = 0; i < V; i++)
        if (inDegree[i] == 0) q.push(i);

    int count = 0;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        count++;
        for (int neighbor : adj[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    return count != V; // cycle exists if not all nodes processed
}

int main() {
    int V = 4;
    vector<vector<int>> adj(V);

    // Graph with a cycle
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1); // back edge → cycle

    if (hasCycleTopologicalSort(V, adj))
        cout << "Graph contains a cycle" << endl;
    else
        cout << "Graph does not contain a cycle" << endl;

    return 0;
}
