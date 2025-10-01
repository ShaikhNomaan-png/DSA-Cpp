/*  🔹 Problem: Number of Operations to Make Network Connected

Problem Statement:
You are given:

n computers (0 to n-1)

connections array of existing cables between computers, where connections[i] = [u, v]

Your task:

Determine the minimum number of operations needed to connect all computers.

One operation = move a cable from one connection to connect two disconnected computers.

If impossible, return -1.

🔹 Key Observations

To connect all computers, at least n-1 cables are required.

If connections.size() < n-1, return -1.

The network can be seen as a graph, where each computer = vertex, cables = edges.

The number of operations = number of connected components - 1.

🔹 Approach Using Disjoint Set (Union-Find)

Initialize Disjoint Set for n computers.

For each connection, union the two computers.

Count number of connected components (distinct parents).

Minimum operations = components - 1.
🔹 Explanation

n = 4, edges = 3

Enough edges: yes (3 >= 4-1)

Using Union-Find:

Union(0,1) → 0 & 1 connected

Union(0,2) → 0,1,2 connected

Union(1,2) → already connected

Count components:

0,1,2 → one component

3 → separate component

Total components = 2

Minimum operations = components - 1 = 2 - 1 = 1 ✅

🔹 Key Points

Need at least n-1 cables to connect n computers.

Count connected components using DFS or Union-Find.

Minimum moves = components - 1.  
*/

#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0;i<n;i++) parent[i] = i;
    }

    int find(int u) {
        if(parent[u] != u) parent[u] = find(parent[u]); // path compression
        return parent[u];
    }

    void unionByRank(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if(pu == pv) return;

        if(rank[pu] < rank[pv]) parent[pu] = pv;
        else if(rank[pv] < rank[pu]) parent[pv] = pu;
        else { parent[pv] = pu; rank[pu]++; }
    }

    int countComponents() {
        int count = 0;
        for(int i=0;i<parent.size();i++)
            if(parent[i] == i) count++;
        return count;
    }
};

int makeConnected(int n, vector<vector<int>>& connections) {
    if(connections.size() < n-1) return -1; // not enough cables

    DisjointSet ds(n);
    for(auto conn : connections) {
        ds.unionByRank(conn[0], conn[1]);
    }

    int components = ds.countComponents();
    return components - 1; // min operations
}

int main() {
    int n = 4;
    vector<vector<int>> connections = {{0,1},{0,2},{1,2}};

    int operations = makeConnected(n, connections);
    if(operations != -1)
        cout << "Minimum operations to connect network = " << operations << endl;
    else
        cout << "Impossible to connect all computers\n";

    return 0;
}

/*  Sure! Let’s explain the **output** of the “Number of Operations to Make Network Connected” problem in detail.

---

# 🔹 Problem Recap

We have:

* `n = 4` computers: 0, 1, 2, 3
* Existing connections: `[[0,1],[0,2],[1,2]]`
* Task: Connect all computers with minimum operations (moving cables if necessary).

---

# 🔹 Step-by-Step Explanation

### Step 1: Check if enough cables exist

* Minimum cables needed to connect `n` computers = `n-1 = 3`
* Given connections = 3 → ✅ Enough cables

If fewer than 3 cables, output = `-1` (impossible).

---

### Step 2: Use Union-Find to find connected components

1. Initialize **Disjoint Set** for 4 computers: each node is its own parent initially

```
Parent: [0,1,2,3]
```

2. Process connections:

* **Union(0,1)** → Merge sets containing 0 and 1

```
Parent: [0,0,2,3]   // 1 points to 0
```

* **Union(0,2)** → Merge sets containing 0 and 2

```
Parent: [0,0,0,3]   // 2 points to 0
```

* **Union(1,2)** → Already in the same set → no change

```
Parent: [0,0,0,3]
```

---

### Step 3: Count connected components

* Component 1: `{0,1,2}` → parent = 0
* Component 2: `{3}` → parent = 3

**Total components = 2**

---

### Step 4: Minimum operations

* Formula: `operations = components - 1 = 2 - 1 = 1`

✅ **Output:** `1`

* Meaning: We need **1 cable** to connect the separate component (computer 3) to the main network.
* For example, move a cable from `[1,2]` to `[2,3]` → all computers connected.

---

# 🔹 Visualization

```
Before moving cable:

Component 1: 0—1—2
Component 2: 3

After 1 operation (connect 2—3):

0—1—2—3   // all computers connected
```

---

# 🔹 Key Takeaways

1. Always check **enough cables exist**: `connections.size() >= n-1`
2. Count **connected components** using Union-Find or DFS
3. **Minimum operations = components - 1**
4. If insufficient cables → **output = -1**

---

If you want, I can also **draw a clear diagram with cable movements** showing exactly which cable to move for this example.

Do you want me to do that?

*/