#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// DFS function for topological sort
void topoDFS(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            topoDFS(neighbor, adj, visited, st);
        }
    }

    st.push(node); // push after all neighbors are processed
}

// Function to perform topological sort
vector<int> topologicalSort(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    stack<int> st;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            topoDFS(i, adj, visited, st);
        }
    }

    // Pop from stack to get topological order
    vector<int> topoOrder;
    while (!st.empty()) {
        topoOrder.push_back(st.top());
        st.pop();
    }
    return topoOrder;
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V);

    // Example DAG
    // 5 → 2 → 3
    // 5 → 0
    // 4 → 0
    // 4 → 1
    // 2 → 3
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> topoOrder = topologicalSort(V, adj);

    cout << "Topological Sort (DFS): ";
    for (int node : topoOrder) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

/*  Sure! Let’s explain the **output of DFS-based Topological Sort (G-21)** in detail.

---

## 🔹 Problem Recap

* **Goal:** Find a **linear ordering of vertices** in a **DAG** such that for every directed edge `u → v`, `u` comes **before** `v`.
* **Method:** DFS-based Topological Sort.
* **Stack logic:** In DFS, a node is **pushed onto the stack after all its neighbors** are visited. Popping the stack gives the topological order.

---

## 🔹 Graph Used

Edges in code:

```
5 → 2 → 3 → 1
5 → 0
4 → 0
4 → 1
```

### Visual Representation:

```
    5      4
   / \    / \
  2   0  0   1
   \
    3
     \
      1
```

* Nodes `0` and `1` have no outgoing edges → “sink nodes”.
* Nodes `5` and `4` have edges → “sources”.

---

## 🔹 DFS & Stack Step-by-Step

We maintain a **visited array** and a **stack**:

1. **DFS at node 0**

   * No neighbors → push `0`
   * Stack: `[0]`

2. **DFS at node 1**

   * No neighbors → push `1`
   * Stack: `[0,1]`

3. **DFS at node 2**

   * Neighbor `3`

     * Neighbor `1` → already visited → push `3`
   * Push `2`
   * Stack: `[0,1,3,2]`

4. **DFS at node 4**

   * Neighbors `0,1` → already visited → push `4`
   * Stack: `[0,1,3,2,4]`

5. **DFS at node 5**

   * Neighbors `2,0` → already visited → push `5`
   * Stack: `[0,1,3,2,4,5]`

---

## 🔹 Final Topological Order

* Pop the stack → `[5, 4, 2, 3, 1, 0]`

**Check validity:**

* Edge `5 → 2` ✅ `5` comes before `2`
* Edge `2 → 3` ✅ `2` comes before `3`
* Edge `3 → 1` ✅ `3` comes before `1`
* Edge `4 → 0` ✅ `4` comes before `0`
* Edge `4 → 1` ✅ `4` comes before `1`

✅ All edges satisfy topological order → output is correct.

---

## 🔹 Output

```
Topological Sort (DFS): 5 4 2 3 1 0
```

> Note: Topological sort is **not unique**. Another valid order could be `[4 5 2 3 1 0]`.

---

## 🔹 Key Points

* DFS **pushes nodes after visiting neighbors**, ensuring dependencies come first.
* Only works for **DAGs**.
* **Time Complexity:** `O(V + E)`
* **Space Complexity:** `O(V)` for visited + stack

---

If you want, I can also **draw the DAG and show how each node is pushed into the stack visually**, which helps in interviews.

Do you want me to do that?

*/