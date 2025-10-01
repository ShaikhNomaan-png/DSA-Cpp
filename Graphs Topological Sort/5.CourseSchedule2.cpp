#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> inDegree(numCourses, 0);

    // Build graph
    for (auto &pr : prerequisites) {
        int u = pr[1], v = pr[0]; // b → a
        adj[u].push_back(v);
        inDegree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++)
        if (inDegree[i] == 0) q.push(i);

    vector<int> order;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        order.push_back(node);

        for (int neighbor : adj[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    if (order.size() == numCourses)
        return order; // valid course order
    else
        return {}; // cycle exists → impossible
}

int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}}; 
    // Possible order: 0 → 1 → 2 → 3 OR 0 → 2 → 1 → 3

    vector<int> order = findOrder(numCourses, prerequisites);
    if (!order.empty()) {
        cout << "Course order: ";
        for (int c : order) cout << c << " ";
        cout << endl;
    } else {
        cout << "No possible order (cycle exists)" << endl;
    }

    return 0;
}

/* 🔹 Output
Course order: 0 1 2 3


Another valid output could be: 0 2 1 3

🔹 Step-by-Step Explanation
Graph:
0 → 1 → 3
0 → 2 → 3


Compute in-degree:

Node	In-degree
0	0
1	1
2	1
3	2

Initialize queue → [0]

Process nodes:

Pop 0 → order [0] → neighbors 1 and 2 → decrease in-degree → push 1,2

Pop 1 → order [0,1] → neighbor 3 → decrease in-degree → not zero yet

Pop 2 → order [0,1,2] → neighbor 3 → in-degree 0 → push 3

Pop 3 → order [0,1,2,3]

All courses processed → valid order found ✅

🔹 Key Points

BFS / Topological Sort ensures dependencies are satisfied.

If cycle exists, return empty array.

Time Complexity: O(V + E)

Space Complexity: O(V + E)
*/