#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> shortestPathUnitWeight(int N, int src, vector<vector<int>>& edges) {
    vector<vector<int>> adj(N);
    for (auto &e : edges) {
        int u = e[0], v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }

    vector<int> dist(N, -1);
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int node = q.front(); q.pop();

        for (int neighbor : adj[node]) {
            if (dist[neighbor] == -1) { // unvisited
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }

    return dist;
}

int main() {
    int N = 6;
    vector<vector<int>> edges = {
        {0,1},{0,2},{1,3},{2,3},{3,4},{4,5}
    };
/*    0 (0)
     / \
   1(1) 2(1)
     \  /
      3(2)
       |
      4(3)
       |
      5(4)       */
    int src = 0;
    vector<int> dist = shortestPathUnitWeight(N, src, edges);

    cout << "Shortest distances from node " << src << ": ";
    for (int d : dist) cout << d << " ";
    cout << endl;

    return 0;
}

