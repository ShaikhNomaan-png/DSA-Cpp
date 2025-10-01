#include <iostream>
#include <vector>
using namespace std;

// DFS function
void DFS(int node, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true;
    cout << node << " ";

    // visit all neighbors
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, adj, visited);
        }
    }
}

int main() {
    int n = 5; // number of vertices
    vector<vector<int>> adj(n); // adjacency list

    // edges (undirected)
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[2].push_back(0);
    adj[2].push_back(4);
    adj[3].push_back(1);
    adj[3].push_back(6);
    adj[4].push_back(2);
    adj[4].push_back(5);
    adj[4].push_back(8);


    vector<bool> visited(n, false);

    cout << "DFS traversal starting from node 0: ";
    DFS(0, adj, visited);
    cout << endl;

    return 0;
}
